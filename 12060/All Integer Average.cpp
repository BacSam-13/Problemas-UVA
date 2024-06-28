//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

/*
Problema: Dada cierta serie de numeros enteror, se busca calcular su promedio e imprimirlo en el formato denumero racional
 b
a-
 c


Solucion: Se calculara la forma b/c del promedio luego de extraer el entero a, lo podemos hacer extrayendo los enteros del b original  y
sumandolo a 'a', luego se simplificara usando el MCD, para asi, calcular las longitudes de a,b,c, y si el resultado es negativo o no para darle forma con base en
una serie de ifs para los posibles casos
*/ 

using namespace std;

int cuenta_dig(int numero){//Regresa la cantidad de digitos del entero
	string temp;

    temp = to_string(numero);
    return temp.size();
}

int mcd(int a, int b){//Funcion para calcular el maximo comun divisor
    int MCD=1; //Regresamod uno si es que alguno es cero   

    int x = max(a,b);
    int y = min(a,b);

    while(y!=0){//Ciclo while para encontrar el maximo comun divisor
        MCD = y;// 
        y = x%y;//a%b regresa el residuo de la division. a%b = c tal que   n*b +c = a
        x = MCD;
    }
    
    return MCD;	
}


int main(int argc, char** argv) {

	int a = 0, b = 0;//entero y numerador inicial
	int espacio_a, espacio_c;//Nos servira para saber que espacio dejar para a si hay, y los guiones segun el denomiador c
	
	int c;//Cantidad de numeros a recibir, o denomiador
	int x;//Variable para recibir numeros
	
	bool flag_signo = false;//Nos dice si ponemos signo o no
	
	int casos = 1;
	cin>>c;
	while(c > 0){
		a = 0;
		b = 0;
		flag_signo = false;		
		
		
		for(int i = 0; i < c; i++){
			cin>>x;
			b += x; 
		}
		
		if(b < 0){//Imprimiremos el signo - a parte
			flag_signo = true;
			b *= -1;
		}
		
        while (b >= c){//Extraremos los enteros que hay
        	b -= c;
        	a++;
		}
		
		//Ahora, ya podremos escribir a(b/c), pero solo queda simplificar b/c
		int MCD = mcd(b,c);
		
 		b = b/MCD;
 		c = c/MCD;
 		
 		espacio_a = cuenta_dig(a);
 		espacio_c = cuenta_dig(c);
 		
 		cout<<"Case "<<casos<<":"<<endl;
		casos++;
 		
 		if(b == 0){//Si no hay residuo, solo imprimimos a con su símbolo
 		
 			if(flag_signo){
 				cout<<"- ";
			}
			cout<<a<<endl;
 		
		}else{
			
			if(a != 0){//Formato de la primera linea si hay parte entera
			
				if(flag_signo){//Espacio para el signo y su espacio
					cout<<"  ";
				}
				
				for(int i = 0; i < espacio_a; i++){//Espacio para el entero a
					cout<<" ";
				}
				
				cout<<setw(espacio_c)<<b;//Para acomodar b sobre las lineas de c  
					
			}else{//Analogo, pero ignoramos el espacio para a
				
				if(flag_signo){//Espacio para el signo y su espacio
					cout<<"  ";
				}
				
				cout<<setw(espacio_c)<<b;//Para acomodar b sobre las lineas de c 				
			}
			cout<<endl;
			
			if(a != 0){//Segunda linea si hay entero
				
				if(flag_signo){//Signo si hay
					cout<<"- ";
				}
				cout<<a;
				
				for(int i = 0; i < espacio_c; i++){//Imprimimos los rengloes necesarios segun c
					cout<<"-";
				}

				
			}else{//Analogo, pero no imprimimos entero
				
				if(flag_signo){//Signo y espacio si hay
					cout<<"- ";
				}
							
				for(int i = 0; i < espacio_c; i++){
					cout<<"-";
				}
					
			}
			cout<<endl;
			
			if(a != 0){//Tercera linea si hay entero
			
				if(flag_signo){//Espacio para el signo y su espacio
					cout<<"  ";
				}
				
				for(int i = 0; i < espacio_a; i++){//Espacio para el entero a
					cout<<" ";
				}	
				
				cout<<c;
								
			}else{//Analogo
			
				if(flag_signo){//Espacio para el signo y su espacio
					cout<<"  ";
				}
				
				cout<<c;
			}
			cout<<endl;
		}
		
		cin>>c;
		
	}
	
	
	return 0;
}
