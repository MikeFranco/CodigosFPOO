/* Autores: Alfaro Flores Luis Fernando
            Mart�nez Rodriguez Jos� Alejandro
                    "Ordenamiento por cuentas"
            Los datos de entrada se han tomado de un archivo guardado en el mismo directorio que el programa.
            La nomenclatura para la cantidad de n�meros se encuentra en el reporte correspondiente*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <string>
#define MAXNUM 1000001
#define MAXSIZE 5001
using namespace std;

struct Registro
{
    int valor;
    int valor1;
} entrada, entrada1;

string nombrearchivo, nombrearchivo1;
int cn,salvacn,valorsalva,si,rango, minimo,mini,maxi;
int a[MAXNUM];
double t_fin,t_ini,secs;


int LeerArchivo()
{

    FILE *archivo1;
    string valorInt;
    printf("\n Teclea el nombre del archivo de entrada: ");
    cin>>nombrearchivo;
    nombrearchivo+=".txt";
    archivo1 = fopen(nombrearchivo.c_str(), "r");
    if(archivo1==NULL)
    {
        printf("No se puede abrir el archivo");
        exit(1);
    }
    else
    {
        printf("Se abrio el archivo correctamente%s\n",nombrearchivo.c_str());
    }
    cn=0;
    for(int i=0; !feof(archivo1); i++)
    {
        fscanf(archivo1,"%i",&entrada.valor);
        a[i]=entrada.valor;
        cn++;
    }
    printf("Valor de n es: %i\n",cn);
    salvacn=cn;
    fclose(archivo1);
    return(0);
}

int GrabaArchivo(int a[])
{
    FILE *archivo2;


    printf("\n Teclea el nombre del archivo de salida:  ");
    cin>>nombrearchivo1;
    nombrearchivo1+=".txt";
    archivo2=fopen(nombrearchivo1.c_str(),"w");
    if(archivo2==NULL)
    {
        printf("No se puede abrir el archivo");
        exit(1);
    }
    else
    {
        printf("Se abrio el archivo correctamente  %s \n",nombrearchivo1.c_str());
    }
    valorsalva=a[0];
    cn=salvacn;
    for(int i=1; i<=cn-1; i++)
    {
        if(valorsalva!=a[i])
        {
            entrada1.valor1=valorsalva;
            valorsalva=a[i];
            fprintf(archivo2,"%i\n",entrada1.valor1);
        }
    }
    printf("valor de n es: %i\n",cn);
    fclose(archivo2);
    string valorInt;

    return(0);
}


void CounterSort(int a[], int cn, int rango, int mini)
{
	int i, j = 0, counter[rango] = {0};
	// Counting the number occurrence of each element.
	for(i=0; i<cn; i++)
		counter[a[i]-mini]++;

	i=0;
	// placing the elements back into array.
	while(i < rango)
	{
		flag:
		a[j] = mini+i;
		j++;
		counter[i]--;

		// place the same element until its counter is zero.
		if(counter[i] > 0)
		goto flag;

		i++;
	}
}



main(){
    si=1;
    do{
        LeerArchivo();
        t_ini=clock();
        cout<<"\nEnter the loweofr and upper limit of the data to be entered: ";
        cin>>mini>>maxi;
	    rango=maxi-mini;
        CounterSort(a,cn,rango,mini);
        t_fin=clock();
        secs=(double)(t_fin-t_ini)/(double)CLOCKS_PER_SEC;
        printf("%.16g milisegundos\n",secs*1000.0);
        system("pause");
        GrabaArchivo(a);
        printf("Deseas probar con otro archivo(Si=1,NO=0)");
        cin>>si;
    }
    while(si==1);
    return(0);
}
