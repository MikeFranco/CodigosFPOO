#include <string>
#include <iostream>
using namespace std;

int sumatoria(int);
int instrucciones();
int cero();
int cambiarStringAInt(string);
bool validarNumero(string);
int validarLength(string);

int main (){
  string numString;
  int numero;
  cout<<"\t\t== Programa que calcula la ==\n";
  cout<<"\t\t== Sumatoria de tu número  ==\n";
  instrucciones();

  cout<<"¿De qué número quieres la sumatoria?"; cin>>numString;
  validarNumero(numString)==1 && validarLength(numString)==1 ? numero = cambiarStringAInt(numString) : system("pause");
  
}

int instrucciones(){
  cout<<"Instrucciones para un buen funcionamiento del código:"<<endl;
  cout<<"\t-Ingresar números mayores a 0"<<endl;
  cout<<"\t-Ingresar un número menor a 10 digitos"<<endl;
  cout<<"\t-Ingresar solo números enteros"<<endl;

}

bool validarNumero(string lado){
  int valido=0;

  for(int i=0;i<lado.size();i++){

    if(isdigit(lado[i])) {valido=1;break;}

  }
  valido==0 ? cout<<"El valor ingresado no es un valor aritmetico\n" : cout<<"";
  return valido;

}

int cero(){
  
}


int validarLength(string lado){
  bool bandera=0;
  lado.length() < 10 ? bandera=1 : bandera=0;
  bandera == 1 ? cout<<"" : cout<<"el dato ingresado es mayor o igual a 10, favor de ingresar uno menor\n";
  return bandera;

}

/*
  Las 3 diferentes formas de hacer la subrutina de la sumatoria de un numero
  Para probar cada funcion, solo hay que descomentarla 
*/
int sumatoria (int numero){
  int suma;
  for(int i=1; i<=numero; i++){
    suma +=i;
  }
  return suma;
}

/*int sumatoria (int numero){
  return numero * (numero+1)/2;
}*/
/*
int sumatoria(int numero){
  int suma;
  if(numero==0) return 0;
  else{
    suma = numero + sumatoria(numero-1);
    return suma;
  }
} */