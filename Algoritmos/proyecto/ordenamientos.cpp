#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector> 
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
int arregloauxiliar[1000000];
string cantidadNumeros;

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
void ordenamientoMezcla(int *, int, int);
void mezclarMitades(int *, int, int, int);
void ordenamientoArbolBinario();
void ordenamientoRadix();

clock_t t_ini, t_fin;

int main()
{
  int opcion;
  double secs;

  cout << "Escoge un ordenamiento\n";
  cout << "\t1. Burbuja\n";
  cout << "\t2. Burbuja balanceado\n";
  cout << "\t3. Insercion\n";
  cout << "\t4. Casilleros\n";
  cout << "\t5. Cuentas\n"; //********
  cout << "\t6. Mezcla\n";
  cout << "\t7. Radix\n"; //********
  cout << "Nota: el ordenamiento de arbol binario está en un archivo diferente" << endl;

  cout << "Ingrese el ordenamiento deseado: ";
  cin >> opcion;
  // se obtiene un string para saber el tipo de ordenamiento que se va a usar
  string nombreOrdenamiento = ordenamientoAElegir(opcion);
  cout << "Favor de capturar los números sin separadores (, o ')" << endl;
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

int LeeArchivo(string cantidadNumeros)
{
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
    cn = cn - 1;
    t_ini = clock();
    ordenamientoMezcla(lista, 0, cn);
    t_fin = clock();
    break;
  case 7:
    t_ini = clock();
    ordenamientoRadix();
    t_fin = clock();
    break;
  }
}

void OrdenamientoBurbuja()
{
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

void ordenamientoBurbujaBidireccional()
{
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

//Structs que necesita el ordenamiento por casilleros
// A structure to represent a node.
struct Node
{
  int value;
  struct Node *next;
};

// A structure to represent a Head Bucket Node of the bucket list.
struct Bucket
{
  // Pointer to head node of Bucket.
  struct Node *head;
};

struct BucketList
{
  int V;
  struct Bucket *array;
};

// A utility function to create a new node for a particular entry in a bucket.
struct Node *newNode(int value)
{
  struct Node *newnode = new Node;
  newnode->value = value;
  newnode->next = NULL;
  return newnode;
}

// A utility function that creates a list of the bucket over the range of input data.
struct BucketList *createBucket(int V)
{
  int i;
  struct BucketList *bl = new BucketList;

  bl->V = V;
  bl->array = new Bucket[V];

  // Initialize each Bucket list as empty by making head as NULL.
  for (i = 0; i < V; i++)
    bl->array[i].head = NULL;

  return bl;
}

// A function to Insert the nodes to corresponding Buckets.
void addNode(struct BucketList *bl, int bckt, int value)
{
  // Creating new data node.
  struct Node *newnode = newNode(value);
  struct Node *temp = new Node;

  if (bl->array[bckt].head != NULL)
  {
    temp = bl->array[bckt].head;

    // Sorting.
    // If the head node value is lesser than the newnode value, then add node at beginning.
    if (temp->value > newnode->value)
    {
      newnode->next = bl->array[bckt].head;
      bl->array[bckt].head = newnode;
    }
    else
    {
      // Search for the node whose value is more than the newnode value.
      while (temp->next != NULL)
      {
        if ((temp->next)->value > newnode->value)
          break;

        temp = temp->next;
      }

      // Insert newnode after temp node.
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }
  else
  {
    bl->array[bckt].head = newnode;
  }
}

// A function to print the result as sorted Data.
void printBuckets(struct BucketList *bl)
{

  int v, i = 0;
  struct Node *pCrawl = new Node;

  for (v = 0; v < bl->V; v++)
  {
    // To view the data in individual bucket remove next line from comment.

    pCrawl = bl->array[v].head;
    while (pCrawl != NULL)
    {
      arregloauxiliar[i] = pCrawl->value;
      lista[i] = arregloauxiliar[i];
      i++;
      pCrawl = pCrawl->next;
    }
  }
}

void ordenamientoCasilleros()
{
  cout << "Se inicia el ordenamiento por casilleros" << endl;

  // Create the BucketLists for the data and set 10 as default number of Buckets.
  int V = 10, range, NOE, i;
  struct BucketList *mybucket = createBucket(V);

  // Dividing range into 10 parts so it will have 10 buckets as default.
  range = 40000 / 10;

  NOE = cn;

  for (i = 0; i < NOE; i++)
  {
    addNode(mybucket, lista[i] / range, lista[i]);
  }

  printBuckets(mybucket);
}

//fin de todo el ordenamiento por casilleros
void ordenamientoCuentas()
{
  cout << "Se inicia el ordenamiento por cuentas" << endl;
  vector<int> arr;
  for(int i = 0; i < sizeof(lista); i++)
    arr .push_back(lista[i]);
  int max = *max_element(arr.begin(), arr.end());
  int min = *min_element(arr.begin(), arr.end());
  int range = max - min + 1;

  vector<int> count(range), output(arr.size());
  for (int i = 0; i < arr.size(); i++)
    count[arr[i] - min]++;

  for (int i = 1; i < count.size(); i++)
    count[i] += count[i - 1];

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    output[count[arr[i] - min] - 1] = arr[i];
    count[arr[i] - min]--;
  }

  for (int i = 0; i < arr.size(); i++)
    lista[i] = output[i];
}

void ordenamientoMezcla(int *a, int low, int high)
{
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

void mezclarMitades(int *a, int low, int high, int mid)
{
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

void ordenamientoRadix()
{
  cout << "Se inicia el ordenamiento radix" << endl;
}
