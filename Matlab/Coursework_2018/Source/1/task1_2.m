%Отдельные графики
p = [0.9 -4.23 2.07 3.83];
x = -2 : 0.05 : 5;
y = polyval(p, x);
xm = -2 : 1 : 5;
ym = polyval(p, xm);

subplot(2, 2, 1)
plot(x , y, 'r-')
hold on
plot(xm , ym, 'k+')
xlabel('x')
ylabel('y')
title('График полиноминальной функции P(x)')
grid on

subplot(2, 2, 2)
plot(x, y, 'g:')
hold on
plot(xm, ym, 'bo')
title('График полиноминальной функции P(x)')
xlabel('x')
ylabel('y')
grid on

subplot(2, 2, 3)
plot(x, y, 'b')
hold on
plot(xm, ym, 'rs')
title('График полиноминальной функции P(x)')
xlabel('x')
ylabel('y')
grid on

subplot(2, 2, 4)
plot(x, y, 'b')
hold on
plot(xm, ym, 'm*')
title('График полиноминальной функции P(x)')
xlabel('x')
ylabel('y')
grid on