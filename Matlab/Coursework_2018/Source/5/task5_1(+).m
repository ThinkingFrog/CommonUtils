%??????? ?? -1 ?? 1
p = [-1.29 -8.21 -4.85 -4.60 -6.27 5.81 6.92 6.83 3.53 5.81 0.11 -6.66];
x = -1 : 0.01 : 1;
y = polyval(p , x);
subplot(2, 1, 1)
plot(x, y);
xlabel('x')
ylabel('y')
grid on
title('?????? ???????? ?? -1 ?? 1')

%??????? ?? -6 ?? -3
p = [-1.29 -8.21 -4.85 -4.60 -6.27 5.81 6.92 6.83 3.53 5.81 0.11 -6.66];
x = -6 : 0.01 : -3;
y = polyval(p , x);
subplot(2, 1, 2)
plot(x, y);
xlabel('x')
ylabel('y')
title('?????? ???????? ?? -6 ?? -3')
grid on