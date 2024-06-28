//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <bits/stdc++.h>
using namespace std;

/*
Problemas:
Hay cinco hombres, un mono y un monton de cocos.
Cada uno divide los cocos en 5 partes iguales, esconde la syua, y le da el sobrante al mono
Cuandoya todos terminan de hacer esto, al dividirlos por ultima vez, no sobra ningun coco.

Si sabemos el numero de cocos, cuantos hombres deberian acompaar a un mono para que lo anteior ocurra otra vez?

Notemos que cada vez que un hombre hace la division, se eliminan (cocos/personas + 1), ya que hay mas cocos que personas, por lo que siempre sobra un coco o ninguno
De otra forma, no se podrian repartir los cocos sin romperlos

Solucion:
Para cada caso, con un for bucamos cual es la mayor cantidad de hombres con la que se puede repetir la situacion, por lo que 
en cada iteracion del for que determina la cantidad de hombres, se realiza otro for para repetir el ciclo mencionado, en el momento en que
la condicion se rompa, compemos el ciclo y reducimos la cantidad de homvres, si la condicion se cumple, se rompe el for de hombres y se imprime la cantidad.
*/

int main() {

    int N;
    cin >> N;

    while (N > -1) {

        bool flag = false;//Asumimos al inicio que no se puede resolver, luego veremos si si. Tambien nos indica cuando encontramos el caso adecuado
        int men;//Hombres a considerar
		
		//Supongamos que no le damos nada al mono, se necesitan de a lo mas sqrt(N) hombres para que se puedan didivir los cocos perfectamente sqrt(N) veces. (El + 1 permite que funcione mejor el codigo, es como un precacucion)
        for (int i = sqrt(N) + 1; (i > 0) && (!flag); i--){//Buscamos la mayor cantidad de hombres tales que se puede cumplir la condicion
            
            men = i;
            int cocos = N;
            //bool stop = false;//Bandera para terminar el caso con los i hombres
            int j;
            bool continuar = true;//Se volvera falso si no lograron pasar todos los hombres a hacer el proceso
            
            for (j = 0; j < men && continuar; ++j){//Cada persona hace su division
                if (cocos%men != 1){//Si no sobra un coco para el mono
                	continuar = false;
				}
                cocos -= (cocos/men + 1);//Restamos los cocos correspondientes
            }
            
            if (continuar && (cocos%men == 0)){//Si cada hombre realizo el proceso bien, y al final no sobran cocos, se cumple la condicion
            	flag = true;
			}
        }

		if(flag){
			cout<<N<<" coconuts, "<<men<<" people and 1 monkey"<<endl;
		}else{
			cout<<N<<" coconuts, no solution"<<endl;
		}
    
       
        cin>>N;
    }
}
