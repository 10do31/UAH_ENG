%% Dan Otieno.
%% CPE 381-01.
%% Homework 2 - Q6.
%% 02/18/2023.
syms t x1 x2 x3 x4

x1 = exp(-0.5*t)*cos(10*t)*heaviside(t);
X1=laplace(x1);
x2 = cos(5*t)*heaviside(t);
X2=laplace(x2);
x3 = heaviside(t);
X3=laplace(x3);
x4 = exp(-t)*heaviside(t);
X4 = laplace(x4);

subplot(261)
fplot(x1,[0,10]);grid
axis([0 10 -1.1 1.1]);title('x(t) = exp(-0.5t)*cos(10t)u(t)')
subplot(262)
splane([1 0.5], [1 1 100.25])

subplot(263)
fplot(x2,[0,10]);grid
axis([0 10 -1.1 1.1]);title('x(t) = cos(5t)u(t)')
subplot(264)
splane([1 0], [1 0 25])


subplot(265)
fplot(x3,[0,10]);grid
axis([0 10 0 1.1]);title('x(t) = u(t)')
subplot(266)
splane([0 1], [1 0 2])
%splane([0 1], [1 1])

subplot(267)
fplot(x4,[0,10]);grid
axis([0 10 0 1.1]);title('x(t) = exp(-t)u(t)')
subplot(268)
%splane([0 1], [1 0 2])
splane([0 1], [1 1])
