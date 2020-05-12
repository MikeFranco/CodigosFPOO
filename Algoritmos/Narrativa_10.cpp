#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct Entrada {
  int valor;
} entrada;

struct Entrada1 {
  int valor1;
} entrada1;

int year, mes, dia;
int salvacn, lista[1000000];
int dias[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int arr[5] = { 20200311, 2020071, 00130311, 20123030 };

string nombrearchivo;
string nombrearchivo1;

int leerArchivo();
int validarFecha();
int validarJuliana();
int validarGregoriana();


int leerArchivo(){
  FILE *archivo1;
  int cn=0;

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
  for (int i=0; !feof(archivo1); i++) {
    fscanf (archivo1, "%i", &entrada.valor);
    lista[i]=entrada.valor;
    cn++;
  }
  salvacn=cn;
  fclose(archivo1);
  return (0);
}


int validarFecha(string fecha){
  if(sizeof(fecha) == 8){
    if(fecha[0] == 0){
      //Puede que ser Juliana
      year = (fecha[1] * 1000) + (fecha[2] * 100) + (fecha[3] * 10) + (fecha[4] * 1);
      dia =  (fecha[5] * 100) + (fecha[6] * 10) + (fecha[7] * 1);
      return year >= 2000
        ? to_string(year) + to_string(dia)
        : fecha;
    }else{
      //Puede que sea Gregoriana
      year = (fecha[0] * 1000) + (fecha[1] * 100) + (fecha[2] * 10) + (fecha[3]*1);
      mes =  (fecha[4] * 10) + (fecha[5] * 1);
      dia = (fecha[6] * 10) + (fecha[7] * 1);
      return year >= 2000
        ? to_string(year) + to_string(mes) + to_string(dia)
        : fecha;
    }

  }else if(sizeof(fecha) == 7){
    //Si el tamaño es 7, puede que sea Juliana
    year = (fecha[0] * 1000) + (fecha[1] * 100) + (fecha[2] * 10) + (fecha[3] * 1);
    dia =  (fecha[4] * 100) + (fecha[5] * 10) + (fecha[6] * 1);
    return year >= 2000
      ? to_string(year) + to_string(dia)
      : fecha;
    
  }else {
    return fecha;//significa que es un número y no es una fecha válida;
  }

}

int main(){
  leerArchivo();
  for(int i = 0; i < 1000000; i++){
    cout<<validarFecha(lista[i]);
  }

}