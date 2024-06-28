//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

#include <iostream>

//Problema:
//El objetivo del codigo es hacer un programa que detecte si las maletas estan permitidas o no
//siguiendo los requisitos a continuacion

using namespace std;

//La maleta debe cumplir lo siguiente: (en cm y kg)
#define Max_length 56//z
#define Max_width 45//x 
#define Max_depth 25//y
//Y la suma de estas no debe exceder 125
#define Max_sum 125

#define Max_weight 7//Peso maximo de las maletas

//Recordemos que para que una maleta sea valida:
//1. Su peso no debe sobrepasar a Max_weight
//2. Sus dimensiones no deben superar a Max_length, Max_width y Max_depth, o la suma de estas no debe exceder a Max_sum


//Solución:
/*
Primero, creamos una estructura maleta para almacenar los datos de una maleta, asi como una función
paradetermine si es valida con base en las condicones ya mencionadas.

Con esto, creamos un arreglo para recibir las t maletas del caso, luego, iteramos entre ellas
y con el uso de la función is_valid(), determinamos si son validas (imprimimos 1) o no (imprimimos 0), a la vez que contamos las maletas
validas para imprimirlas con el resultado final.
*/


struct maleta{
	float z;//length
	float x;//width
	float y;//depth
	float weight;
	
	bool is_valid(){
		
		if(weight > 7){//Si excede el peso, no puede ser valida
			return false;
		}
		
		//Ahora solo resta evaluar si cumple con las dimensiones establecidas o la suma de estas
		
		if( (z <= Max_length) && (x <= Max_width) && (y <= Max_depth) ){//Si cumple con las dimensiones adecuadas
			return true;
		}
		
		float sum = x+y+z;//sumamos sus dimensiones
		
		if( (sum <= Max_sum) ){//Si la suma de sus dimensiones estan bajo el maximo
			return true;
		}
		
		return false;
	}
	
};


int main(int argc, char** argv) {
	
	int t;//Maletas a revisar;
	cin>>t;
	
	int sum = 0; //Contar maletas validas
	
	maleta Array[t];
	
	for(int i = 0; i < t; i++){
		cin>>Array[i].z>>Array[i].x>>Array[i].y>>Array[i].weight;
		
		if(Array[i].is_valid()){//La maleta cumple las normas
			cout<<"1"<<endl;
			sum++;
		}else{//No las cumple
			cout<<"0"<<endl;
		}
		
	}
	
	cout<<sum<<endl;
	
	return 0;
}
