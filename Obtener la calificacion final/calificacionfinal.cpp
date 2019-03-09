#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

int instrucciones();
bool validarCalif(string);
float volverAIngresarCalificacion();
float cambiarStringAInt(string);
int validarLength(string);
float calificacionFinal(float, float, float);


int main(){
  string calif1string, calif2string, calif3string;
  float calif1num, calif2num, calif3num;
  system("clear");
  cout<<"\n\t\t¿Cuál es tu calificación final del semestre?\n\n";
  instrucciones();

  cout<<"¿Cuál fue tu calificación del primer parcial? "; cin>>calif1string;
  validarCalif(calif1string)==1 && validarLength(calif1string)==1 ? calif1num=cambiarStringAInt(calif1string) : calif1num=volverAIngresarCalificacion();

  cout<<"\n¿Cuál fue tu calificación del segundo parcial? "; cin>>calif2string;
  validarCalif(calif2string)==1 && validarLength(calif2string)==1 ? calif2num=cambiarStringAInt(calif2string) : calif2num=volverAIngresarCalificacion();

  cout<<"\n¿Cuál fue tu calficación del tercer parcial? "; cin>>calif3string;
  validarCalif(calif3string)==1 && validarLength(calif3string)==1 ? calif3num=cambiarStringAInt(calif3string) : calif3num=volverAIngresarCalificacion();

  system ("clear");
  cout<<"\n\n\t\t\tCalificacion del primer parcial "<<calif1num<<endl;
  cout<<"\n\n\t\t\tCalificacion del segundo  parcial "<<calif2num<<endl;
  cout<<"\n\n\t\t\tCalificacion del tercer parcial "<<calif3num<<endl;

  float califFinal = calificacionFinal(calif1num, calif2num, calif3num);
  califFinal < 6
    ? cout<<"\nHaz reprobado el semestre con "<<califFinal<<" :( échale ganas en el recurse\n\n"
    : cout<<"\n¡Felicidades, pasaste el semestre con "<<califFinal<<" :D\n\n";

}

int instrucciones(){
  cout<<"\n\t Para un buen funcionamiento del programa favor de:\n";
  cout<<"--Ingresar la calificación únicamente con 2 decimales\n";
  cout<<"--Ingresar únicamente números, de lo contrario, volver a ingresar la calificacion\n\n\n";
}

bool validarCalif(string calificacion){

  int valido=0;

  for(int i=0;i<calificacion.size();i++){
    if(isdigit(calificacion[i])) {
      valido=1; break;
      if(calificacion=="."){
        valido=1; break;
      }
    }
  }
  valido==0 ? cout<<"El valor ingresado no es un valor aritmetico\n" : cout<<"";
  return valido;

}

int validarLength(string calificacion){
  bool bandera=0;
  calificacion.length() <=3 ? bandera=1 : bandera=0;
  bandera == 1 ? cout<<"" : cout<<"La calificación no puede tener más de 2 digitos, favor de ingresar uno menor\n";
  return bandera;

}

float cambiarStringAInt(string calificacion){
  float newCalif = atof(calificacion.c_str());
  newCalif >= 11 || newCalif==0 ? newCalif=volverAIngresarCalificacion() : newCalif;
  return newCalif;

}

float volverAIngresarCalificacion(){
  cout<<"La calificacion no puede ser leída correctamente\n";
  string calif;
  float calificacion;
  bool bandera = 0;
  while(bandera == 0){
    cout<<"\nIngrese de nuevo la calificacion: "; cin>>calif;

    if(validarCalif(calif)==1 && validarLength(calif)==1) {
      calificacion=cambiarStringAInt(calif);
      bandera=1;

    } else cout<<"Favor de revisar las instrucciones\n";
  }
  return calificacion;
}

float calificacionFinal(float calif1, float calif2, float calif3){
  float mayor = calif1;
  mayor < calif2 ? mayor = calif2 : mayor;
  mayor < calif3 ? mayor = calif3 : mayor;
  return mayor;

}