%% ======================================================================== %%
% Dan Otieno.
% CPE 381-01.
% Homework 4 - Q1.
% 03/28/2023.
%% ======================================================================== 
clear all; clf
wmax=20;

n1=[1 0 4*pi^2]; d1= [1 2 (1.25+4*pi^2) (0.25+4*pi^2)];
figure(1)
[w,Hm,Ha]=freqresp_s(n1,d1,wmax);

n2=[1 -3 3+4*pi^2 -(1+4*pi^2)]; d2=[1 3 3+4*pi^2 (1+4*pi^2)];
figure(2)
[w,Hm,Ha]=freqresp_s(n2,d2,wmax);

n3=[1 -1]; d3=[1 3 3+4*pi^2 (1+4*pi^2)];
figure(3)
[w,Hm,Ha]=freqresp_s(n3,d3,wmax);
%% ======================================================================== %%
function [w,Hm,Ha]=freqresp_s(b,a,wmax)
w=0:0.01:wmax;
H=freqs(b,a,w);
Hm=abs(H);
Ha=angle(H)*180/pi;

subplot(311)
plot(w,Hm)
axis([0 wmax 0 1.1*max(Hm)])
ylabel('|H(j \omega)|')
grid
xlabel('\Omega')
title(' Magnitude response')

subplot(312)
plot(w,Ha)
axis([0 wmax 1.1*min(Ha) 1.1*max(Ha)])
ylabel('< H(j \omega)')
xlabel('\Omega')
title(' Phase response')
grid

subplot(313)
splane(b,a)
title('Poles/Zeros')
grid
end
%% ======================================================================== %%