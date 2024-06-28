//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mc
#include <bits/stdc++.h>
using namespace std;

map <int, int> orden;//Para guardar el orden de ingreso de los especimenes

/*
Problema:
La Estación Espacial Internacional contiene muchas centrífugas en sus laboratorios. Cada centrífuga tendrá algunos
número (C) de cámaras, cada una de las cuales puede contener 0, 1 o 2 especímenes. Tienes que escribir un programa.
que asigna todos los S especímenes a las cámaras de modo que ninguna cámara contenga más de 2 especímenes
y se minimiza la siguiente expresión para IMBALANCE

IMBALANCE = sum_{i=1}^{2} (|CMi - AM|) 


CMi: masa de la cámara de la cámara i y se calcula sumando las masas de las muestras
asignado a la cámara i.

AM: masa promedio de las cámaras y se calcula dividiendo la suma de las masas de todos
especímenes por el número de cámaras (C).

1<=C<=5
1<=S<=2C
*/


/*
Solucion:
Ya que buscamos minimizar el valor de IMBALANCE, y este depende directamente de la suma de ciertas masas 
(generalmente son d dos, a veces de una).
Por lo tanto, la mejor forma de minimizar estas sumas, es evitando incrementar mas las mayores masas, por lo que se buscara
que aquellos especimenes con una mayor masa se encuentren solos en una camara. 
Para eso se ordeno el vector, ya que habra C camaras, podemos armar 2*C parejas, donde las primeras 2*C -S parejas (tomando extremos del inicio y final del vector)
seran especimenes solos, es decir, que la preja sera un especimen de gran masa y una mas cero.
Cuando se acaben los ceros, el resto de las parejas tendran masa miníma.
Luego se ordenan segun su orden de ingreso, lo cual hacemos cun map y una funcion comparador
    */

bool compare(pair<int, int> A, pair<int, int> B){
	
	return orden[A.first] < orden[B.first];
	
}

int main() {

    int Set = 1;
    int C, S;
    while (cin >> C >> S) {

        vector<int> especimenes(2*C, 0);//Solo llenamoremos S entradas
        orden.clear();
        
        long double masa_total = 0;
        for (int i = 0; i < S; ++i) {
            cin>>especimenes[i];
            orden[especimenes[i]] = i;
            masa_total += especimenes[i];
        }
		orden[0] = 10000;
		
        sort(especimenes.begin(), especimenes.end());
        //Al ordenarse, se cumple que las primeras 2*C - S entradas estan llenas de ceros
        


        long double AM = masa_total / C;
        long double IMBALANCE = 0;

        cout << "Set #" << Set << endl;
        Set++;
        
        vector<pair<int, int>> camaras(C);
        
        for (int i = 0; i < C; i++){//i representara el extremo izquierdo
            int j = 2*C - 1 - i;//j representara el extremo derecho
            IMBALANCE += fabs(especimenes[i] + especimenes[j] - AM);

            
            if(orden[especimenes[i]] < orden[especimenes[j]]){//Almacenamos los especimenes seun su orden de aparicion.
            	camaras[i] = make_pair(especimenes[i], especimenes[j]);
			}else{
				camaras[i] = make_pair(especimenes[j], especimenes[i]);
			}

        }
        
        sort(camaras.begin(), camaras.end(), compare);
        
        for(int i = 0; i < C; i++){//Imrprimimos las camaras ya ordenadas
        	cout<<" "<<i<<":";
        	if(camaras[i].first != 0){//I
        		cout<<" "<<camaras[i].first;
			}
			
			if(camaras[i].second != 0){
				cout<<" "<<camaras[i].second;
			}
			cout<<endl;
        	
		}
        
        cout << "IMBALANCE = " << setprecision(5) << fixed << IMBALANCE << endl << endl;
    }
}
