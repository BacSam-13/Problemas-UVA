//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <bits/stdc++.h>
using namespace std;


#define Max_n 100;//Maximo de estudiantes

/*
Problema: Dada una lista de estudiantes, con sus nombres y cumpleaños, buscamos determinar quinen es el mas viejo, y quien es el mas joven.

Solucion: Desarrollamos una escructura student para almacenar los datos de un estudiante, así como un operador < el cuanl determin quien es mayor dependiendo de cual cupleaños
ocurrio antes.
Usando year, mes y dia, en ese orden en caso de empate.
Con este operador, ordenamos el vector donde recibimos a los estudiantes e imprimimos la primero y ultima entrada.
*/

struct student{
	string name;
	int day;
	int month;
	int year;
	
	bool operator <(const student &x){//Para comparar edades y asi ordenar un arreglo de estudiantes
		
		
		if(year != x.year){//comparamos el year en que nacieron si son difernetes
			return year > x.year;//Tener un year menor indica ser mayor
		}else if(month != x.month){//comparamos el year en que nacieron si son difernetes
			return month > x.month;//Tener un mes menor indica ser mayor 
		}
		return day > x.day;//Tener un dia menor indica ser mayor
		
		
	}
	
};


void print(student *A, int n){
	
	cout<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Estudiante numero "<<i<<": "<<A[i].name<<"\t"<<
		A[i+1].day<<"\t"<<A[i].month<<"\t"<<A[i].year<<endl;
	}
	cout<<endl;
}

int main(int argc, char** argv) {

	int n;
	
	cin>>n;//numero de estudiantes
	
	//Variables para recibir datos
	string nombre;
	int dia, mes, y;//y equivale a year en espanol
	
	student Array[n]; //Para recibir los datos  (Name dd mm yy)
	
	for(int i = 0; i < n; i++){
		cin>>nombre>>dia>>mes>>y;
		
		Array[i].name = nombre;
		Array[i].day = dia;
		Array[i].month = mes;
		Array[i].year = y;
	}
	
	sort(Array, Array + n);//Ordenamos el arreglo de menor a mayor, (el operador < definido antes)
	
	cout<<Array[0].name<<endl;//Estudiante mas joven
	cout<<Array[n-1].name<<endl;//Estudiante mas viejo
	
	return 0;
}
