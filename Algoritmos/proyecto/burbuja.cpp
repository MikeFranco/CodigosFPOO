#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

struct Entrada {
  int valor;
} entrada;

struct Entrada1 {
  int valor1;
} entrada1;

int i=0, j=0, k=0, intervalo, temp, n=0, cn=0, salvacn;
int si,izq,der,temporal,pivote,ban=0,valorsalva;

int lista[1000000];

int LeeArchivo();
int Ordenamiento();
int guardarArchivoOrdenado();
string ordenamientoAElegir();

clock_t t_ini, t_fin;
double secs;
string nombrearchivo;
string nombrearchivo1;

int LeeArchivo(){
  FILE *archivo1;
  string valorInt;
  printf("\n Teclea el nombre del archivo de entrada: ");
  cin >> nombrearchivo;
  nombrearchivo+= ".txt";
  archivo1 = fopen(nombrearchivo.c_str(), "r");

  if(archivo1== NULL ){
    printf(" No se puede abrir el archivo ");
    exit(1);
  }else{
    printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
  }
  cn=0;
  for (int i=0; !feof(archivo1); i++) {
    fscanf (archivo1, "%i", &entrada.valor);
    lista[i]=entrada.valor;
    cn++;
  }
  salvacn=cn;
  fclose(archivo1);
  return (0);
}

int guardarArchivoOrdenado(){
  FILE *archivo2;
  string valorInt;
  printf("\n Teclea el nombre del archivo de salida: ");
  cin >> nombrearchivo1;
  nombrearchivo1+= ".txt";
  archivo2 = fopen(nombrearchivo1.c_str(), "w");

  if(archivo2== NULL ){
    printf(" El archivo no se abrio. ");
    exit(1);

  }else{
    printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo1.c_str() );
  }

  cn=salvacn;
  salvacn=0;
  for (i=0; i<cn; i++) {
    entrada1.valor1=lista[i];
    fprintf(archivo2, "%i\n", entrada1.valor1);
    salvacn++;
  }
  fclose(archivo2);
  return (0);
}

string ordenamientoAElegir(int opcion){
  switch (opcion) {
    case 1:
      return "burbuja";
      break;
    case 2:
      return "burbuja no sé qué";
      break;
    default:
      cout<<"No encontré esa opción, repita de nuevo";
      break;
  }
}

void OrdenamientoBurbuja (int lista[], int cn){
  printf("Ordenamiento Burbuja\n");
  int i, j, aux;
  for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(lista[j] > lista[j+1]){
				aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}
}

int main(){
  int opcion;
  cout<<"Escoge un ordenamiento\n";
  cout<<"1. Ordenamiento Burbuja\n";

  cout<<"Ingrese el ordenamiento: "; cin>>opcion;
  string nombreOrdenamiento = ordenamientoAElegir(opcion);
  cout<<nombreOrdenamiento;

  /* LeeArchivo();

  // Inicia area de medicion de tiempo
  t_ini = clock(); // almacena tiempo inicial
  Ordenamiento(lista, cn); // realiza el ordenamiento
  t_fin = clock(); // almacena tiempo final
  // Termina area de medicion de tiempo
  
  secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
  printf("%.16g milisegundos\n", secs * 1000.0); // muestra el tiempo utilizado
  guardarArchivoOrdenado(); */
  return 0;
}
