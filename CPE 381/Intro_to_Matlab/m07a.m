% m07a.m
% Image Processing Examples 
%
% Emil Jovanov
%

%% let's import the image
A=imread('rose_BW.jpg'); % black and white image of the rose
B=A(:,:,1);
imshow(B)


%% processing
B(1:100,:)=0; % initilize all pixels in the first 100 rows to "black"
%B(1:100,:)=255;
imshow(B)


%% 
isize=size(B);
N=isize(1); % number of rows
M=isize(2); % number of columns

for i=1:N % for all rows
    for j=1:M % for all columns
        if i==j % is this pixel on diagonal?
            B(i,j)=255; % set it to "white" or maximum intensity
        end % if
    end % end for all cols
end % end for all rows

% show modified image
imshow(B)


%% let's make a small image
C=zeros(4,4,3); % 4 rows, 4 columns, 3 components (RGB)
C(1,1,1)=255; % red component, set it to max
C(2,2,2)=255; % green component, set it to max
C(3,3,3)=255; % blue component, set it to max
C(4,4,1)=255; % white
C(4,4,2)=255; % white
C(4,4,3)=255; % white
figure
image(C)


