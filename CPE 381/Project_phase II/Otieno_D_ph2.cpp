/*
Dan Otieno.
CPE 381.
Project - Phase 2.
Please compile using this command: g++ filename.cpp -o whateverNameHere
Run using this command: ./whateverNameHere
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "coeffs1.h"
#include "coeffs2.h"

using namespace std;

// Header Struct (Also contains WAV file control fields).
typedef struct  HEADER
{
    uint8_t         chunkID[4];     //Contains letters "RIFF", 4 bytes in 0 position
    uint32_t        chunkSize;
    uint8_t         format[4];      //Contains letters "WAVE"
    uint8_t         subChunk1ID[4]; //Contains letters "fmt"
    uint32_t        subChunk1Size;  // 16-bit file..
    uint16_t        audioFormat;	//Our format is PCM, pulse-code modulated
    uint16_t        numChannels;	//Number of channels is 2, stereo
    uint32_t        sampleRate;		//Sample rate is 11,025
    uint32_t        byteRate;		//SampleRate* NumChannels * BitsPerSample/8
    uint16_t        blockAlign;		//NumChannels * BitsPerSample/8
    uint16_t        bitsPerSample;	//16 bits per sample
    uint8_t         subchunk2ID[4];	//Contains letters "data"
    uint32_t        subchunk2Size;	//NumSamples * NumChannels * BitsPerSample/8, number of bytes in data
} wHeader;

void fnFilter(double* x, double* y, short sample, double* B, int size);

int main()
{
	wHeader wavHdr;
	const char* fPath;
	string fIn;
	size_t byteshdr;
	float Left,Right; // floating point samples
	int hdrSize, fSize, size;

	hdrSize = sizeof(wHeader);

	//Prompt for user input in command terminal to open mod file.
	cout << "Enter input filename: ";
	getline(cin, fIn);
	fPath  = fIn.c_str();
	cout << "Reading from file path, please wait...." << endl;
	FILE* wFile = fopen(fPath, "rb");

	//Get the size of the file in total
	fseek(wFile, 0, SEEK_END);
	fSize = ftell(wFile);
	fseek(wFile, 0, SEEK_SET);
	cout << "Size of File: " << fSize << endl;
	byteshdr = fread(&wavHdr, hdrSize, 1, wFile);


	//Checking header size.
	int datasize = wavHdr.subchunk2Size * 8 / wavHdr.bitsPerSample;
	cout << "--------------------------------------" << endl;
	cout << "Size of Header(bytes): " << byteshdr << endl;
	cout << "--------------------------------------" << endl;
	// Number of samples
	int bytesPerSample = wavHdr.bitsPerSample / 8;
	cout << "Bits per Sample: " << wavHdr.bitsPerSample << endl;
	cout << "--------------------------------------" << endl;
	cout << "Bytes per sample: " << bytesPerSample << endl;
	cout << "--------------------------------------" << endl;
	int samples = wavHdr.chunkSize / bytesPerSample;
	cout << "Samples: " << samples << endl;
	cout << "--------------------------------------" << endl;
	int smplRate = wavHdr.sampleRate;
	cout << "Sample Rate: " << smplRate << endl;
	cout << "--------------------------------------" << endl;


	//Read and output the contents of the data section of the wave:
	short* audioData = new short[datasize];
	short* outData = new short[datasize];

	// Open file for output (write file).
	FILE* outPut;
	outPut = fopen("Otieno_D_filt.wav", "wb");
	fwrite(&wavHdr, hdrSize, 1, outPut);

	//Start timer:
	clock_t timeStart = clock();

	//Signal Processing for Frequency of 11,025Hz.
	if(smplRate == 11025)
	{
		double* B = new double[BLen1];
		size = BLen1;
		for(int i = 0; i < BLen1; i++)
		{
			B[i] = B0[i];
		}
		double* xLeft = new double[size];
		double* yLeft = new double[size];
		double* xRight = new double[size];
		double* yRight = new double[size];

		for (int i = 0; i < size; i++)
		{
			xLeft[i] = yLeft[i] = xRight[i] = yRight[i] = 0;
		}
		for (int i = 0; i < datasize; i++)
		{
			fread(&audioData[i], sizeof(short), 1, wFile);

			if (i % 2 == 0)
			{
				fnFilter(xLeft, yLeft, audioData[i], B, size);
				outData[i] = (short)yLeft[0];
			}
			else
			{
				fnFilter(xRight, yRight, audioData[i], B, size);
				outData[i] = (short)yRight[0];
			}

			fwrite(&outData[i], sizeof(short), 1, outPut);
		}
	}
	else if (smplRate == 22050)
	{
		size = BLen2;
		double* B = new double[BLen2];
		for (int i = 0; i < BLen2; i++)
		{
			B[i] = B1[i];
		} 

		double* xLeft = new double[size];
		double* yLeft = new double[size];
		double* xRight = new double[size];
		double* yRight = new double[size];
		
		for (int i = 0; i < size; i++)
		{
			xLeft[i] = yLeft[i] = xRight[i] = yRight[i] = 0;
		} 

		for (int i = 0; i < datasize; i++)
		{
			fread(&audioData[i], sizeof(short), 1, wFile);

			if (i % 2 == 0)
			{
				fnFilter(xLeft, yLeft, audioData[i], B, size);
				outData[i] = (short)yLeft[0];
			}
			else
			{
				fnFilter(xRight, yRight, audioData[i], B, size);
				outData[i] = (short)yRight[0];
			}

			fwrite(&outData[i], sizeof(short), 1, outPut);
		}
	}
	else
	{
		cout << "---------------------------------------------" << endl;
		cout << "Error! Use only 11025Hz or 22050Hz wav files." << endl;
		cout << "---------------------------------------------" << endl;
	}

	//Timer stop.
	double timeStop = (double)(clock() - timeStart)/CLOCKS_PER_SEC;

	//Close the wave file
	fclose(wFile);

	// Print execution time in console.
	cout << "Duration of Program execution: " << timeStop << setprecision(3) << "secs." <<endl;
	cout << "Processing complete...exiting Program...." << endl;

	return 0;
}

void fnFilter(double* x, double* y, short sample, double* B, int size)
{
	double templ;

	for (int i = size - 1; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	x[0] = sample;

	templ = 0;
	for (int i = 0; i < size; i++)
	{
		templ += x[i] * B[i];
	}

	y[0] = templ;

}