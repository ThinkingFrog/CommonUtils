%Создание полинома
p = [-1.29 -8.21 -4.85 -4.60 -6.27 5.81 6.92 6.83 3.53 5.81 0.11 -6.66];
x = -5.5 : 0.05 : 3;
y = polyval(p , x);
plot(x, y);
xlabel('x')
ylabel('y')
grid on
hold on

%Нахождение корней
r = roots(y);
x0 = r(imag(r) == 0);
plot(x0, 0, 'ro');