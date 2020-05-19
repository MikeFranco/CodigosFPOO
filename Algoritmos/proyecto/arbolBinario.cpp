// Plantilla de Arbol Binario de B�squeda en C++
// (C) Abril 2002, Salvador Pozo
// C con Clase: http://c.conclase.net

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
clock_t t_ini, t_fin;
int lista[1000000];

int LeeArchivo(string);
int guardarArchivoOrdenado(string);


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

int guardarArchivoOrdenado(string cantidadNumeros)
{
  FILE *archivoSalida;
  string nombreArchivoSalida = "num" + cantidadNumeros + "_arbol_binario.txt";

  archivoSalida = fopen(nombreArchivoSalida.c_str(), "w");

  if (archivoSalida == NULL){
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

using namespace std;

class ArbolABB {
  private:
   class Nodo {
     public:
      // Constructor:
      Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      Nodo *izquierdo;
      Nodo *derecho;
   };

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;

  public:
   // Constructor y destructor b�sicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   // Insertar en �rbol ordenado:
   void Insertar(const int dat);
   // Comprobar si el �rbol est� vac�o:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una funci�n a cada elemento del �rbol:
   void InOrden(void (*func)(int&) ,Nodo *nodo=NULL, bool r=true);
};

// Insertar un int en el �rbol ABB
void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) ,Nodo *nodo, bool r){
  if(r) nodo = raiz;
  if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
  func(nodo->dato);
  if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

void guardarOrden(int &d) {
  lista[i] = d;
  i++;
}

int main(){
  string cantidadNumeros;
  double secs;
  cout << "¿Cuantos valores quieres ordenar? (10/100/1,000/10,000/100,000/1'000,000): ";
  cin >> cantidadNumeros;
  LeeArchivo(cantidadNumeros);

  ArbolABB ArbolInt;

  // Inserci�n de nodos en �rbol:
  for (int i = 0; i < cn; i++){
    ArbolInt.Insertar(lista[i]);
  }
  // Mostrar el �rbol en tres ordenes distintos:
  cout << "InOrden: ";
  t_ini = clock();
  ArbolInt.InOrden(guardarOrden);
  t_fin = clock();
  cout << endl;

   secs = (double)(t_fin - t_ini) / (double)CLOCKS_PER_SEC; // determina los milisegundo utilizados
   printf("%.16g milisegundos\n", secs * 1000.0);           // muestra el tiempo utilizado
   guardarArchivoOrdenado(cantidadNumeros);
   cin.get();
   return 0;
}
