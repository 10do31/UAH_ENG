% eng101 M06 examples
%
% E. Jovanov
%

%% #1 for loop example
% the same problem
for i=1:4   % execute for all values of i starting with 1 until 4 with increment 1
    fprintf('loop counter: %d, square: %d\n',i,i.^2) % print statement
end
fprintf('\n')



%% #2 factorial example
n = 1; % initialize counter
nFactorial = 1; % initialize the result with factorial of 1
while nFactorial < 1e5 % while the result is less than 100000
    n = n + 1;	% update counter
    nFactorial = nFactorial * n; % new value is previous value multiplied 
					% with the current value of the counter
end
fprintf('The maximum value of n for factorial < 100,000 is %d\n',n-1)
fprintf('  and the value of the factorial is %d\n',factorial(n-1))


%% #3 while loop example
% print squares of the first 4 integers
i=1; % start from 1
while i<5 % for all numbers less than 5
    fprintf('%d ',i.^2); % print the square of the current number
    i=i+1;               % update the counter, go to the next number in sequence
end
fprintf('\n')


%% #4 break example
% Sum a sequence of random numbers until the next random number 
%   is greater than an upper limit. 
%   Then, exit the loop using a break statement

limit = 0.8; s = 0; % initialize variables
niter=1;
while 1 % infinite loop
  tmp = rand; % generate new random number
  fprintf('%d: random value: %.2f\n',niter,tmp)
  if tmp > limit % is the greater than the limit
    break % exit the loop
  end 
  niter=niter+1;    % update my loop counter
  s = s + tmp; % update the sum by adding the latest number and continue
end

fprintf('Random number is %.2f and sum is %.2f\n',tmp,s)



%% #5 for loop vs logic example
% generate 1,000 integers with values 1 to 100
clc
xrand=randi(100,1,1000);
% for loop
j=0; % initialize counter
for i=1:length(xrand) 	% fo all elements of the random array
    if (xrand(i)>4 & xrand(i)<10) % check if the value is between 4 and 10
        j=j+1;	% if it is, increment the counter
    end
end
fprintf('The number of values between 4 and 10 is %d\n',j)



%% logic example
% alternative approach to previous problem
s1=xrand>4; % all elements >4
s2=xrand<10; % all elements <10
sum(s1&s2)



%% File I/O example
% write text file with program generated text strings
%

fid=fopen('m06test.txt','wt'); % open the file
fprintf(fid,'ENG101\n');    % write 1st line of text
fprintf(fid,'Emil Jovanov\n'); % write 2nd line of text
fclose(fid); % close the file

% you can open the file and read it in Windows Explorer or similar program


%% reading binary file
% counting number of characters and lines in binary file
%
clc
fname='ENG101_F2020.pdf';   % define file name
fid=fopen(fname,'rb');  % open the file as 'binary' for 'read' operations
i=0;    % initialize character couner
num_lines=0; % initialize variable with the number of lines

while(~feof(fid))   % until the end of the file
    c=fread(fid,1,'char');  % read one byte, one character!
    i=i+1;          % update number of bytes/characters
    if c == 10      % is current character CARRIAGE RETURN?
        num_lines=num_lines+1;          % update line counter
    end
end
fclose(fid);         % close the file

% print the result
fprintf('Length of the file %s is %d bytes\n',fname,i);
fprintf('  and file has %d lines\n',num_lines);
