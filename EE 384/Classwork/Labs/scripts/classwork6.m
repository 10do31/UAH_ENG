%% ========================================================================================
% Dan Otieno.
% EE 384 -> Spring '24.
% Classwork 6.
% Due date: 02/27/24.
% Credit to Sayan Samanta for assistance with Matlab scripts.
%% Problem 1 - Histogram Equalization.
close all;clear all;clc
q1a = imread('lowcontrast.jpg');
figure(1);
imshow(q1a);('Display of original image.');
figure(2);
imhist(q1a);title('Histogram of original image.');

histoeq = fnHisteq(q1a);
figure(3);
imshow(histoeq);title('Display of equalized image.');
figure(4);
imhist(histoeq);title('Histogram of equalized image.');
%% Problem 2 - Loading image.
q2 = imread('lena.bmp');
q2Gray = rgb2gray(q2);
%% Problem 2a - Edge Detection: Roberts Operator.
q2a = edge(q2Gray, "roberts");
figure(5);
imshow(q2a);title('Edge Detection: Roberts.');
%% Problem 2b - Edge Detection: Prewitt Operator.
q2b = edge(q2Gray, "prewitt");
figure(6);
imshow(q2b);title('Edge Detection: Prewitt.');
%% Problem 2c - Edge Detection: Sobel Operator.
q2c = edge(q2Gray, "sobel");
figure(7);
imshow(q2c);title('Edge Detection: Sobel.');
%% Problem 3 - Laplacian Edge Sharpening.
q3 = imread('blur_image.jpg');
C = im2double(q3);
fnLaPlacian(C);
%% Functions.
function value = fnHisteq(imageIn)
    l = 256;
    histo = imhist(imageIn);
    cdf = cumsum(histo);
    norm = cdf / numel(imageIn);
    val = l*norm(double(imageIn) + 1);
    value = uint8(val);
end

function imOut = fnLaPlacian(imIn)
    mask = [-1 -1 -1; -1 8 -1; -1 -1 -1];
    convq3 = imfilter(imIn, mask);

    % normalize image.
    minCov = min(convq3(:));
    maxCov = max(convq3(:));
    convq3 = (convq3 - minCov) / (maxCov - minCov);

    % Sharpening image.
    sharpImg = imIn + convq3;
    minSharp = min(sharpImg(:));
    maxSharp = max(sharpImg(:));
    imOut = (sharpImg - minSharp) / (maxSharp - minSharp);

    imOut = imadjust(imOut, [60/255 200/255], [0 1]);
    figure(8);
    subplot(1,3,1);imshow(imIn);title('Original Image.');
    subplot(1,3,2);imshow(convq3);title('Masked Image.');
    subplot(1,3,3);imshow(imOut);title('Sharpened Image.');
end