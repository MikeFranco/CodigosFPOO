#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

void leeArchivo();
int isFecha();
void aJuliana();

string fecha;
int n=0;
int l;
int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int diasJ[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int main(){
  leeArchivo();
  return 0;
}

void leeArchivo(){

  ifstream archivo1;
  archivo1.open("fechas.txt");

  if(archivo1 == NULL){
    cout<<"No se pudo abrir el archivo"<<endl;
  }else{
    cout<<"Se abrio correctamente el archivo: "<<endl;
  }

  while(getline(archivo1, fecha)){
    l = fecha.size();
    cout<<fecha<<" ";

    int res = isFecha();

    if(res==0){
      cout<<"No es una fecha"<<endl;
    }else if(res==1){
      cout<<endl;
      aJuliana();
    }else if(res==2){
      cout<<"aquí estaba la agustina, debe de entrar la gregoriana";
      cout<<endl;
      
    }
    cout<<endl;
    n++;
    system("pause");
  }

  archivo1.close();
}

int mes=0;
int dia=0;
int year=0;
float bis=0;

int isFecha(){
  int res=0;

  string a="";
  a += fecha[0];
  a += fecha[1];
  a += fecha[2];
  a += fecha[3];

  stringstream an(a);
  year=0;
  an >> year;

  bis = (year%4);
  //cout<<bis<<endl;

  if(l == 10){
    if(fecha[4] == 32 && fecha[5] != 32 && fecha[6] != 32){
      string m="";
      m += fecha[5];
      m += fecha[6];

      stringstream geek(m);
      mes = 0;
      geek >> mes;

      if(mes < 12){
        if(fecha[7] == 32 && fecha[8] != 32 && fecha[9] != 32){
          string d="";
          d += fecha[8];
          d += fecha[9];
          stringstream g(d);
          dia=0;
          g >> dia;

          if(mes == 1 || mes == 3 || mes == 5 || mes ==7 || mes == 8 || mes ==10 || mes==12){
            if(dia <= 31){
              res=1;
            }
          }else if(mes==4 || mes==6 || mes==9 || mes==11){
            if(dia <= 30){
              res=1;
            }
          }else if(mes==2 && bis==0){
            if(dia <= 28){
              res=1;
            }
          }else if(mes==2 && bis!=0){
            if(dia <= 29){
              res=1;
            }
          }
        }

      }
    }
  }else if(l == 8 || l == 7 || l == 6){
    if(fecha[4] == 32){
      if(fecha[5]!=32 && fecha[6]!=32 && fecha[7]!=32){
        string ds = "";
        ds += fecha[5];
        ds += fecha[6];
        ds += fecha[7];
        stringstream days(ds);
        days >> dia;

        if(dia <= 366 && bis==0){
          res = 2;
        }else if(dia <=365 && bis!=0){
          res = 2;
        }
      }
    }
  }
  return res;
}

void aJuliana()
{
  int dias=0;
  for(int i=0; i<(mes-1); i++){
    dias += meses[i];
  }
  dias += dia;

  if(mes>2 && bis==0){
    dias++;
  }

  cout<<year<<" "<<dias<<endl;
}
