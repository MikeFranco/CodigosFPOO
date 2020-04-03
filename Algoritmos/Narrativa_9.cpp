#include<iostream>

using namespace std;

int main(){
	int numero,unidades,decenas,centenas,millar; 
	
	cout<<"Digite un numero: "; 
	cin>>numero; 
	
	unidades = numero % 10; numero /= 10; 
	decenas = numero % 10; numero /= 10; 
	centenas = numero % 10; numero /= 10; 
	millar = numero % 10 ; numero /= 10; 
	
	switch(millar){

		case 1: cout<<"1\n";break;
		case 2: cout<<"2\n";break;
		case 3: cout<<"3\n";break;
		case 4: cout<<"4\n";break;
		case 5: cout<<"5\n";break;
		case 6: cout<<"6\n";break;
		case 7: cout<<"7\n";break;
		case 8: cout<<"8\n";break;
		case 9: cout<<"9\n";break;
	}
	
	switch(centenas){
		case 1: cout<<"1\n";break;
		case 2: cout<<"2\n";break;
		case 3: cout<<"3\n";break;
		case 4: cout<<"4\n";break;
		case 5: cout<<"5\n";break;
		case 6: cout<<"6\n";break;
		case 7: cout<<"7\n";break;
		case 8: cout<<"8\n";break;
		case 9: cout<<"9\n";break;

	}
	
	switch(decenas){
		case 1: cout<<"1\n";break;
		case 2: cout<<"2\n";break;
		case 3: cout<<"3\n";break;
		case 4: cout<<"4\n";break;
		case 5: cout<<"5\n";break;
		case 6: cout<<"6\n";break;
		case 7: cout<<"7\n";break;
		case 8: cout<<"8\n";break;
		case 9: cout<<"9\n";break;
	}
	
	switch(unidades){
		case 1: cout<<"1\n";break;
		case 2: cout<<"2\n";break;
		case 3: cout<<"3\n";break;
		case 4: cout<<"4\n";break;
		case 5: cout<<"5\n";break;
		case 6: cout<<"6\n";break;
		case 7: cout<<"7\n";break;
		case 8: cout<<"8\n";break;
		case 9: cout<<"9\n";break;
	}
	return 0;
}
