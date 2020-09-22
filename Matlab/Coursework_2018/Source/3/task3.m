%Задаем эллиптический параболоид
a = 9.47;
b = 8.11;
x0 = 0.84;
y0 = 1.88;
z0 = 1.99;
x = -50 : 1 : 50;
y = -50 : 1 : 50;
[X, Y] = meshgrid(x, y);
Z = (X-x0).^2/a^2+(Y-y0).^2/b^2+z0;
figure
subplot(1, 2, 1)
mesh(X, Y, Z)
subplot(1, 2, 2)
surf(X, Y, Z)
shading interp

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
figure
subplot(1, 2, 1)
mesh(X, Y, Z1)
hold on
mesh(X, Y, Z2)
subplot(1, 2, 2)
surf(X, Y, Z1)
hold on
surf(X, Y, Z2)
shading interp
colormap summer