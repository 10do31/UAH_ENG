/*
Dan Otieno.
CPE 381.
Project - Phase 1.
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


int main()
{
	wHeader wavHdr;
	const char* fPath;
	string fIn, fOut;
	size_t byteshdr;
	float Left,Right; // floating point samples
	int hdrSize, fSize;
	int absCh1, absCh2;
	short maxVal;

	hdrSize = sizeof(wHeader);

	maxVal = 32767; // 16-bit samples.


	//Prompt for user input in command terminal to open mod file.
	cout << "Enter input filename: ";
	getline(cin, fIn);
	fPath  = fIn.c_str();
	cout << "Reading from file path, please wait...." << endl;
	FILE* wFile = fopen(fPath, "rb");

	//Start timer:
	clock_t timeStart = clock();

	//Get the size of the file in total
	fseek(wFile, 0, SEEK_END);
	fSize = ftell(wFile);
	fseek(wFile, 0, SEEK_SET);
	cout << "Size of File: " << fSize << endl;
	byteshdr = fread(&wavHdr, hdrSize, 1, wFile);


	//Checking header size.
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


	//Read and output the contents of the data section of the wave:
	short audio1[samples];
	short audio2[samples];

	for (int i = 0; i <= samples; i++)
	{
		fread(&audio1[i], 2, 1, wFile);
		fread(&audio2[i], 2, 1, wFile);
	}


	//Maximum absolute for each channel:
	absCh1 = abs(audio1[0]);

	for (int j = 0; j <= samples; j++)
	{
		if (abs(audio1[j]) > abs(absCh1) )
		{
			absCh1 = abs(audio1[j]);
		}
	}

	absCh2 = abs(audio2[0]);
	for (int k = 0; k <= samples; k++)
	{
		if (abs(audio2[k]) > abs(absCh2) )
		{
			absCh2 = abs(audio2[k]);
		}
	}

	// Open file for output (write file).
	FILE* outPut;

	outPut = fopen("Otieno_mod.wav", "wb");
	fwrite(&wavHdr, hdrSize, 1, outPut);

	short aOut[2];

	for (int k = 0; k <= samples; k++)
	{
		double rand_left = 65535 * ((rand () / (double) RAND_MAX) - 0.5);
		double rand_right = 65535 * ((rand () / (double) RAND_MAX) - 0.5);


		Left = audio1[k] + 0.01 * rand_left ; // add random noise to Left channel
		Right = audio2[k] + 0.01 * rand_right; // add random noise to Right channel

		if (Left > maxVal) 
		{
			aOut[0] = (short)maxVal; // clip sample to cater for overflow.
		}
		else 
		{
			aOut[0] = (short)Left;		
		} // write output samples

		if (Right > maxVal) 
		{
			aOut[1] = (short)maxVal; // clip the sample in the case of the overflow.
		}
		else 
		{
			aOut[1] = (short)Right;		
		} // write output samples
			// right channel

		fwrite(&aOut[0], sizeof(short), 1, outPut);
		fwrite(&aOut[1], sizeof(short), 1, outPut);

	}


	//Close the wave file
	fclose(wFile);

	//Timer stop.
	double timeStop = (double)(clock() - timeStart)/CLOCKS_PER_SEC;
	float recLength = ((float)samples / 2) / (float)wavHdr.sampleRate;

	// Printing output summary.
	cout << "Enter summary filename: ";
	getline(cin, fOut);
	ofstream wavInfo(fOut.c_str());
	cout << "Printing summary, please wait...." << endl;
	wavInfo << "**************************************************" << endl;
	wavInfo << "Name: Dan Otieno" << endl;
	wavInfo << "Filename: " << fIn << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Number of channels: " << wavHdr.numChannels << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Sampling Freq: " << wavHdr.sampleRate << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Bits per Sample: " << wavHdr.bitsPerSample << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Record Length: " << recLength << setprecision(3) << "secs." << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Absolute Maximum - Channel 1: " << absCh1 << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Absolute Maximum - Channel 2: " << absCh2 << endl;
	wavInfo << "--------------------------------------------------" << endl;
	wavInfo << "Duration of Program execution: " << timeStop << setprecision(3) << "secs." <<endl;
	wavInfo << "**************************************************" << endl;

	cout << "Processing complete..." << endl;
	wavInfo.close();

	return 0;
}


