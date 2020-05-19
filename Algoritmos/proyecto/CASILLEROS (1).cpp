/* Autores: Alfaro Flores Luis Fernando 
          Martínez Rodríguez José Alejandro			

                       "Ordenamiento por Casilleros"
    Los datos de entrada se han tomado de un archivo guardado en el mismo directorio que el programa,
    la nomenclatura para la cantidad de números se encuentra en el reporte correspondiente  */


#include   <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

// A structure to represent a node.
struct Node
{
 int value;
 struct Node* next;
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
 struct Bucket * array;
};


// A utility function to create a new node for a particular entry in a bucket.
struct Node* newNode(int value)
{
 struct Node* newnode = new Node;
 newnode->value = value;
 newnode->next = NULL;
 return newnode;
}

// A utility function that creates a list of the bucket over the range of input data.
struct BucketList* createBucket(int V)
{
 int i;
 struct BucketList* bl = new BucketList;

 bl->V = V;
 bl->array = new Bucket[V];   


 // Initialize each Bucket list as empty by making head as NULL.
 for(i = 0; i < V; i++)
  bl->array[i].head = NULL;

 return bl;
}


struct Entrada {
    int valor;
} entrada;

struct Entrada1 {
    int valor1;
} entrada1;

// A function to Insert the nodes to corresponding Buckets.
void addNode(struct BucketList* bl, int bckt, int value)
{
 // Creating new data node.
 struct Node *newnode = newNode(value);
 struct Node *temp = new Node;

 if(bl->array[bckt].head != NULL)
 {
  temp = bl->array[bckt].head;

  // Sorting.
  // If the head node value is lesser than the newnode value, then add node at beginning.
  if(temp->value > newnode->value)
  {
   newnode->next = bl->array[bckt].head;
   bl->array[bckt].head = newnode;
  }
  else
  {
   // Search for the node whose value is more than the newnode value.
   while(temp->next != NULL)
   {
    if((temp->next)->value > newnode->value)
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
  // Assign head of the Bucket as newnode since bucket head is NULL.
  bl->array[bckt].head = newnode;
 }
}



int arr[1000000];
int arregloauxiliar[1000000]; 
int i=0, j=0, k=0;
int lista[1000000];
int n=0;
int cn=0;
int salvacn;
int si;
int LeeArchivo();
int Ordenamiento();
int GrabaArchivo();
clock_t t_ini, t_fin;
double secs;
string nombrearchivo;
string nombrearchivo1;

// A function to print the result as sorted Data.
void printBuckets(struct BucketList *bl)
{
 int v,i=0;;
 struct Node* pCrawl = new Node;
 
 for(v = 0; v < bl->V; v++)
 {
  // To view the data in individual bucket remove next line from comment.
  //cout<<"\n\t bucket "<<endl;

  pCrawl = bl->array[v].head;  
  while (pCrawl != NULL)
  {
   
   //cout<<pCrawl->value<<endl;
   
   arregloauxiliar[i]=pCrawl->value;
   i++;
   pCrawl = pCrawl->next;
  }
 }
}


int LeeArchivo(){
  FILE *archivo1;
    string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
  cin >> nombrearchivo;

nombrearchivo+= ".txt";                //  le agregarmos la extension ".txt"

  archivo1 = fopen(nombrearchivo.c_str(), "r");            // Abrimos archivo

  if(archivo1== NULL ){
    printf(" No se puede abrir el archivo ");
    exit(1);
  }
  else{
    printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
    }
    cn=0;
    for (int i=0; !feof(archivo1); i++) {
        fscanf (archivo1, "%i", &entrada.valor);
        lista[i]=entrada.valor;
        cn++;
  }
  printf("valor de n es:  %i\n",cn);
  salvacn=cn;
  fclose(archivo1);
  return (0);
}


int GrabaArchivo(){
  FILE *archivo2;
    string valorInt;

    printf("\n Teclea el nombre del archivo de salida:   ");
  cin >> nombrearchivo1;
  nombrearchivo1+= ".txt";                 // leagregarmos la extension ".txt"

  archivo2 = fopen(nombrearchivo1.c_str(), "w");            // Abrimos archivo

  if(archivo2== NULL ){
    printf(" No se puede abrir el archivo ");
    exit(1);
  }
else{
    printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo1.c_str() );
    
    }
    cn=salvacn;
    salvacn=0;
    for (i=0; i<cn; i++) {
        entrada1.valor1=arregloauxiliar[i];
        fprintf(archivo2, "%i\n", entrada1.valor1);
        salvacn++;
        }
    printf("valor de n es:  %i\n",salvacn);
  fclose(archivo2);
  return (0);
}


int main()
{
si=1;	
do{
	
 // Create the BucketLists for the data and set 10 as default number of Buckets.
 int V = 10, range, NOE, i;
 struct BucketList* mybucket = createBucket(V);

 //cout<<"\n\nEnter the upper limit in the power of 10 (10 or 100 or 1000 ..) to create Bucket: ";
 //cin>>range;

 // Dividing range into 10 parts so it will have 10 buckets as default.
 range = 40000/10;

 LeeArchivo();	
 t_ini = clock();  
 //printf ("Enter the number of data element to be sorted: ");
 NOE=cn;
 //printf("el valor de NOE es %d     \n",NOE);
 
 printf("Ordenamiento por casilleros\n");
 for(i = 0; i < NOE; i++)
 {
  //printf("%d ", lista[i]);	
  //cout<<"Enter element "<
  //cin>>arr[i];
  addNode(mybucket, lista[i]/range, lista[i]);
 }

 // Print the adjacency list representation of the BucketList i.e the sorted Output.
 //cout<<"\nSorted Data ";
  t_fin = clock();            // almacena tiempo final
 // Termina area de medicion de tiempo
        secs  =  (double)(t_fin  -  t_ini)  /  (double)CLOCKS_PER_SEC;  //  determina  los  milisegundo utilizados
        printf("%.16g milisegundos\n", secs * 1000.0);   // muestra el tiempo utilizado
        printBuckets(mybucket);
        GrabaArchivo();
  		//system("pause");     
    //printf("el arreglo copiado es:\n");
    //for(int w=0; w<cn; w++)
    //{
	//printf("%d\n", arregloauxiliar[w]);
	//}
	
	printf("Deseas probar con otro archivo (Si=1, NO=0) ");
    cin >> si;
}while(si==1);
 return 0;
}   


