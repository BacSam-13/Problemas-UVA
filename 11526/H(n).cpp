//Baruc Samuel Cabrera García
//baruc.cabrera@ugto.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Problema:
Cual es el valor de la siguiente funcion?:
long long H(int n){
	long long res = 0;
	for( int i = 1; i <= n; i=i+1 ){
		res = (res + n/i);
	}
	return res;
}*/

/*
Solucion:
Notemos que podemos reducir el calculo de H(n), calculando hasta H(sqrt(n)), luego, este
resultados los mutiplicamos por 2 y le restamos floor(sqrt(n+.0001))^2
*/

/*
long long H(long long n){
	
	long long res = 0;
	
	for(long long i = 1; i <= n; i++){
		res += n/i;
	}
	return res;
}

vector<double> Sumi(10000000);//Suma de 1/j desde 1 a i
void Prepare_S(int n){
	Sumi[1] = 1;
	for(int i = 2; i <= n; i++){
		Sumi[i] = Sumi[i-1]+(1/i);
	}
}

vector<long long> H_vec(10000000);//32 bit integer
void Prepare_H(int n){
	
	H_vec[1] = 1;

	for(int i = 2; i <= n; i++){
		H_vec[i] = H_vec[i-1] + Sumi[i] + (n/(n+1)); 
	}
}
*/


int main(){
	
    int cases, extra;
    long long n,res;
    
    cin>>cases;
    
    while(cases--){
        cin>>n;
        res = 0;
        extra = sqrt(n + .0001);
        
        for(long long i = 1;i*i <= n; i++){
        	res += (n/i);
		}
		
		cout<<2*res - extra*extra<<endl;

    }
        return 0;
}
