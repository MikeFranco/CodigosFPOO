#include<iostream>

using namespace std;


int main()
{
	
	int val1,val2, area=0;
	
	cout<<"Digite los 2 valores: "; cin>>val1>>val2;
	
	area= val1*val2;
	
	if (val1 == val2)
	{
		cout<<"El area es : "<<area<<" y es de un cuadrado ";
	}
	
	else {
		cout<<"El area es : "<<area<<" y es de un rectangulo ";
	}
	
	
	
	return 0;
}
