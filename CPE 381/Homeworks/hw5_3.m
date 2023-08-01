%% ====================================================%%
% Dan Otieno.
% CPE 381-01.
% Homework 5
%% ====================================================%%
% Q1c.
a=[1 0 -0.4];
b=1;
x=[1 zeros(1,15)];
h=filter(b,a,x);
n=0:15;
figure(1)
stem(n,h); axis([0 15 0 1]);
grid;ylabel('h[n]'); xlabel('n')
%% ====================================================%%
% Q2a, Q2b. Q2e.
a = 1;
b = [0, 1, 2, 3, 4]; 
x = zeros(1,20); 
x(1) = 1;
y = filter(b,a,x);

figure(2)
subplot(221);
plot(y);
grid on;
subplot(222);
impz(y);
grid on;
subplot(223);
stepz(y);
grid on;
%% ====================================================%%
% Q3
% Plot the convolution y[n] = x[n] * h[n]
x = [0, 1, 1, 1, 0]
h = [1.4, 1, 0.3]
y=conv(x, h)
figure(3)
stem(y)
grid on
%% ====================================================%%