//Baruc Samuel Cabrera García
//baru.cabrera@cimat.mx

#include <bits/stdc++.h>
using namespace std
#define MAX 1000//Maximo de contenedores a ingresar 
;

#define LET 26//Hay 26 tipos de contenedores
;

/*
Problema: Dados a lo mas MAX contenedores de LET tipos(A-Z), se busca apilarlos de tal forma que los barcos A-Z puedan recoger todos sus contenedores sin realizar intercambios.
Ademas, se busca minimizar la cantidad de pila de contenedores

Solucion: 
Preparamos un vector de pilas, donde el primero contenedor forma la primera pila.
Luego, los demas contenedores se van apilando con la condicion de que se pongan encima de un contendor con mayor valor.
Si no se pudo encontrar una pila con esa condicion, se crea una nueva inmediatamente a lado.
Cada que se crea una nueva pila, incluyendo la inicial, se aumenta en 1 el resultado.

*/

int caract(int *A){//Cuenta las letras totales ingresadas(Los disitntos tipos de contenedores)
	
	int sum = 0;
	
	for(int i = 0; i < LET; i++){
		if(A[i]>0){
			sum++;
		}
	}
	cout<<endl;
	return sum;
}

int main(int argc, char** argv) {

	int caso = 1;
	string word;//Recibimos las letras de los contenedores
	bool flag = false;//Bandera que nos permitira saber cuando un contenedor no se pudo colocar en algun stack     xxxxxx
	cin>>word;
	
	while(word != "end"){
		int contenedores_p = 0;//Numero de pilas de contenedores actuales
        vector < stack<char> > Pilas (26);//Vector de pilas (En el peor de los casos, hay una pila para cada tipo de contenedor)
        
        Pilas[0].push(word[0]);//Se agrega como primer la primera pila de contenedores
		contenedores_p++;
		
		for(int i = 1; i < word.length(); i++){//Analizamos al resto de contenedores
			flag = false;
			
			for(int j = 0; j < contenedores_p; j++){//Vemos donde puede ir el contenedor, en los diferentes stacks
				
				if(word[i] <= Pilas[j].top()){//Si el contenedor puede ser recogido antes que el primer contenedor en la pila j, lo agregamos a esta, (El contenedor B se puede poner encima de uno B,C,...., pero no de A)
					Pilas[j].push(word[i]);//Apilamos el contenedor
					flag = true;//Se encontro pila para el contenedor
					break;//Dejamos de buscar
				}
			}
			
			if(!flag){//Si flag es false, es decir, no se encontro pila para el contenedor i, entonces armamos uno nuevo.
		        Pilas[contenedores_p].push(word[i]);//Se agrega como una nueva pila de contenedores
				contenedores_p++;//Otra nueva pila		
			}
			
		}		
			
			cout<<"Case "<<caso<<": "<<contenedores_p<<endl;		
			caso++;
			
			cin>>word;
	}
	
	
	return 0;
}
