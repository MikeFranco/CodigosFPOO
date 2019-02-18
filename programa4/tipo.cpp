#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

bool validarLado(string);
int tipoTriangulo(int, int, int);
int volverIngresarLado();
int cambiarStringAInt(string);
int validarTriangulo(int, int, int);
int validarLength(string);
string error();
int valido();

int main(){

  string lado1, lado2, lado3;
  int newLado1, newLado2, newLado3;
  cout<<"\t\t==== Programa que dice tu tipo de triangulo segun sus lados ====\n\t\tFavor de ingresar un numero menor a 10 digitos\n\n";

  cout<<"Ingrese el lado 1: "; cin>>lado1;
  if(validarLado(lado1)==1 && validarLength(lado1)==1) newLado1=cambiarStringAInt(lado1); else newLado1=volverIngresarLado();

  cout<<"\nIngrese el lado 2: "; cin>>lado2;
  if(validarLado(lado2)==1 && validarLength(lado2)==1) newLado2=cambiarStringAInt(lado2); else newLado2=volverIngresarLado();

  cout<<"\nIngrese el lado 3: "; cin>>lado3;
  if(validarLado(lado2)==1 && validarLength(lado3)==1) newLado3=cambiarStringAInt(lado3); else newLado3=volverIngresarLado();

  validarTriangulo(newLado1, newLado2, newLado3)==1 ? cout<<"\nLos numero ingresados si forman un triangulo\n" : cout<<"\nNo es un triangulo\n";
  int validacion = tipoTriangulo(newLado1, newLado2, newLado3);
  validacion==3 ? cout<<"\n\nTu triangulo es un equilatero\n\n" : validacion==1 ? cout<<"\n\nTu triangulo es un isoceles\n\n" : cout<<"\n\nTu triangulo es un escaleno\n\n";
}

bool validarLado(string lado){
  int valido=0;

  for(int i=0;i<lado.size();i++){

    if(isdigit(lado[i])) valido=1;break;

  }
  return valido;

}

int validarTriangulo(int lado1, int lado2, int lado3){
  int bandera = 0;
  int res1 = lado1 + lado2;
  int res2 = lado1 + lado3;
  int res3 = lado2 + lado3;
  (res1 > lado3) && (res2 > lado2) && (res3 > lado1)
    ? bandera=1
    : bandera=0;
  return bandera;
}

int cambiarStringAInt(string lado){
  int newLado = atoi(lado.c_str());
  (newLado <= 0) ? cout<<"El dato ingresado no es valido\n" : cout<<"\tEl dato ingresado si es valido\n";
  return newLado;
}

int validarLength(string lado){
  bool bandera=0;
  lado.length() < 10 ? bandera=1 : bandera=0;
  return bandera;
}

int volverIngresarLado(){
  string lado;
  int newLado;
  bool bandera = 0;
  while(bandera == 0){
    cout<<"\n\nIngrese de nuevo el lado: "; cin>>lado;
    if(validarLado(lado)==1 && validarLength(lado)==1) {
      newLado=cambiarStringAInt(lado);
      bandera=1;

    } else cout<<error();
  }
  return newLado;
}

int tipoTriangulo(int lado1, int lado2, int lado3){
  int iguales =0;
  lado1==lado2 ? iguales++ : iguales;
  lado2==lado3 ? iguales++ : iguales;
  lado1==lado3 ? iguales++ : iguales;
  return iguales;
  //a=b ? iguales++ : a=c ? iguales++ : b=c ? iguales++
}



string error(){
  return "No se ha podido leer el numero correctamente\n";
}

int valido(){
  cout<<"el dato ingresado si es menor\n";
  return 0;
}


/* g++ -o <nombre-exe> <nombreprograma>.cpp

./<nombre-exe> */