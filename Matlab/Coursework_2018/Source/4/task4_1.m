%Задаем эллиптический параболоид
a = 9.47;
b = 8.11;
x0 = 0.84;
y0 = 1.88;
z0 = 1.99;
u = (-40:0.5:40)';
v = [0:0.05*pi:2*pi];

%Координаты через параметрические уравнения
X = x0 + a*u*cos(v);
Y = y0 + b*u*sin(v);
Z = u.^2*ones(size(v));


%Задаем двуполостный гиперболоид
a= 1.50;
b= 9.58;
c= -5.30;
x0= -1.70;
y0= -0.75;
z0= 1.58;
u1 = (-10:0.1:10)';
v1 = 0:pi/100:2*pi;
[U, V1] = meshgrid(u1,v1);

%Координаты через параметрические уравнения
X1 = x0 + a*sinh(V1).*cos(U);
Y1 = y0 + b*sinh(V1).*sin(U);
Z1 = z0 + c*cosh(V1);
Z2 = z0 - c*cosh(V1);

subplot(1, 3, 1)
surf(X, Y, Z)
hold on
shading interp
mesh(X1, Y1, Z1)
mesh(X1, Y1, Z2)
shading interp
colormap summer
view(0, 10)

subplot(1, 3, 2)
surf(X, Y, Z)
hold on
shading interp
mesh(X1, Y1, Z1)
hold on
mesh(X1, Y1, Z2)
shading interp
colormap summer
view(20, 30)

subplot(1, 3, 3)
surf(X, Y, Z)
hold on
shading interp
mesh(X1, Y1, Z1)
hold on
mesh(X1, Y1, Z2)
shading interp
colormap summer
view(70, 10)