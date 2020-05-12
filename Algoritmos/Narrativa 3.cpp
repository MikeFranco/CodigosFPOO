#include <iostream>

using namespace std;

int main()
{
	
    int arrayLength, number_to_found, inicio=0;
    cout<<"¿Cuantos numeros quieres ingresar?: "; cin>>arrayLength;
	cout<<"¿Que numero quieres encontrar?: "; cin>>number_to_found;
    int final = arrayLength-1;
    int pivote = (inicio+final)/2;
    int numbers[arrayLength];
    
    for(int i=0; i<arrayLength; i++)
	{
		int number;
		cout<<"Captura el numero para la posicion: "<<i+1<<" "; cin>>number;
    	numbers[i] = number;
	}
    while(inicio <= final){
    	
    	if(numbers[pivote] < number_to_found)
    		inicio=pivote+1;
		else if(numbers[pivote] == number_to_found){
			cout<<"Se encontro en la posicion: "<<pivote+1;
			break;
		}else
			final = pivote - 1;
		pivote = (inicio+final)/2;
	}
	if(inicio>final) cout<<"No se encontro el numero";
		
}
