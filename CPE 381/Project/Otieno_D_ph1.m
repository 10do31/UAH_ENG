%% CPE 381 - Project - Phase 1.
% Dan Otieno.
%% ============================================= %%
auHeader = audioinfo("Otieno_D_orig.wav");
auData = audioread("Otieno_D_orig.wav");
%% ============================================= %%
data(1:14*11025, 1)= auData(1:14*11025, 1);
data(1:14*11025, 2)= auData(1:14*11025, 2);

Fs = auHeader.SampleRate;
nSamples = length(data);

% Signal replaced at t = 7 secs.
muteAudio = data;
len1 = 7*auHeader.SampleRate;
len2 = length(data);
nLen = (len1+1):len2;
muteAudio(nLen, :) = 0;
%% ============================================= %%
t = nLen./Fs;
muteAudio(nLen, 1) = 0.3*sin(2*pi*1810.*t + pi/4);
muteAudio(nLen, 2) = 0.25*sin(2*pi*1990.*t + 3*pi/4);

audiowrite('Otieno_D_mod.wav', muteAudio, 11025)
%% ============================================= %%