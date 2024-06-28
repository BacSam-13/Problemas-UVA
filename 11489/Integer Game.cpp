//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Problema:
Se juego un juego entre S y T, donde S tiene el primero turno, donde cada uno retira un numero, 
y pierde quien se quede sin numeros que retirar, pero con la condición siguiente:

Un jugador puede eliminar un dígito particular si la suma de los dígitos del número resultante 
es un múltiplo de 3 o no quedan dígitos.
Supongamos que N = 1234. S tiene 4 movimientos posibles. Es decir, puede eliminar 1, 2, 3 o 4. De estos, dos de
son movimientos válidos, los cuales son 4 y 1.

Cada numero N tiene a lo mas 1000 digitos, y no tiene ceros.

Hacer un codigo, que dado el digito N, escribir quien gana, S o T
*/


/*
Solucion:
Debido a la naturaleza del juego, no importa que digito se retire siempre y cuando cumpla con la condición antes mencionada.
Por lo que en el momento en que ya no se puedan retirar numeros, verificamos lo siguiente:

Si el numero inicial tiene un tamaño par, entonces:
	1. Si los ditigos finales son pares, gana T
	2. Si los digitos finales son impares, gana S
	
Si el numero inicial tiene un tamaño impar, entonces:
	1. Si los ditigos finales son pares, gana S
	2. Si los digitos finales son impares, gana T	
	
Para esto, buscamos el primer numero que se pueda retirar y que cumpla la condicion, realizamos esto mientras contamos los movimientos hasta que no se pueda mas,
y finalmente consideramos los casos antes mencionados.
*/

int cuenta_dig(int numero){//Regresa la cantidad de digitos del entero
	string temp;

    temp = to_string(numero);
    return temp.size();
}

int main(int argc, char** argv) {
	
	int caso;
	cin>>caso;
	
	string N;
	
	for(int c = 1; c <= caso; c++){
		cin>>N;
		
		int dig_o = N.size();//Guardamos los digitos iniciales para compararlos con los finales, y así ver quien gano
		
		bool play = true;//Para indicar si se realiza un movimiento
		
		while(play){//Seguimos removiendo hasta que no se pueda realizar un cambio
			play = false;
			int suma = 0;//Sumar los digitos y verificar si su suma es un multiplo de 3
			int idx;//Nos ayuda a marcar que index borrar
			for(int i = 0; i < N.size(); i++){//Ignoraremos el digito i
			
				for(int j = 0; j < N.size(); j++){
					if(i != j){//Verificar si j no es i, para asi ignorarlo
						suma += N[j] - '0';//Sumamos el digito j (le restamos '0' para reescalar)
					}
					
				}
				
				if(suma % 3 == 0){//Si el retirar el digito i esuna jugada valida
					play = true;
					N.erase(i, 1);
					i = N.size();//Para romper el for
				}
				suma = 0;
			}
		

		}
		
		cout<<"Case "<<c<<": ";
		
		
    	if( (dig_o - N.size()) %2 == 0){//Si la cantidad original y la final ambas son pares o impares
    		cout<<"T"<<endl;
		}else{//Si difieren
			cout<<"S"<<endl;
		}

		
	}
	
	return 0;
}
