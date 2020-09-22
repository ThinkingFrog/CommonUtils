p = [0.9 -4.23 2.07 3.83];
r = roots(p);
sort(r);
x1 = r(1)-5: 0.1 : r(1)+5;
y1 = g11(x1);

subplot(1,2,1)
grid on
hold on
plot(x1,y1,'b');
line([r(1), r(1)],[-16*10^13,2*10^13], 'Linestyle', '--', 'Color', 'r')
xlabel('X');
ylabel('Y');
title('График с одним корнем полинома')

x = r(1)-10:0.1:r(3)+10; 
y = g11(x)
c=3;
b=abs(y)>c;
y(b)=NaN;
subplot(1,2,2)
grid on
hold on
plot(x,y,'b')
line([r(1), r(1)],[-4,5], 'Linestyle', '--', 'Color', 'r')
line([r(2), r(2)],[-4,5], 'Linestyle', '--', 'Color', 'r')
line([r(3), r(3)],[-4,5], 'Linestyle', '--', 'Color', 'r')
xlabel('X');
ylabel('Y');
title('График с тремя корнями полинома')