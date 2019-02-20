/*
  Autor: Miguel Angel Franco Peza
  Secuencia: 2NM22
*/
//el cero no es valido, por qué?
//checar los negativos

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int instrucciones();
bool validarLado(string);
int tipoTriangulo(int, int, int);
int volverIngresarLado();
int cambiarStringAInt(string);
int validarTriangulo(int, int, int);
int validarLength(string);
int valido();

int main(){

  string lado1, lado2, lado3;
  int newLado1, newLado2, newLado3;
  cout<<"\n\n\t\t\t==== Programa que dice tu tipo de triangulo segun sus lados ====\n";
  instrucciones();

  cout<<"Ingrese el lado 1: "; cin>>lado1;
  if(validarLado(lado1)==1 && validarLength(lado1)==1) newLado1=cambiarStringAInt(lado1); else newLado1=volverIngresarLado();
  //if(newLado1<=0) newLado1=volverIngresarLado();

  cout<<"\nIngrese el lado 2: "; cin>>lado2;
  if(validarLado(lado2)==1 && validarLength(lado2)==1) newLado2=cambiarStringAInt(lado2); else newLado2=volverIngresarLado();

  cout<<"\nIngrese el lado 3: "; cin>>lado3;
  if(validarLado(lado2)==1 && validarLength(lado3)==1) newLado3=cambiarStringAInt(lado3); else newLado3=volverIngresarLado();

  int valido = validarTriangulo(newLado1, newLado2, newLado3);
  int verTipoTriangulo = tipoTriangulo(newLado1, newLado2, newLado3);

  verTipoTriangulo==3 && valido==1
    ? cout<<"\nTu triangulo es un equilatero\n\n"
    : verTipoTriangulo==1 && valido==1
      ? cout<<"\nTu triangulo es un isosceles\n\n"
      : verTipoTriangulo==0 && valido==1
        ? cout<<"\nTu triangulo es un escaleno\n\n"
        : cout<<"No es un triangulo"<<endl;
}

int instrucciones(){
  cout<<"\nInstrucciones para un buen funcionamiento del programa:\n";
  cout<<"\t\t*Ingresar un numero menor a 10 digitos\n";
  cout<<"\t\t*Ingresar unicamente numeros\n\n";
}

bool validarLado(string lado){
  int valido=0;

  for(int i=0;i<lado.size();i++){
    if(isdigit(lado[i])) {return valido=1;break;}

  }
  //return valido
  //checar la validacion para regresar un 1
  valido==0 ? cout<<"El valor ingresado no es un valor aritmetico\n" : cout<<"";
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
  newLado <= 0 ? volverIngresarLado() : newLado;
  //(newLado <= 0) ? cout<<"El dato ingresado no es valido\n" : cout<<"\tValor del numero ingresado->"<<newLado<<endl;
  return newLado;
}

int validarLength(string lado){
  bool bandera=0;
  lado.length() < 10 ? bandera=1 : bandera=0;
  bandera == 1 ? cout<<"" : cout<<"el dato ingresado es mayor o igual a 10, favor de ingresar uno menor\n";
  return bandera;
}

int volverIngresarLado(){
  string lado;
  int newLado;
  bool bandera = 0;
  while(bandera == 0){
    cout<<"\nIngrese de nuevo el lado: "; cin>>lado;
    if(validarLado(lado)==1 && validarLength(lado)==1) {
      newLado=cambiarStringAInt(lado);
      newLado<=0 ? volverIngresarLado(): bandera=1;

    } else cout<<"Favor de revisar las instrucciones\n";
  }
  return newLado;
}

int tipoTriangulo(int lado1, int lado2, int lado3){
  int iguales =0;
  lado1==lado2 ? iguales++ : iguales;
  lado2==lado3 ? iguales++ : iguales;
  lado1==lado3 ? iguales++ : iguales;
  return iguales;

}

int valido(){
  cout<<"el dato ingresado si es menor\n";
  return 0;
}
