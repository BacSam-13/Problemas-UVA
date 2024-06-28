//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Tenemos N edificios, cada uno con una anchura y altura determinada.
Debemos averiguar si "the skyline" esta decreciendo o creciendo.
Decimos que esta creciendo si la subsecuencia creciente de edificios 
mas larga es mas grande o igual a la subsecuencia decreciente mas larga de edificios.(1)
En otro caso, decimos que es decreciente.

Ahora, es necesariomencionar que la longitud de la subceucneica es la suma de las anchuras de los edificios.

Ejemplo: Si tenemos 6 edificios con las siguientes alturas y anchuras
10, 100, 50, 30, 80, 10
50,  10, 10, 15, 20, 10
--
--           ------
    -----------      --

Tenemos una subcecuenica creciente de 3 edificos con una longitud total de 85
Y una subcecuencia decreciente de 1 edificio con longitud total de 50 (es la que tiene la maxima longitud total, hay una de 4 edificos con longitud total de 45)


*/


/*
Solución:
		Primero, guardaremos las alturas y anchiras de todos los edificios.
		Luego, almacenaremos la altura y anchura del i+1 edificio en la entrada i de cada vector.
		Notemos que supondremos que ese edificio forma parte de una subsecuencia creciente o decreciente de edificios. (Hay subsecuenicas de un elementos)
		De esta forma, se evaluaran las i subsecuencias previos y determinaremos si este edificio es el ultimo de esta nueva subsecuenica creciente o decreciente.
		Esto ultimo se debe a que iremos armando las subcecuencias optimas, ya sean crecientes o decrecientes, tomando en cuenta los grupos de edificios de la forma [0,k]
		Es decir, que obtendremos la subsecuenia optima para un edificio, con esta subsecuenica, encontraremos la subsecuencia optima para dos edificios, y asi sucesivamente.
		
		Esto lo comprobaremos facil comparando la altura del ultimo edificio de las subsecuencias anteriores con la altura del nuevo edificio.
		Si cumple con la característica deseada para formar una subsecuencia, guardaremos la anchura de dicha subsecuenia y la del edificio que estemos evaluando
		
		Al final, hacemos un recorrido buscando la lognitud maxima creciente y decreciente, e imprimimos el resultado con base al maximo de ests dos
*/


int main() {

    int N;//Numero de casos
    cin>>N;
    
    for(int i = 0; i < N; i++) {

        int n_edif;//Numero de edificios en el caso
        cin>>n_edif;
        
        vector <int> alturas(n_edif);
        vector <int> anchuras(n_edif);
        //Vectores para guardar la altura y anchura del i+1 edificio

        for (int i = 0; i < n_edif; i++){
        	cin>>alturas[i];
		} 

  
        for (int i = 0; i < n_edif; i++){
        	cin>>anchuras[i];
		}

		//Los siguientes vectores son para considerar subsecuencias crecientes y subcrecientes.

		
        vector <int> incr_alt(n_edif);
        vector <int> incr_anc(n_edif);
        
        vector <int> decr_alt(n_edif);
        vector <int> decr_anc(n_edif);
		        
        for (int i = 0; i < n_edif; i++) {
			
			//Ultimo edificio de la nueva subsecuencia (Puede ser primero y ultimo)
            incr_alt[i] = alturas[i];
            incr_anc[i] = anchuras[i];

            decr_alt[i] = alturas[i];
            decr_anc[i] = anchuras[i];

            for (int j = 0; j < i; ++j){//Evaluamos las i-1 subsecuenias anteriores
            
                if (incr_alt[j] < incr_alt[i]){//Si la altura del edificio actual es mayor a la del ultimo edificio de la subsecuencia j, podemos formar una nueva subsecuenia creciente
                	
                    if (incr_anc[j] + anchuras[i] > incr_anc[i]){//Vemos si la anchura de la nueva subsecuencia seria mayor a la subsecuencia actual
                    	incr_anc[i] = incr_anc[j] + anchuras[i];//Si es asi, guardamos la anchura de esta nueva subsecuenia
					}                                   	
				}


                if (decr_alt[j] > decr_alt[i]){//Si la altura del edificio actual es mayor a la del ultimo edificio de la subsecuencia j, podemos formar una nueva subsecuenia decreciente
                	
                    if (decr_anc[j] + anchuras[i] > decr_anc[i]){//Vemos si la anchura de la nueva subsecuencia seria mayor a la subsecuencia actual
                    	decr_anc[i] = decr_anc[j] + anchuras[i];//Si es asi, guardamos la anchura de esta nueva subsecuenia
					}            	
				}

                        
            }
        }
        
        
		//En este punto, conocemos las anchuras totales de todas las subsecuencias que terminan en el edificio i, por lo que solo resta encontrar las que tengan mayor anchura de cada tipo
        
		//Anchuras de las subsecuencias crecientes y decrecientes.
		
		int total_anc_incr = 0;
        int total_anc_decr = 0;
        
        for (int i = 0; i < n_edif; i++) {//Buscamos la subsecuenia con mayor anchura
            
			if (total_anc_incr < incr_anc[i]){
            	total_anc_incr = incr_anc[i];
			}
			
            if (total_anc_decr < decr_anc[i]){
            	total_anc_decr = decr_anc[i];
			}
			
        }

        cout << "Case " << i+1 << ". ";
        
        if (total_anc_incr >= total_anc_decr){//Recordemos el punto (1)
        	//La skyline es creciente
        	cout<<"Increasing ("<<total_anc_incr<<"). Decreasing ("<< total_anc_decr<< ")." << endl;
		}else{
			//La skyline es decreciente
			cout<<"Decreasing ("<< total_anc_decr<< "). Increasing ("<< total_anc_incr<< ")." << endl;
		} 
		

	}
	
}
