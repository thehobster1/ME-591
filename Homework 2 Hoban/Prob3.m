clear all
close all

eps = 0.034; %eV
r0 = 3; %A
a = 1.7; %1/A

m = 12; %Da
sigma = 2.7; %A
s = 12;
rcut = 12; %A

v = [227, 617, 217];

v1 = [322, 231, -417];

r = [0, -2, -14];

r1 = [-2, 4, -2];

rc = (r + r1)/2;

rr = (r1 - r);

rtest = rc - rr/2;

r1test = rc + rr/2;

vc = (v + v1)/2;

vr = (v1 - v);

vtest = vc - vr/2;

v1test = vc + vr/2;


cr = v1 - v;

Hr = m*norm(cr)^2/4;

Lr = norm(m/2*cross(rr, cr));

b = 2*Lr/(m*norm(cr));


fun = @(rfun) Hr - Lr^2/(m*rfun^2) - 4*eps*(sigma/rfun)^s;
 
rMin = fzero(fun, r0);

fun2 = @(rfun2) Lr.*(m*rfun2.^2.*sqrt((Hr - 4*eps*(sigma*rfun2.^-1).^s)/m - Lr^2*(m^2*rfun2.^2).^-1)).^-1;

q = integral(fun2, rMin, rcut);

x = pi() - 2*q;

n = (r1 - r)/norm(r1-r);

vp = v + (dot(cr, n))*n;

v1p = v1 - (dot(cr, n))*n;

