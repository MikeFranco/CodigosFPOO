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
  string nombreArchivoSalida = "num" + cantidadNumeros + "_arbol_binario" + ".txt";

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

using namespace std;

class ArbolABB {
  private:
   //// Clase local de Lista para Nodo de ArbolBinario:
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
   // Funci�n de b�squeda:
   bool Buscar(const int dat);
   // Comprobar si el �rbol est� vac�o:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar n�mero de nodos:
   const int NumeroNodos();
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una funci�n a cada elemento del �rbol:
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
  private:
   // Funciones auxiliares
   void auxContador(Nodo*);
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
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}


// Buscar un valor en el �rbol
bool ArbolABB::Buscar(const int dat)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // int encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No est� en �rbol
}

// Contar el n�mero de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Funci�n de prueba para recorridos del �rbol
void Mostrar(int &d){
   cout << d << ",";
}

int main(){
  string cantidadNumeros;
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
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   cin.get();
   return 0;
}