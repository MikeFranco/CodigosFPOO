/* 
Miguel Angel Franco Peza
Secuencia: 2CM32
 */

#include<iostream>
#include<stack>
using namespace std;

stack <string> pila;
int validateString(char*);
int validateStack(int, char);

int main(){
    char gramatica[10];
    cout<<"Ingrese Gramatica: ";cin>>gramatica;

    if(validateString(gramatica)) cout<<"La Gramatica es Aceptada, la pila esta vacia";
    else cout<<"La Gramatica No es Aceptada, la pila contiene variables"<<endl;
}

int validateStack(int estado , char lectura){
   if( estado == 1 && lectura == 'x' ) {pila.push("xSy"); return 1;}

   if( estado == 1 && lectura == 'y' ) {pila.pop(); return 2;}

   if(estado == 2 && lectura == 'y')  {pila.pop(); return 2;}

   return 0;
}

int validateString(char gramatica[10]){
  int i = 0;
  int estado = 1;

  while(gramatica[i]) {
    cout<<gramatica[i]<<endl;
    estado = validateStack(estado,gramatica[i]); i++;
  }
  
  if ( estado == 2 && pila.empty()) return 1;
  return 0;
}