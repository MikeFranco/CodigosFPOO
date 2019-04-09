/*Clase del cuadrado*/
#include <iostream>

using namespace std;
float validateNumber();

class cuadrado {
  private: float lado;
  public: 
  cuadrado (float dato) { lado = dato; }
  float perimetro () { return lado *4.0; }
  float area () { return lado * lado; }
  void cambiarLado (float nuevoLado) { lado = nuevoLado; }
  float consultarLado () { return lado; }
};

main(void){
  float aux;
  cout<<"Este programa crea una clase cuadrado. \n";
  cout<<"Teclee el valor del lado: ";
  cuadrado cuadro(validateNumber()); //se crea el objeto
  cout<<"El perímetro es: "<< cuadro.perimetro()<<endl;
  cout<<"El área es: "<< cuadro.area()<<endl;

};

float validateNumber(){
  float lado; 
  cin>>lado;
  while( !cin ) {
    cout << "Favor de ingresar un número. \n";
    cin.clear();
    cin.ignore();
    cin>>lado;
  }

  return lado;
}