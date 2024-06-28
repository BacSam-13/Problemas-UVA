//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

/*
Problema: Dadas ciertas fechas: DD/MM/YYYY y una cierta cantidad de dias N, se busca imprimir la fecha tras transcurrir los
N dias desde la fecha

Solucion: Se emplea un vector para guardar la cantidad de dias de los 12 meses del año, uno para un año regular
y otro para el año bisitesto, ademas de una funcion que determina si un año es bisiesto o no.

Con esto, se crea un ciclo while para ir sumando la cantidad de dias a nuestra fecha, y cada vez que exceda la cantidad de dias de su respectivo mes, se cambia
al mes siguiente, o al mes inicial si es Diciembre, y de igual forma, se cambia al año siguiente.
De esta forma, con un bool que nos permite saber cuando se deja de iterar entre meses, se saldra dl ciclo y se imprimira la fecha
*/

#include <bits/stdc++.h>
#include <iostream>


using namespace std;

bool bisiesto(int year){//Determina si el year (ano suena gracioso) es bisiesto, segun el criterio siguiente:
						//es divisible por 4 y no lo es por 100 ó si es divisible por 400.
	if( (year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0) ){
		return true;
	}
	return false;
}

int main(int argc, char** argv) {
	
	vector<int> Mes  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Dias que tienen los meses en un año normal
    vector<int> Mes_b{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Dias que tienen los meses en un año bisiesto
	
	
	int N, day, month, year;
	cin>>N>>day>>month>>year;
	
	while( N!=0 && day!=0 && month!=0 && year!=0 ){
		
		day += N; //Sumamos los dias que queremos calcular
		
		bool flag = true;//Para indicaros cuando dejar de cambiar de mes
			
        while(flag){
            flag = false;
			 
            if (bisiesto(year)){//Si el año es bisiesto
            
                if (day > Mes_b[month-1]){//Si los dias son mayores a los dias que tiene el mes, pasamos al siguiente
                	
					day -= Mes_b[month-1]; 
					month++; 
					flag = true;//Se hizo un cambio
					
					if(month > 12){//Si era diciembre y se hizo el cambio, pasamos a enero del año siguiente
						month = 1;
						year++;
					}
				}
              
            }else{//Analogo, pero con un año normal
            
                if (day > Mes[month-1]){//Si los dias son mayores a los dias que tiene el mes, pasamos al siguiente
                	
					day -= Mes[month-1]; 
					month++; 
					flag = true;//Se hizo un cambio
					
					if(month > 12){//Si era diciembre y se hizo el cambio, pasamos a enero del año siguiente
						month = 1;
						year++;
					}
				}
            }                    
        }	
		
		cout<<day<<" "<<month<<" "<<year<<endl;
		cin>>N>>day>>month>>year;	
		
	}
			
	
	return 0;
}
