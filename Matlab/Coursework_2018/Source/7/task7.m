x = sym('x');
a = sym('a');
m = sym('m');
b = sym('b');
n = sym('n');
h = sym('h');

%¹452
f452 = ((1 + a*x)^(1/m)-(1+ x*b)^(1/n))/x;
pretty(f452)
f452l = limit(f452, x, 0);    
pretty(f452l)

%¹498
f498 = (1-cot(x)^3)/(2-cot(x)-cot(x)^3);
pretty(f498)
f498l = limit(f498, x, 0);      
pretty(f498l)

%¹585
f585 = (atan(x+h)-acot(x))/h;
pretty(f585)
f585l = limit(f585,x,Inf);
pretty(f585l)

%¹900
y900 = (2+3*x)/x^4*(1-x^3)^(1/2)+3*log(sqrt(1+(1-x^2))/x);
pretty(y900)
y900d = diff(y900);
pretty(y900d)

%¹916
y916 = sqrt(1/2)*atan(sqrt(2)/x);
pretty(y916)
y916d = diff(y916);
pretty(y916d)

%¹1358
y1358 = (a^x-x^a)/(x - a);
pretty(y1358)
y1358d = diff(y1358,4);
pretty(y1358d)