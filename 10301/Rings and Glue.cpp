//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
El pequeño Timmy jugaba con anillos y pegamento, haciendo que varios se pegaran entre si al caerse al suelo.
Por lo que el pequeño Timmy debe recogerlos antes de que su mama llegue.
Pero como Timmy es un aficionado de los numeros, recogera primero la secuenica de anillos pegados que tenga mas anillos, 
y queremos saber cuantos anillos tiene esta.

Dos anillos están pegados si y solo si se superponen en algún punto, pero ningún anillo se superpondrá nunca.
en un solo punto. Todos los anillos son del tipo donut (con un agujero en ellos). Sin embargo, pueden,
según Timmy, ser considerado “infinitamente delgados”.

Solucion:
Teniendo ya todos los anillos con su radio y coordenadas, hacems una función la cual nos indica si dos anillos se intersectan con base
en procedimientos de geometría ya vistos en cursos pasados.

Ya que tenemos como determinar si dos anillos se intersectan, hacemos un vector de cabezas, en la cual guardaremos el anillo de cabeza de cada uno,
así, donde el anillo cabeza del anillo i, es el anillo con mayor idx tal que esta pegado a este.
De esta forma, podemos crear un vector count para contar los anillos totales pegados a las cabezas, ya solo resta encontrar el idx tal que tiene el maximo y listo.
*/

bool intersect( vector< pair< float, pair<float, float> > > &ring, int i, int j){

    float dist_x = ring[i].second.first - ring[j].second.first;//Distancia entre los centros de los anillos segun el eje x
    float dist_y = ring[i].second.second - ring[j].second.second;//Distancia entre los centros de los anillos segun el eje y
    float distance = sqrt((dist_x*dist_x) + (dist_y*dist_y));//Distancia total entre los centros de los anillos
    double sum_radios = ring[i].first + ring[j].first;//Suma de los dos radios
    double dif_radios = abs(ring[i].first - ring[j].first);//diferencias entre los radios
    
    //Si no se cumple lo 1ero, los anillos ni se tocan, si no se cumple lo segundo, un anillo estaria dentro de otro
    if((distance <= sum_radios) && (distance >= dif_radios)){//Si la suma de los radios es mayor o igual a la disntancia entre los centros de los anillos, y esta distancia es mauor o igual a la diferencia de los radios
    	return true;//Los anillos se soreponen
	}else{
		return false;
	}

}

int main(){
	
    int n;
    cin>>n;
    
    while(n != -1){

        vector< pair<float, pair<float, float> > > ring(n);
        
        for(int i = 0; i < n; ++i){//Recibimos coordenadas (x,y) del anillo, y el radio de este

            cin>>ring[i].second.first>>ring[i].second.second>>ring[i].first;
        }

        vector<int> head(n);
        
        for (int i = 0; i < n; ++i){//Si enumeramos los anillos, head[i] dira el anillo con numero mas alto al que esta pegado el anillo i (1-2-3-6 -> 6)
        	head[i] = i;
		}

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
            	
                if (head[i] != head[j] && intersect(ring, i, j)){//Si los anillos no parecen estar pegados (aun) y uno se sobrepone a otro 
                	
                    int ne_w = max(head[i], head[j]);
                    int old = min(head[i], head[j]);
                    for (int k = 0; k < n; k++){
                    	if (head[k] == old){
                    		head[k] = ne_w;
						}
					}
                        
                }
            }
        }

        vector<int> count(n, 0);//Para contar los anillos de cada cabeza
        int max = 0;//La maxima cantidad de anillos
        
		for(int i = 0; i < n; i++){
            count[head[i]]++;
            
            if (count[head[i]] > max){
            	max = count[head[i]];
			}
        }
		
		if(max == 1){
			cout<<"The largest component contains 1 ring."<<endl;
		}else{
			cout<<"The largest component contains "<<max<<" rings."<<endl;
		}


        cin>>n;
    }
}
