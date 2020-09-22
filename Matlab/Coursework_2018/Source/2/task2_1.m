x1 = -10:0.01:0;
x2 = 0:0.01:10;
x3 = 10:0.01:20;
p = [0.9 -4.23 2.07 3.83];

y = f11(x1);
yp = polyval(p, x2);
yg = g11(x3);

x01 = fzero(@f11, -1)
y01 = f11(x01)

hold on
plot(x1, y, 'k--')
plot(x2, yp, 'b-.')
plot(x3, yg, 'g')
plot(x01, y01, 'bo')


r=roots(p)
r = r(r > 0 & r < 10);
yr=polyval(p,r)
plot(r, yr, 'r*')


x03=fzero(@g11,10)
y03=g11(x03)
plot(x03, y03, 'ks')
title('График кусочно заданной функции')
grid on
xlabel('x')
ylabel('y')
legend('График функции f(x)','График полинома P(x)','График функции g(x)', 'Корни f(x)', 'Корни P(x)', 'Корни g(x)', 'Location','northwest')