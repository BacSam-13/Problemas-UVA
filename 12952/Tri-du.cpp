#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Tri-du es un juego de cartas inspirado en el popular juego de Truco. El juego utiliza una baraja normal de 52 cartas,
con 13 cartas de cada palo, pero los palos se ignoran. Lo que se utiliza es el valor de las cartas, considerado como
números enteros del 1 al 13.
En el juego, cada jugador recibe tres cartas. Las reglas son simples:

• Un Trío (tres cartas del mismo valor) gana a un Par (dos cartas del mismo valor).

• Un trío formado por cartas de mayor valor gana a un trío formado por cartas
de menor valor.

• Una Pareja formada por cartas de mayor valor gana a una Pareja formada por cartas de menor valor.

Tenga en cuenta que el juego puede no tener un ganador en muchas situaciones; en esos casos se devuelven las tarjetas
a la baraja, que se vuelve a barajar y comienza un nuevo juego.
Un jugador ya recibió dos de las tres cartas y conoce sus valores. Su tarea es escribir un
programa para determinar el valor de la tercera carta que maximiza la probabilidad de que ese jugador gane
el juego.
*/

/*
Solucion:
En este caso, se debe determinar si es mejor formar una pareja o un trio. Lo cual podemos determinar si las dos cartas recibidas son iguales o no,
si lo son, se elige facil el trio, en otro caso, se elige la carta de mayor valor de las ya recibidas.
*/

int main(int argc, char** argv) {
	
	
	int a, b;
	
	while(cin>>a>>b){
		if(a == b){
			cout<<a<<endl;
		}else{
			cout<<max(a,b)<<endl;
		}
	}
	
	
	return 0;
}
