x = sym('x');

t2=taylor(x^2-log(x+1), x, 'Order', 2);
pretty(t2)
t3=taylor(x^2-log(x+1), x, 'Order', 3);
pretty(t3)
t4=taylor(x^2-log(x+1), x, 'Order', 4);
pretty(t4)
t5=taylor(x^2-log(x+1), x, 'Order', 5);
pretty(t5)

%преобразование из символьного в числовое значение 
k2= sym2poly(t2)
k3= sym2poly(t3)
k4= sym2poly(t4)
k5= sym2poly(t5)


%Построение 
x1= -0.5:0.01:1;
y1= polyval(k2, x1);           %график разложения 2
plot(x1, y1, 'm-')
hold on

y1= polyval(k3, x1);           %график разложения 3
plot(x1, y1, 'k-') 

y1= polyval(k4, x1);           %график разложения 4
plot(x1, y1, 'r-') 

y1= polyval(k5, x1);           %график разложения 5
plot(x1, y1, 'g-') 

x2= -0.5:0.01:1;
y2= f12(x2);                %график функции
plot(x2, y2, 'b-') 

legend('График 2 разложения Тейлора', 'График 3 разложения Тейлора', 'График 4 разложения Тейлора', 'График 5 разложения Тейлора', 'График функции')
xlabel('x')            
ylabel('y')         
grid on