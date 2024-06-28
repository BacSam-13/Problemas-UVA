//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define n 4

/*
Problema:
Con base en el metodo del cuadrado medio, se busca verificar para un valor 
inicial dado a0 cuántos números diferentes se producen. (Dado un numero, el siguiente en la secuencia son los n numeros medios de este al cuadrado)

Para este caso, usaremos n=4
*/


/*
Solucion:
Ahora, con base en la naturaleza del metodo, en el momento en que encontremos un a_i tal que sea igual
a a_j para algun j en [0,i], significaría que comenzaria un ciclo, por ende el resultado sería i-1.

Ya que buscamos almancenar los numeros generados, usaremos un map, el cual nos ayudara a almacenar los numeros distintos, por
lo que su tamaño sera la respuesta, es decir, i-1
*/

int cuenta_dig(int numero){//Regresa la cantidad de digitos del entero
	string temp;

    temp = to_string(numero);
    return temp.size();
}

int main(int argc, char** argv) {
	
	
	int a_0;
	cin>>a_0;
	
	map<int, int> mapita;
	
	while(a_0 != 0){
		
		while(mapita.find(a_0) == mapita.end()){//Mientras a_0 no este en el map
			mapita.insert({a_0, 1});//Ya que no esta en el mapa, y por ende es un nuevo numero
			
			a_0 *= a_0;//Caculamos su cuadrado
			
			int dig = cuenta_dig(a_0);//Buscamos que tenga 8 digitos para extrar los 4 de en medio
			string temp = to_string(a_0);//Lo volvemos string para extraer esos numeros, o agregar mas
			
			for(int i = dig; i < 8; i++){//Si no tiene 8 digitos, llenamos con 0´s a la izquierda para que los tenga
				temp.insert(0, 1, '0');//Posicion, Tamaño, Objeto
			}
			
			temp = temp.substr(2, n);//Extraemos los caracteres de en medio (01234567) Hay 8 caracteres, los 4 de enmedio son del 2 al 5 (4 caracteres en total)
			
			a_0 = stoi(temp);//Lo convertimos en numero para verificar si ya se ingreso en el mop, si no, se repite lo anterior			
		}
		
		cout<<mapita.size()<<endl;
		
		mapita.clear();
		cin>>a_0;//Nuevo caso
	}
	
	return 0;
}
