%% ========================================================================================
% Dan Otieno.
% EE 307 -> Spring '24.
% Quiz 2.
% Due date: 04/02/24.
%% 
close all; clear all, clc;
I = 1; % current.
a = 1; % side length of the square loop.
dl = 0.001; 

% Unit vectors.
ax = [1 0 0];
ay = [0 1 0];
az = [0 0 1];

% Initialize total magnetic field (H = 0).
H = [0 0 0];
% Looping through y values.
for y = -a:dl:a
    R = sqrt(y^2 + a^2);
    dH = cross(I * dl * ay, [-a -y 0]) / (pi * R^3);
    H = H + dH;
end

% Normalizing H.
H_mag = norm(H);
H_dir = H / H_mag;

% Displaying results.
disp('Magnetic field (H) at the center of the loop:');
disp(['Magnitude: ', num2str(H_mag)]);
disp(['Direction: ', num2str(H_dir)]);