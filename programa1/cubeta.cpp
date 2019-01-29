/*
Hecho por: Miguel Ángel Franco Peza
Secuencia: 2NM22
Título: Programa 1: vaciar una cubeta a .5lts/s
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  int altura;
  float volumen, diametro, pi=3.14159265358979323846;

  cout<<"ingresar altura: "; cin>>altura;
  cout<<"ingresar diametro: "; cin>>diametro;
  cout<<("la altura mide: ") <<altura <<(" y el radio mide: ") <<diametro/2 <<endl;
  volumen = (pi * ((diametro/2)*(diametro/2)) * altura);
  cout<<("El volumen de su cubeta es: ") <<setprecision(3) <<volumen <<(" cm^3\n");
  float vaciado = volumen;
  vaciado == 20.0
    ? cout<<"La cubeta se vacía en 40 segundos"<<endl
    : vaciado < 30
      ? cout<<"La cubeta se vacia en: " <<vaciado*2 <<" segundos\n"
      : cout<<"La cubeta se vacía en: " <<setprecision(3) <<(vaciado*2)/60 <<" minutos" <<endl;
  return 0;

}
