%% ========================================================================================
% Dan Otieno.
% EE 384 -> Spring '24.
% Final Project - Speech Recognition.
% Due date: 04/08/24.
% This program combines python and MATLAB functionalities to...
% ...read, process and transcribe a wav audio file.
% Works cited: 
% "Zhang, A. (2017). Speech Recognition (Version 3.8) [Software].
% Available from https://github.com/Uberi/speech_recognition#readme."
% Instructions:
% 1. Run MATLAB script as "speechproject" (if in MATLAB console).
% 2. Select python script (speak.py).
% 3. Select .wav file when prompted (demoaudio.wav).
% 4. When script is done, see console output, and "transcribed.txt" file.
%% =========================================================================================
clear all; clc;
%-------------------------------------------------------------------------------------------
% Browse for Python file (.py extension specified).
[pythonScript, pythonScriptPath] = uigetfile('*.py', 'Select the Python script');
if pythonScript == 0
    disp('No Python script selected. Exiting program now...');
    return;
end
%-------------------------------------------------------------------------------------------
% Browse for audio file (using wav file for this implementation).
[audioFile, audioPath] = uigetfile('*.wav', 'Select an audio file');
if audioFile == 0
    disp('No audio file selected. Exiting...');
    return;
end
%-------------------------------------------------------------------------------------------
% Get audio file information.
audioFullPath = fullfile(audioPath, audioFile);
audioInfo = audioinfo(audioFullPath);
audioLengthSeconds = audioInfo.TotalSamples / audioInfo.SampleRate;
%-------------------------------------------------------------------------------------------
% Read the audio file and plot the signal waveform.
[y, Fs] = audioread(audioFullPath);

figure;
subplot(2,1,1);
plot((0:length(y)-1)/Fs, y);
xlabel('Time (s)');ylabel('Amplitude');grid on;
title('Audio Signal Waveform');
%-------------------------------------------------------------------------------------------
% Call Python script to transcribe audio and measure processing time.
tic;
[status, result] = system(['python "', fullfile(pythonScriptPath, pythonScript), '" "', audioFullPath, '"']);
processingTime = toc;
%-------------------------------------------------------------------------------------------
% Display transcription information.
if status == 0
    disp('Transcription:');
    disp(result);
    
    % Plot the spectrogram.
    subplot(2,1,2);
    spectrogram(y(:,1), hamming(256), 128, 256, Fs, 'yaxis', 'centered');
    title('Spectrogram');
%-------------------------------------------------------------------------------------------
    % Save transcription output to a text file.
    outputFile = 'transcribed.txt';
    fid = fopen(outputFile, 'w');
    fprintf(fid, '%s', result);
    fclose(fid);
    disp(['Transcription saved to ' outputFile]);
%-------------------------------------------------------------------------------------------   
    % Display additional information on console and save to text file.
    additionalInfo = sprintf('\n\nAdditional Information:\nAudio Length: %.2f seconds\nSampling Rate: %d Hz\nProcessing Time: %.2f seconds', audioLengthSeconds, audioInfo.SampleRate, processingTime);
    disp(additionalInfo);
    fid = fopen(outputFile, 'a');
    fprintf(fid, '%s', additionalInfo);
    fclose(fid);
    disp(['Additional information saved to ' outputFile]);
else
    disp('Error occurred during speech-to-text conversion:');
    disp(result);
end
%-------------------------------------------------------------------------------------------