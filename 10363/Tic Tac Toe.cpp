//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Problema:
Dado un tablero de gato, buscamos determinar si es posible que dicho tablero aparezca en una partida de gato regular.

Recordemos que X empieza, luego O le sigue, y así consecutivamente. 
Y el juego terminar cuando el tablero esta lleno o una fila esta llena del mismo símbolo

Por ejemplo: El siguiente talero es imposible de obtener
X..
OO.
OXO
Ya que deben haber a lo mas 2 O´s


Solución:
Para determinar si un tablero es imposible, gaurdara el tablero en una matriz de caracteres, con la evaluaremos ciertos casos que pueden ocasionar que
dicho tablero se imposible, ya sea en la cantidad de X´s u O´s, o las posiciones de los mismos.
Estos casos se mencionaran mas adelante en el codigo

*/

int main() {

    int n;
    cin>>n;//Recibimos los casos
    
    while (n--) {

        vector< vector<char> > tab(3, vector<char> (3));//Generamos una matriz 3x3 para representar el tablero

        for (int i = 0; i < 3; ++i){//Recibimos el tablero; //Se pueden recibir los siguientes caracteres {X, ., O}
            cin>>tab[i][0]>>tab[i][1]>>tab[i][2];
        }

        int n_X = 0;
        int n_O = 0;
        
        //Contamos los X´s y O´s
        //Nos servira mas adelante, ya que para que el tablero sea valido, se debe cumplir que n_X = n_O o n_X  = n_O + 1
        /*
        	XXX	
        	OXO
        	XOO
        */
		
		
		for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j){
            	
                if (tab[i][j] == 'X'){
                	n_X++;
				}else if(tab[i][j] == 'O'){
					n_O++;
				}
            }
        }
		
		//Para contar los juegos completos de gato, de X y O. //Hay veces donde un juego termina con mas de una linea
        int x_hor, x_ver, x_dia;//Horizontal, vertical y diagonal
        int o_hor, o_ver, o_dia;
		//Inicializamos a cero        
        x_hor = x_ver = x_dia = 0;
        o_hor = o_ver = o_dia = 0;
		
		//Buscamos en el tablero por lineas rectas (Horizonatales y verticales) //Es claro que no puede haber mas de una de cada una
        for (int i = 0; i < 3; ++i){
        	
            if(tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X'){
            	x_hor++;
			}
                
            if(tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O'){
            	o_hor++;
			}
                
            if(tab[0][i] == 'X' && tab[1][i] == 'X' && tab[2][i] == 'X'){
            	x_ver++;
			}
                
            if(tab[0][i] == 'O' && tab[1][i] == 'O' && tab[2][i] == 'O'){
            	o_ver++;
			}
                
        }
        //Luego, buscamos por líneas diagonales
        if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X'){
        	 x_dia++;
		}
		
        if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O'){
        	o_dia++;
		}
		
        if(tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X'){
        	x_dia++;
		}
		
        if(tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O'){
        	o_dia++;
		}
		//cout<<"n_X="<<n_X<<endl;
		//cout<<"n_O="<<n_O<<endl;

		
        bool game = true;//Veremos si el tablero es valido
        
        if( !(n_X == n_O || n_X == n_O +1) ){//Si la cantidad de Xs u Os no coinciden como se menciono al inicio
        	game = false;
		}
		
		if(x_hor > 1 || x_ver > 1 || o_hor > 1 || o_ver > 1){//Si hay mas de una fila veritcal o horizontal ganda
			game = false;
		}
	
		if( (x_hor +  x_ver + x_dia >= 1) && (o_hor + o_ver + o_dia >= 1) ){//Recordemos que pueden haber una linea recta y diagonal de un simbolo, pero si eso sucede, no debe haber ninguna linea del simbolo restante
			game = false;
		}	
		
		if( (x_hor + x_ver + x_dia >= 1) && (n_X == n_O) ){//Si X gano, X tuvo que tener el movimiento final, y como empezo primero, se debe cumplir que n_X = n_0 + 1
			game = false;	
		}

		if( (o_hor + o_ver + o_dia >= 1) && (n_X == n_O + 1) ){//Si O gano, O tuvo que tener el movimiento final, y como empezo segundo, se debe cumplir que n_X = n_0
			game = false;	
		}

		if(game){//Si no se dio ninguna situacion contradictoria (Paso todos los sensores anteriores)
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
        
    }
}
