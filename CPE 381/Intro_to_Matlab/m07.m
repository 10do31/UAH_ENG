% m07.m
%

%% function example

% create a function that would calculate the magnitude 
% of the vector with coordinates (X,Y)
%
X=3;
Y=4;

%m=sqrt(X.^2+Y.^2);

% call my custom function
m=vector_magnitude(X,Y);
disp(m)

m=vector_magnitude(8,19);
disp(m)


function r=vector_magnitude(X,Y)
% vector magnitued function returns magnitude of the 
%   vector from coordinate beginning to point with coordinates (X,Y). 
%   The same as absolute value of the complex number X+jY
% Use:
%   r=vector_magnitude(X,Y)
% Inputs:
%   X,Y point coordinates
% Output:
%   r - vector magnitude
%

r=sqrt(X.^2+Y.^2); % calculate vector magnitude

end
