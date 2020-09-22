x = sym('x');

t2=taylor(x^2-log(x+1), x, 'Order', 2);
pretty(t2)
t3=taylor(x^2-log(x+1), x, 'Order', 3);
pretty(t3)
t4=taylor(x^2-log(x+1), x, 'Order', 4);
pretty(t4)
t5=taylor(x^2-log(x+1), x, 'Order', 5);
pretty(t5)

%�������������� �� ����������� � �������� �������� 
k2= sym2poly(t2)
k3= sym2poly(t3)
k4= sym2poly(t4)
k5= sym2poly(t5)


%���������� 
x1= -0.5:0.01:1;
y1= polyval(k2, x1);           %������ ���������� 2
plot(x1, y1, 'm-')
hold on

y1= polyval(k3, x1);           %������ ���������� 3
plot(x1, y1, 'k-') 

y1= polyval(k4, x1);           %������ ���������� 4
plot(x1, y1, 'r-') 

y1= polyval(k5, x1);           %������ ���������� 5
plot(x1, y1, 'g-') 

x2= -0.5:0.01:1;
y2= f12(x2);                %������ �������
plot(x2, y2, 'b-') 

legend('������ 2 ���������� �������', '������ 3 ���������� �������', '������ 4 ���������� �������', '������ 5 ���������� �������', '������ �������')
xlabel('x')            
ylabel('y')         
grid on