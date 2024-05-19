%% ========================================================================================
% Dan Otieno.
% EE 384 -> Spring '24.
% Classwork 4.
% Due date: 02/13/24.
% Credit to Sayan Samanta for assistance with Matlab scripts.
%% Question 1 -- Variables.
close all;clear all;clc
fs = 8e3;
ts = 1/fs;
t = 0:ts:0.05;
f1 = 1209;
f2 = 1336;
y1 = cos(2*pi*f1*t);
y2 = cos(2*pi*f2*t);
y = y1 + y2;
%% Problem 1a - Plot y(t) in Frequency and Time domains.
% Time domain.
subplot(3,1,1)
grid on
plot(fs*t, y1, 'r-'), title('1209 hz sine wave');
subplot(3,1,2)
grid on
plot(fs*t, y2, 'b-'), title('1336 hz sine wave');

figure(1);
subplot(3,1,3)
grid on
plot(fs*t, y, 'k-'), title('Signal y(t)');

% Magnitude response.
L = length(y);
n = pow2(nextpow2(L));
y_dft = fft(y, n);
y_s = fftshift(y_dft);
f = (-n/2:n/2-1) * (fs/n);

figure(2);
plot(f, abs(y_s)/n, 'm-');
grid on
title('Q1a. Plot of y(t) in Frequency Domain.');
%% Problem 1b - Design low-pass filter.
% Butterworth Lowpass filter design.
Wp = (2*f1)/fs;
Ws = (2*f2)/fs;
Rp = 3;
Rs = 40;
[l, Wn] = buttord(Wp, Ws, Rp, Rs);
[b, a] = butter(l, Wn, 'low');
yf = filter(b, a, y);

figure(3);
n = 512;
freqz(b, a, n, fs);

% Magnitude response.
L = length(yf);
n = pow2(nextpow2(L));
yf_dft = fft(yf, n);
y_s = fftshift(y_dft);
f = (-n/2:n/2-1) * (fs/n);

figure(4);
subplot(2,1,1);
plot(t, yf, 'b-');grid on;xlabel('Time');ylabel('Magnitude');
title('Q1b. Plot of signal in the time domain');
subplot(2,1,2);
plot(f, abs(y_s)/n, 'k-');grid on;xlabel('Frequency(Hz)');
ylabel('Q1b. Magnitude response of the signal.');
%% Problem 1c - Design high-pass filter.
% Elliptic Highpass filter design.
Wp = (2*f2)/fs;
Ws = (2*f1)/fs;
Rp = 3;
Rs = 40;
[h, Wn] = ellipord(Wp, Ws, Rp, Rs);
[b1, a1] = ellip(h, Rp, Rs, Wn, 'high');
yfh = filter(b1, a1, y);

figure(5);
freqz(b1, a1, n, fs);

% Magnitude response.
L = length(yfh);
n = pow2(nextpow2(L));
yh_dft = fft(yfh, n);
yh_s = fftshift(yh_dft);
f = (-n/2:n/2-1) * (fs/n);

figure(6);
subplot(2,1,1);
plot(t, yfh, 'r-');grid on;xlabel('Time');ylabel('Magnitude');
title('Q1c. Plot of signal in the time domain');
subplot(2,1,2);
plot(f, abs(yh_s)/n, 'k-');grid on;xlabel('Frequency(Hz)');
title('Q1c. Magnitude response of the signal.');
%% Problem 1d - design band-pass filter.
% Bandpass
Wp = (2*[1200 1225])/fs;
Ws = (2*[1110 1240])/fs;
Rp = 3;
Rs = 40;
[bp, Wn] = ellipord(Wp, Ws, Rp, Rs);
[b2, a2] = ellip(bp, Rp, Rs, Wn, 'bandpass');
yfb = filter(b2, a2, y);

figure(7);
freqz(b2, a2, n, fs);
% Magnitude response.
L = length(yfb);
n = pow2(nextpow2(L));
yb_dft = fft(yfb, n);
yb_s = fftshift(yb_dft);

figure(8);
subplot(2,1,1);
plot(t, yfb, 'm-');grid on;xlabel('Time');ylabel('Magnitude');
title('Q1d. Plot of signal in the time domain');
subplot(2,1,2);
plot(f, abs(yb_s)/n, 'k-');grid on;xlabel('Frequency(Hz)');
title('Q1d. Magnitude response of the signal.');

%% Problem 2a - Plot ECG_signal versus time domain.
load SAMPLE_ECG.mat
x = ECG_Data;
Fs = 512;
T = length(x) / Fs;
dt = 1/Fs;
t2 = 0:dt:T-dt;
% 
figure(9);
plot(t2, x, 'b-');grid on;xlabel('Time');ylabel('ECG Signal');
title('Q2a. ECG Signal versus Time Domain.');
hRate = (length(findpeaks(x)) / length(x)) * 60; % Number of peaks per minute.
hRateSecs = 1 / (hRate / 60); % Invert heart rate to get time per beat.
fprintf("===============================================================================\n");
fprintf('Estimated Heart Rate: %.2f beats per minute or %.2f seconds per beat.\n', hRate, hRateSecs);
fprintf("===============================================================================\n");
%% Problem 2b - Plot frequency spectrum of the ECG signal.
L = length(x);
n = pow2(nextpow2(L));
Y_dft = fft(x, n);
Y_s = fftshift(Y_dft);
f = (-n/2:n/2-1) * (Fs/n);

figure(10);
plot(f, abs(Y_s)/n, 'r-');grid on;xlabel('Frequency (Hz).');
ylabel('Amplitude.');
title('Q2b. Frequency spectrum of the ECG Signal.');
%% Problem 2c - Baseline Wander removal.
% Baseline wander removal.
F1 = 0.5;
F2 = 0.2;
Wp = (2*F1)/Fs;
Ws = (2*F2)/Fs;
Rp = 3;
Rs = 40;
[bw, Wn] = ellipord(Wp, Ws, Rp, Rs);
[b, a] = ellip(bw, Rp, Rs, Wn, 'high');
yf = filter(b, a, x);

figure(11);
n = 512;
freqz(b, a, n, Fs);

% Magnitude response.
L = length(x);
n = pow2(nextpow2(L));
Y_dft = fft(x, n);
Y_s = fftshift(Y_dft);
f1 = (-n/2:n/2-1) * (Fs/n);

figure(12);
plot(f1, abs(Y_s)/n, 'r-');grid on;xlabel('Frequency(Hz)');ylabel('Magnitude');
title('Q2c. Frequency Spectrum of the signal.');
%% Problem 3a - Plot message signal versus time.
Fs = 500;
t = 0:1/Fs:1;
f = 10;
m = sin(2*pi*f*t);

figure(13);
plot(t, m, 'g-')
title(['Q3a. Message Signal with f = ', num2str(f), 'Hz'])
xlabel('Time, t.'); ylabel('Amplitude.')
%% Problem 3b - Use my_ammod function.
Fc = 100;
am_mod = my_ammod(m, Fc, Fs);
%% Problem 3c - Plot frequency spectrum of the message signal and modulated signal.
m_psd = periodogram(m);
mod_psd = periodogram(am_mod);

figure(14);
subplot(2,1,1);
plot(10*log10(m_psd));grid on;xlabel('Frequency(Hz)'), ylabel('Magnitude');
title('Q3c.Frequency Spectrum of the Message Signal');

subplot(2,1,2);
plot(10*log10(mod_psd));grid on;xlabel('Frequency(Hz)'), ylabel('Magnitude');
title('Frequency Spectrum of the Modulated Signal');

fprintf("===============================================================================\n");
fprintf("Difference between the two plots:\n");
fprintf("The message signal peaks at 10Hz, while the modulated signal peaks at 100Hz.")
fprintf("\n===============================================================================\n");
%% Problem 3d - Use my_amdemod function.
am_demod = my_amdemod(am_mod,Fc,Fs);
% Plot inside function
% Freq specturm plot
figure(15);
d_psd = periodogram(am_mod);
plot(10*log10(d_psd));grid on; xlabel('Frequency'), ylabel('Magnitude');
title('Q3d. Frequency Spectrum of Demodulated Signal');
fprintf("===============================================================================\n");
fprintf("The demodulated signal has less noise compared to the modulated signal.\n");
fprintf("The message signal is better visible on the demodulated plot.")
fprintf("\n===============================================================================\n");
%% Functions.
function am_mod = my_ammod(sig, cf, fa)
    t = (0:length(sig)-1)/fa;
    c = cos(2*pi*cf*t);
    am_mod = sig.*c;
    figure(16);
    plot(t, am_mod, 'm-');grid on;xlabel('Time');ylabel('Amplitude');
    title('MyAmmod: Modulated Signal.');
end

function am_demod = my_amdemod(am_mod, cf, fd)
    t = (0:length(am_mod)-1) / fd;
    c = cos(2*pi*cf*t); 
    am_demod = am_mod.*c;
    figure(17);
    plot(t, am_demod, 'r-');grid on;xlabel('Time');ylabel('Amplitude');
    title('MyAmdemod: Demodulated Signal.');
end