clear all
close all

eps = 0.03; %eV
r0 = 3; %A
a = 1.7; %1/A

eps = eps *1.60218* 10^(-19); %To Joules
%r0 = r0*10^(-10);%m
%a = a*10^(10); %m

f1 = f(r0/2, r0, eps, a);

f2 = f(r0*2, r0, eps, a);

f3 = f(r0*4, r0, eps, a);

rStar = log(2)/a+r0;

fStar = f(rStar, r0, eps, a);



function f = f(r, r0, eps, a)

    f = (2*eps*a*(exp(-2*a*(r-r0)) - exp(-a*(r-r0))))*10^(9)*10^(10); %nM

end