%�������� ��������
p = [-1.29 -8.21 -4.85 -4.60 -6.27 5.81 6.92 6.83 3.53 5.81 0.11 -6.66];
x = -6 : 0.5 : 3;
y = polyval(p , x);
subplot(4, 1, 1)
plot(x, y);
xlabel('x')
ylabel('y')
grid on
hold on
title('������ ��������')

%���������� ������
r = roots(y);
x0 = r(imag(r) == 0)
plot(x0, 0, 'ro');

%�������� ������ ����������� ��������
p1 = polyder(p);
y1 = polyval(p1, x);
subplot(4, 1, 2)
plot(x, y1);
xlabel('x')
ylabel('y')
grid on
hold on
title('������ ������ ����������� ��������')

%���������� ������
r1 = roots(p1);
x0 = r1(imag(r1) == 0);
plot(x0, 0, 'ro');

%�������� ������ ����������� ��������
p2 = polyder(p1);
y2 = polyval(p2, x);
subplot(4, 1, 3)
plot(x, y2);
xlabel('x')
ylabel('y')
grid on
hold on
title('������ ������ ����������� ��������')

%���������� ������
r2 = roots(p2);
x0 = r2(imag(r2) == 0);
plot(x0, 0, 'ro');

%�������� ������� ����������� ��������
p3 = polyder(p2);
y3 = polyval(p3, x);
subplot(4, 1, 4)
plot(x, y3);
xlabel('x')
ylabel('y')
grid on
hold on
title('������ ������� ����������� ��������')

%���������� ������
r3 = roots(p3);
x0 = r3(imag(r3) == 0);
plot(x0, 0, 'ro');