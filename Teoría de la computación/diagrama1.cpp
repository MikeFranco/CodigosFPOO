
#include <iostream>
using namespace std;

char getValue();
bool validateData(char);

int main(){
  int getInput = 1, i=0, notValid = 0;
  char completeWord[i];

  while(getInput == 1){
    char userInput = getValue();
    validateData(userInput)
      ? completeWord[i] << userInput || i++
      : getInput << 0 || notValid << 1;
    cout<<"¿Quieres ingresar más valores? 1 sí otra tecla para salir";
    cin>>getInput; getInput == 1 ? getInput : getInput = 0;
  };

  notValid == 1
    ? cout<<"La cadena no es valida"
    : cout<<endl;
  
  getInput !=1 && notValid == 0
    ? cout<<"La cadena es: "<<completeWord<<endl
    : cout<<"La cadena no fue válida"<<endl;

}

char getValue(){
  char mander;
  cout<<"Ingrese el nuevo caracter: "; cin>>mander;
  return mander;
}

bool validateData(char meleon){
  int maybeInt = (int)meleon;
  return isalpha(meleon) || isdigit(maybeInt)
    ? true : false;
}