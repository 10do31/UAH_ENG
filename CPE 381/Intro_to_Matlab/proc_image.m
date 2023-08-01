% proc_image.m
% Image processing example
% E. Jovanov
% Feb 2020
%

%% Read image and initialize dimensions
A=imread('uah_night.jpg');
% image(A)
imsize=size(A); % size of the image?
N=imsize(1); M=imsize(2);    % how many rows and columns?

%% process image
A1=A;   % processed image, just copy the old one
cnt=0;  % counter
for i=1:N % for all rows
    for j=1:M   % and columns
        for k=1:3   % and pixel components
            % A1(i,j,k)=0;
            % A1(i,j,k)=255;
            % A1(i,j,k)=A1(i,j,1);
            A1(i,j,k)=255-A1(i,j,k);
            % how many pixels have red component smaller than the blue?
%             if A1(i,j,1) < A1(i,j,3)
%                 cnt=cnt+1;
%             end
        end
    end
end
fprintf('The number of red components smaller than blue is %d\n',cnt)

% and plot the results
subplot(121)
image(A)
subplot(122)
% image(A(:,:,1))
image(A1)
