#include <iostream>
#include <sstream>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

char cadena[30], simboloAceptado[]="E+.-";
int estado=1, CaractEsp=0, finCadena=0, i=0;
int identLetras=0, identNumeros=0;

//Funcion para convertir int a string
string itoa(int num)
{
  stringstream s;
  s<<num;
  return s.str();
}

//Tabla
struct analizadorLexico{
  string EstadoTabla;
  char EntradaTabla;
};
analizadorLexico *datosTabla = new analizadorLexico[30];

int main(){
  cout<<"Ingrese la cadena: ";
  cin>>cadena;
  finCadena=strlen(cadena); // SABER LA LONGITUD DE LA CADENA    
  
  for(i=0; i<finCadena; i++){    
    switch(estado){
      case 1:
        //identificar si es un numero
        identNumeros = isdigit(cadena[i]);
        if(identNumeros>0){
          estado = 3;
          datosTabla[i].EstadoTabla = itoa(estado); 
          datosTabla[i].EntradaTabla = cadena[i]; 
          CaractEsp=1; 
        }
        //identificar si es un simbolo aceptado
        for(int j=0; j<4; j++){
          if(cadena[i]==simboloAceptado[j]){
            estado = 2;
            datosTabla[i].EstadoTabla = itoa(estado); 
            datosTabla[i].EntradaTabla = cadena[i]; 
            CaractEsp=1; 
          }
        }
        if(CaractEsp==0){
          estado=2;
        }
      break;
      case 2: 
        if(i == 0){
          datosTabla[i].EstadoTabla = "error";
          datosTabla[i].EntradaTabla = cadena[i]; 
        } else if(i != 0){
          datosTabla[i].EstadoTabla = "error";
          datosTabla[i].EntradaTabla = cadena[i]; 
        }
      break;
      case 3: 
        CaractEsp=0;
        //identificar si es un numero
        identNumeros = isdigit(cadena[i]);
        if(identNumeros>0){
          estado = 3;
          datosTabla[i].EstadoTabla = itoa(estado); 
          datosTabla[i].EntradaTabla = cadena[i]; 
          CaractEsp=1; 
        }
        //identificar si es un simbolo aceptado
        for(int j=0; j<4; j++){
          if(cadena[i]==simboloAceptado[j]){
            estado = 3;
            datosTabla[i].EstadoTabla = itoa(estado); 
            datosTabla[i].EntradaTabla = cadena[i]; 
            CaractEsp=1; 
          }
        }
        if(CaractEsp==0){
          estado=2;
        }
      break;
    }
  }
  cout<<"\nEstado   Entrada"<<endl;
  for(i=0; i<finCadena; i++){
    cout<<datosTabla[i].EstadoTabla<<"\t "<<datosTabla[i].EntradaTabla<<endl;
  }
  if(estado == 3){
    cout<<"\nCadena Aceptada"<<endl;
  }else{
    cout<<"\nCadena NO aceptada"<<endl;
  }
  return 0;
}