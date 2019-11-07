#include<iostream>
using namespace std;

int main(void){
	int estado = 1, opcion=1, contador=1;
	char mander, cadenaCompleta[100];

	cout<<"Introduce un valor: "; cin>>mander; cout<<endl;
	if(isalpha(mander)){
		cadenaCompleta[0]=mander;
		cout<<"¿Quieres ingresar mas valores? 1 para si y cualquier tecla para no: "; cin>>opcion;
		cout<<endl;
		cin.ignore();
		while(opcion==1){
			cout<<"Introduce un valor: "; cin>> cadenaCompleta[contador]; cout<<endl;
			cin.ignore();
			contador++;
			cout<<"¿Quieres ingresar mas valores? 1 para si y cualquier tecla para no: "; cin>>opcion;
			cout<<endl;
		}
		cout<<"la cadena es "<<cadenaCompleta<<endl;
	}else{
		cout<<"No se acepta la cadena";
	}
	return 0;
}