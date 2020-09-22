x = sym('x');
p = [0.9 -4.23 2.07 3.83];

t=solve(0.9*x^3-4.23*x^2-2.07*x+3.83);

t1=vpa(t);
t1=sort(t1)

t2=roots(p);
t2=sort(t2)

t31=fzero(@f11, -1, 0);
t32=fzero(@f11, 1, 2);
t33=fzero(@f11, 4, 5);
t3 = [t31 t32 t33];
if(size(t3) == [1 3]) 
    t3 = t3'
end
sort(t3)

delta1=abs(t1-t2)
delta2=abs(t1-t3)