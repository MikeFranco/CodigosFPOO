#include <typeinfo>
#include <iostream>
#include <string>

using namespace std;

bool validateLetter(char);
bool validateNumber(char);
bool error();
bool stateIn2();
bool actualState(int);

int main(){
  int state = 1; string word;
  cout<<"Ingrese la cadena de caracteres que quiera validar: "; cin>>word; cout<<word<<endl;

  for(int i=0; i<word.size(); i++){
    cout<<"Estado Actual: "<<state<<endl;
    state == 1
      ? validateLetter(word[i])
        ? state = 3
        : validateNumber(word[i])
          ? state = 2
          : state == 3
            ? validateLetter(word[i]) || validateNumber(word[i])
              ? state = 3
              : error()
            : state == 2
                ? stateIn2()
                : error()
      : error();

  }
  cout<<"Así acaba el estado:"<<state<<endl;

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

bool stateIn2(){
  cout<<"El estado es 2 y no se puede cambiar de estado"<<endl;
  return false;
}

bool actualState(int newState){
  cout<<"El estado actual es: "<< newState <<endl;
  return true;
}