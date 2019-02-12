/*
Hecho por: Miguel Ángel Franco Peza
Secuencia: 2NM22
Título: Programa 1: vaciar una cubeta a .5lts/s
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  float altura, volumen, diametro, pi=3.14159265358979323846;

  cout<<"ingresar altura en metros: "; cin>>altura;
  cout<<"ingresar diametro en metros: "; cin>>diametro;
  cout<<("la altura mide: ") <<altura <<" metros" <<(" y el radio mide: ") <<diametro/2 <<" metros" <<endl;
  volumen = (pi * ((diametro/2)*(diametro/2)) * altura);
  cout<<("El volumen de su cubeta es: ") <<setprecision(4) <<volumen <<(" m^3\n");
  int litros = volumen*1000;
  cout<<"la cubeta tiene: " <<litros <<" litros" <<endl;
  litros == 20.0
    ? cout<<"La cubeta se vacía en 40 segundos"<<endl
    : litros < 30
      ? cout<<"La cubeta se vacia en: " <<litros*2 <<" segundos\n"
      : cout<<"La cubeta se vacía en: " <<setprecision(3) <<(litros*2)/60 <<" minutos" <<endl;
  return 0;

}
