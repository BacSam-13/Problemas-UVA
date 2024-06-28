//Baruc Samuel Cabrera García
//baruc.cabrera@cimat.mx
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

#include<bits/stdc++.h>
using namespace std;

//Problema:
//Dados a lo mas 100 proyectos y 100,000 estudiantes, se hizo un concurso donde cada alumno se registra a un proyecto (en mayusculas)
//con su nombre de usuario(caracteres en minusculas que empiezan con una minuscula).
//El objetivo es contar cuantos alumnos se inscribieron a cada proyecto, pero con ciertas condiciones:
//-Solo se contara una inscripción a cada proecyo (Unos se inscribieron varias veces al mismo)
//-Si uno se inscribe a mas de un proyecto, se anulan todas sus participaciones

//Con las reglas anteriores, se bucsca ordenar los nombres de proyectos con base en su cantidad de alumnos inscritos, de mayor a menor.
//Y en caso de empate, respeta el orden alfabetico de los proyectos


/*
Solucion: Para esta solucion, se creara una funcion comparador para poder ordenar los proyectos con base en su cantidad de alumnos o nombre en caso de empate.
Luego, para cada caso se construiran dos maps, uno para guardar a los alumnos y al primer proyecto que se ingresaron, y otro para guardar a los proyectos 
y a su numero asignado, y finalmente, un vector de respuesta que cuente a los estudiantes inscritos en cada proyecto segun su numero asignado. 
De esta forma, podemos comprobar con el map de students si ya se inscribio a otro proyecto para eliminar su participacion del vector answer y banearlo del vector students.
De esta forma, solo ordenamos el vector answer con el comparador y listo.
*/



//Comparador para usar en sort
bool comparador(const pair<int, string> &a, const pair<int, string> &b) {//Para ordenar los proyectos al final segun su cantidad de estudiantes y su nombre en caso de empate

    if (a.first > b.first){//Es cierto si el entero de a es mayor al de b
    	return true;
	}
	
    if (b.first > a.first){//Es falso si el entero de b es mayor al de a
    	return false;
	}
	
    return a.second<b.second;//En caso de empate, regresar si el string de a es menor al de b
}

bool check_proyect(string word) {//Verificamos si la string es un proyecto o no (Los proyectos estan todos en mayusculas)

    for(int i = 0; i < word.size(); ++i){
    	
        if((word[i] < 'A' || word[i] > 'Z') && word[i] != ' '){//Si la i+1-esima letra no esta en mayusculas y no es un espacio
        	return false;//No es un nombre de proyecto
		}
	}


    return true;
}


int main() {

    string text;
    //getchar();
    getline(cin, text);//Nombre del primer proyecto
	
    while (text[0] != '0'){//Mientras aun se reciban proyectos

        vector< pair<int, string> > answer;//Vector final para guardar los proyectos (Tambien nos permitira ordenarlo)
        map<string, int> proyects;//Map para guardar los proyectos y asignarle un numero a cada uno
        map<string, int> students;//Para registrar a los estudiantes y al ultimo proyecto que se ingresaron como numero
        
        int index = 0;//Ir contando a los estudiantes en la lista

        while (text[0] != '1'){//Mientras continue este caso
			//cout<<"XXXX: "<<line[0]<<endl;
            string project = text;
            answer.push_back(make_pair(0, project));
            proyects[project] = index;
            index++;
			
			//getchar();
            getline(cin, text);//Recibimos al posible nuevo para el proyecto estudiante


            while (text[0] != '1' && !check_proyect(text)){//Si no se termino el caso y no es un nombre de proyecto
				//cout<<"FLAG"<<endl;
                string std = text;
                if (students.find(std) != students.end()){//Si encontramos al estudiante registrado
                
                    if (students[std] != proyects[project] && students[std] != -1){//Si el estudiante estaba registrado en un proyecto diferente y no ha sido anulada ya su participacion
                        answer[students[std]].first--;//Descontamosa un estudiante del proyecto actual
                        students[std] = -1;//Lo descalificamos
                    }
                    
                }else{
                    students[std] = proyects[project];//Lo registramos
                    answer[students[std]].first++;//Contamos a un nuevo estudiante para el proyecto
                }
				
				//getchar();
                getline(cin, text);

            }
        }

        sort(answer.begin(), answer.end(), comparador);//Ordenamos los proyectos
        
        for (int i = 0; i < answer.size(); i++){
        	cout << answer[i].second << " " << answer[i].first << endl;
		}
            
        getline(cin, text);

        //cout<<"--->"<<text<<endl;
	}
}




