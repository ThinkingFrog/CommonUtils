%Вывод графика функции f(х)
x = -5 : 0.05 : 5;
y = f11(x);
plot(x, y, 'b')
title('график функции f(x)')
xlabel('x')
ylabel('y')
grid on
hold on

%Отметка корней на графике
rx = fzero(@f11, [-5, -3]);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')
text(rx-0.5, -0.1, 'root');

rx = fzero(@f11, -3);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')
text(rx-0.2, -0.1, 'roots');

rx = fzero(@f11, -17/7);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')

rx = fzero(@f11, [-2, 3]);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')
text(rx-0.6, -0.1, 'root');

rx = fzero(@f11, [3, 5]);
x0 = rx(imag(rx) == 0);
plot(x0, 0, 'ro')
text(rx-0.5, -0.1, 'root');

xlabel('x')
ylabel('y')

%Нахождение экстремумов
[x, y] = fminbnd(@f11, -5, -3);
plot(x, y, 'g*')
text(x-0.2, y-0.2, 'min');

[x, y] = fminbnd(@f11, -3, 2);
plot(x, y, 'g*')
text(x-0.2, y+0.2, 'min');

[x, y] = fminbnd(@f12, -3, 0);
plot(x, y, 'g*')
text(x-0.2, y+0.2, 'max');

[x, y] = fminbnd(@f12, 0, 5);
plot(x, -y, 'g*')
text(x-0.3, -y-0.2, 'max');

[x, y] = fminbnd(@f11, 2, 5);
plot(x, y, 'g*')
text(x-0.6, y, 'min');