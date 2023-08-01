% m05.m
%
% Module 5 examples
% 
% E. Jovanov
%

%% Conditional execution
a=input('What is the value of a? ');
if a>4
    a=a+2;
end

if a>3 
    fprintf('a is greater than 3\n')
else
    fprintf('a is smaller than 3\n')
end

%% while loop example
% print squares of the first 4 integers
i=1; % start from 1
while i<5 % for all numbers less than 5
    fprintf('%d ',i.^2); % print the square of the current number
    i=i+1;               % update the counter, go to the next number in sequence
end
fprintf('\n')

%% for loop example
% the same problem
for i=1:4   % execute for all values of i starting with 1 until 4 with increment 1
    fprintf('%d ',i.^2); % print statement
end
fprintf('\n')

