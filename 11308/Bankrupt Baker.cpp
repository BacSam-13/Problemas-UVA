//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Probema:
Queremos checar t blinders
Guardamos el nombre del blinder
La cantidad de ingredientes (estos luego se reciben por nombre y precio)
La cantidad de recetas (cada receta recibe su nombre, la cantidad de ingredientes, luego sus ingredientes y la cantidad de cada uno)
Y el presupuesto para el blinder

Queremos saber cuales recetas de cada blinder son posibles de preparar con el presupuesto y los ingredientes, segun su orden creciente de precio
Si no es posible, imprimer que es muy caro


Solucion:
Primero, por cada caso, recibimos los ingredientes y sus precios para analizar las recetas, luego se usa un vector de parejas para guardar los titulos y precios
de cada receta, ya que recibiremos su titulo y los ingredientes necesarios.
Conforme vamos recibiendo la receta y sus ingredientes, y la agregamos al vector con su nombre y precio total si es que no excedio el presupuesto.
Luego ordenamos el vector y lo imprimimos en caso de no estar vacio.
*/

void Mayusculas(string &s){//Funcion para volver una string de minusculas a mayusculas
	
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return toupper(c); });

}

int main() {

    int t;
    cin>>t;

    while (t--) {

        string title;
        getchar();
        getline(cin, title);

        int m, n, b;
        cin>>m>>n>>b;//Numero de ingredientes, Numero de recetas, Presupuesto
		
        map<string, int> ingredients;//Guardamos los m ingredientes junto con su precio
        
        for (int i = 0; i < m; i++) {
            string ingred;
            int precio;
            cin>>ingred>>precio;

            ingredients[ingred] = precio;
        }

        vector< pair<int, string> > result;//Para guardar los precios y nombres de las recetas

        for (int i = 0; i < n; i++) {//Recibimos las n recetas del briden

            string recipe;
            getchar();
            getline(cin, recipe);

            int k;
            cin>>k;//Ingredientes de la receta

            int precio_total = 0;
            for (int j = 0; j < k; j++) {
                string ingred;
                int cantidad;
                cin>>ingred>>cantidad;

                precio_total += ingredients[ingred]*cantidad;//Vemos cuanto costara el usar el ingrediente (costo de cada unidad de ingrediente * unidades del ingrediente)
            }

            if (precio_total <= b){//Si no supera el presupuesto, es válida la receta
            	result.push_back(make_pair(precio_total, recipe));
			}
			
        }

        sort(result.begin(), result.end());//Ordenamos segun first, y second en caso de empate
        Mayusculas(title);//Pasamos a mayusculas

        cout<<title<<endl;
        
        if(result.size() == 0){
        	cout<<"Too expensive!"<<endl;
		}else{
			
			for (int i = 0; i < result.size(); ++i){
				 cout << result[i].second << endl;
			}
               
		}
		cout<<endl;
        
    }
    
}
