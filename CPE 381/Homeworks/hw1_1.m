% Dan Otieno.
% CPE 381-01.
% Homework 1 - Q1.
% 01/27/2023.

%===============================%
k = 0:1:6;
z = exp(1i*pi.*(2*k+1)/7);
%===============================%
plot(real(z),imag(z),'bo')
title('Solutions Plot');
axis equal
grid on
ylabel('Y (Imaginary part)');
xlabel('X (Real part)');
z1 = abs(z(1));
c = linspace(0,2*pi,100);
hold on
plot(z1*cos(c),z1*sin(c),'r-')
%===============================%
