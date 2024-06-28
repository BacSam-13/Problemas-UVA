//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
using namespace std;

/*
Problema:
Dado un reloj donde la manecilla de la hora se mueve cada 12 minutos, se busca saber que angulos pueden ser formados por las manecillas de este reloj

Solucion:
Despues de un largo analisis, se llego a la conclución que todo angulo multiplo de 6 puede ser formado por las manecillas, por lo que
solo es necesario confirmar si el angulo%6==0 para responder el problema.
Esto ya que el angulo entre un minuto y otro, es de 6 grados.
*/

//La manecilla de las horas se mueve cada 12 minutos
//12 horas = 720 minutos

/*
Primero notemos que siempre es posible tomar un angulo multiplo de 30, y a este, le podemos restar o sumar 11 tics,
ya que son los tics de tolerancia antes de que se mueva la hora.
Recordemos que un tic vale 6 grados, por lo que si un gradoes de la forma
30*i + 6*j,    con 0<=i<=6  y  -11<=j<=11

Como podemos notar, todos los posibles grados son divisibles entre 6, que es justamente el ángulo entre dos tics.

Por lo tanto, podemos afirmar que un grado es visible en el reloj si este cumple que grado%6 = 0
*/

int step_minute(int minute){//Recibe la posicion del minutero y regresa cuantos tics le faltan para que la hora avanze
	return 12 - (minute%12);
}


int minute_hour(int minute){//Recibe donde esta el minutero y cuantas posiciones debe de avanzar la manecilla de las horas
	
	return (minute/12)%5;
}


int tics(int minute, int hour){//Regresa la distancia entre el minutero y la manecilla de la hora en tics (6 grados)
	
	if(minute == 60){
		minute = 0;
	}else if(hour == 60){
		hour = 0;
	}
	
	int x = abs(minute-hour);	
	
	if( x > 30){
		return 60-x;
	}else{
		return x;
	}
	
}

int angle(int minute, int hour){
	return 6*tics(minute, hour);
}

void casos(int grado){//Con base en lo mencionado al inicio, imprime si el grado es valido o no
	
	if(grado%6 == 0){
		cout<<"Y"<<endl;
	}else{
		cout<<"N"<<endl;
	}
	
}

int main(int argc, char** argv){
	
	int x;
	
	while(cin>>x){
		casos(x);
	}
	
	return 0;
}
