//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Minimo comun mutliplo
Un numero puede ser minimo comun multiplo de varias parejas distintas de numeros, a esta cantidad
de parejas se les llama cardinalidad LCM, por lo que buscamos sonocer dicha cardinalidad de unnumero N

Solucion:
Se llenara un vector con los divisores del numero en cuestión, y se formaran las parejas posibles usando combinatoria y la funcion check, la cual
determina si en efecto el numero es su minimo comun multiplo
*/

vector<long long> divisores;//Guarda los divisores de un numero N


void calculate_div(int N){//Llenamos el vector divisores con base en N

    int top = (int)sqrt(N);//El maximo divisor de un numero N, es a lo mas su raiz cuadrada
    
    for(int i = 1; i <= top ; i++) {
    	
        if(N%i == 0) {
        	
            divisores.push_back(i);
            if(i * i != N){//Guardamos su complemento 10/2 = 5 <-> 10/5 = 2
            	divisores.push_back(N/i);
			}
                
        }
    }

}

long long mcd(long long a, long long b){//Funcion para calcular el maximo comun divisor
    long long MCD=1; //Regresamod uno si es que alguno es cero   

    long long x = max(a,b);
    long long y = min(a,b);

    while(y!=0){//Ciclo while para encontrar el maximo comun divisor
        MCD = y;// 
        y = x%y;//a%b regresa el residuo de la division. a%b = c tal que   n*b +c = a
        x = MCD;
    }
    
    return MCD;	
}

int check(long long a, long long b, long long N){//Funcion para determinar si N es el minimo comun multiplo de N (Se obtuvo en internet)

	if((long long)a/mcd(a, b)*b == N){
		return true;
	}
	
	return false;
}

int main(int argc, char** argv) {
	
	int N;
	cin>>N;
	while(N != 0){
		int count = 0;
		divisores.clear();
		calculate_div(N);
		
		//Ahora, hacemos un recorrido a lo largo de los divisores de N
		for(int i = 0; i < divisores.size(); i++){
			for(int j = i; j < divisores.size(); j++){
				//Determinamos si los divisores i y j cumplen la condicon deseada
				if(check(divisores[i], divisores[j], N)){
					count++;
				}
			}
		}
		
		cout<<N<<" "<<count<<endl;
		cin>>N;
	}
	
	
	return 0;
}
