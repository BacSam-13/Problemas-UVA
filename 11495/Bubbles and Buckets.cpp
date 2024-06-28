//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Similar a Bubble Sort, dos amigos buscan jugar a "ordenar" un arreglo de N elementos desordenados
Tales que cada jugador elige una pareja de numeros consecutivos y desordenados y los intercambia, el
jugador que no pueda realizar un intercambio, pierde.

Los jugadores con Marcelo y Carlos. Marcelo siempre empieza primero

Solución:
Empleando divide and conquer, determinamoscuantos swaps se nesecitan para ordenar el arreglo o ya no se puedan hacer swaps con la condicion ya mencionada. Luego, se analiza la paridad 
de los swaps, ya que si es impar, gana Marcelo, y Carlos si es par
*/


int count_moves(vector<int> &v, int left, int right) {

    if(right-left == 0){//Si no se puede realizar otra vez algun swap
    	return 0;
	}

    int left_moves = count_moves(v, left, (left + right)/2);//Dados los idx del extremo izquierdo y derecho, evaluamos cuantos swaps se pueden hacer en la mitad izquierda
    int right_moves = count_moves(v, (left + right)/2 + 1, right);//Y en la mitad derecha
    
    int moves = left_moves + right_moves;//Los movimientos totales

    vector<int> aux(right - left + 1);//Vector auxiliar para el nuevo orden
    int li = left;//idx para moernos desde la izquierda
    int middle = (left + right)/2 + 1;
    int ri = middle;//Para movernos desde la mitad

    int i;
    for(i = 0; i < right - left + 1  && li < middle && ri <= right; ++i){//Llenaremos aux mientras li no llegue a la mitad, y ri no sobrepase la derecha
        if (v[li] < v[ri]){//Swap
            aux[i] = v[li];
            li++;
        }else{
            aux[i] = v[ri];//No hubo swap
            ri++;
            moves += middle - li;
        }
    }

    while (li < middle) {//Llenamos el resto en caso de que aun se pueda llenar
        aux[i] = v[li];
        i++;//++i;
        li++;//++li;
    }
    
    while (ri <= right) {
        aux[i] = v[ri];
        i++;//++i;
        ri++;//++ri;
    }
    
    for (int j = 0; j < aux.size(); ++j){//Actualizamos v
    	v[left + j] = aux[j];
	}

    return moves;
}

int main(){

    int n;
    cin>>n;//Primer juego (N)
    
    while(n){//Si N = 0, se terminan los juegos

        vector<int> array(n);
        for(int i = 0; i < n; ++i){
        	cin>>array[i];
		}
		

		
        if (count_moves(array, 0, n-1) & 0x01){//Calculamos los switchs que se pueden realizar en total. Si es un numero impar, el utimo en hacer el switch es Marcelo, por lo que gana el
        	cout<<"Marcelo"<<endl;
        	
		}else{//Si los movimientos son pares, el utimo en hacer el switch es Carlos, por lo que gana el
			cout<<"Carlos"<<endl;
		}
            

        cin>>n;
    }
}
