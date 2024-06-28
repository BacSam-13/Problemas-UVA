//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define e 0
#define d  1
#define ha 1
#define hb 1

/*
Problema:
String Distance es un número entero no negativo que mide la distancia entre dos cadenas. Aquí damos
la definición. Una lista de transformación es una lista de cadenas, donde cada cadena, excepto la última, puede ser
cambió a la cadena seguida de agregar un carácter, eliminar un carácter o reemplazar un carácter. los
La longitud de una lista de transformación es el recuento de cadenas menos 1 (que es el recuento de operaciones para transformar
estas dos cuerdas). La distancia entre dos cadenas es la longitud de una lista de transformación de una cadena
al otro con la longitud mínima. Debes escribir un programa para calcular la distancia entre
dos cadenas y dar la lista de transformación correspondiente
*/

/*
Solución:
Para este codigo, se usara como referencia el codigo de la tare 7, ejercicio 1, con la diferencia de que se
construir una funcion para imprimir las operaciones de forma recurvisa. La cual considera la cantidad de operaciones y las modificaciones
en la string, ya que ciertas operaciones aumentan o disminuyen su tamaño.
*/

int min_2(int a, int b){
	if(a < b){
		return a;
	}else{
		return b;
	}
}




int min_3(int a, int b, int c){//Regresa el minimo de tres enteros

	int minimo = min_2(a,b);
	
	
	return min_2(minimo, c);

}

void print_op(int i, int j, vector<vector<int>>& mat, const string &A, const string &B, int &op, int &steps){
	
	//op nos indica la operacion que estamos realizando
	//steps nos indica la posicion donde insertamos, reemplazamos o quitaos un caracter
	//Ya que las posiciones estan indexadas en ceros, y estas cambian dependiendo de las operaciones
	//abc, eliminar 1 -> bc
	//bc ahora tiene dos caracteres, por lo que hay que considerar 
	
    if(i==0 && j==0){
    	return;
	}
    
    if(i!=0 && j!=0 && A[i-1] == B[j-1]){//Si hay match
        print_op(i-1, j-1,mat, A, B, op, steps);
        
    }else if(j!=0 && mat[i][j] == mat[i][j-1]+1){//Si insetamos un caracter en A
        print_op(i, j-1, mat, A, B, op, steps);
        steps++;//Aumenta en el tamaño de A
        op++;
        cout <<op <<" Insert "<<i+steps<<","<<B[j-1]<<endl;
        
    }else if(i!=0 && mat[i][j] == mat[i-1][j]+1){
        print_op(i-1, j, mat, A, B, op, steps);
        op++;
		cout <<op <<" Delete "<<i+steps<<endl;
        steps--;//Se reduce en uno el tamaño de A
        
    }else if(mat[i][j] == mat[i-1][j-1]+1){
        print_op(i-1, j-1, mat, A, B, op, steps);
        op++;
		cout<<op <<" Replace "<<i+steps<<","<<B[j-1]<<endl;
		//No se cambia el tamaño de A
    }
}


//Realizamos el calculo de la matriz para convertir A en C
void calcular_mat(const string &A, const string &B){
	
	int cas1, cas2, cas3;//Para guardar los minimos de cada matriz
	vector <vector <int>> matriz(A.size()+1, vector<int>(B.size()+1,0));

		
	for(int j = 0; j <= B.size(); j++){
		matriz[0][j] = j;
	}

		
	for(int i = 0; i <= A.size(); i++){
		matriz[i][0] = i;
	}

	
	for(int i = 1; i <= A.size(); i ++){//Armamos la matriz para convertir A en B
		for(int j = 1; j <= B.size(); j++){
			
            if(A[i-1] == B[j-1]){//Si hay  match, no hay peso, no es necesario modificar        //Si A(j) es igual a C(i) el costo de la celda es 0.
                matriz[i][j] = matriz[i-1][j-1];
            }else{//Si re quiere intercambiar
	            cas1 = matriz[i-1][j] + 1;//Agregar caracter
				cas2 = matriz[i][j-1] + 1;//Eliminar caracter
				cas3 = matriz[i-1][j-1] + 1;//Reemplazar acaracter. Se suma cero si es match, se suma 1 si no.
				matriz[i][j] = min_3(cas1, cas2, cas3);
			}			
			
			
		}
	}

	cout<<matriz[A.size()][B.size()]<<endl;

	int op = 0, steps = 0;
	
	print_op(A.size(), B.size(), matriz, A, B, op, steps);//Equivalente al while para obtener las operaciones en la tarea 7, pero usa recursividad para irlas imprimiendo en el orden correcto
	
	
}


int main(int argc, char** argv) {
	
	string A, B;
	
	bool enter = false;//Para dar el salto entre casos
	
	while(getline(cin, A)){
		
		
		getline(cin,B);
		
		if(!enter){
			enter = true;
		}else{
			cout<<endl;
		}
		
		calcular_mat(A, B);
	}
		
	return 0;
}
