% Dan Otieno.
% Midterm - 03/06/23.
%% Question 2.
load htst.mat

Fs=200; % Sampling frequency.
Ts=1./Fs; % Period.
t=-4:Ts:4; % h(t), -4 <= t <= 4s.

x=zeros(size(t));
x((4*Fs+1):length(t)) = h;

x1=zeros(size(t));
tau=2; % signal delay.
i=(4+tau) * Fs+1;
x1((i-length(h)+1):i)=fliplr(h);

figure(1)
subplot(2,1,1)
plot(t,x, 'b'),title('h(t)'),xlabel('time [s]'), grid on;

subplot(2,1,2)
plot(t,x1,'r'),title('h(tau-t)'),xlabel('time [s]'), grid on;

% What is the value of the h(tau-t) at time t=1.4s?
%HINT: time in the sampled signal is represented as an index of the array.
index=(4+1.4) * Fs+1;
fprintf('Value of h(tau-t) at t = %.1fs: %.3f\n',t(index),x1(index))
% Value at t = 1.4s is printed in the console.


%% Question 4.
figure(2)
subplot(1,2,1)
splane([3 4],[1 2 4]);

subplot(1,2,2)
t=0:0.1:10;
x=3*exp(-t).*cos(sqrt(3)*t)+1/sqrt(3).*exp(-t).*sin(sqrt(3)*t);
plot(t,x, 'm'), title('Zeros and Poles in Laplace domain.'),grid on;
