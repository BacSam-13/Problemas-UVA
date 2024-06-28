//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <cstdlib>
using namespace std;

/*
Problema: Dado un laberimento formado por paredes (1) y pasillos (0), y un robot que empiece
 en la entrada [b-1][0] mirando hacia la derecha
Avanzara siempre teniendo una pared o casilla '1' a su derecha
Si no puede avanzar, girara hacia su izquierda hasta que pueda
El recorrido termina al volver a la casilla de inicio
El objetivo es imprimir el numero de csillas que se visitaron 0, 1, 2, 3 y 4 veces en ese orden.
*/


//Solución:
//El objetivo sera usar la estrategia para moverse y sumar .5 a cada casilla de la matriz count, luego redondear sus valores hacia abajo y contar
//las casillas visitadas

bool check(int **A, int b, int w, char B, int i, int j){//Regresasa si es posible avanzar en la dirección dada

//Verifica si esta en el borde o enfrente hay una pared('1')

		
	if(B == 'N'){//Arriba
		
		if( i == 0  || A[i-1][j] == 1){
			return false;
		}
		return true;
		
	}
	
	if(B == 'S'){//Abjo
		
		if( i+1 == b  || A[i+1][j] == 1){
			return false;
		}
		return true;
		
	}

	if(B == 'E'){//Derecha
		
		if( j+1 == w  || A[i][j+1] == 1){
			return false;
		}
		return true;
		
	}	
	
		//Izquierda (W) por default
		
	if( j == 0  || A[i][j-1] == 1){
		return false;
	}
	return true;
					
}

void move(int **A, char* B, int &k, int &i, int &j, int b, int w){//Avanza  
//Verifica si puede girar y avanzar hacia la derecha en lugar de ir al frente
		
	if(B[abs(k%4)] == 'N'){//Arriba

		if( check(A, b, w, B[abs( (k+3)%4 )], i, j) ){
			k--;//Se reduce el valor de k, ya que en lugar de mantener su direccion o girar a la izquierda, giro a la derecha
			j++;
		}else{
			i--;
		}
	
		return;
	}
	
	if(B[abs(k%4)] == 'S'){//Abajo

		if( check(A, b, w, B[abs( (k+3)%4 )], i, j) ){
			j--;
			k--;
		}else{
			i++;
		}	

		return;
	}

	if(B[abs(k%4)] == 'E'){//Derecha

		if( check(A, b, w, B[abs( (k+3)%4 )], i, j) ){
			i++;
			k--;
		}else{
			j++;
		}
	
		return;
	}	
	
	if(B[abs(k%4)] == 'W'){//Izquierda

		if( check(A, b, w, B[abs( (k+3)%4 )], i, j) ){
			i--;
			k--;
		}else{
			j--;
		}	

		return;
	}
				
}

void printmap(int **A, int b, int w, int x, int y){//Imprime la ubicacion actual del robot conforme al laberinto
	
	for(int i = 0; i < b; i++){
		for(int j = 0; j < w; j++){
			
			if( (i == x) && (j == y)){
				cout<<"x ";
			}else{
				cout<<A[i][j]<<" ";	
			}
			
		}
		cout<<endl;
	}

	return;
}



void step(int **A, float **B, int &i, int &j, int b, int w, int &k, char* D){
	
	
	while(1){//Gira a su izquierda hasta que pueda avanzar hacia enfrente o su derecha
		
		if(check(A, b, w, D[abs(k%4)], i, j) || check(A, b, w, D[abs( (k+3)%4 )], i, j) ){//Se usa abs para poder usar el arrar[4] junto con los giros a la izquierda (k++) y giros a la derecha (k--)

			B[i][j] += .5;//Se marca la salida de la casilla previa
			move(A, D, k, i, j, b, w);//Hacemos el movimiento
			B[i][j] += .5;//Se marca la entrada a la siguiente casilla
			return;
		}
		k++;
			
	}

}

void Resultado(float **F, int **A, int b, int w){
	int Opciones[] = {0,0,0,0,0};
	int x;
	
	for(int i = 0; i < b; i++){
		for(int j = 0; j < w; j++){
			if(A[i][j] != 1){//Ignoramos las casillas pared
				x = F[i][j];//Redondeamos los valores
				Opciones[x]++;//Se aumenta en uno la cantidad de casillas visitadas x veces;				
			}

		}
	}	
	
	for(int h = 0; h < 5; h++){
		cout.width(3);
		cout<<Opciones[h];
	}
	cout<<endl;
	
	return;
}




int main(int argc, char** argv) {
	
		
	int b, w;
	char Dir[] = {'E', 'N', 'W', 'S'};//Usar i%4 (Empezando en 0) junto con abs para ciclar
	
	while(cin>>b>>w){
		
		if(b == 0 || w == 0){
			break;
		}
		
		string word;
		
    	int** maze = new int*[b];
    	float** count = new float*[b];   
		 	
    	for (int i = 0; i < b; ++i){
        	maze[i] = new int[w];
        	count[i] = new float[w];        	
        	cin>>word;
			for(int j = 0; j < w; j++){
				maze[i][j] = word[j] - '0';//Guardamos ls diferencis ASCCII para asi tener sus numeros
				count[i][j] = 0;//Matriz para guardar lacantidad de visitas a cada casilla
			}
		}
		

		
		int i = b-1; 
		int j = 0;//(i,j) es la casilla inicial, la esquina inferior izquierda
		int k = 0;//Comenzamos mirando a Dir[0] = 'E'
		

		
		do{
			step(maze, count, i, j, b, w, k, Dir);//Avanzamos hasta volver a la casilla inicial
		}while( (i != b-1) || (j != 0) );
		
		
		
		Resultado(count, maze, b, w);
		
		for(int i = 0; i < b; i++){
			delete[] maze[i];
			delete[] count[i];
		}
		
		
	}
	
	
	
	return 0;
}
