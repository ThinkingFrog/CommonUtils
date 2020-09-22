%Вывод графика полинома
p = [0.9 -4.23 2.07 3.83];
x = -2 : 0.05 : 5;
y = polyval(p, x);
plot(x, y, 'b')
title('график полинома')
xlabel('x')
ylabel('y')
grid on
hold on

%Отметка корней на графике
r = roots(p);
x0 = r(imag(r) == 0);
plot(x0, 0, 'ro')
xlabel('x')
ylabel('y')

%Нахождение экстремумов через корни производной
p1 = polyder(p);
r1 = roots(p1);
x01 = r1(imag(r1) == 0);
y01 = polyval(p, x01);
plot(x01, y01, 'g*')

%Нахождение выпуклостей через корни второй производной
p2 = polyder(p1);
r2 = roots(p2);
x02 = r2(imag(r2) == 0);
y02 = polyval(p, x02);
plot(x02, y02, 'ms')