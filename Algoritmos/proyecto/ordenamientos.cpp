#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

struct Entrada
{
  int valor;
} entrada;

struct Entrada1
{
  int valor1;
} entrada1;

int i = 0, j = 0, k = 0, n = 0, cn = 0, salvacn;

int lista[1000000];

int LeeArchivo(string);
int guardarArchivoOrdenado(string, string);
string ordenamientoAElegir(int);
void iniciarOrdenamientos(int);

//Funciones de ordenamientos
void OrdenamientoBurbuja();
void ordenamientoBurbujaBidireccional();
void ordenamientoInsercion();
void ordenamientoCasilleros();
void ordenamientoCuentas();
void ordenamientoMezcla(int*, int, int);
void mezclarMitades(int*, int, int, int);
void ordenamientoArbolBinario();
void ordenamientoRadix();


clock_t t_ini, t_fin;

int main()
{
  int opcion;
  string cantidadNumeros;
  double secs;

  cout << "Escoge un ordenamiento\n";
  cout << "\t1. Burbuja\n";
  cout << "\t2. Burbuja balanceado\n";
  cout << "\t3. Insercion\n";
  cout << "\t4. Casilleros\n";
  cout << "\t5. Cuentas\n";
  cout << "\t6. Mezcla\n";
  cout << "\t7. Arbol binario\n";
  cout << "\t8. Radix\n";

  cout << "Ingrese el ordenamiento deseado: ";
  cin >> opcion;
  // se obtiene un string para saber el tipo de ordenamiento que se va a usar
  string nombreOrdenamiento = ordenamientoAElegir(opcion);
  cout << "¿Cuantos valores quieres ordenar? (10/100/1,000/10,000/100,000/1'000,000): ";
  cin >> cantidadNumeros;

  //Se da por hecho de que el archivo que se leerá será el que se encuentra
  //en esta carpeta
  LeeArchivo(cantidadNumeros);

  iniciarOrdenamientos(opcion);

  secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
  printf("%.16g milisegundos\n", secs * 1000.0);           // muestra el tiempo utilizado
  guardarArchivoOrdenado(cantidadNumeros, nombreOrdenamiento);
  return 0;
}

int LeeArchivo(string cantidadNumeros){
  FILE *archivo1;
  string nombrearchivo = "num" + cantidadNumeros + ".txt";
  archivo1 = fopen(nombrearchivo.c_str(), "r");

  if (archivo1 == NULL)
  {
    printf(" No se puede abrir el archivo ");
    exit(1);
  }
  else
  {
    cout << " Se abrio el archivo correctamente \n";
  }
  cn = 0;
  for (int i = 0; !feof(archivo1); i++)
  {
    fscanf(archivo1, "%i", &entrada.valor);
    lista[i] = entrada.valor;
    cn++;
  }
  salvacn = cn - 1; //se pone un -1 porque cuando se termina el for de la línea 46,
  //al pasar al guardar archivo, el contador toma en cuenta el feof
  fclose(archivo1);
  return (0);
}

int guardarArchivoOrdenado(string cantidadNumeros, string nombreOrdenamiento)
{
  FILE *archivoSalida;
  string nombreArchivoSalida = "num" + cantidadNumeros + nombreOrdenamiento + ".txt";

  archivoSalida = fopen(nombreArchivoSalida.c_str(), "w");

  if (archivoSalida == NULL)
  {
    printf(" El archivo no se abrio. ");
    exit(1);
  }
  else
  {
    printf(" Se abrio el archivo correctamente %s\n ", nombreArchivoSalida.c_str());
  }

  cn = salvacn;
  salvacn = 0;
  for (i = 0; i < cn; i++)
  {
    entrada1.valor1 = lista[i];
    fprintf(archivoSalida, "%i\n", entrada1.valor1);
    salvacn++;
  }
  fclose(archivoSalida);
  return (0);
}

string ordenamientoAElegir(int opcion)
{
  switch (opcion)
  {
  case 1:
    return "_burbuja";
    break;
  case 2:
    return "_burbuja_bidireccional";
    break;
  case 3:
    return "_insercion";
    break;
  case 4:
    return "_casilleros";
    break;
  case 5:
    return "_cuentas";
    break;
  case 6:
    return "_mezcla";
    break;
  case 7:
    return "_arbol_binario";
    break;
  case 8:
    return "_radix";
    break;
  default:
    cout << "No encontré esa opción, repita de nuevo" << endl;
    exit(1);
    break;
  }
}

void iniciarOrdenamientos(int opcion)
{
  switch (opcion)
  {
  case 1:
    t_ini = clock();
    OrdenamientoBurbuja();
    t_fin = clock();
    break;
  case 2:
    t_ini = clock();
    ordenamientoBurbujaBidireccional();
    t_fin = clock();
    break;
  case 3:
    t_ini = clock();
    ordenamientoInsercion();
    t_fin = clock();
    break;
  case 4:
    t_ini = clock();
    ordenamientoCasilleros();
    t_fin = clock();
    break;
  case 5:
    t_ini = clock();
    ordenamientoCuentas();
    t_fin = clock();
    break;
  case 6:
    cout << "Se inicia el ordenamiento mezcla" << endl;
    cn = cn-1;
    t_ini = clock();
    ordenamientoMezcla(lista, 0, cn);
    t_fin = clock();
    break;
  case 7:
    t_ini = clock();
    ordenamientoArbolBinario();
    t_fin = clock();
    break;
  case 8:
    t_ini = clock();
    ordenamientoRadix();
    t_fin = clock();
    break;
  }
}
void OrdenamientoBurbuja(){
  cout << "Se inicia el ordenamiento burbuja" << endl;
  int i, j, aux;
  for (i = 1; i < cn; i++)
  {
    for (j = 0; j < cn - i; j++)
    {
      if (lista[j] > lista[j + 1])
      {
        aux = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = aux;
      }
    }
  }
}

void ordenamientoBurbujaBidireccional(){
  cout << "Se inicia el ordenamiento burbuja bidireccional" << endl;
  int lado_izq = 0, lado_derecho, aux;
  lado_derecho = cn - 2;

  do
  {
    for (int j = lado_izq + 1; j <= lado_derecho; j++)
    {
      if (lista[j - 1] > lista[j])
      {
        aux = lista[j];
        lista[j] = lista[j - 1];
        lista[j - 1] = aux;
      }
    }
    lado_derecho -= 1;
    for (int i = lado_derecho; i > lado_izq; i--)
    {
      if (lista[i - 1] > lista[i])
      {
        aux = lista[i];
        lista[i] = lista[i - 1];
        lista[i - 1] = aux;
      }
    }
    lado_izq += 1;
  } while (lado_derecho >= lado_izq);
}

void ordenamientoInsercion()
{
  int indice;
  cout << "Se inicia el ordenamiento por insercion" << endl;
  for (int i = 0; i < cn; i++)
  {
    indice = lista[i]; //k es el indice
    j = i - 1;
    while (j >= 0 && lista[j] > indice)
    {
      lista[j + 1] = lista[j];
      j--;
    }
    lista[j + 1] = indice;
  }
}

void ordenamientoCasilleros()
{
  cout << "Se inicia el ordenamiento por casilleros" << endl;
}

void ordenamientoCuentas()
{
  cout << "Se inicia el ordenamiento por cuentas" << endl;
}

void ordenamientoMezcla(int *a, int low, int high){
  int mid;

  if (low < high)
  {
    mid = (low + high) / 2;
    // Parte a la mitad el arreglo
    ordenamientoMezcla(a, low, mid);
    ordenamientoMezcla(a, mid + 1, high);

    //Mezcla los arreglos divididos
    mezclarMitades(a, low, high, mid);
  }
}

void mezclarMitades(int *a, int low, int high, int mid){
  //Aquí ya vienen los 2 arreglos, de la mitad hacia abajo y
  //la mitad hacia arriba, ordenados
  int i, j, k, temp[high - low + 1];
  i = low;
  k = 0;
  j = mid + 1;
  //Se mezclan las dos mitades en el arreglo temp
  while (i <= mid && j <= high)
  {
    if (a[i] < a[j])
    {
      temp[k] = a[i];
      k++;
      i++;
    }
    else
    {
      temp[k] = a[j];
      k++;
      j++;
    }
  }

  // Se ingresan todos los valores faltantes desde i hasta la mitad en temp
  while (i <= mid)
  {
    temp[k] = a[i];
    k++;
    i++;
  }

  // Insert all the remaining values from j to high into temp[].
  // Se ingresan todos los valores faltantes desde j hasta el final en temp
  while (j <= high)
  {
    temp[k] = a[j];
    k++;
    j++;
  }

  // Asigna los números ordenados al arreglo original
  for (i = low; i <= high; i++)
  {
    a[i] = temp[i - low];
  }
}

void ordenamientoArbolBinario()
{
  cout << "Se inicia el ordenamiento arbol binario" << endl;
}

void ordenamientoRadix()
{
  cout << "Se inicia el ordenamiento radix" << endl;
}
