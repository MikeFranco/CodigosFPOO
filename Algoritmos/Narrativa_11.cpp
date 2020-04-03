#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

FILE *archivoGenerado;
struct RegistroDeDatos {
  int valorRandom;
} entrada;

int generarArchivo();

int inicio, final, valor, cantidadNumeros, inicio2;
string nombreArchivo;

/* //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
int main(){
  generarArchivo();
  
}

int generarArchivo(){
  srand(time(NULL));
  cout<<"Ingrese el nombre del archivo: "; cin>>nombreArchivo;
  nombreArchivo += ".txt";

  archivoGenerado = fopen(nombreArchivo.c_str(), "w");

  if(archivoGenerado == NULL){
    cout<<"Hubo un error, no se pudo abrir el archivo";
    exit(1);
  }else cout<<"Se abrió correctamente el archivo: "<<nombreArchivo.c_str();
  do {
    cout<<"Ingrese el valor inicial: "; cin>>inicio;
    inicio2 = inicio;
    cout<<"Ingrese el valor final: "; cin>>final;
    cout<<"Ingrese el numero de valores que quiere: "; cin>>cantidadNumeros;
  }while(final-inicio>=2000000);
  for(int i=0; i<cantidadNumeros; i++){
          entrada.valorRandom = inicio2 + rand()%(final+1 - inicio2);
          fprintf(archivoGenerado, "%i\n", entrada.valorRandom);
  }
  fclose(archivoGenerado);
}