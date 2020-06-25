#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

int main(){
	int filas=0, columnas=0, bandera=0,j=0;
	int ini=0, fin=0, x=0, x2=0;
	int tablaRelaciones[62][4]={
			1,1,0,0,
			1,2,1,9,
			1,2,1,6,
			1,3,7,7,
			1,3,2,0,
			1,4,12,9,
			1,4,9,11,
			1,5,12,15,
			1,5,11,11,
			1,6,12,13,
			1,6,6,8,
			1,7,12,11,
			1,7,13,7,
			1,8,9,10,
			1,8,8,15,
			1,9,16,17,
			1,9,13,12,
			1,10,12,22,
			1,10,12,18,
			1,11,13,19,
			1,11,5,14,
			1,12,14,7,
			1,12,2,8,
			1,13,21,19,
			1,13,3,20,
			1,14,12,18,
			1,14,12,9,
			1,15,21,17,
			1,15,22,11,
			1,16,14,30,
			1,16,12,20,
			1,17,21,15,
			1,17,17,16,
			1,18,13,24,
			1,18,13,15,
			1,19,14,18,
			1,19,17,23,
			1,20,20,28,
			1,20,21,19,
			1,21,20,26,
			1,21,8,23,
			1,22,21,18,
			1,22,19,7,
			1,23,14,19,
			1,23,15,28,
			1,24,28,26,
			1,24,16,29,
			1,25,12,23,
			1,26,35,17,
			1,26,10,11,
			1,27,29,31,
			1,27,21,12,
			1,28,31,32,
			1,28,19,21,
			1,29,38,33,
			1,29,31,21,
			1,30,14,30,
			1,30,12,19,
			1,31,28,27,
			1,31,21,31,
			1,32,20,40,
			1,32,16,45,
	};
	//Impresion de tabla de adyacencias
	cout<<"Este programa nos indica la ruta optima, pretende ser una posible solucion al problema del agente viajero \n";
	cout<<"Los estados de la republica se enumeran del 1 (CDMX) al 32 en las primeras dos columnas  \n";
	cout<<"Para simplificar el problema inicial propusimos que el la CDMX tuviera carreteras directas a cada estado \n";
	cout<<"Las ultimas dos columnas representan los km y el precio de las casetas \n";
	cout<<"Las aristas son bidireccionales";

	for(filas=0;filas<62;filas++){
		for(columnas=0;columnas<4;columnas++){
			cout<< tablaRelaciones[filas][columnas]<<"\t";
		}
		cout<<endl;
	}
	for(j=0;j==0;){
	//Captura de inicio y fin del grafo
	cout<<"\nIngrese el inicio: ";
	cin>>ini;
	cout<<"\nIngrese el fin: ";
	cin>>fin;

	if(ini < 0 && ini > 32){
		cout<<"Los valores de inicio deben de ser positivos y menores a 32"<<endl;
		exit(1);
	}
	if(fin < 0 && fin > 32){
		cout<<"Los valores de fin deben de ser positivos y menores a 32"<<endl;
		exit(1);
	}
	
	cout<<"\nLa ruta menos viable: \n";

	for(filas=0;filas<62;filas++){
		if(tablaRelaciones[filas][0]==ini && tablaRelaciones[filas][1]==fin){
			for(columnas=0;columnas<4;columnas++){
				cout<<tablaRelaciones[filas][columnas]<<"    ";
			}
			bandera=1;
			filas=62;
		}
	}
	
	if(bandera==0){
		cout<<"No existe ruta";
	}
	cout<<endl;
	
	cout<<"\nLa ruta OPTIMA: \n";
	
	for(filas=0;filas<62;filas++){
		if(tablaRelaciones[filas][0]==ini && tablaRelaciones[filas][1]==fin){

			x=filas; 
			for(x2=filas+1;x2<62;x2++){
				if(tablaRelaciones[x2][0]==ini && tablaRelaciones[x2][1]==fin){
					x=x2;
					for(columnas=0;columnas<4;columnas++){
						cout<<tablaRelaciones[x][columnas]<<"    ";
					}
				}else{
					filas=62;
				}
			}
		}
	}

	
	cout<<"\nTodas las rutas son: \n";
	//Todas las Rutas
	for(filas=0;filas<62;filas++){
		if(tablaRelaciones[filas][0]==ini && tablaRelaciones[filas][1]==fin){
			for(columnas=0;columnas<4;columnas++){
				cout<<tablaRelaciones[filas][columnas]<<"    ";
			}
			cout<<endl;
		}
	}
}
	
	system("pause");
}
