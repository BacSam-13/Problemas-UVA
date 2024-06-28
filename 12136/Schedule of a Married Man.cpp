//Baruc Samuel Cabrera Garc�a
//baru.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* 
Problema:
El a�o pasado planteamos un problema de aritm�tica de licenciatura que hizo que algunos solteros se sintieran realmente infelices. 
As� que para equilibrar las cosas, estamos haciendo un problema en la dura agenda de una casada hombre.

Nuestro apuesto h�roe, Danny, recientemente se ha
casado y eso ha creado muchos problemas
para �l, al menos eso es lo que piensan sus amigos.
Tantas promesas incumplidas, tantas citas y cenas perdidas. �Error! Danny, ahora esta
perdiendo pistas incluso de los c�lculos m�s simples, por lo que
debes ayudarlo a decidir si puede asistir a su reuni�n o no. Danny est� ocupado con su
esposa durante gran parte del d�a. Esta gran parte est� indicada por un tiempo de inicio y un tiempo de finalizacion.
Entonces Danny tiene una reuni�n importante en un d�a, se la pierde si se traslapa o toca (Por
ejemplo, si el lapso de tiempo de Danny con su esposa termina a las 18:00 y la reuni�n comienza a las 18:00, entonces los
dos horarios entran en conflicto y Danny se pierde la reuni�n) la hora programada para su esposa. Dado el tiempo
que Danny ha asignado para su esposa y el lapso de tiempo de la reuni�n, tendr� que averiguar si
Danny se pierde esa reuni�n o no.

//Solucion:
Se creo una estructura tiempo para almacenar horas, y se definio el operador < para determinar si esa hora ocurre
antes que otra, usando sus horas y minutos en caso de empate.

Con este operador, y la funcion check, podemos determinar si un dos horarios, cada uno formado por 2 tiempo�s, ocurren en distintos tiempos,
es decir, no se sobreponen.

De esta forma, al recibir las horas como string y pasandolas a tiempo�s, podemos determinar si el esposo puede asistir o no a la reunion.
*/

struct tiempo{
	int a;//Hora
	int b;//Minutos
	
	bool operator < (const tiempo &y){
		if(a <= y.a){
			if(a < y.a){
				return true;
			}
			
			if(b < y.b){
				return true;
			}else{
				return false;
			}
			
		}
		
		return false;
		
	}
};


bool check(tiempo x, tiempo y, tiempo f, tiempo g){//Verifica si las horas se traslapan  (x,y) es el primer horario, (f,g) es el segundo horario
	if(g < x || y < f){//Si el segundo horario termina antes que el primero, o el primero termina antes que el primero
	return true;
	}else{
		return false;
	}

}

int main(int argc, char** argv){
	
	int N;
	cin>>N;
	
	for(int i = 1; i <= N; i++){
		string aux;
		tiempo x, y, f, g;
		
		cin>>aux;
		x.a = stoi(aux.substr(0,2));
		x.b = stoi(aux.substr(3,2));
		
		cin>>aux;
		y.a = stoi(aux.substr(0,2));
		y.b = stoi(aux.substr(3,2));
		
		cin>>aux;
		f.a = stoi(aux.substr(0,2));
		f.b = stoi(aux.substr(3,2));
		
		cin>>aux;
		g.a = stoi(aux.substr(0,2));
		g.b = stoi(aux.substr(3,2));
		
		if(check(x,y,f,g)){
			cout<<"Case "<<i<<": Hits Meeting"<<endl;
		}else{
			cout<<"Case "<<i<<": Mrs Meeting"<<endl;
		}		
		
	}
	
	
	return 0;
}
