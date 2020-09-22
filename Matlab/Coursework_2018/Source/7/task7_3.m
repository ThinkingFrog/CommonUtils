syms x01 x02 x03;

matrix = random('unid', 19, 3, 3) - 10 %матрица 3 на 3 из рандомных чисел от -9 до 9
right = random('unid', 19, 3, 1) - 10  %массив правых коэффициентов от -9 до 9

f1= matrix(1,1)*x01 + matrix(1,2)*x02 + matrix(1,3)*x03 - right(1,1)
f2= matrix(2,1)*x01 + matrix(2,2)*x02 + matrix(2,3)*x03 - right(2,1)
f3= matrix(3,1)*x01 + matrix(3,2)*x02 + matrix(3,3)*x03 - right(3,1)

[rot(1), rot(2) ,rot(3)]= solve (f1, f2, f3, 'x01', 'x02', 'x03')
rot= vpa(rot, 10)
if(size(rot) == [1 3]) 
    rot = rot'
end

root1= matrix\right
delta=abs((root1 - rot)./rot)