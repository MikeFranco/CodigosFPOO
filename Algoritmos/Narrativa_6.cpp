#include <stdlib.h>
#include <stdio.h>
#include <string.h> /*a�adimos la biblioteca "string.h" */
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

string nombrearchivo;
int arreglo [1000];
int comparador [1000];
int contador=0;
int conta=0;
int n=0;
int ayuda[1000];
int auxi=0;
FILE  *fp;


int abrir_archivo() {
    
  printf("Nombre de archivo: ");
  cin>> nombrearchivo;

  nombrearchivo+= ".txt";

  fp = fopen(nombrearchivo.c_str(), "r");
  if (fp==NULL){
    printf("No se encuentra el archivo deseado");
  }else{
    printf("Se abrio correctamente el archivo\n");
    while(feof(fp)==0){
      fscanf(fp,"%d", &arreglo[contador]);
      contador++;
    }
  }
  fclose ( fp );
  return 0;

}


int ordenar(){

  int i,j,aux_elem,movimientos;
  movimientos=0;

  for(int i=0;i<1000-1;i++){

    for(j=1;j<1000;j++){
    
      if(arreglo[j]<arreglo[j-1]){
        aux_elem=arreglo[j];
        arreglo[j]=arreglo[j-1];
        arreglo[j-1]=aux_elem;
        movimientos++;
      }
    }
  }
}

int copiar(){

  for(int n=0;n<1000;n++){
    auxi=arreglo[n];
    comparador[n]=auxi;
  }

}

int mostrarArreglo(){
  for(int contadore=0;contadore<1000;contadore++){
    printf("Valor: %d\n",comparador[contadore]);
  }
}

int eliminar(){
  int n=0, auxi=0;
  for(int i=0;i<1000;i++){
    if(arreglo[i]!=arreglo[i+1]){
      auxi=arreglo[i];
      ayuda[n]=auxi;
      n++;
    }
  }

}


int comparar()
{
  int y=0;
  n=0;
  auxi=0;
  contador=0;
  int resultado=0;
  for(y=0;y<1000;y++){
    if(comparador[y]==ayuda[n]){
      contador++;
      if(comparador[y]!=comparador[y+1]){
        printf("\n%d tiene: %d elementos repetidos\n",ayuda[n],contador,resultado);
        n++;
        resultado=contador+resultado;
        contador=0;
      }
    }
  }
  printf("\n\n\t\tTOTAL DE REPETICIONES %d", resultado);

}

int main()
{
  abrir_archivo();
  ordenar();
  copiar();
  eliminar();
  comparar();

}
