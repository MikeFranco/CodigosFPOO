/*
  Elaborado por: Miguel Angel Franco Peza
  Secuencia: 2NM22
*/

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

int sumatoria(int);
int instrucciones();
int cambiarStringAInt(string);
bool validarNumero(string);
int validarLength(string);
int volverIngresarNumero();
int delay(int);

int main (){
  string numString;
  int numero;
  cout<<"\t\t== Programa que calcula la ==\n\t\t== Sumatoria de tu número  ==\n";
  instrucciones();

  cout<<"¿De qué número quieres la sumatoria? "; cin>>numString;
  validarNumero(numString)==1 && validarLength(numString)==1 ? numero = cambiarStringAInt(numString) : numero = -1;
  cout<<"\nRevisando datos, un momento por favor...\n";
  delay(700000);
  numero == -1
    ? cout<<"No ingresaste numeros, favor de ingresar numeros\n"
    : cout<<"La sumatoria de tu numero es: "<<sumatoria(numero)<<endl<<endl;

}

int instrucciones(){
  cout<<"\nInstrucciones para un buen funcionamiento del código:"<<endl;
  cout<<"\t-Ingresar números mayores a 0"<<endl;
  cout<<"\t-Ingresar un número menor a 6 digitos"<<endl;
  cout<<"\t-Ingresar solo números enteros"<<endl;
  cout<<"\t-Si ingresas primero números y luego letras, se podrá leer sin problema tu sumatoria\n"<<endl;

}

bool validarNumero(string lado){
  int valido=0;

  for(int i=0;i<lado.size();i++){

    if(isdigit(lado[i])) {valido=1;break;}

  }
  return valido;

}

int cambiarStringAInt(string numString){
  int numero = atoi(numString.c_str());
  numero <= 0 ? numero=volverIngresarNumero() : numero;
  return numero;

}

int volverIngresarNumero(){
  string numStr;
  int num;
  bool bandera = 0;
  while(bandera == 0){
    cout<<"\nIngrese de nuevo el numero: "; cin>>numStr;
    if(validarNumero(numStr)==1 && validarLength(numStr)==1) {
      num=cambiarStringAInt(numStr);
      bandera=1;

    } else cout<<"Favor de revisar las instrucciones\n";
  }
  return num;

}

int validarLength(string num){
  bool bandera=0;
  num.length() < 6 ? bandera=1 : bandera=0;
  bandera == 1 ? cout<<"" : cout<<"el dato ingresado es mayor o igual a 6, favor de ingresar uno menor\n";
  return bandera;

}

int delay (int n) {
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}

/*
  Las 3 diferentes formas de hacer la subrutina de la sumatoria de un numero
  Para probar cada funcion, solo hay que descomentarla 
*/

int sumatoria (int numero){
  return numero * (numero+1)/2;

}

/*int sumatoria (int numero){
  int suma=0;
  for(int i=1; i<=numero; i++) suma +=i;
  return suma;

}*/


/*int sumatoria(int numero){
  int suma;
  return 0
    ? numero == 0
    : suma = numero + sumatoria(numero-1);

}*/
