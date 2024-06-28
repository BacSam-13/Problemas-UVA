//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//1<=N>=1000	

/*
Problema: Dada una fecha de embarazo, se busca saber si el bebe nacera siendo Cancer o Scorpio, considerando el tiempo
de gestación de una madre.

*/

/*
Solucion:
La idea del codigo es usar la funcion bisiesto() para determinar si un year es bisiesto o no, yasi modoficar el vector Mes[].
Asi, al recibir el dia, mes y year de gestacion, se sumaran las 40 semanas al dia y se iran restando los dias de los meses
que se transcurriran. En cuanto se hayan restado los dias y tengamos al final una fecha final, se usara el vector Zodiaco usando month como
indice para asi determinar si el dia de nacimiento entra al inicio del periodo zodiacal o no, notemos que Zodiaco[i] es el iesimo signo, y Z[0]=Z[12].
Esto ultimo se debe al uso de Mes[0] = Zodiaco[0] = 0

El codigo es similar a Y3K, pero en este caso consideramos si la fecha final entra en un peridio de tiempo
*/

bool bisiesto(int year){//Determina si el year (ano suena gracioso) es bisiesto, segun el criterio siguiente:
						//es divisible por 4 y no lo es por 100 ó si es divisible por 400.
	if( ( (year%4 == 0) && (year != 0) ) || (year%400 == 0) ){
		return true;
	}
	return false;
}

int main(int argc, char** argv) {
	
	vector<int> Mes    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  	//Para poder usar Mes[i] como el i-esimo mes, y que i-1 >= 0 (Para Signo) 
    vector<int> Zodiaco{0, 21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23}; //Lo mismo que con el Mes. Primer dia del inicio del ciclo zodiacal
	vector<string> Signo{"capricorn", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};
	
	int N;
	cin>>N;//Leemos casos
	
	int day, month, year;
	
	
	for(int i = 1; i <= N; i++){
		scanf("%2d%2d%4d", &month, &day, &year); //Nos permite separar la informacion
		
		if( bisiesto(year) ){
			Mes[2] = 29;
		}else{
			Mes[2] = 28;
		};
		
		day += 40*7; //40 semanas de gestacion.
		
		while(day > Mes[month]){//Mientras el dia sea mayor al mes actual, iremos recorriendo los meses y disminuyendo los dias
			
			day -= Mes[month];//Restamos dias
			month ++;//Cambiamos de mes
			
			if(month > 12){//Si cambiamos de year
			
				year++;
				month = 1;
				
				if( bisiesto(year) ){
					Mes[2] = 29;
				}else{
					Mes[2] = 28;
				};	
			}
		}
		
        if(day<10 || month<10){//Para imprimir un 0 si el dia o mes tienen solo un digito
        
            if(day<10 && month<10){
            	cout<<i<<" 0"<<month<<"/0"<<day<<"/"<<year<<" ";
			}else if(day < 10){
				cout<<i<<" "<<month<<"/0"<<day<<"/"<<year<<" ";
			}else if(month < 10){
				cout<<i<<" 0"<<month<<"/"<<day<<"/"<<year<<" ";
			} 

        }else{
            cout<<i<<" "<<month<<"/"<<day<<"/"<<year<<" ";
        }
        
		
		if(day < Zodiaco[month]){
			cout<<Signo[month-1]<<endl;
		}else{
			cout<<Signo[month]<<endl;
		}
		
	}
	
	
	return 0;
}
