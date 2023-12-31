% Dan Otieno.
% CPE 381-01.
% Homework 1 - Q4 & Q5.
% 01/30/2023.
%==========================================================================%
% Both Questions 4 and 5 of Homework 1 are included in this MATLAB script.
%==========================================================================%
%==========================================================================%
%                    START QUESTION 4: INITIALIZATION.
%==========================================================================%
Fs = 20;%<-------------------------Sampling frequency.
Ts = 1/Fs;%<-----------------------Sampling interval.
f = 2;%<---------------------------Signal frequency 2Hz.
tmax = 4;%<------------------------Maximum time.
t = -tmax:Ts:tmax;%<---------------Time [s].
N = length(t);%<-------------------Number of elements in Vector.
i0 = round(4*Fs)+1;%<--------------Index of time 0 (4s after -4s).
t1 = 0:Ts:4;%<---------------------Time > 0 [s].
%==========================================================================%
%                    SIGNAL.
%==========================================================================%
A = 2;%<---------------------------Amplitude.
xenv = A*exp(-t1);%<---------------Envelope A*e^(-t).
x = xenv.*sin(2*pi*f*t1);%<--------Signal for t>0.
y = zeros(1,N);%<------------------Initialize all elements to 0.
y(i0:N) = x;%<---------------------Add values from time 0.
%==========================================================================%
%                    SIGNAL PLOT: END QUESTION 4.
%==========================================================================%
figure%<---------------------------New Figure. 
plot(t,y,t1,xenv,'r:',t1,-xenv,'r:'), xlabel('t [s]'), ylabel('y'), grid on;
title('Signal Plot for Question 4.');
%==========================================================================%
%                    START QUESTION 5: SIGNAL IS y(2-Tau).
%==========================================================================%
tau = 2;%<-------------------------Tau (delay) = 2[s].
t3 = 0:Ts:(tmax+tau);%<------------New time to include with original plot.
N3 = length(t3);%<-----------------Number of elements.
y3 = zeros(1,N);%<-----------------Initialize elements to 0.
xenv3 = exp(-t3);%<----------------This is our envelope.
x3 = A*xenv3.*sin(2*pi*f.*t3);%<---Signal for t3>0.
y3(1:N3) = fliplr(x3);
%==========================================================================%
%                    SIGNAL PLOT.
%==========================================================================%
figure%<---------------------------New Figure.
plot(t,y,'b',t1,xenv,'r:',t1,-xenv,'r:',t,y3,'g');
xlabel('t [s]'), ylabel('y'), grid on;
title('Signal Plot for Question 5.');
legend('y(t)','+ve envelope', '-ve envelope', 'y(2-t)');
%==========================================================================%
%                    End of Script.
%==========================================================================%


