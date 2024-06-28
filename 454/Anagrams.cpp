//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

/*
Problema:
Dadas una serie de frases, determinar cuales de ellas son anagramas

Solucion:
La idea del codigo es emplear una funcion que elimine los espacios de cada frase y ordenarla en orden alfabetico
para que así, si dos frases son anagramas, tras evaluarse en Anagrama() deben de ser iguales.
*/

string Anagrama(string word){

    word.erase( remove( word.begin(), word.end(),' ' ), word.end() );//Eliminamos todos los ' ' en el string
    sort(word.begin(), word.end());//Ordenamos el string
    
    return word;
}


int main(int argc, char** argv) {
	
	int X;//Numero de casos

    cin>>X; 
    
    cin.ignore(); //Ignoramos las linea en blanco
    cin.ignore();
    
    while(X--){//Restamos a X, y entra el while, se rompe cuando X<0
   		
   		string words;//Para recibir las frases
   		
   		vector<string> vect_words;//Vector para almacenar las frases
   		
   		while (getline(cin, words)){ //Leemos las frases y se almacenan en el vector
			if (words == ""){//Si ya no hay mas palabras que leer, rompemos el while
				break;
			}
            vect_words.push_back(words);
        }
        
        sort(vect_words.begin(), vect_words.end());//Ordenamos las frases 


        //Con los siguientes fors, comparamos la i-esima frase ya ordenada con el resto de las frases
        //Si en efecto son anagramas, imprimimos la respuesta esperada
        for(int i = 0; i < vect_words.size(); i++){
        	
            for(int j = i+1; j < vect_words.size(); j++){
                
				if(Anagrama(vect_words[i]) == Anagrama(vect_words[j])){//Al tener la i-esima y la j-esima frase sin ' ' y ordenadas, si son anagramas, deben de ser iguales
                     cout << vect_words[i] << " = " << vect_words[j] << endl;
                }
            }
        }

        if(X){//Enter si aun hay casos por analizar
            cout<<endl;
        }

    }        
   		
	
	
	
	return 0;
}
