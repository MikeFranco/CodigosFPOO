#include <iostream>

using namespace std;

int main()
{

    int arrayLength, number_to_found, searchType, is_found = 0; 
    cout<<"¿Cuantos numeros quieres ingresar?: "; cin>>arrayLength;
        cout<<"¿Que numero quieres encontrar?: "; cin>>number_to_found;
        cout<<"¿Que busqueda quieres realizar? (Busqueda lineal=0; Busqueda lineal mejorada=1): ";
        cin>>searchType;
    int numbers[arrayLength];
    
    for(int i=0; i<arrayLength; i++)
        {
                int number;
                cout<<"Captura el numero para la posicion: "<<i+1<<" "; cin>>number;
        numbers[i] = number;
        }

        for(int i=0; i<arrayLength; i++){
                if(numbers[i] == number_to_found && searchType == 0){
                         is_found = 1;
                }
                if(numbers[i] == number_to_found && searchType == 1){
                        is_found = 1;
                        break;
                }
        }
        is_found == 1
                ? cout<<"Lo encontre"
                : cout<<"No lo encontre";

}
