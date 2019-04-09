
#include <iostream>

using namespace std;

float validateNumber(){
  float numero; 
  cin>>numero;
  while( !cin ) {
    cout << "Favor de ingresar un número. \n";
    cin.clear();
    cin.ignore();
    cin>>numero;
  }

  return numero;
}