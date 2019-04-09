#include <iostream>
#include <math.h>
using namespace std;

int delay(int);

int delay () {
  int n = 700000;
  int i,j, freq=n-1;
  for (i=2; i<=n; i++) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;

}