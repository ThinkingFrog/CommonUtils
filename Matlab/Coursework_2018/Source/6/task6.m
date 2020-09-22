%По методу Крамера
m = load('matrix.txt')   %матрица
right = load('rightpart.txt')  %правая часть
y = det(m)   %определитель

%Находим корни
l = length(right);
    for i = 1:l
        maxr = m;
        maxr(:,i) = right;
        x(i) = det(maxr)/y
    end
    
%Метод обратной матрицы
right = right';
x1=inv(m)*right
   
%Метод Гаусса
x2=m\right  %находим корни

%Находим максимальные компоненты вектора невязки
xT = x'
k0 = m*xT - right %вектор невязки
t0 = max(abs(k0))

k1 = m*x1 - right %вектор невязки
t1 = max(abs(k1))

k2 = m*x2 - right;%вектор невязки
t2 = max(abs(k2))

%Вывод: Способ Гаусса наиболее точный

%Вводим погрешность
h = [0.02, 0.03, 0.04, 0.05];

%for i=1:4
 %   maxr = m.*(rand(size(m))*h(i)) + m
  %  x3 = maxr\right
   % delta(i)= max(abs((x2-x3)./x1)) %находим относительную погрешность исходных данных
%end

for i=1:4
    ri = right.*(rand(size(right))*h(i)) + right
    x3 = m\ri
    deltar(i)= max(abs((x2-x3)./x1)) %находим относительную погрешность правой части
end


%Графики погрешностей
%subplot(2, 1, 1)
%plot(h, delta);
%title('Относительная погрешность исходных данных');
%xlabel('% изменения');
%ylabel('погрешность');
%grid on

%subplot(2, 1, 2)
plot(h, deltar);
title('Относительная погрешность правой части');
xlabel('% изменения');
ylabel('погрешность');
grid on
% погрешность вектора свободных коэффициентов сильнее влияет на решение
