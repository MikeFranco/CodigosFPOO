//Adaptado de https://stackoverflow.com/questions/19611198/finding-square-root-without-using-sqrt-function
//Miguel Ángel Franco Peza
//Secuencia: 2NM22
#include <math.h>
#include <iostream>

using namespace std;

double raizcuadrada(double x) {
    if (x <= 0) return -1;

    int exponente = 0;
    x = frexp(x, &exponente);
    if (exponente & 1) {
        exponente--;
        x *= 2;
    }
    double y = (1+x)/2;
    double z = 0;
    while (y != z) {
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exponente/2);
}

int main(){
  double x = raizcuadrada(90);
  cout<<"La raiz de tu numero es: "<<x<<endl<<endl;
}