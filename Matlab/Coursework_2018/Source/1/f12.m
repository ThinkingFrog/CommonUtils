function y = f12(x)
a = 1.7;
b = 0.7;
c = 2.6;
d = 0.3;
y = -1*(atan(a+b.*x).*cos(c+d.*x.*x));