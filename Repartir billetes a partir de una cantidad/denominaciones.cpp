/*
  Autor: Miguel Angel Franco Peza
  Secuencia: 2NM22
*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int instrucciones();
bool validarCantidad(string);
int volverIngresarCantidad();
int cambiarStringAInt(string);
int validarLength(string);
int regresarCambio(int);
int delay(int);

int main(){

  string montoUsr;
  int montoUsrInt;
  cout<<"\n\n\t\t\t==== Programa que te dará un monto en diferentes denominaciones ====\n";
  instrucciones();

  cout<<"Ingrese la cantidad que desee cambiar: "; cin>>montoUsr;
  validarCantidad(montoUsr)==1 && validarLength(montoUsr)==1
    ? montoUsrInt=cambiarStringAInt(montoUsr)
    : montoUsrInt=volverIngresarCantidad();

  cout<<"Calculando tu cambio, un momento por favor.."<<endl;
  delay(700000);
  regresarCambio(montoUsrInt);

}

int instrucciones(){
  cout<<"\nInstrucciones para un buen funcionamiento del programa:\n";
  cout<<"\t\t*Ingresar una cantidad menor a $6,000\n";
  cout<<"\t\t*Ingresar unicamente numeros\n\n";

}

bool validarCantidad(string lado){
  int valido=0;

  for(int i=0;i<lado.size();i++){

    if(isdigit(lado[i])) {valido=1;break;}

  }
  valido==0 ? cout<<"El valor ingresado no es un valor aritmetico\n" : cout<<"";
  return valido;

}

int cambiarStringAInt(string cantidad){
  int monto = atoi(cantidad.c_str());
  monto <= 6000 ? monto : monto=volverIngresarCantidad();
  return monto;

}

int validarLength(string cantidad){
  bool bandera=0;
  cantidad.length() < 5 ? bandera=1 : bandera=0;
  bandera == 1 ? cout<<"" : cout<<"el dato ingresado es mayor o igual a 4, favor de ingresar uno menor\n";
  return bandera;

}

int volverIngresarCantidad(){
  string montoUs;
  int montoInt;
  bool bandera = 0;
  while(bandera == 0){
    cout<<"\nLa cantidad no pudo ser leída correctamente";
    cout<<"\nIngrese de nuevo la cantidad: "; cin>>montoUs;
    if(validarCantidad(montoUs)==1 && validarLength(montoUs)==1) {
      montoInt=cambiarStringAInt(montoUs);
      bandera=1;

    } else cout<<"Favor de revisar las instrucciones\n";
  }
  return montoInt;
}

int regresarCambio(int monto){

  int denominacion[] = {500, 100, 50, 10, 5, 1};
  int resultado;
  for (int i = 0; monto > 0; i++)
    if ((resultado = monto / denominacion[i]) > 0){
      monto >= 50
      ? cout<<"Billetes de "<<denominacion[i]<<": "<<resultado<<endl
      : cout<<"Monedas de "<<denominacion[i]<<": "<<resultado<<endl;
      monto %= denominacion[i];
    }

}

int delay (int n) {
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}