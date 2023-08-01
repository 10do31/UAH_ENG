%% =============================================== %%
% Dan Otieno
% CPE 381
% Project Phase II
%-------------------------------------------------------
%% Modified Wav file Spectrum (Input).
[y,Fs]= audioread('Otieno_D_mod.wav');
s1=y(:,1); % s1 will represent the spectrum plots for mod.wav.
figure;
plot(s1)
grid on;
%-------------------------------------------------------
%% Filtered Wav file Spectrum.
[y,Fs]= audioread('Otieno_D_filt.wav');
s2=y(:,1); % s2 will represent the spectrum plots for filt.wav.
figure;
plot(s2)
grid on;
%--------------------------------------------------------