// Autores: Edna Martha Miranda Chávez
//          Sergio Fuenlabrada Velázquez
//
//Descripción:  Grafo no dirigido 
//
//              Tabla de adyacencias
//                  Columnas de la tabla
//                  --->    Ini  Fin      A           B          C          D          E     Nodos  Total
//	
//                          Ini  - En esta columna se identifica el nodo de inicio de la ruta
//                          Fin  - En esta columna se identifica el nodo de destino de la ruta o nodo de fin o final
//                          A B C D E  -  Nodos del grafo
//                                     -     Por cada nodo se tienen dos valores
//                                                  1.- El peso o costo del arco - lo que cuesta llegar al nodo indicado
//                                                  2.- Dentro de la ruta el orden en el cual se toca al arco
//                                                      el orden en el cual se van tocando los nodos.
//                          Nodos - Total de nodos tocados para llegar del nodo origen al destino o fin
//                          Total - Peso total o costo total de toda la ruta del nodo origen al nodo destino o fin
//
//                Filas de la tabla
//                      Es la ruta que se puede tomar para llegar del nodo origen al nodo destino o fin
//
//
// ¿Porque se genera la tabla de adyacencias de tipo string?
//
//             Esto se hizo con el objetivo de facilitar el manejo de la tabla de adyacencias
//
//             Si se crea la tabla de tipo entera (integer) los nodos se deben manejar como equivalencias
//             esto es:   A = 1, B = 2, etc.  Y esto complica un poco la programación
//
//             Si se crea de tipo char (character) sólo acepta un caracter (un número, símbolo o letra)
//             el problema se encuentra en la columna total ya que sólo se puede registrar un número 
//             esto si provoca un error, ya que como se ve en este ejemplo la segunda fila no se podria 
//             poner el costo total de la ruta 11. 
//                   Ini  Fin      A           B          C          D          E     Nodos  Total
//            	    {"A","B",   " "," ",   "5","2",   "6","1",   " "," ",   " "," ",   "2",   "11"},
//
//                   La ruta del nodo A al B, primero toca el nodo C (valor 6), depues toca el nodo B
//                   (valor 5), toca dos nodos y el costo total de ese camino o ruta es 11.
//
//
//                 Ini  Fin      A           B          C          D          E     Nodos  Total
// 	               {"A","D",   " "," ",   "5","1",   "5","2",   "8","4",   "7","3",   "4",   "25"},
//
//                   La ruta del nodo A al D, primero toca el nodo B (valor 5), depues toca el nodo C
//                   (valor 5), despues toca el nodo E (valor 7), despues toca el nodo D (valor 8)
//                   toca cuatro nodos y el costo total de ese camino o ruta es 25.
//
//
//
// OBSERVA:
//             Observa que en la tabla de adyacencias, están ordenadas las rutas o caminos del menor peso al mayor
//             y de la ruta que toca menos nodos a la que toca mas nodos.
//             Posiblemente haya una ruta que pese menos y toque mas nodos, por eso se guarda el numero de nodos 
//             tocados en la ruta  
//
//EJECUTA:
//             Prueba el programa mostrando la ruta de E a D
//
//
    

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

	string tabAdyacencias [65][14] = {
	
	//   Ini  Fin      A           B          C          D          E     Nodos  Total	    
	    {"A","B",   " "," ",   "5","1",   " "," ",   " "," ",   " "," ",   "1",   "5"},
	    {"A","B",   " "," ",   "5","2",   "6","1",   " "," ",   " "," ",   "2",   "11"},
	    {"A","B",   " "," ",   "6","4",   "6","1",   "8","3",   "7","2",   "4",   "27"},
	    
	    {"A","C",   " "," ",   " "," ",   "6","1",   " "," ",   " "," ",   "1",   "6"},
	    {"A","C",   " "," ",   "5","1",   "5","2",   " "," ",   " "," ",   "2",   "10"},
	    {"A","C",   " "," ",   "5","1",   "7","4",   "6","2",   "8","3",   "4",   "26"},
	    
	    {"A","D",   " "," ",   "5","1",   " "," ",   "6","2",   " "," ",   "2",   "11"},    	    
	    {"A","D",   " "," ",   "5","2",   "6","1",   "6","3",   " "," ",   "3",   "17"},
	    {"A","D",   " "," ",   " "," ",   "6","1",   "8","3",   "7","2",   "3",   "21"},
	    {"A","D",   " "," ",   "5","1",   "5","2",   "8","4",   "7","3",   "4",   "25"},
	    
	    {"A","E",   " "," ",   " "," ",   "6","1",   " "," ",   "7","2",   "2",   "13"},
	    {"A","E",   " "," ",   "5","1",   "5","2",   " "," ",   "7","3",   "3",   "17"},
		{"A","E",   " "," ",   "5","1",   " "," ",   "6","2",   "8","3",   "3",   "19"},
	    {"A","E",   " "," ",   "5","2",   "6","1",   "6","3",   "8","4",   "4",   "25"},	    
	    
	    {"B","A",   "5","1",   " "," ",   " "," ",   " "," ",   " "," ",   "1",   "5"},
	    {"B","A",   "6","2",   " "," ",   "5","1",   " "," ",   " "," ",   "2",   "11"},
	    {"B","A",   "6","4",   " "," ",   "7","3",   "6","1",   "8","2",   "4",   "27"},
	    
	    {"B","C",   " "," ",   " "," ",   "5","1",   " "," ",   " "," ",   "1",   "5"},
	    {"B","C",   "5","1",   " "," ",   "6","2",   " "," ",   " "," ",   "2",   "11"},
	    {"B","C",   " "," ",   " "," ",   "7","3",   "6","1",   "8","2",   "3",   "21"},
	    
	    {"B","D",   " "," ",   " "," ",   " "," ",   "6","1",   " "," ",   "1",   "6"},
	    {"B","D",   " "," ",   " "," ",   "5","1",   "8","3",   "7","2",   "3",   "20"},
	    {"B","D",   "5","1",   " "," ",   "6","2",   "8","4",   "7","3",   "4",   "26"},
	    
	    {"B","E",   " "," ",   " "," ",   "5","1",   " "," ",   "7","2",   "2",   "12"},
	    {"B","E",   " "," ",   " "," ",   " "," ",   "6","1",   "8","2",   "2",   "14"},
	    {"B","E",   "5","1",   " "," ",   "6","2",   " "," ",   "7","3",   "3",   "18"},
	    
	    {"C","A",   "6","1",   " "," ",   " "," ",   " "," ",   " "," ",   "1",   "6"},
	    {"C","A",   "5","2",   "5","1",   " "," ",   " "," ",   " "," ",   "2",   "10"},
	    {"C","A",   "5","4",   "6","3",   " "," ",   "8","2",   "7","1",   "4",   "26"},
	    
	    {"C","B",   " "," ",   "5","1",   " "," ",   " "," ",   " "," ",   "1",   "5"},
	    {"C","B",   "6","1",   "5","2",   " "," ",   " "," ",   " "," ",   "2",   "11"},
	    {"C","B",   " "," ",   "6","3",   " "," ",   "8","2",   "7","1",   "3",   "21"},
	    
	    {"C","D",   " "," ",   " "," ",   " "," ",   "8","2",   "7","1",   "2",   "15"},
	    {"C","D",   " "," ",   "5","1",   " "," ",   "6","2",   " "," ",   "2",   "11"},
	    {"C","D",   "6","1",   "5","2",   " "," ",   "6","3",   " "," ",   "3",   "17"},
	    
	    {"C","E",   " "," ",   " "," ",   " "," ",   " "," ",   "7","1",   "1",   "7"},
	    {"C","E",   " "," ",   "5","1",   " "," ",   "6","2",   "8","3",   "3",   "19"},
	    {"C","E",   "6","1",   "5","2",   " "," ",   "6","3",   "8","4",   "4",   "25"},
	    
	    {"D","A",   "5","2",   "6","1",   " "," ",   " "," ",   " "," ",   "2",   "11"},
	    {"D","A",   "6","3",   "6","1",   "5","2",   " "," ",   " "," ",   "3",   "17"},
	    {"D","A",   "6","3",   " "," ",   "7","2",   " "," ",   "8","1",   "3",   "21"},
	    
	    {"D","B",   " "," ",   "6","1",   " "," ",   " "," ",   " "," ",   "1",   "6"},
	    {"D","B",   " "," ",   "5","3",   "7","2",   " "," ",   "8","1",   "3",   "20"},
	    {"D","B",   "6","3",   "5","4",   "7","2",   " "," ",   "8","1",   "4",   "26"},
	    
	    {"D","C",   " "," ",   "6","1",   "5","2",   " "," ",   " "," ",   "2",   "11"},
	    {"D","C",   " "," ",   " "," ",   "7","2",   " "," ",   "8","1",   "2",   "15"},	    
	    {"D","C",   "6","2",   "6","1",   "6","3",   " "," ",   " "," ",   "3",   "17"},
	    
	    {"D","E",   " "," ",   " "," ",   " "," ",   " "," ",   "8","1",   "1",   "8"},
	    {"D","E",   " "," ",   "6","1",   "5","2",   " "," ",   "7","3",   "3",   "18"},
	    {"D","E",   "5","2",   "6","1",   "6","3",   " "," ",   "7","4",   "4",   "24"},
	    
	    {"E","A",   "6","2",   " "," ",   "7","1",   " "," ",   " "," ",   "2",   "13"},
	    {"E","A",   "5","3",   "5","2",   "7","1",   " "," ",   " "," ",   "3",   "17"},
	    {"E","A",   "5","3",   "6","2",   " "," ",   "8","1",   " "," ",   "3",   "19"},
	    
	    {"E","B",   " "," ",   "5","2",   "7","1",   " "," ",   " "," ",   "2",   "12"},
	    {"E","B",   " "," ",   "6","2",   " "," ",   " "," ",   "8","1",   "2",   "14"},
	    {"E","B",   "6","2",   "5","3",   "7","1",   " "," ",   " "," ",   "2",   "18"},
	    
	    {"E","C",   " "," ",   " "," ",   "7","1",   " "," ",   " "," ",   "1",   "7"},
	    {"E","C",   " "," ",   "6","2",   "5","3",   " "," ",   "8","1",   "3",   "19"},
	    {"E","C",   "5","2",   "6","3",   "6","4",   " "," ",   "8","1",   "4",   "25"},
	    
	    {"E","D",   " "," ",   " "," ",   " "," ",   "8","1",   " "," ",   "1",   "8"},
	    {"E","D",   "6","2",   "5","3",   "7","1",   "6","4",   " "," ",   "4",   "24"},
	    {"E","D",   " "," ",   "5","2",   "7","1",   "6","3",   " "," ",   "3",   "18"}
	};



int main(){
	
	int i = 0, j = 0, k = 0, l = 0, m = 0, inicio = 0, fin = 0, cont = 0, filaNumNodos = 0, contador = 0, respuesta = 0;
	string origen = " ", destino = " ", numNodos = " ";

	
	system("color f0");
    for (k = 0; k == 0; ){

		system("cls");
		cout<<"\tGRAFO NO DIRIGIDO";

		for (l=0; l==0;){
			cout<<"\n\nIngrese el Nodo de ORIGEN, con letras mayusculas (A, B, C, D o E): ";
			fflush(stdin);
			getline(cin, origen);
			fflush(stdin);
			if (origen == "A" || origen == "B" || origen == "C" || origen == "D" || origen == "E"){
				l=1;
			}
			else{
				cout<<"\n\nEl nodo de ORIGEN no existe, intente nuevamente ";
			}
		}

		for (m=0; m==0; ){
			for (l=0; l==0;){
				cout<<"\n\nIngrese el Nodo DESTINO, con letras mayusculas (A, B, C, D o E): ";
				fflush(stdin);
				getline(cin, destino);
				fflush(stdin);
				if (destino == "A" || destino == "B" || destino == "C" || destino == "D" || destino == "E"){
					l=1;
				}
				else{
					cout<<"\n\nEl nodo de DESTINO no existe, intente nuevamente ";
				}
			}
		    if (origen != destino){
			    m=1;
			}
			else {
				cout<<"\n\nEl nodo de origen y destino es el mismo";
			}
		}
			

		cout<<"\n********************************************";
		cout<<"\nNodo Origen: "<<origen;
		cout<<"\nNodo Destino:  "<<destino;
		cout<<"\n\n******* Todas las posibles rutas del nodo origen al nodo destino";
		cout<<"\n  Inicio  Destino\tA\tB\tC\tD\tE\tNodos\tPeso";
		
		for(i=0; i<65; i++) {    //CAMBIAR EL NUMERO DEPENDIENDO DE LAS FILAS QUE TENGA EL PROGRAMA
		
			if(origen == tabAdyacencias[i][0] && destino == tabAdyacencias[i][1]) {
					inicio = i;
				    cout<<"\n    "<<tabAdyacencias[i][0]<<"\t    "<<tabAdyacencias[i][1]<<"\t        "<<tabAdyacencias[i][2]<<" "<<tabAdyacencias[i][3]<<"\t"<<tabAdyacencias[i][4]<<" "<<tabAdyacencias[i][5]
				    	<<"\t"<<tabAdyacencias[i][6]<<" "<<tabAdyacencias[i][7]<<"\t"<<tabAdyacencias[i][8]<<" "<<tabAdyacencias[i][9]<<"\t"<<tabAdyacencias[i][10]<<" "<<tabAdyacencias[i][11]
					    <<"\t"<<tabAdyacencias[i][12]<<"\t"<<tabAdyacencias[i][13]<<endl;
					
					numNodos = tabAdyacencias[i][12];
					filaNumNodos = contador;
				
				for (contador = i+1; contador < 65; contador++){
					i++;
					
					if (origen == tabAdyacencias[contador][0] && destino == tabAdyacencias[contador][1]) {
					  	cout<<"\n    "<<tabAdyacencias[contador][0]<<"\t    "<<tabAdyacencias[contador][1]<<"\t        "<<tabAdyacencias[contador][2]<<" "<<tabAdyacencias[contador][3]<<"\t"<<tabAdyacencias[contador][4]<<" "<<tabAdyacencias[contador][5]
				    	    <<"\t"<<tabAdyacencias[contador][6]<<" "<<tabAdyacencias[contador][7]<<"\t"<<tabAdyacencias[i][8]<<" "<<tabAdyacencias[contador][9]<<"\t"<<tabAdyacencias[contador][10]<<" "<<tabAdyacencias[contador][11]
					        <<"\t"<<tabAdyacencias[contador][12]<<"\t"<<tabAdyacencias[contador][13]<<endl;
					        
					   	if (tabAdyacencias[contador][12] >= numNodos){
							numNodos = tabAdyacencias[contador][12];
							filaNumNodos = contador;	
						}    
			        }
			        else{
			          fin = contador - 1;	
			          contador = 65;
			       	} 
			    }
			}	
		}
		
		cout<<"\n\n*******La ruta MAS CORTA de "<<origen<<"  a  "<<destino;
				cout<<"\n  Inicio  Destino\tA\tB\tC\tD\tE\tNodos\tPeso";
				cout<<"\n    "<<tabAdyacencias[inicio][0]<<"\t    "<<tabAdyacencias[inicio][1]<<"\t        "<<tabAdyacencias[inicio][2]<<" "<<tabAdyacencias[inicio][3]<<"\t"<<tabAdyacencias[inicio][4]<<" "<<tabAdyacencias[inicio][5]
		            <<"\t"<<tabAdyacencias[inicio][6]<<" "<<tabAdyacencias[inicio][7]<<"\t"<<tabAdyacencias[inicio][8]<<" "<<tabAdyacencias[inicio][9]<<"\t"<<tabAdyacencias[inicio][10]<<" "<<tabAdyacencias[inicio][11]
			        <<"\t"<<tabAdyacencias[inicio][12]<<"\t"<<tabAdyacencias[inicio][13]<<endl;
			        
		cout<<"\n\n*******La ruta MAS LARGA de "<<origen<<"  a  "<<destino;
				cout<<"\n  Inicio  Destino\tA\tB\tC\tD\tE\tNodos\tPeso";
				cout<<"\n    "<<tabAdyacencias[fin][0]<<"\t    "<<tabAdyacencias[fin][1]<<"\t        "<<tabAdyacencias[fin][2]<<" "<<tabAdyacencias[fin][3]<<"\t"<<tabAdyacencias[fin][4]<<" "<<tabAdyacencias[fin][5]
		            <<"\t"<<tabAdyacencias[fin][6]<<" "<<tabAdyacencias[fin][7]<<"\t"<<tabAdyacencias[fin][8]<<" "<<tabAdyacencias[fin][9]<<"\t"<<tabAdyacencias[fin][10]<<" "<<tabAdyacencias[fin][11]
			        <<"\t"<<tabAdyacencias[fin][12]<<"\t"<<tabAdyacencias[fin][13]<<endl;			        
	
		cout<<"\n\n*******La ruta que MENOS NODOS TOCA "<<origen<<"  a  "<<destino;
				cout<<"\n  Inicio  Destino\tA\tB\tC\tD\tE\tNodos\tPeso";
				cout<<"\n    "<<tabAdyacencias[inicio][0]<<"\t    "<<tabAdyacencias[inicio][1]<<"\t        "<<tabAdyacencias[inicio][2]<<" "<<tabAdyacencias[inicio][3]<<"\t"<<tabAdyacencias[inicio][4]<<" "<<tabAdyacencias[inicio][5]
		            <<"\t"<<tabAdyacencias[inicio][6]<<" "<<tabAdyacencias[inicio][7]<<"\t"<<tabAdyacencias[inicio][8]<<" "<<tabAdyacencias[inicio][9]<<"\t"<<tabAdyacencias[inicio][10]<<" "<<tabAdyacencias[inicio][11]
			        <<"\t"<<tabAdyacencias[inicio][12]<<"\t"<<tabAdyacencias[inicio][13]<<endl;	
			        

	
		cout<<"\n\n*******La ruta que MAS NODOS TOCA  "<<origen<<"  a  "<<destino;
				cout<<"\n  Inicio  Destino\tA\tB\tC\tD\tE\tNodos\tPeso";
				cout<<"\n    "<<tabAdyacencias[filaNumNodos][0]<<"\t    "<<tabAdyacencias[filaNumNodos][1]<<"\t        "<<tabAdyacencias[filaNumNodos][2]<<" "<<tabAdyacencias[filaNumNodos][3]<<"\t"<<tabAdyacencias[filaNumNodos][4]<<" "<<tabAdyacencias[filaNumNodos][5]
		            <<"\t"<<tabAdyacencias[filaNumNodos][6]<<" "<<tabAdyacencias[filaNumNodos][7]<<"\t"<<tabAdyacencias[filaNumNodos][8]<<" "<<tabAdyacencias[filaNumNodos][9]<<"\t"<<tabAdyacencias[filaNumNodos][10]<<" "<<tabAdyacencias[filaNumNodos][11]
			        <<"\t"<<tabAdyacencias[filaNumNodos][12]<<"\t"<<tabAdyacencias[filaNumNodos][13]<<endl;				        
			        
	
		cout<<"\n\nDesea consultar otro camino o ruta? \n\tPara terminar oprima cualquier tecla,  Para continuar oprima  1 : ";
		cin>>respuesta;
		if (respuesta != 1){
			cout<<"\n\n\t\t\tHasta luego\n  ";
			k = 1;
		}
    }
	system ("pause");
}


