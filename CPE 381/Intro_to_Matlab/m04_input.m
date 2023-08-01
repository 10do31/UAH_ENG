% m04_input.m
%
% Description: using MATLAB user input for publishing
%
% E. Jovanov 
% September 2020
%

%% Numeric input
% speed = input('Enter speed in [mph]: ')



%% Input for publishing
speed=str2num(cell2mat(inputdlg('Enter speed in [mph]: ')));
speed
