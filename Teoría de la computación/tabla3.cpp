#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    int estado=1, i=0;
    string palabra;
    cout<<"Ingrese la notificación científica: "; cin>>palabra;
    while(palabra[i]!='\0'){
        if (isdigit(palabra[i])){estado=7;}
        else if (palabra[i]=='E'){estado=5;}
        else if (palabra[i]=='*'){estado=3;}
        else if (palabra[i]=='+'){estado=6;}
        else if (palabra[i]=='-'){estado=6;}
        i++;
    }

    if (estado==3){cout << "No Aceptado";}
    if (estado==5){cout << "No Aceptado";}
    if (estado==6){cout << "No Aceptado";}
    else if (estado==7){cout << "Aceptado";}
    else {cout << "Error, la notación ingresada no es válida";}
}