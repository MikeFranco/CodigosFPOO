
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;

int op = 0, i = 0, e = 0, c = 0, si = 1;

string arbol[16] = {
	"Franco Peza", "Victor", "Valeria", "Juan", "María Luisa",
	"Luis", "Alejandra", "Miguel", "Mónica", "Claudia", "Ricardo", "Jovita",
	"Rodrigo", "Diana", "* Miguel Jr. *", "Omar"
};

void imprimeArbol();
int imprimeMenu();

void imprimeArbol()
{
	cout << "\t\t\t\t       ARBOL GENEALOGICO FAMILIA FRANCO PEZA\n\n";
	cout << "\t\t\tFranco \t\t\t\tPeza\n";
	cout << "\t\t / \t\t \\ \t\t / \t\t \\  \n";
	cout << "\t\t" << arbol[1] << "\t\t" << arbol[2] << "\t\t" << arbol[3] << "\t\t" << arbol[4] << endl;
	cout << "\t\t \\ \t\t / \t\t \\ \t   | \t   / \n";
	cout << "\t" << arbol[5] << "\t" << arbol[6] << "\t" << arbol[7] << "\t\t" << arbol[8] << "  " << arbol[9] << "  " << arbol[10] << "     " << arbol[11] << endl;
	cout << "\t \\     \t / \t\t     \\ \t\t / \t\t      \\"<< "       /" << endl;
	cout << "      " << arbol[12] << "   " << arbol[13] << "\t\t     " << arbol[14] << "\t\t\t" << arbol[15] << endl;
}

int imprimeMenu()
{
	int opcion = 0;
	cout << "\nSelecciona la pregunta a responder \n";
	cout << "\nCuales son:  \?";
	cout << "\n\t1.-  Apellidos familiares: ";
	cout << "\n\t2.-  Los nombres de los abuelos paternos: ";
	cout << "\n\t3.-  Los nombres de los abuelos maternos: ";
	cout << "\n\t4.-  Los nombres de mis padres: ";
	cout << "\n\t5.-  Todos los nombres de los hijos de los abuelos paternos: ";
	cout << "\n\t6.-  Todos los nombres de los hijos de los abuelos maternos: ";
	cout << "\n\t7.-  Todos los nombres de los nietos de los abuelos paternos: ";
	cout << "\n\t8.-  Todos los nombres de los nietos de los abuelos maternos: ";
	cout << "\n\t9.-  Quien es tu abuel@ consentid@ o el mas querid@: ";
	cout << "\n\t10.- Quien es tu prim@ consentid@ o el mas querid@: ";
	cout << "\n\t11.- En que lugar estoy yo, quienes son mis padres y cual es mi nombre: ";
	cout << "\n\t12.- Salir";
	cout << "\n Teclee el numero de opcion deseada:  ";
	cin >> opcion;
	return (opcion);
}

int main()
{
	int i = 0, opcion = 0, respuesta = 0;
	for (i = 0; i == 0;)
	{

		imprimeArbol();
		opcion = imprimeMenu();
		switch (opcion)
		{
		case 1:
			cout << "\n\n\tMis Apellidos familiares son: ";
			cout << arbol[0] << endl;
			break;

		case 2:
			cout << "\n\n\tLos nombres de mis abuelos paternos son: ";
			cout << arbol[1] << " y " << arbol[2] << endl;
			break;

		case 3:
			cout << "\n\n\tLos nombres de mis abuelos maternos: ";
			cout << arbol[3] << " y " << arbol[4] << endl;
			break;

		case 4:
			cout << "\n\n\tLos nombres de mis padres son: ";
			cout << arbol[7] << " y " << arbol[8] << endl;
			break;

		case 5:
			cout << "\n\n\tTodos los nombres de los hijos de mis abuelos paternos: ";
			cout << arbol[6] << " y " << arbol[7] << endl;
			break;

		case 6:
			cout << "\n\n\tTodos los nombres de los hijos de mis abuelos maternos: ";
			cout << arbol[8] << " , " << arbol[9] << " y " << arbol[10] << endl;
			break;

		case 7:
			cout << "\n\n\tTodos los nombres de los nietos de mis abuelos paternos: ";
			cout << arbol[12] << " , " << arbol[13] << " y " << arbol[14] << endl;
			break;

		case 8:
			cout << "\n\n\tTodos los nombres de los nietos de mis abuelos maternos: ";
			cout << arbol[14] << " y " << arbol[15] << endl;
			break;

		case 9:
			cout << "\n\n\tQuien es tu abuel@ consentid@ o el mas querid@: ";
			cout << arbol[3] << endl;
			break;

		case 10:
			cout << "\n\n\tEl prim@ con el que me llevo mejor es : " << arbol[13] << endl;
			break;

		case 11:
			cout << "\n\n\tSoy hij@ de  " << arbol[7] << "  y  " << arbol[8] << "\tmi nombre es: " << arbol[14] << endl;
			break;

		case 12:
			printf("\n\n\tHasta luego \n");
			i = 1;
			break;
		default:
			printf("\n\n\tSeleccion invalida, intente nuevamente\n");
			break;
		}
	}
}
