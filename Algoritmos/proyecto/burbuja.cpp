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

int LeeArchivo(string);
void OrdenamientoBurbuja();
int guardarArchivoOrdenado();
string ordenamientoAElegir();

clock_t t_ini, t_fin;
double secs;

int LeeArchivo(string cantidadNumeros){
  FILE *archivo1;
  string nombrearchivo = "num";
  nombrearchivo += cantidadNumeros;
  nombrearchivo += ".txt";
  archivo1 = fopen(nombrearchivo.c_str(), "r");
  cout<<nombrearchivo;
  if(archivo1 == NULL ){
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

/* int guardarArchivoOrdenado(){
  FILE *archivo2;
  string valorInt;
  printf("\n Teclea el nombre del archivo de salida: ");
  //cin >> nombrearchivo1;
  //nombrearchivo1+= ".txt";
  //archivo2 = fopen(nombrearchivo1.c_str(), "w");

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
} */

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

void OrdenamientoBurbuja (){
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
  string cantidadNumeros;
  cout<<"Escoge un ordenamiento\n";
  cout<<"1. Ordenamiento Burbuja\n";

  cout<<"Ingrese el ordenamiento: "; cin>>opcion;
  // se obtiene un string para saber el tipo de ordenamiento que se va a usar
  string nombreOrdenamiento = ordenamientoAElegir(opcion);
  cout<<"¿Cuantos valores quieres ordenar? (10/100/1,000/10,000/100,000/1'000,000): ";
  cin>>cantidadNumeros;
  
  //Se da por hecho de que el archivo que se leerá será el que se encuentra
  //en esta carpeta
  LeeArchivo(cantidadNumeros);
  
  // Inicia area de medicion de tiempo
  switch(opcion) {
    case 1:
      t_ini = clock(); // almacena tiempo inicial
      OrdenamientoBurbuja(); // realiza el ordenamiento
      t_fin = clock(); // almacena tiempo final
    break;
    case2:

    break;
  }
  // Termina area de medicion de tiempo

  secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
  printf("%.16g milisegundos\n", secs * 1000.0); // muestra el tiempo utilizado
  //guardarArchivoOrdenado();
  return 0;
}
