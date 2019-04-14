#include <bits/stdc++.h>
#include <string>
using namespace std;

float sumatoria(string a);//constructor

int main(){
  string x,z;
  cout<<"Sumatorias"<<endl;
  cout<<"Ingresa tu numero: ";
  do {
    cin>>x;
  }while(x == '0');
  sumatoria(x);
  z= sumatoria(x);
  cout<<"la sumatoria es: "<<z<<endl;
  return 0;
}

float sumatoria(string a){
  int sum;
  string n;
  n=atof(a);
  if(n>=1) sum = (n*(n+1)/2);
  else sum= -1;
  return sum;
}