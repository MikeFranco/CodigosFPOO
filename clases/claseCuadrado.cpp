/*Clase del cuadrado*/
#include <iostream>
#include <math.h>
using namespace std;
float validateNumber();
int delay();

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
  delay();
  cout<<"El perímetro es: "<< cuadro.perimetro()<<endl;
  delay();
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

int delay () {
  int n = 700000;
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}