//Baruc Samuel Cabrera Gacía
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Jollo es un sencillo juego de cartas que a los niños de Logonia les encanta jugar. Se juega entre dos
jugadores con una baraja normal de 52 cartas. En el juego, las cartas se ordenan según su rango y
traje, formando una secuencia de 52 valores distintos.
El juego se compone de tres rondas, jugadas en una serie al mejor de tres (un jugador debe ganar dos
rondas para ganar el juego). Al comienzo del juego se baraja el mazo y se le da a cada jugador
una mano de tres cartas. En cada ronda los jugadores se muestran una carta entre sí y el jugador con la
la carta más alta gana la ronda. Las cartas que se muestran en una ronda se descartan (es decir, no se pueden mostrar
otra vez).
Al hijo del rey le encanta jugar. Pero no es muy inteligente y pierde con frecuencia ante su hermana pequeña.
Y cuando pierde, llora tan fuerte que nadie puede soportarlo. El sirviente que reparte las cartas al Príncipe
y su hermana teme que lo envíen a prisión si el Príncipe sigue perdiendo. El sirviente está permitido
para ver cada carta que reparte, y después de repartir cinco cartas (tres a la Princesa y dos al Príncipe) él
quiere saber cuál es la carta más baja que debe repartir al Príncipe para que no haya posibilidad de que
pierde el juego, no importa lo mal que juegue.

Cada caso de prueba se da en una sola línea que contiene cinco enteros distintos A, B, C, X e Y, que describen
las cartas repartidas a los jugadores. Las tres primeras cartas se entregan a la Princesa (1 = A, B, C = 52) y
las dos últimas cartas se le dan al Príncipe (1 = X, Y = 52). El último caso de prueba va seguido de una línea
que contiene cinco ceros.
*/

vector <int> Princess(3);//Cartas para la princesa
vector <int> Prince  (2);//Cartas para el principe
vector <bool> Deck    (53, true);//Nos dice que cartas estan disponibles

/*
Solucion:
Debido a que buscamos que el principe gane, debeos encontrar la minima carta tal que el principe pueda ganar 2 partidas,
por lo tanto, buscamos elegir una carta disponible en los casos donde puede que el principe gane.
(Al mencionar i cartas de la princesa, se supondra que son las i primeras cartas de sus 3 cartas ordenadas de menor a mayor)

-Si el principe tiene dos cartas que les ganan a las 3 de la princesa- 2/3 garantizadas
	Se elige la carta disonible de menor valor
	
-Si el principe tiene una carta que le gana a las 3 de la princesa- 1/3 garantizadas
	Se elige la carta disponible con menor valor tal que sea mayor a todas las de la princesa
	
-Si las dos cartas del principe le ganan a dos de la princesa- 0/3 garantizadas
	Buscamos una carta que le gane de nuevo a dos de la princesa, de esta forma, si la 3era le gana a una de las del principe,
	podra ganar 2/3
	
En el resto de casos, el principe no puede ganar
	
*/


int main(int argc, char** argv) {
	
	cin>>Princess[0]>>Princess[1]>>Princess[2]>>Prince[0]>>Prince[1];
	
	while(Princess[0] != 0){//Si una carta vale cero, se rompe el while

		sort(Princess.begin(), Princess.end());//Se ordenan los vectores para su mejor uso
		sort(Prince.begin(), Prince.end());
		
		for(int i = 0; i < 3; i++){//Marcamos las cartas del principe y la princesa como no disponibles
			Deck[Princess[i]] = false;
			
			if(i < 2){
				Deck[Prince[i]] = false;;
			}
		}
		
		int card = 53;//Para elegir la carta que permita ganar al principe (Si en un caso se elige una carta, buscaremos que en los demas casos no se elija una carta mayor a la ya seleccionada)
		
		//Ahora, segun las cartas dadas, buscaremos los casos donde puede que sea posible que elprincip e logre un 2/3, y buscaremos si en esos casos hay una carta disponible
		
		//CAS0 1
		if (Prince[0] > Princess[2]){//Si las dos cartas del principe son mayores a las 3 de la princesa, tomamos la primera carta disponible, ya que con las 2 que ya tiene, puede ganar 2/3
			//cout<<"CASO 1: ";
            for (int i = 1; i < card; i++){
            	if(Deck[i]){//Si podemo tomar la carta i, la tomamos
            		card = i;
            		break;
				}
			}
			
		
        }
		
		//CASO 2
		if(Prince[1] > Princess[2]){//Si la segunfa carta del principe es mayor a las 3 de la princesa, debemos escoger una carta que le gane a las 3 de la princsa, asi el principe ganara 2/3
			//cout<<"CASO 2: ";   
			for(int i = Princess[2] + 1; i < card; i++){
				if(Deck[i]){
					card = i;
					break;
				}
			}    
			
		//CASO 3		
		}
		
		if(Prince[0] > Princess[1]){//Si las cartas del principe le ganan a dos de la princesa, buscamos una carta que nos permita ganarle a esas dos, ya que si pierde una, con las 2 cartas restantes logra tener 2/3
			//cout<<"CASO 3: ";
			for(int i = Princess[1] + 1; i < card; i++){
				if(Deck[i]){
					card = i;
					break;
				}
			}

		}
		
		//En el resto de casos, el principe las tiene todas las de perder, por lo que no es necesario examinarlas
		
		if(card != 53){
			cout<<card<<endl;
		}else{
			cout<<-1<<endl;
		}
		
		
		cin>>Princess[0]>>Princess[1]>>Princess[2]>>Prince[0]>>Prince[1];
		Deck.assign(53, true);
	}
	
	return 0;
}
