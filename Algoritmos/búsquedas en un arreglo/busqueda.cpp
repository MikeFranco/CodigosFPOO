#include <iostream>
#include <string>
using namespace std;

int main() {
  int cantidadArray = 0;
  cout<<"¿Cuantos valores quieres ingresar?"; cin>>cantidadArray; cout<<cantidadArray;
  string array[cantidadArray];

  for(int i = 0; i < sizeof(array); i++){
    string valor = "";
    cout<<"Ingresa el valor para el index: "<< i <<endl; cin>>valor;
    array[i] = valor;
  }

  cout<<array;

}