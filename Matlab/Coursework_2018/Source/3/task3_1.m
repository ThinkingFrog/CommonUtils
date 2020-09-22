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

subplot(2, 2, 1)
mesh(X, Y, Z1)
hold on
mesh(X, Y, Z2)
view(150, 50)

subplot(2, 2, 2)
mesh(X, Y, Z1)
hold on
mesh(X, Y, Z2)
view(50, 50)

subplot(2, 2, 3)
surf(X, Y, Z1)
hold on
surf(X, Y, Z2)
shading interp
view(50, 150)

subplot(2, 2, 4)
surf(X, Y, Z1)
hold on
surf(X, Y, Z2)
shading interp
view(150, 150)

colormap winter