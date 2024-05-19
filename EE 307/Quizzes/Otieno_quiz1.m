%% ========================================================================================
% Dan Otieno.
% EE 307 -> Spring '24.
% Project 1.
% Due date: 03/08/24.
%% 
close all;clear all;clc;
% Constants
k = 8.9875517923e9;     % Coulomb's constant in N*m^2/C^2.
Q = 0.1e-6;     % Charge in Coulombs.
theta = deg2rad(30);    % Angle from x-axis in radians.
d = 1;      % Spacing between charges in meters.
n = 18238; % Number of charges.
x = zeros(1,n);
y = zeros(1,n);
z = zeros(1,n);
for i = 1:n
    x(i) = (i-1) * d * cos(theta); % x-coordinate.
    y(i) = (i-1) * d * sin(theta); % y-coordinate.
    % Charges lie in the x-y plane, so z(i) = 0.
end

% Define points we want to calculate.
point1 = [12115, 10272, 45];
point2 = [20265, 11792, 125];
point3 = [16623, 15321, 1456];

% Calculate the force on Q0.
F = [0, 0, 0]; % Initialize force vector.
for i = 2:n
    r = [x(i) - x(1), y(i) - y(1), z(i) - z(1)]; % Position vector from Q0 to Qi.
    r_mag = norm(r); % Magnitude of the position vector.
    F = F - k * Q^2 * r / r_mag^3; % Add contribution to force from each charge.
end

% Calculate electric field intensity at point1.
E = [0, 0, 0]; % Initialize electric field vector.
for i = 1:n
    r = point1 - [x(i), y(i), z(i)]; % Position vector from charge to point1.
    r_mag = norm(r); % Magnitude of the position vector
    E = E + k * Q * r / r_mag^3; % Add contribution to electric field from each charge.
end

% Calculate electric flux density at point2.
D = [0, 0, 0]; % Initialize electric flux density vector.
for i = 1:n
    r = point2 - [x(i), y(i), z(i)]; % Position vector from charge to point2.
    r_mag = norm(r); % Magnitude of the position vector
    D = D + k * Q / (4 * pi) * r / r_mag^3; % Add contribution to electric flux density from each charge.
end

% Calculate electric potential at point3.
V = 0; % Initialize electric potential.
for i = 1:n
    r = point3 - [x(i), y(i), z(i)]; % Position vector from charge to point3.
    r_mag = norm(r); % Magnitude of the position vector.
    V = V + k * Q / r_mag; % Add contribution to electric potential from each charge.
end

% Output results.
disp(['Force on Q0: ', num2str(F)]);
disp(['Electric field intensity at point1: ', num2str(E)]);
disp(['Electric flux density at point2: ', num2str(D)]);
disp(['Electric potential at point3: ', num2str(V)]);