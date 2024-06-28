//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
En las finales mundiales recientes de ACM ICPC (2015), hubo 13 problemas y cada uno de ellos fue resuelto por al menos
menos un equipo. Bueno, no discutiremos sobre cómo sucedió o quién hizo eso.
En este concurso, SIUPC'2015, esperamos tener como máximo 128 equipos en el lugar. Tres hurras por
por convertirte en uno de los equipos participantes!
Ahora, discutiremos lo que queríamos preparar para usted. Desde la final mundial de 2015, solo estamos
inspirado para tener un conjunto de 13 problemas, cada uno de los cuales puede ser resuelto por al menos un equipo participante.
Afortunadamente, nos hemos enterado de un sistema de inteligencia artificial llamado "PAUL". dado un conjunto
de problemas, para cada problema individual, puede predecir el número de equipos que van a resolver
ese problema.
Ahora necesitamos tu ayuda. Te vamos a dar las predicciones de PAUL para algunos conjuntos de problemas.
Para cada uno de los conjuntos de problemas (con 13 problemas), le pedimos que nos diga si podemos considerar el
conjunto para que cada problema de ese conjunto pueda ser resuelto por al menos un equipo.

Solución:
Ya que la condición que queremos confirmar se cumple si todos los elemetos de cada set son mayores a 1,
hacemos un vector de vectores, donde en cada vector de este almacenamos el vector de un set.
Al tenerlos almacenados, iteramos entre ellos y contamos las entradas mayores o iguales a 1, 
si son 13, imprimimos que el set cumple la condición
*/

vector<vector<int>> problem_set;//Para guardar los equipos que Paul creen que resolveran los problemas [i][j] guarda los equipos que resolveran el j-esimmo problema en la prediccion i+1

int main(int argc, char** argv) {
	
	int S;//Conjuntos de 13 problemas dados por PAUl (los equipos que Paul cree que resolveran dicho problema)
	cin>>S;
	
	problem_set.assign(S, vector<int>(13));
	
	for(int i = 0; i < S; i++){
		for(int j = 0; j < 13; j++){
			cin>>problem_set[i][j];
		}
	}
	
	//Para que un set de prediccion para un conjunto sea sea valida, solo requerimos que todos los problemas puedan ser resueltos por al menos algun equipo, es decir, que todo el conjunto tenga valores mayores o iguales a 1
	for(int i = 0; i < S; i++){
		int count = 0;
		for(int j = 0; j < 13; j++){
			if(problem_set[i][j] >= 1){
				count++;
			}
		}
		
		cout<<"Set #"<<i+1<<": ";
		if(count == 13){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}	
	
	return 0;
}
