%pde画图
z=readmatrix("pde.csv");
%M,N为空间步数与时间步数
M=10;
N=50;
%区间x,t
x=[0,1];
t=[0,0.5];
h=(x(2)-x(1))/M;
k=(t(2)-t(1))/N;
x0=x(1):h:x(2);
t0=x(1):k:t(2);
[X,Y]=meshgrid(x0,t0);
figure
surf(X,Y,z,'FaceAlpha',1.0);

