#include <iostream>
using namespace std;

int delay();
void menu();
float validateNumber();
float opciones(class rectangulo);

class rectangulo{
  private:
  float base, altura;
  public:
  rectangulo (float datoBase, float datoAltura) { base = datoBase; altura = datoAltura; }
  float perimetro() { return ((2*base) + (2*altura)); }
  float area() { return (base*altura); }
  void cambiarBase (float nuevaBase) { base = nuevaBase; }
  void cambiarAltura (float nuevaAltura) { altura = nuevaAltura; }
  float consultarBase() { return base; }
  float consultarAltura() { return altura; }

};

int main(){
  cout<<"\t\t\tClase de un Rectángulo\n";
  cout<<"Favor de ingresar, separados por un enter o un espacio, la altura y la base del rectángulo: ";
  rectangulo rectang(validateNumber(), validateNumber());
  cout<<"\nLa altura del rectángulo es: "<<rectang.consultarAltura();
  cout<<"\nLa base del rectángulo es: "<<rectang.consultarBase()<<endl;
  menu();
  opciones(rectang);

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
  int n = 60000;
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=i/2;j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}

void menu(){
  cout<<"\n¿Qué deseas hacer con los datos que ingresaste del rectángulo?\n";
  cout<<"1. Calcular el perímetro\n2. Calcular el área\n3. Cambiar la base\n";
  cout<<"4. Cambiar la altura\n5. Consultar la base\n6. Consultar la altura\n7. Salir\n";
  cout<<"Opcion: ";
}

float opciones(rectangulo rectang){
  int exit = 1;
  int respuesta;
  respuesta = validateNumber();
  while(exit != 0){

    switch(respuesta){
      case 1:
        cout<<"Calculando el perímetro..."<<endl;
        delay();
        cout<<"El perímetro es: "<<rectang.perimetro()<<endl;
      break;
      case 2:
        cout<<"Calculando el área...";
        delay();
        cout<<"El área es: "<<rectang.area()<<endl;
      break;
      case 3:
        cout<<"Ingresa el nuevo valor de la base: ";
        rectang.cambiarBase(validateNumber());
      break;
      case 4:
        cout<<"Ingresa el nuevo valor de la altura: ";
        rectang.cambiarAltura(validateNumber());
      break;
      case 5:
        cout<<"El nuevo valor de la base es: "<<rectang.consultarBase()<<endl;
      break;
      case 6:
        cout<<"El valor de la altura es: "<<rectang.consultarAltura()<<endl;
      break;
      case 7:
      break;
      default:
        cout<<"Favor de ingresar una opción válida";
      break;
    }
    cout<<"¿Deseas hacer alguna otra acción? (Presiona 0 para salir, cualquier otra tecla para continuar)"; cin>>exit; delay();
    if(exit != 0 ) { menu(); respuesta = validateNumber();}
  }

}