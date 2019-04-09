#include <iostream>
using namespace std;

int delay();
void menu();
float validateNumber();
float opciones(int);

class rectangulo{
  private:
  float base;
  float altura;
  public:
  rectangulo (float datoBase, float datoAltura) { base = datoBase; altura = datoAltura; }
  float perimetro() { base+base+altura+altura; }
  float area() { base * altura; }
  void cambiarBase (float nuevaBase) { base = nuevaBase; }
  void cambiarAltura (float nuevaAltura){ altura = nuevaAltura; }
  float consultarBase() { return base; }
  float consultarAltura() { return altura; }

};

int main(){
  int ans;
  cout<<"\t\t\tClase de un Rectángulo\n";
  cout<<"Favor de ingresar, separados por un enter o un espacio, la altura y la base del rectángulo: ";
  rectangulo aver(validateNumber(), validateNumber());
  cout<<"\nLa altura del rectángulo es: "<<aver.consultarAltura();
  cout<<"\nLa base del rectángulo es: "<<aver.consultarBase()<<endl<<endl;
  cout<<aver.area();
  /* menu();
  ans = validateNumber();
  opciones(ans);
  switch(ans){
    case 1:
      cout<<"El perímetro es: "<<rectangulo.perimetro()<<endl;
    break;

  } */
  /* case 2:
    cout<<rectangulo.area(); */
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
  cout<<"Opcion: ";
}

float opciones(int respuesta){

  //float per = rectangulo.perimetro();

}