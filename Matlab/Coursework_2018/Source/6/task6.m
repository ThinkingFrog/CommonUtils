%�� ������ �������
m = load('matrix.txt')   %�������
right = load('rightpart.txt')  %������ �����
y = det(m)   %������������

%������� �����
l = length(right);
    for i = 1:l
        maxr = m;
        maxr(:,i) = right;
        x(i) = det(maxr)/y
    end
    
%����� �������� �������
right = right';
x1=inv(m)*right
   
%����� ������
x2=m\right  %������� �����

%������� ������������ ���������� ������� �������
xT = x'
k0 = m*xT - right %������ �������
t0 = max(abs(k0))

k1 = m*x1 - right %������ �������
t1 = max(abs(k1))

k2 = m*x2 - right;%������ �������
t2 = max(abs(k2))

%�����: ������ ������ �������� ������

%������ �����������
h = [0.02, 0.03, 0.04, 0.05];

%for i=1:4
 %   maxr = m.*(rand(size(m))*h(i)) + m
  %  x3 = maxr\right
   % delta(i)= max(abs((x2-x3)./x1)) %������� ������������� ����������� �������� ������
%end

for i=1:4
    ri = right.*(rand(size(right))*h(i)) + right
    x3 = m\ri
    deltar(i)= max(abs((x2-x3)./x1)) %������� ������������� ����������� ������ �����
end


%������� ������������
%subplot(2, 1, 1)
%plot(h, delta);
%title('������������� ����������� �������� ������');
%xlabel('% ���������');
%ylabel('�����������');
%grid on

%subplot(2, 1, 2)
plot(h, deltar);
title('������������� ����������� ������ �����');
xlabel('% ���������');
ylabel('�����������');
grid on
% ����������� ������� ��������� ������������� ������� ������ �� �������
