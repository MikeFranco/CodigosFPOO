#include <typeinfo>
#include <iostream>
#include <string>

using namespace std;

bool validateLetter(char);
bool validateNumber(char);
bool error();
bool actualState(int);

int main(){
  int state = 0; string word;
  cout<<"Ingrese la cadena de caracteres que quiera validar: "; cin>>word; cout<<word<<endl;

  for(int i=0; i<word.size(); i++){
    cout<<"Estado Actual: "<<state<<endl;
    switch(state){
      case 0:
        return validateLetter(word[i])
          ? actualState(1) && state = 1
          : validateNumber(word[i])
          ? actualState(2) && state = 2
          : error();
      break;
      case 1:
        return validateLetter(word[i]) || validateNumber(word[i])
          ? actualState(1) && state = 1
          : error();
      break;
      case 2:
        actualState(2);
        error();
        i = word.size(); break;
    }

  }

}

bool validateLetter(char letter) { return isalpha(letter) ? true : false; }

bool validateNumber(char number) {
  int intNumber = (int)number; 
  return isdigit(intNumber) ? true : false;
}

bool error(){
  cout<<"El caracter no es válido"<<endl;
  return false;
}

bool actualState(int newState){
  cout<<"El estado actual es: "<< newState <<endl;
  return true;
}