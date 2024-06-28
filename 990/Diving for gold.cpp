//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <bits/stdc++.h>
using namespace std;

/*
Problema:
UN exlorador encontro tesoros submarions, y por razones que no quiero explicar, tiene que determinar de que forma puede obtener la mayor ganancia
con base en la profundidad y ganancia del tesoro, considerando que tiene oxigeno limitado.

Solucion:
Similar al problema del ladro, se uso programación dinámica para determinar que tesoros combienen, considerado que la profundidad determina el tiempo que cuesta recoger el tesoro,
y los segundos restantes de oxigeno.
Para esto, usamos dos matrices que nos indican los costos de cada tesoro y los tesoros que tomaremos.
Para finalmente con un vector guardar los tesoros que tomaremos e imprimirlos junto con us valor y prodfundidad.
*/

vector<vector<int>> memo;//Matriz de progrmacion dinamica
vector<vector<bool>> take;//Matriz compañera que nos ayuda a saberque tesoros se tomaran
vector<int> tesoros;//Guardamos los valores de cada tesoro
vector<int> depth;//Guardamos la profundidad de cada tesoro
vector<int> tiempo;//El tiempo que cuesta recojer cada tesoro, bajada y subida



int solve_matriz(int t,int j, int n){

	if(t<0){//Si se acabo el tanque
		return 0;
	}
	
	//Si ya consideramos todos los tesoros
	if(j==n){
		return 0;
	}
	
	//Si ya fue calculada la casilla
	if(memo[t][j]!=-1){
		return memo[t][j];
	}
	
	int a = 0;
	int b = 0;
	
	if (t-tiempo[j]>=0){//Si aun queda tiempo disponible en el oxigeno
		a = solve_matriz(t-tiempo[j], j+1, n) + tesoros[j];//a representa la ganaica de tomar el tesoro j
	}
	b = solve_matriz(t, j+1, n);//La ganacia de no tomarlo
	
	if(a > b){//Si es mejor tomar el tesoro j que dejarlo, lo marcamos en la matriz take
		take[t][j] = true;
		memo[t][j] = a;//Guardamos la ganancia optima
		return a;
	}else{
		
		memo[t][j] = b;
		return b;
	}
	
}

int main(){
	int t, w;//Para guardar los segundos del tanque y la constante
	bool enter =true;//Para imprimir enter entre casos
	
	while(cin>>t>>w){

		
		if (!enter){
			cout<<endl;	
		}else{
			enter = false;
		}
		
		
		//init();
		
		int n;//Numero de tesoros
		cin>>n;
		
		tesoros.assign(n, 0);
		depth.assign(n, 0);
		tiempo.assign(n, 0);
		
		for(int i=0; i < n; i++){
			cin>>depth[i]>>tesoros[i];
			tiempo[i] = depth[i]*3*w;
		}
		
		memo.assign(t+1, vector<int>(n, -1));// [tiempo][tesoros]
		take.assign(t+1, vector<bool>(n, false));
		
		cout<<solve_matriz(t, 0, n)<<endl;//Con PD calculamos la ganancia optima
		
		vector<int> f_tesoros;//Vector para guardar los index de los tesoros que se eligieron, usando la matriz take como referencia
		
		int T = t;//Para recorrer
		
		for(int i=0; i < n; i++){//Vemos todos los tesoros
			
			if(take[T][i]==true){//Si tomamos el tesoro i al tener T de oxigeno
				f_tesoros.push_back(i);//Lo guardamos
				T -= tiempo[i];//Restamos el tiempo que cuesta recoger el tesoro
			}
		}
		
		cout << f_tesoros.size() << endl;
		
		for(int i=0;i < f_tesoros.size();i++){
			cout<<depth[f_tesoros[i]]<<" "<<tesoros[f_tesoros[i]]<<endl;
		}
	}
		
	return 0;
}
