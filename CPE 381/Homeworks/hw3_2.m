%% Dan Otieno.
%% CPE 381-01.
%% Homework 3 - Q2.
%% 02/18/2023.
syms t x1 x2
x1=4*exp(-2*t)*cos(8*t)*heaviside(t);
x2=4*exp(-4*t)*cos(8*t)*heaviside(t);

% X1 = (5*(s + 2))/((s + 2)^2 + 64)
% X1 = (5*s+10)/(s^2+4*s+68)
X1=laplace(x1)
splane([5 10],[1 4 68])

% X2 = (5*(s + 4))/((s + 4)^2 + 64)
% X2 = (5*s+20)/(s^2+8*s+80)
X2=laplace(x2)
figure
splane([5 20],[1 8 80])