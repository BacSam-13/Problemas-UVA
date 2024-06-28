//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problrema: Dado un numero, de a lo mas 10^100 digitos, buscamos determinar si es multiplo de 17
*/

/*
Solucion:
Debido a que buscamos determinar si un numero es multiplo de 17, realizamos una suma de todos sus digitos por separado
De estaforma, al aplicar %17 a cada digio (multiplicado por su respecitva potencia de 10), podemos facilitar el cálculo final de %17.
Ya que en el peor de los casos, se calcularia para un numero de tamaño 10^100
*/
int main(int argc, char** argv) {
	
	
	string n;
	cin>>n;
	while(n != "0"){
		
		if(n.size() < 2){//Es claro que no es multiplo de 18
			cout<<0<<endl;
		}else{
			
			int rest = 0;
			//Usamos esto ya que stoi falla si el tamaño es muy grande
			for(int i = 0; i < n.size(); i++){
				rest = ((rest*10) + n[i]- '0') % 17;
			}
			
			if(rest == 0){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}			
				
		}
		
		cin>>n;

	}
	
	
	return 0;
}
