//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx

#include <bits/stdc++.h>
using namespace std;

#define GRANT 40 //Beca

/*
Problema:
En un pais medieval, para dar becas, dan tarjetas con un codigo atras.
Se pagan $40 a cada estudiante al año en el dia laboral mas cercano a su cumpleaños.
(Solo los hombres van a la escuela)

La beca se paga en un cajero antiguo y dificil de robar, donde hay una boveda que guarda una gran cantidad de monedas de $1.
Estas pasan a la "tienda de salida" solo cuando esta esta vacia.

Al encenderse por la mañana, y la tienda este vacía, movera una moneda, luego 2, luego 3, etc...
Hasta que alcance algún limite preestablecido k. Luego se reinicia la salida de monedas, 1,2,3,.....,k

Los alumnos forman cola en esta máquina y, a su vez, cada alumno introduce su tarjeta. La máquina
dispensa lo que tiene en su tienda de salida y actualiza la cantidad pagada a ese estudiante escribiendo el
nuevo total en la tarjeta. Si el estudiante no ha recibido su beca completa, retira su tarjeta y se reincorpora al
cola al final. Si la cantidad en la tienda más lo que el estudiante ya ha recibido llega a más
de $40, la máquina solo paga lo suficiente para hacer un total de $40. Dado que este hecho se registra
en la tarjeta, no tiene sentido que el alumno siga haciendo cola y se va. la cantidad restante
en la tienda está disponible para el próximo estudiante.

De esta forma, hacer un código que lea N (estudiantes) y el limite k, y diga en que orden salen los estudiantes de la fila.
*/


/*
Solucion:
En cada caso, se recibiran la cantidad de estudiantes y el limite k del cajer, con estos datos, se creara un vector para los
N estudiantes.
Y se realizara un while para que cada estudiante recoja lo que se encuentra en la randija.
La cual se va repondiendo cada vez que esta vacía, y considerando el límite k, lo que se oluciona con un %.
Este ciclo while continua hasta que todos los estudiantes hayan recogido toda su beca, e ignora a los estudiantes que
ya la recogieron, porque estos ya dejaron la fila.
Con esta estructura de while, imprimimos los indices de los estudiantes que completen su beca.
*/
int main() {

    int N, k;
    cin>>N>>k;
    
    while( (N != 0) && (k != 0) ){

        vector<int> students(N, 0);//Lo que se le pago a cada estudiante (debe llegar hasta 40 para irse de la fila)
        int finished = 0;//Alumnos que dejaron la fila
        int i_stu = 0;//Indice para los estudiantes, así sabremos quien es el que esta frente al cajera
        int i_mo = 0;//Indice para ronda del dinero(en la ronda cero, da uno, en la uno, da 2, y así....)
        int rendija = i_mo+1;//Al inicio, hay $1 en la tienda ya que es la ronda cero(le diremos rendija de ahora en adelante)

        while(finished < N){//Mientras aun haya estudiantes en la fila

            if (students[i_stu] != GRANT){//Si el estudiante No.i_stu aun no reclama su beca
            	
                if (students[i_stu] + rendija >= GRANT) {//Si con el dinero de la randija alcanzamos o superamos la meta
                    rendija -= GRANT - students[i_stu];//Restamos el dinero que tomo el estudiante (se resta asi porque solo toma para completar sus $40, el resto lo deja)
                    students[i_stu] = GRANT;//Ya tiene su beca
                    cout.width(3);
                    cout<<i_stu + 1;
                    //cout << (i_stu+1 > 9? " ":"  ") << i_stu+1;
                    finished++;
                }else{//El estudiante toma todo el dinero que hay en la randija
                    students[i_stu] += rendija;
                    rendija = 0;
                }
            }

            if(rendija == 0){//Si se vacio la rendija
                i_mo++;//Avanzamos a la siguiente ronda de monedas.
                i_mo = i_mo%k;//El %k es para que se vuelva 0 si llega al limite, vuelva a valer cero
				rendija = i_mo + 1;//Vemos cuanto dinero tiene la randija en esta ronda
            }
            i_stu++;//Pasamos al siguiente estudiante
            i_stu = i_stu%N;//Para mantener la estructura de cola
        }
        
        cout<<endl;
        
        cin>>N>>k;
    }
}
