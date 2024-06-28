//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Hay lenguajes que tienen palabras en comun, como "actual" en español e ingles.
El objetivo del problema es que dada un lenguaje de inicio y uno de final. Dar una secuencia de palabras tales que
sus adyacantes comparten el hecho de que son palabras en distintos lenguajes. De esta forma, llegar del idioma de inicio al final
Ejemplo: Sea Portugues el idioma de inicio y Frances el idioma final sea Frances, se puede usar

Portugues/Español   Español/Ingles   Ingles/Frances
amigo               actual           date

Ademas de esto, buscamos en total usar la minima cantidad de letras, ademas de que las palabras continuas tengan una inicial diferente.
Por lo que una solución valida para el ejemplo previo sería:

Portugues/Español   Español/Ingles   Ingles/Frances
amigo               red           date

Con 12 letras en total


Dadas ciertas listas de palabras con sus idiomas, ademas de las palabras de inicio y fin. Se busca responder si es posible realizar la accion y decir el mínio de letras
*/

/*
Solución:
Notemos que podemos ver los lenguajes como nodos, y las palabras en comun como aristas, por lo que se puede resolver como el problema de ruta mas corta desde un nodo a otro.
Por lo que usaremos el Algoritmo de Dijkastra para esto, donde usaremos los caracteres de las palabras de las aristas como pesos
*/


/*
Como nota extra: //impossivel significa impossible en Portugies
*/

int dijkstra(   vector< vector< pair<int, pair<string, bool> > > > &g, int start_lang, int end_lang) {

    //priority_queue composed by <<total_lenght, last_letter>, language>
    priority_queue< pair< pair<int, char>, int > > Q; //Cola de prioridad para Dijkastra. Guardamos 
    
    Q.push(make_pair(make_pair(0, 'A'), start_lang));//Un elemento general para empezar el ciclo. Se eliminara casi inmediatamente al entrar al while
	//Se guarda 'A' porque las palabras siempre estaran en minusculas, asi garantizamos que no se active el primer if del for

    while (!Q.empty()) {
		
		//Extraemos el top de Q
        pair< pair<int, char>, int > p = Q.top();
        Q.pop();

        if (p.second == end_lang){//Si llegamos al idioma final
        	return -p.first.first;//Regresamos la longitud (recordemos que guardamos las longitudes en negativo)
		}

        for (int i = 0; i < g[p.second].size(); ++i) {//Exploramos las aristas (palabras) del lenguaje (p.second). Recordemos que cada lenguaje tiene asignado un numero diferente

            //if !used(current_edge) and
            // first_letter(current_edge) != last_letter
            //Si la arista no ha sido usada (!false) y si la primera letra de la i-esima arista (palabra) del nodo no es igual a la que tenemos registrada 
            if (   !g[p.second][i].second.second && g[p.second][i].second.first[0] != p.first.second) {

                //add this edge to the queue
                //inverse length to let the queue sort the shortest first
                Q.push( make_pair( make_pair(  -(-(p.first.first) + g[p.second][i].second.first.size()), g[p.second][i].second.first[0]), g[p.second][i].first) );//Agregamos este nuevo nodo
                //Guardamos (longitud total, primer caracter de la palabra (arista) que se agrego), lenguaje siguiente
				//Notemos que guardamos las longitudes negativas, para que asi la queue ordene primero las mas cortas

                g[p.second][i].second.second = true;//Marcamos la arista como usada
            }
        }
    }

    return -1;
}


int main(){
	
    int n;
    cin>>n;
    
    while (n != 0){

        //map to get the corresponding index for each language
        map<string, int> mapita;//A cada lenguaje le asignamos un idnex para el grafo. Es decir, según el lenguaje que queremos, nos dice en que nodo esta dicho lenguaje, ademas de sus palabras con idiomas adyacentes
        
        vector< vector< pair<int, pair<string, bool> > > > grafo;//Vector de aristas; guardamos el lenguaje de "salida", la palabra y si fue usada
        
		int g_index = 0;//Aristas del grafo (Una palabra que comparte dos lenguajes, la consideraremos como dos aristas)
		//Para guardar la posicion de cada lenguaje en el grafo. Ademas de contar el numero de aristas (grafo dirigido y aristas dobles)

        string start_leng, end_leng;
        
        cin>> start_leng >> end_leng;//Recibimos los lenguajes de inicio y fin

        for(int i = 0; i < n; ++i){//Consideraremos n palabras

            string l_1, l_2, word;
            cin>>l_1>>l_2>>word;//Lenguaje 1, Lenguaje 2, palabra

            if (mapita.find(l_1) == mapita.end()){//Si es la primera vez que ingresamos el lenguaje
                mapita[l_1] = g_index;//Guardamos el nodo de dicho lenguaje
                g_index++;//Hay un nodo mas
                grafo.push_back(vector< pair<int, pair<string, bool> > > ());//Preparamos un vector para guardar las palabras de dicho lenguaje, asi como sus lenguajes adyacentes
            }
            
            if (mapita.find(l_2) == mapita.end()){//Analogo a l_1
                mapita[l_2] = g_index;
                g_index++;
                grafo.push_back(vector< pair<int, pair<string, bool> > > ());
            }

            grafo[mapita[l_1]].push_back(make_pair(mapita[l_2], make_pair(word, false)));//Guardamos la palabra que conecta l_1 a l_2 (Aun no usamos la palabra, por lo que guardamos false)
            grafo[mapita[l_2]].push_back(make_pair(mapita[l_1], make_pair(word, false)));//Guardamos la palabra que conecta l_2 a l_1 (Aun no usamos la palabra, por lo que guardamos false)
        }

        if ( ( mapita.find(start_leng) == mapita.end() ) || ( mapita.find(end_leng) == mapita.end() ) ){//Si no hay palabras para los idiomas de inicio o fin, es evidente que no hay una solucion
            cout << "impossivel" << endl;
        } else {
        	
            int cost = dijkstra(grafo, mapita[start_leng], mapita[end_leng]);//Obtenemos el costo para ir de start_leng a end_leng (-1 en caso de haber camino)
            
			if(cost == -1){
				cout <<"impossivel"<<endl;
				
			}else{
				cout<<cost<<endl;
				
			}
			
        }


        cin>> n;
    }
}
