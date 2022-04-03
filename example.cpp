#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include"pde.h"
using namespace std;

ld ux0(ld x){return sin(pi*x)+sin(2*pi*x);}
ld l(ld t){return 0;}
ld r(ld t){return 0;}
ld utx0(ld x){return 0;}

int main()
{
	ls x={0,1},t={0,0.5};
	int M=10,N=50;
	ld c=4;
	pde::wave_eq(ux0,utx0,l,r,x,t,c,M,N,"pde.csv");
	return 0;
}
