#include <iostream>
using namespace std;

int delay();
void menu();
float validateNumber();

class rectangulo{
  private:
  float base;
  float altura;
  public:
  rectangulo (float datoBase, float datoAltura) { base = datoBase; altura = datoAltura; }
  float perimetro() { (2*base) + (2*altura); }
  float area() { base * altura; }
  void cambiarBase (float nuevaBase) { base = nuevaBase; }
  void cambiarAltura (float nuevaAltura){ altura = nuevaAltura; }
  float consultarBase() { return base; }
  float consultarAltura() { return altura; }

};

int main(){
  cout<<"\t\t\tClase de un Rectángulo\n";
  rectangulo rect();
  cout<<"Favor de ingresar la base del rectángulo: ";
  menu();
}


float validateNumber(){
  float numero;
  cin>>numero;
  while( !cin ) {
    cout << "Favor de ingresar un número. \n";
    cin.clear();
    cin.ignore();
    cin>>numero;
  }

  return numero;
}

int delay () {
  int n = 700000;
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=i/2;j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}

void menu(){
  cout<<"1";

}