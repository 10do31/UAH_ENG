% plotMrmRetLog.m
% This script prompts the user for a MRM-RET logfile, reads, parses, and
% produces a "waterfall plot" of the motion filtered scans and detection lists 
% in the logfile
clear all; close all; clc

%% Query user for logfile - pii 6.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb6,dnmb6] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb6,fnmb6));
[cfgb6,reqb6,scnb6,det6] = readMrmRetLog(fullfile(dnmb6,fnmb6));

[fnmt6,dnmt6] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt6,fnmt6));
[cfgt6,reqt6,scnt6,dett6] = readMrmRetLog(fullfile(dnmt6,fnmt6));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 6.
rawscansIb6 = find([scnb6.Nfilt] == 1);
rawscansV_background6 = reshape([scnb6(rawscansIb6).scn],[],length(rawscansIb6))';

rawscansIt6 = find([scnt6.Nfilt] == 1);
rawscansV_target6 = reshape([scnt6(rawscansIt6).scn],[],length(rawscansIt6))';

scan_difference6 = abs(rawscansV_background6 - rawscansV_target6);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference6(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background6(10,:)), title('Background Plot for pii 6.')  
%Taget plot
figure; plot(Rbin,rawscansV_target6(10,:)), title('Target Plot for pii 6.')
% Difference plot
figure;plot(Rbin,scan_difference6(10,:)), title('Difference Plot for pii 6.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a6,i]=max(scan_difference6(10,:));
%distance = Rbin(i)
noise_sample6 = scan_difference6(10,125:175);

noise_var6 = var(noise_sample6);
SNR6= 10*log10(a6^2/noise_var6);
PII6=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 7.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb7,dnmb7] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb7,fnmb7));
[cfgb7,reqb7,scnb7,det7] = readMrmRetLog(fullfile(dnmb7,fnmb7));

[fnmt7,dnmt7] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt7,fnmt7));
[cfgt7,reqt7,scnt7,dett7] = readMrmRetLog(fullfile(dnmt7,fnmt7));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 7.
rawscansIb7 = find([scnb7.Nfilt] == 1);
rawscansV_background7 = reshape([scnb7(rawscansIb7).scn],[],length(rawscansIb7))';

rawscansIt7 = find([scnt7.Nfilt] == 1);
rawscansV_target7 = reshape([scnt7(rawscansIt7).scn],[],length(rawscansIt7))';

scan_difference7 = abs(rawscansV_background7 - rawscansV_target7);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference7(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background7(10,:)), title('Background Plot for pii 7.')  
%Taget plot
figure; plot(Rbin,rawscansV_target7(10,:)), title('Target Plot for pii 7.')
% Difference plot
figure;plot(Rbin,scan_difference7(10,:)), title('Difference Plot for pii 7.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a7,i]=max(scan_difference7(10,:));
%distance = Rbin(i)
noise_sample7 = scan_difference7(10,125:175);

noise_var7 = var(noise_sample7);
SNR7= 10*log10(a7^2/noise_var7);
PII7=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 8.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb8,dnmb8] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb8,fnmb8));
[cfgb8,reqb8,scnb8,det8] = readMrmRetLog(fullfile(dnmb8,fnmb8));

[fnmt8,dnmt8] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt8,fnmt8));
[cfgt8,reqt8,scnt8,dett8] = readMrmRetLog(fullfile(dnmt8,fnmt8));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 8.
rawscansIb8 = find([scnb8.Nfilt] == 1);
rawscansV_background8 = reshape([scnb8(rawscansIb8).scn],[],length(rawscansIb8))';

rawscansIt8 = find([scnt8.Nfilt] == 1);
rawscansV_target8 = reshape([scnt8(rawscansIt8).scn],[],length(rawscansIt8))';

scan_difference8 = abs(rawscansV_background8 - rawscansV_target8);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference8(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background8(10,:)), title('Background Plot for pii 8.')  
%Taget plot
figure; plot(Rbin,rawscansV_target8(10,:)), title('Target Plot for pii 8.')
% Difference plot
figure;plot(Rbin,scan_difference8(10,:)), title('Difference Plot for pii 8.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a8,i]=max(scan_difference8(10,:));
%distance = Rbin(i)
noise_sample8 = scan_difference8(10,125:175);

noise_var8 = var(noise_sample8);
SNR8= 10*log10(a8^2/noise_var8);
PII8=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 9.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb9,dnmb9] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb9,fnmb9));
[cfgb9,reqb9,scnb9,det9] = readMrmRetLog(fullfile(dnmb9,fnmb9));

[fnmt9,dnmt9] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt9,fnmt9));
[cfgt9,reqt9,scnt9,dett9] = readMrmRetLog(fullfile(dnmt9,fnmt9));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 9.
rawscansIb9 = find([scnb9.Nfilt] == 1);
rawscansV_background9 = reshape([scnb9(rawscansIb9).scn],[],length(rawscansIb9))';

rawscansIt9 = find([scnt9.Nfilt] == 1);
rawscansV_target9 = reshape([scnt9(rawscansIt9).scn],[],length(rawscansIt9))';

scan_difference9 = abs(rawscansV_background9 - rawscansV_target9);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference9(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background9(10,:)), title('Background Plot for pii 9.')  
%Taget plot
figure; plot(Rbin,rawscansV_target9(10,:)), title('Target Plot for pii 9.')
% Difference plot
figure;plot(Rbin,scan_difference9(10,:)), title('Difference Plot for pii 9.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a9,i]=max(scan_difference9(10,:));
%distance = Rbin(i)
noise_sample9 = scan_difference9(10,125:175);

noise_var9 = var(noise_sample9);
SNR9= 10*log10(a9^2/noise_var9);
PII9=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 10.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb10,dnmb10] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb10,fnmb10));
[cfgb10,reqb10,scnb10,det10] = readMrmRetLog(fullfile(dnmb10,fnmb10));

[fnmt10,dnmt10] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt10,fnmt10));
[cfgt10,reqt10,scnt10,dett10] = readMrmRetLog(fullfile(dnmt10,fnmt10));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 10.
rawscansIb10 = find([scnb10.Nfilt] == 1);
rawscansV_background10 = reshape([scnb10(rawscansIb10).scn],[],length(rawscansIb10))';

rawscansIt10 = find([scnt10.Nfilt] == 1);
rawscansV_target10 = reshape([scnt10(rawscansIt10).scn],[],length(rawscansIt10))';

scan_difference10 = abs(rawscansV_background10 - rawscansV_target10);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference10(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background10(10,:)), title('Background Plot for pii 10.')  
%Taget plot
figure; plot(Rbin,rawscansV_target10(10,:)), title('Target Plot for pii 10.')
% Difference plot
figure;plot(Rbin,scan_difference10(10,:)), title('Difference Plot for pii 10.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a10,i]=max(scan_difference10(10,:));
%distance = Rbin(i)
noise_sample10 = scan_difference10(10,125:175);

noise_var10 = var(noise_sample10);
SNR10= 10*log10(a10^2/noise_var10);
PII10=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 11.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb11,dnmb11] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb11,fnmb11));
[cfgb11,reqb11,scnb11,det11] = readMrmRetLog(fullfile(dnmb11,fnmb11));

[fnmt11,dnmt11] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt11,fnmt11));
[cfgt11,reqt11,scnt11,dett11] = readMrmRetLog(fullfile(dnmt11,fnmt11));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 11.
rawscansIb11 = find([scnb11.Nfilt] == 1);
rawscansV_background11 = reshape([scnb11(rawscansIb11).scn],[],length(rawscansIb11))';

rawscansIt11 = find([scnt11.Nfilt] == 1);
rawscansV_target11 = reshape([scnt11(rawscansIt11).scn],[],length(rawscansIt11))';

scan_difference11 = abs(rawscansV_background11 - rawscansV_target11);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference11(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background11(10,:)), title('Background Plot for pii 11.')  
%Taget plot
figure; plot(Rbin,rawscansV_target11(10,:)), title('Target Plot for pii 11.')
% Difference plot
figure;plot(Rbin,scan_difference11(10,:)), title('Difference Plot for pii 11.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a11,i]=max(scan_difference11(10,:));
%distance = Rbin(i)
noise_sample11 = scan_difference11(10,125:175);

noise_var11 = var(noise_sample11);
SNR11= 10*log10(a11^2/noise_var11);
PII11=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 12.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb12,dnmb12] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb12,fnmb12));
[cfgb12,reqb12,scnb12,det12] = readMrmRetLog(fullfile(dnmb12,fnmb12));

[fnmt12,dnmt12] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt12,fnmt12));
[cfgt12,reqt12,scnt12,dett12] = readMrmRetLog(fullfile(dnmt12,fnmt12));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 12.
rawscansIb12 = find([scnb12.Nfilt] == 1);
rawscansV_background12 = reshape([scnb12(rawscansIb12).scn],[],length(rawscansIb12))';

rawscansIt12 = find([scnt12.Nfilt] == 1);
rawscansV_target12 = reshape([scnt12(rawscansIt12).scn],[],length(rawscansIt12))';

scan_difference12 = abs(rawscansV_background12 - rawscansV_target12);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference12(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background12(10,:)), title('Background Plot for pii 12.')  
%Taget plot
figure; plot(Rbin,rawscansV_target12(10,:)), title('Target Plot for pii 12.')
% Difference plot
figure;plot(Rbin,scan_difference12(10,:)), title('Difference Plot for pii 12.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a12,i]=max(scan_difference12(10,:));
%distance = Rbin(i)
noise_sample12 = scan_difference12(10,125:175);

noise_var12 = var(noise_sample12);
SNR12= 10*log10(a12^2/noise_var12);
PII12=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 13.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb13,dnmb13] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb13,fnmb13));
[cfgb13,reqb13,scnb13,det13] = readMrmRetLog(fullfile(dnmb13,fnmb13));

[fnmt13,dnmt13] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt13,fnmt13));
[cfgt13,reqt13,scnt13,dett13] = readMrmRetLog(fullfile(dnmt13,fnmt13));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 13.
rawscansIb13 = find([scnb13.Nfilt] == 1);
rawscansV_background13 = reshape([scnb13(rawscansIb13).scn],[],length(rawscansIb13))';

rawscansIt13 = find([scnt13.Nfilt] == 1);
rawscansV_target13 = reshape([scnt13(rawscansIt13).scn],[],length(rawscansIt13))';

scan_difference13 = abs(rawscansV_background13 - rawscansV_target13);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference13(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background13(10,:)), title('Background Plot for pii 13.')  
%Taget plot
figure; plot(Rbin,rawscansV_target13(10,:)), title('Target Plot for pii 13.')
% Difference plot
figure;plot(Rbin,scan_difference13(10,:)), title('Difference Plot for pii 13.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a13,i]=max(scan_difference13(10,:));
%distance = Rbin(i)
noise_sample13 = scan_difference13(10,125:175);

noise_var13 = var(noise_sample13);
SNR13= 10*log10(a13^2/noise_var13);
PII13=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 14.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb14,dnmb14] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb14,fnmb14));
[cfgb14,reqb14,scnb14,det14] = readMrmRetLog(fullfile(dnmb14,fnmb14));

[fnmt14,dnmt14] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt14,fnmt14));
[cfgt14,reqt14,scnt14,dett14] = readMrmRetLog(fullfile(dnmt14,fnmt14));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 14.
rawscansIb14 = find([scnb14.Nfilt] == 1);
rawscansV_background14 = reshape([scnb14(rawscansIb14).scn],[],length(rawscansIb14))';

rawscansIt14 = find([scnt14.Nfilt] == 1);
rawscansV_target14 = reshape([scnt14(rawscansIt14).scn],[],length(rawscansIt14))';

scan_difference14 = abs(rawscansV_background14 - rawscansV_target14);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference14(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background14(10,:)), title('Background Plot for pii 14.')  
%Taget plot
figure; plot(Rbin,rawscansV_target14(10,:)), title('Target Plot for pii 14.')
% Difference plot
figure;plot(Rbin,scan_difference14(10,:)), title('Difference Plot for pii 14.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a14,i]=max(scan_difference14(10,:));
%distance = Rbin(i)
noise_sample14 = scan_difference14(10,125:175);

noise_var14 = var(noise_sample14);
SNR14= 10*log10(a14^2/noise_var14);
PII14=2.^(6:15);

% ----------------------------------------------------------------------------------------------------------

%% Query user for logfile - pii 15.
%dnm = '.'; fnm = 'MRM_002.csv';
[fnmb15,dnmb15] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmb15,fnmb15));
[cfgb15,reqb15,scnb15,det15] = readMrmRetLog(fullfile(dnmb15,fnmb15));

[fnmt15,dnmt15] = uigetfile('*.csv');
fprintf('Reading logfile %s\n',fullfile(dnmt15,fnmt15));
[cfgt15,reqt15,scnt15,dett15] = readMrmRetLog(fullfile(dnmt15,fnmt15));

%% Separate raw, bandpassed, and motion filtered data from scn structure
% (only motion filtered is used)

%% Pull out the raw scans (if saved) - pii 15.
rawscansIb15 = find([scnb15.Nfilt] == 1);
rawscansV_background15 = reshape([scnb15(rawscansIb15).scn],[],length(rawscansIb15))';

rawscansIt15 = find([scnt15.Nfilt] == 1);
rawscansV_target15 = reshape([scnt15(rawscansIt15).scn],[],length(rawscansIt15))';

scan_difference15 = abs(rawscansV_background15 - rawscansV_target15);

%% Create the waterfall horizontal and vertical axes
Tbin = 32/(512*1.024);  % ns
T0 = 0; % ns
c = 0.29979;  % m/ns
Rbin = c*(Tbin*(0:size(scan_difference15(1,:),2)-1) - T0)/2;% Range Bins in meters

%Background plot
plot(Rbin,rawscansV_background15(10,:)), title('Background Plot for pii 15.')  
%Taget plot
figure; plot(Rbin,rawscansV_target15(10,:)), title('Target Plot for pii 15.')
% Difference plot
figure;plot(Rbin,scan_difference15(10,:)), title('Difference Plot for pii 15.')

%[a05,i] = max(scan_difference(10,100:122)); %In a range of distance values
%Rbin=i+99;                                  %100=0.9m, 122=1.1m
[a15,i]=max(scan_difference15(10,:));
%distance = Rbin(i)
noise_sample15 = scan_difference15(10,125:175);

noise_var15 = var(noise_sample15);
SNR15= 10*log10(a15^2/noise_var15);
PII15=2.^(6:15);
% ----------------------------------------------------------------------------------------------------------