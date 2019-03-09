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
int validarMenor6000(int);
int validarLength(string);
int regresarCambio(int);

int main(){

  string montoUsr;
  int montoUsrInt;
  cout<<"\n\n\t\t\t==== Programa que te dará un monto en diferentes denominaciones ====\n";
  instrucciones();

  cout<<"Ingrese la cantidad que desee cambiar: "; cin>>montoUsr;
  validarCantidad(montoUsr)==1 && validarLength(montoUsr)==1
    ? montoUsrInt=cambiarStringAInt(montoUsr)
    : montoUsrInt=volverIngresarCantidad();
  
  int valido = validarMenor6000(montoUsrInt);
  valido == 1 ? cout<<"si es menor o igual a 6000" : cout<<"no es menor a 6000\n";
  regresarCambio(montoUsrInt);
  int quinientos=regresarCambio(montoUsrInt);
  cout<<"\nhay "<<quinientos<<" de $500\n";

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

int validarMenor6000(int cantidad){
  int bandera;
  cantidad <= 6000
    ? bandera=1
    : bandera=0;
  return bandera;
}

int cambiarStringAInt(string cantidad){
  int monto = atoi(cantidad.c_str());
  monto <= 6000 ? monto : monto=volverIngresarCantidad();
  //monto <= 0 ? monto=volverIngresarCantidad() : monto;
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
    cout<<"\nIngrese de nuevo la cantidad: "; cin>>montoUs;
    if(validarCantidad(montoUs)==1 && validarLength(montoUs)==1) {
      montoInt=cambiarStringAInt(montoUs);
      bandera=1;

    } else cout<<"Favor de revisar las instrucciones\n";
  }
  return montoInt;
}

int regresarCambio(int monto){
  int quinientos, cien, cincuenta, diez, cinco, uno;
  int division;
  for(int i=0; i<monto; i++){
    division=monto%500;
    if(division == 0) quinientos++;
    else break;
  }
  return quinientos;
}
