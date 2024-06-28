//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Dado un valor para x, y una serie de coeficientes, buscamos calcular el valor de un polinomio derivado con esos coeficientes en orden decreciente. (a_0x^n + ... + a_n-1x + a_n)

Solucion:
Rdibiremos los coeficientes como string y los separaremos para saber el grado del polinomio e imprimir u valor con la formaula clasica de la derivada de un polinomio, considerandoe el valor para x ya dado
*/



long long count_num(string s){//Nos permite contar los numeros en el string, segun el formato del problema
	
	if(s.size() == 0){
		return 0;
	}
	
	long long n = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			n++;
		}
	}
	
	return n;
}

//Recordemos que x^y = (x*x)^(y/2)
long long potencia(long long x, long long y){//Funcion para calcular x^y de forma recursvisa. (Suponemos que x no es cero)
	if(y == 0){
		return 1;
	}
	
	if(y % 2 == 0){//Caso de y par, se puede hacer como se menciono al inicio
		return potencia(x*x,y/2);
	}else{
		return x*potencia(x*x,y/2);//x^y = (x*x)^(floor(y/2) + (1/2) )
	}
	
}

vector<long long> a(10000000);//a_0, ..., a_n-1 (n coeficientes) //El tamaño se eligio con tanteo, fallaba si se usaba count_num para declararlo del tamaño justo

void print_v(vector<long long> v){
	for(int i = 0; i < v.size(); i++){
		cout<<"["<<v[i]<<"] ";
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	
	
	long long x;
	
	while(cin>>x){
		
		string coef;
		getline(cin, coef);
		getline(cin, coef);//Recbibimos los coeficientes
		
		//cout<<"Hay "<<n<<" coeficientes"<<endl;
		
        stringstream aux;//Para extraer los coeficientes
        aux<<coef;
        
        long long n = 0;
        while(aux>>a[n]){//Truco para leer los datos y contar los numeros que hay en el coeficiente
        	n++;
		}
		
		//cout<<"Los coeficientes son:"<<endl;
		//print_v(a);
		
		long long pol = 0;
		
		for(int i = 0; i < n-1; i++){
			pol += a[i]*(n-i-1)*potencia(x, (n-2)-i);
		}
		//a_0*(n-1)*(x^(n-2)) + a_1*(n-2)*(x^(n-3)) + ... + a_(n-2)
		
		
		cout<<pol<<endl;
	}
	
	return 0;
}
