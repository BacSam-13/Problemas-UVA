//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Problema:
Dada la configuración de las serpientes y escaleras en un tablero de juego(10x10) y una secuencia de tiradas de dados, usted
debe de determinar las posiciones de todas las fichas en el tablero de juego. La secuencia de tiradas de dados no necesita
ser completo (es decir, no es necesario que conduzca a que ningún jugador gane). La secuencia de tiradas de dados también puede continuar
después de que termine el juego; en este caso, las tiradas de dados después del final del juego deben ignorarse
*/

/*
Solucion: En este codigo, trataremos a las serpientes y escaleras como agujeros negros, los cuales nos permiten avanzar o retroceder.
De esta forma, al ir lanzando las tiradas de dado, usando % con los jugadores, podemos avanzar lo que corresponda el dado y movernos lo que indica el hoyo negro en caso de haber
caido en uno, el juego termina cuando un juggador llegue a la casilla 100 o se acaben las tiradas.
*/


int main(){
	
    int casos;
    cin>>casos;
    
    for (int i = 0; i < casos; i++){
        int a, b, c;
        
        cin >> a >> b >> c;//N. Jugarodes, N. Agujeros Negros, N. Tiradas
        vector<int> Posiciones(a, 1);
        vector<int> Dice(c);
		 
		//Ignoraremos la casilla 0
		vector<int> Moves(101, 0);//Guardamos cuantas espacios se movera el jugador al caer en la casilla i. Un agujero de 3 a 10, hace que Moves[3] = 7
        
        for(int j = 0; j < b; j++){//Recibimos los agujeros negros y guardamos cuantas casillas hay que avanzar o retroceder segun el agujero negro
        	
            int start, end;
            cin >>start>>end;
            
            Moves[start] = end - start;
        }
        
        int dice;//Para recibir los movimientos del dado
        for(int j = 0; j < c; j++){
        	cin>>dice;
        	Dice[j] = dice;
		}
        
        
        
        for (int j = 0; j < c; j++){//Analizamos las c tiradas de dado hasta que gane un jugador o se acaben las tiradas. el z%a nos permite ciclar a los jugadores
        
            Posiciones[j%a] += Dice[j];
                
            while (Posiciones[j%a] < 100 && Moves[Posiciones[j%a]] != 0){//Mientras el jugador no gane, o deje de caer en algun agujero negro
            	Posiciones[j%a] += Moves[Posiciones[j%a]];
			}
                
                
                if (Posiciones[j%a] >= 100){//Vemos si el jugador gano
                	break;
				}
                    

        }
        
        for (int i = 0; i < a; ++i){
        	cout<<"Position of player "<<i+1<<" is "<<Posiciones[i]<<"."<<endl;
		}
            
    
    }

}
