#pragma once
#include<cmath>
#include"matrix.h"
typedef std::initializer_list<ld> ls;
typedef ld (*F)(ld);
namespace pde
{
//u(x,0),ut(x,0),u(a,t),u(b,t),区间,系数c,空间步数,时间步数,写入文件
void wave_eq(F f,F diff,F flt,F frt,ls x,ls t,ld c,int M=10,int N=10,const char*file="wave.csv")
{
	ld h=(*(x.begin()+1)-*x.begin())/M,k=(*(t.begin()+1)-*t.begin())/N;//步长
	mat<ld>u(N+1,M+1),A(M-1,M-1),w(1,M-1),w0,w1,d(1,M-1);
	ld r=c*k/h,r2=r*r,r0=2-2*r2;
	//初始化系数矩阵A
	A[0][0]=r0;
	A[0][1]=r2;
	A[M-2][M-2]=r0;
	A[M-2][M-3]=r2;
	for(int j=0;j<M-1;++j)
	A[j][j]=r0;
	for(int j=1;j<M-2;++j)
	{
		A[j][j-1]=r2;
		A[j][j]=r0;
		A[j][j+1]=r2;
	}
	//初始化迭代边界条件
	for(int j=0;j<=M;++j)
	u[0][j]=f(*x.begin()+j*h);
	for(int i=1;i<=N;++i)
	{
		u[i][0]=flt(*t.begin()+i*k);
		u[i][M]=frt(*t.begin()+i*k);
	}
	//第一行
	w=u.cuts(0,0,1,M-1);
	w0=w;
	w*=1/2.*A;
	for(int j=0;j<M-1;++j)
	w[0][j]+=k*diff(*x.begin()+(j+1)*h);
	w[0][0]+=r2/2.*flt(*t.begin());
	w[0][M-2]+=r2/2.*frt(*t.begin());
	//其余行
	for(int i=1;i<=N;++i)
	{
	for(int j=1;j<M;++j)
	u[i][j]=w[0][j-1];
	w1=w;
	w*=A;
	w-=w0;
	w[0][0]+=r2*flt(*t.begin()+i*k);
	w[0][M-2]+=r2*frt(*t.begin()+i*k);
	w0=w1;
	}
	//写入文件
	FILE*fp;
	fp=fopen(file,"w");
	for(int i=0;i<=N;++i)
	{
	for(int j=0;j<M;++j)
	fprintf(fp,"%Lf,",u[i][j]);
	fprintf(fp,"%Lf\n",u[i][M]);
	}
}
}