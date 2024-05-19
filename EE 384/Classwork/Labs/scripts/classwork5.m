%% ========================================================================================
% Dan Otieno.
% EE 384 -> Spring '24.
% Classwork 5.
% Due date: 02/20/24.
% Credit to Sayan Samanta for assistance with Matlab scripts.
%% Question 1a - Read and show image lena.bmp.
close all;clear all;clc
q1a = imread('lena.bmp');
figure(1);
imshow(q1a);
title('Display of original image.');
%% Question 1b - Convert image into gray-scale using rgb2gray function.
q1b = rgb2gray(q1a);
figure(2);
imshow(q1b);
title('Display of image converted using Matlab function.');
%% Question 1c - Write custom function to convert image to grayscale, test it.
q1c = fnRGBtoGray(q1a);
figure(3);
imshow(q1c);
title('Display of image converted using my function.');
%% Question 1d - Save the converted image as lena_gray.jpg.
imwrite(q1c, 'lena_gray.jpg');
%% Question 2a - Read and show lowcontrast.jpg.
q2a = imread('lowcontrast.jpg');
figure(4);
imshow(q2a);
title('Display of original low-contrast image.');
%% Question 2b - Show the histogram of the image using "imhist".
figure(5);
imhist(q2a);
title('Histogram of original low-contrast image using imhist function.');
%% Question 2c - Use histeq to enhance contrast using histogram equalization.
q2c = histeq(q2a);
figure(6);
imhist(q2c);
title('Histogram of enhanced low-contrast image using histeq function.');
figure(7);
imshow(q2c);
title('Display of enhanced low-contrast image.');
%% Question 3a - Add Salt&Pepper noise to lena's gray-scale image using imnoise.
q3a = imread('lena_gray.jpg');
noise = imnoise(q3a, 'salt & pepper', 0.05);
figure(8);
imshow(noise);
title('Image with Salt & Pepper noise.');
%% Question 3b - Filter the noise using medfilt2 with 3x3 window.
q3b = medfilt2(noise);
figure(9);
imshowpair(noise, q3b, 'montage');
title('Salt&Pepper noise vs. Filtered with medfilt2 (3x3) to remove noise.');
%% Question 3c - Filter the noise using medfilt2 with 5x5 window.
x = 5;
y = 5;
q3c = medfilt2(noise, [x y]);
figure(10);
imshowpair(noise, q3c, 'montage');
title('Salt&Pepper noise vs. Filtered with medfilt2 (5x5) to remove noise.');
fprintf("===============================================================================\n");
fprintf("When window size is increased, the filtering is more effective to remove noise.\n");
fprintf("However, the drawback of that, is the resulting filtered image is blurrier.\n");
fprintf("===============================================================================\n");
%% Functions.
function grImage = fnRGBtoGray(A)
    grImage = 0.3*A(:,:,1) + 0.6*A(:,:,2) + 0.1*A(:,:,3);
end