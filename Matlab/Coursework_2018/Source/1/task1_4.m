%Вывод графика функции f(х)
x = -3 : 0.05 : 4;
y = f11(x);

%Вывод графика полинома
p = [0.9 -4.23 2.07 3.83];
yp = polyval(p, x);
grid on
hold on

%Вывод 4 подграфиков
subplot(2, 2, 1)
hold on
grid on
plot(x, yp, 'k')
plot(x, y, 'b')
xlabel('x')
ylabel('y')
title('График полинома и функции')
legend('Полином', 'Функция', 'Location', 'southeast')


%График с экстремумами
subplot(2, 2, 2)
hold on
grid on
plot(x, yp, 'k')
plot(x, y, 'b')

p1 = polyder(p);
r1 = roots(p1);
x01 = r1(imag(r1) == 0);
y01 = polyval(p, x01);
plot(x01, y01, 'g*')

[xm, ym] = fminbnd(@f11, -3, 1.5);
plot(xm, ym, 'r*')

[xm, ym] = fminbnd(@f12, 1.5, 4);
plot(xm, -ym, 'r*')

xlabel('x')
ylabel('y')
title('График полинома и функции с экстремумами')
legend('Полином', 'Функция', 'Экстремумы полинома', 'Экстремумы функции', 'Location', 'southeast')


%График с корнями
subplot(2, 2, 3)
hold on
grid on
plot(x, yp, 'k')
plot(x, y, 'b')

rx = fzero(@f11, [-3, 4]);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')

r = roots(p);
x0 = r(imag(r) == 0);
plot(x0, 0, 'go')

rx = fzero(@f11, -3);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')

xlabel('x')
ylabel('y')
title('График полинома и функции с корнями')
legend('Полином', 'Функция', 'Корни функции', 'Корни полинома', 'Location', 'southeast')


%График с выпуклостями
subplot(2, 2, 4)
hold on
grid on
plot(x, yp, 'k')
plot(x, y, 'b')

p2 = polyder(p1);
r2 = roots(p2);
x02 = r2(imag(r2) == 0);
y02 = polyval(p, x02);
plot(x02, y02, 'ro')

xlabel('x')
ylabel('y')
title('График полинома и функции с выпуклостями')
legend('Полином', 'Функция', 'Выпуклости полинома', 'Location', 'southeast')