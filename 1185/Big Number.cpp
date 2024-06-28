//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
En muchas aplicaciones se requieren números enteros muy grandes. Algunas de estas aplicaciones están utilizando
claves para la transmisión segura de datos, cifrado, etc. En este problema se le da un número, tiene
para determinar el número de dígitos en el factorial del número.
Los numeros en cuestion cumplen que  1 <= n <= 10^7

Solucion: 
Notemos que se cumple que los digitos de i! se puede calcular como piso de los difitos de (i-1)! + log10(i).
Esto ya que los productos del factorial se pueden representar con la suma de logaritmos, donde cada vez que se alcance una suma que equivalga a log10(10 o mas),
se aumenta en uno la cantidad de digitos.
Por lo tanto, si preecalculamos los digitos de los numeros de 1 a 10000000, podemos responder facil a las preguntas 
*/

#define MAX  10000000

vector<double> dig(MAX+2);

void prepare_dig(){ //Guardamos los digitos de (i+1)!
	dig[1] = 1;
	for(int i = 2; i <= MAX+1; i++){
		dig[i] = dig[i-1] + log10(i);
	}
}

int main(){
	

	
	int cases, n;
	
	prepare_dig();
	/*
	for(int i = 1; i < 1001; i++){
		cout<<"log10("<<i<<") = "<<log10(i)<<"\t"<<dig[i]<<endl;
	}
	*/
	cin>>cases;
	
    while(cases--){
        cin>>n;
        cout<<(int)dig[n]<<endl;//Equivalente a funcion piso

    }
    return 0;
}
