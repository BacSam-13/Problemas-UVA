//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

/*
Problema:
Dado un tablero NxN con N impar, se busca saber las coordenadas de la casilla P al aanzar en modo espiral, comenzando desde el centro y yendo en sentido anti horario

Solucion:
Primero, buscaremos la cada en la que se encuentra la casilla P, lo cual haremos con un ciclo while haciendo uso de las dimensiones de cada capa.
Con esto en mente, buscaremos las coordenadas de esa casilla tomando como origen del plano al centro del tablero.
Con estas nuevas coordenadas, las juntamos con las dimensiones reales del tablero para convertirlas en las coordenadas deseadas
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



//Ya que sabemos en que capa esta, podemos dividirla en 4 sectores. Donde el lateral derecho, inferior, laterial izquierdo y Latera superior tienen longitud Capa - 1 
//(Recordemos que esta capa tiene 4(Capa-1) cuadrados)
pair<int,int> solucion(int P, int C){//Considerando la Capa como unica, encontamos sus coordendas (Como si no hubiera capaz externas, luego las modificamos para considerarlas)
    //Notese que las coordenadas se enviaran como instrucciones para moverse desde el centro. (Casillas a moverse en el eje Y, y en el eje X)
	
	long long Squares = (long long)C*C;//Cuadrados dentro de la capa
    int D = C/2;//Distancia desde el centro a la capa de interes
    
    if(P > Squares - C){//Si esta en el lateral derecho
    	return make_pair(P - Squares + D, D);//Calculamos cuanto tiene que avanzar para llegar a su fila, es claro su columna
	}
    
    Squares -= 	C - 1;//Vamos a considerar ahora la cara inferior
    
    if(P > Squares - C){
    	return make_pair(-D, P - Squares + D);//Un calculo analogo considerando la cara ingerior
	}
    
    Squares -= C - 1;//Lateral izquierdo
    
    if(P > Squares - C){
    	return make_pair(Squares - P - D, -D);
	}
    
    Squares -= C - 1;//Cara superior por default
    
    return make_pair(D, Squares - P - D);
}




int main(int argc, char** argv) {
	
	int SZ;
	long long P;
	
	cin>>SZ>>P;
	
	while(SZ != 0 && P != 0){
		
		
		int C = SZ;//Buscamos la longitud de cada lado de la capa en la que esta P
		
		while((C > 1) && ((long long)(C - 2)*(C - 2) >= P)){//Mientras no estemos en la capa 1, y la posicion se encuentre en la capa inferios (Entre cada capa, hay una diferencia de 2 cuadrados en cada lado)
			C -= 2;//Pasamos a la capa interna(Reducimos en dos el largo de sus lados)
		}
		
		pair <int, int> coord = solucion(P, C);

		//Consideramos las dimensiones reales del tablero para saberlas coordenadas con base en cuanto nos debemos de mover desde el centro
		//El +1 es porque tambien hay que considerar al centro del tablero		
        coord.first  += (SZ/2) + 1;
        coord.second += (SZ/2) + 1;
		
		cout<<"Line = "<<coord.first<<", column = "<<coord.second<<"."<<endl;
		
		cin>>SZ>>P;
	}
	
	return 0;
}

