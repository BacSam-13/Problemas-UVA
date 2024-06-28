//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
Una permutación de una cadena es el conjunto de todas las formas posibles de combinar sus caracteres. Por ejemplo, la permutación
de “abc” es {“abc”, “acb”, “bac”, “bca”, “cab”, “cba”}. El tamaño de este conjunto es el factorial de la
tamaño inicial de la cadena.
Dada una cadena y un N, encuentre el (N + 1)-ésimo elemento más pequeño de la permutación de S (considere el orden lexicográfico;


Solución:
Considerando la longitud del string, podemos dividir sus permutaciones divididas por bloques, uno por letra.
Por lo tanto, podemos determinar en cual bloque esta con base en N y así ir imprimiendo los caracteres que determinaron ese bloque.
Así, podemos determinar el resultado de manera recursiva mientras aun queden caracteres.
*/

void print_vector(vector<unsigned long long int> &v){
	for(int i = 0; i < v.size(); i++){
		cout<<"["<<v[i]<<"]"<<endl;
	}
	cout<<endl;
}

int main() {

    vector<unsigned long long int> factorial(20);//Ya que cada string tiene a lo mas 20 caracteres, nesecitamos conocer desde 0! a 20!
    factorial[0] = 1;
    for (int i = 1; i < 20; ++i){
    	factorial[i] = factorial[i-1] * (i+1);
	}
	//print_vector(factorial);
	//factorial(i) = (i+1)!
	
    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {
        
        string word;
        cin>>word;
        sort(word.begin(), word.end());//El resultado es el mismo si cambiamos el orden del string


        unsigned long long int N;
        cin>>N;//Buscamos la (N+1)-th cadena

        for (int i = word.size()-1; i > 0; --i) {
        	//cout<<endl<<N<<"%";
            int a = N / factorial[i-1];//Con las letras actuales(sin contar una), hay factorial[i-1] posibles permutaciones, por lo que cada bloque de permutaciones (que tienen el primer caracter fijo), tienen est tamaño, por lo tanto, al dividir N, entre este tamaño, nos dira en cual bloque esta, y ya que las permutaciones estan ordenadas, nos dira que caracter ira primero en la permutación resultado
            N %= factorial[i-1];//Ya que eliminamos un caracter, se reducieron las posibles permutaciones restantes, por lo que N tiene que cambiar su valor considerando las permutaciones restantes. Es decir, el tamalo de los bloques se reducira, por lo que N debe disminuir ya que se borraron varias posibles permutaciones
            //cout<<factorial[i-1]<<" = "<<N<<endl;
			cout<<word[a];//Imprimimos el caracter de la permutación
            word.erase(a, 1);//Borramos la letra
        }
        
        cout << word[0] << endl;//El último caracter por default
    }
}
