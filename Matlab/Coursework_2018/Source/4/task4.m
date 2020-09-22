%Задаем эллиптический параболоид
a = 9.47;
b = 8.11;
x0 = 0.84;
y0 = 1.88;
z0 = 1.99;
x = -5 : 1 : 5;
y = -25 : 1 : 25;
[X, Y] = meshgrid(x, y);
Z = (X-x0).^2/a^2+(Y-y0).^2/b^2+z0;

%Задаем двуполостный гиперболоид
a= 1.50;
b= 9.58;
c= -5.30;
x0= -1.70;
y0= -0.75;
z0= 1.58;
x = -5 : 1 : 5;
y = -25 : 1 : 25;
[X, Y] = meshgrid(x, y);
Z1 = sqrt((1 + (X-x0).^2/a^2 + (Y-y0).^2/b^2)*c^2)+z0;
Z2 = -sqrt((1 + (X-x0).^2/a^2 + (Y-y0).^2/b^2)*c^2)+z0;

subplot(1, 3, 1)
mesh(X, Y, Z)
hold on
shading interp
surf(X, Y, Z1)
surf(X, Y, Z2)
shading interp
colormap summer
view(0, 10)

subplot(1, 3, 2)
mesh(X, Y, Z)
hold on
shading interp
surf(X, Y, Z1)
hold on
surf(X, Y, Z2)
shading interp
colormap summer
view(20, 30)

subplot(1, 3, 3)
mesh(X, Y, Z)
hold on
shading interp
surf(X, Y, Z1)
hold on
surf(X, Y, Z2)
shading interp
colormap summer
view(70, 10)