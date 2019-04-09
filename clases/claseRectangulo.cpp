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
  cout<<"Favor de ingresar, separados por un enter o un espacio, la altura y la base del rectángulo: ";
  rectangulo rectangulo(validateNumber(), validateNumber());
  cout<<"La altura del rectángulo es: "<<rectangulo.consultarAltura()<<endl;
  cout<<"La base del rectángulo es: "<<rectangulo.consultarBase()<<endl;
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
  cout<<"¿Qué deseas hacer con los datos que ingresaste del rectángulo?\n";
  cout<<"1. Calcular el perímetro\n2. Calcular el área\n3. Cambiar la base\n";
  cout<<"4. Cambiar la altura\n5. Consultar la base\n6. Consultar la altura\n";

}