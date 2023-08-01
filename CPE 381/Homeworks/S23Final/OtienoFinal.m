%% ===========================================================
% Dan Otieno.
% CPE 381 Final.
% 04/26/23.
%% ==================== Q12 ==================================
% This was completed manually but plotted in MATLAB to double-check myself.
xn = [0.1 0.3 0.24 0.39 0.41 0.3 0.23 -0.2 -0.15 0.2 0.4]
hn = [-0.1 0.2 -0.05]
y = conv(xn, hn)
stem(y)
grid on
%% ==================== Q18 ==================================
load('final_exam.mat');
Fs= 200;
NFFT = 1024;
dF = Fs/ NFFT; 
t = (0:NFFT-1)*dF;
M_win = hanning(1024); 
x = x .* transpose(M_win);
FFT_x = fft(x,1024);
FFT_x = abs(FFT_x);
plot(t,FFT_x);
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on
%--------------------------------------------------------------


