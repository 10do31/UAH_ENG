#include <iostream>
#include <string>
#include <fstream>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

//Make a struct to put all the header info in
typedef struct  HEADER
{
    uint8_t         ChunkID[4];     //Contains letters "RIFF", 4 bytes in 0 position
    uint32_t        ChunkSize;
    uint8_t         Format[4];      //Contains letters "WAVE"
    uint8_t         SubChunk1ID[4]; //Contains letters "fmt"
    uint32_t        SubChunk1Size;  // Our file is 16 bit.
    uint16_t        AudioFormat;	//Our format is PCM, pulse-code modulated
    uint16_t        NumChannels;	//Number of channels is 2, stereo
    uint32_t        SampleRate;		//Sample rate is 11,025
    uint32_t        ByteRate;		//SampleRate* NumChannels * BitsPerSample/8
    uint16_t        BlockAlign;		//NumChannels * BitsPerSample/8
    uint16_t        BitsPerSample;	//16 bits per sample
    uint8_t         Subchunk2ID[4];	//Contains letters "data"
    uint32_t        Subchunk2Size;	//NumSamples * NumChannels * BitsPerSample/8, number of bytes in data
} wHeader;

void dashes(int d)
{
	for(int i = 0; i < d; i++)
	{
		ofstream << "-" << endl;
	}
}