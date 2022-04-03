z=readmatrix("C:\Users\SekaiGao\Desktop\&C++\pde.csv");
M=10;
N=50;
h=1/M;
k=0.5/N;
x=0:h:1;
t=0:k:0.5;
[X,Y]=meshgrid(x,t);
figure
surf(X,Y,z,'FaceAlpha',1.0);

