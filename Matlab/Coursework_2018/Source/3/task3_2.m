a= 9.47;
b= 8.11;
x0= 0.84;
y0= 1.88;
z0= 1.99;
x = -50 : 1 : 50;
y = -50 : 1 : 50;
[X, Y] = meshgrid(x, y);
Z = (X-x0).^2/a^2+(Y-y0).^2/b^2+z0;

subplot(2, 2, 1)
surfl(X, Y, Z, [100 100])
view(50, 50)
shading interp

subplot(2, 2, 2)
surfl(X, Y, Z, [100 100])
view(100, 100)
shading interp

subplot(2, 2, 3)
surfl(X, Y, Z, [150 50])
shading interp
view(50, 50)

subplot(2, 2, 4)
surfl(X, Y, Z, [150 50])
shading interp
view(100, 100)

colormap autumn