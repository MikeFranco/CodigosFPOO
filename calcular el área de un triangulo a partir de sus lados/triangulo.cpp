/*
Hecho por: Miguel Angel Franco
Secuencia: 2NM22
Título: Obtener el área de un triángulo a partir de sus 3 lados
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){

  float lado1, lado2, lado3, area, s;
  cout<<"Ingresar el lado 1: "; cin>>lado1;
  cout<<"Ingresar el lado 2: "; cin>>lado2;
  cout<<"Ingresar el lado 3: "; cin>>lado3;
  s = (lado1+lado2+lado3)/2;
  cout<<"el valor de semiperimetro es: " <<setprecision(3) <<s <<endl;
  float aux = (s*(s-lado1)*(s-lado2)*(s-lado3));
  area = sqrt(aux);
  area <= 0 || isnan(area)
    ? cout<<"el area es un numero imaginario "<<endl
    : cout<<"el area del triangulo es: " <<setprecision(3) <<area <<endl;
  return 1;

}