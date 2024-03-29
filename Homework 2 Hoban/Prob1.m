clear all
close all

m = 28;

d = 3.7;

kb = 1.380649*10^-23; %j/K

v = [-322, -541, -415];

v1 = [-346, 620, 545];

n = [-0.819, -0.531, -0.214];


cr = v1 - v; %m/s

crp = cr - 2*(dot(cr, n))*n; %m/s

crNorm = norm(cr); %m/s

crpNorm = norm(crp); %m/s

vp = v + (dot(cr, n))*n; %m/s

v1p = v1 - (dot(cr, n))*n; %m/s

x = acos(dot(cr,crp)/(norm(cr)*norm(crp))); %radians

theta = (pi()-x)/2; 

b = d*sin(theta); %Angstrom

