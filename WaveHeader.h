//Authors: Samuel DeLange, Jamie Lee, Nikhil Sharma
//Group Project
//4/27/2021

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

// This header copied from https://gist.github.com/Jon-Schneider/8b7c53d27a7a13346a643dac9c19d34f
/*
 * https://docs.fileformat.com/audio/wav/
 * Positions	Sample Value	Description
1 - 4	“RIFF”	Marks the file as a riff file. Characters are each 1 byte long.
5 - 8	File size (integer)	Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you’d fill this in after creation.
9 -12	“WAVE”	File Type Header. For our purposes, it always equals “WAVE”.
13-16	“fmt "	Format chunk marker. Includes trailing null
17-20	16	Length of format data as listed above
21-22	1	Type of format (1 is PCM) - 2 byte integer
23-24	2	Number of Channels - 2 byte integer
25-28	44100	Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
29-32	176400	(Sample Rate * BitsPerSample * Channels) / 8.
33-34	4	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
35-36	16	Bits per sample
37-40	“data”	“data” chunk header. Marks the beginning of the data section.
41-44	File size (data)	Size of the data section.
 */

typedef struct wav_header{
	// RIFF Header
	char riff_header[4]; // Contains "RIFF"
	int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
	char wave_header[4]; // Contains "WAVE"

	// Format Header
	char fmt_header[4]; // Contains "fmt " (includes trailing space)
	int fmt_chunk_size; // Should be 16 for PCM
	short audio_format; // Should be 1 for PCM. 3 for IEEE Float
	short num_channels; // 1 for mono 2 for stereo
	int sample_rate;
	int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
	short sample_alignment; // num_channels * Bytes Per Sample
	short bit_depth; // Number of bits per sample

	// Data
	char data_header[4]; // Contains "data"
	int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
	char bytes[]; // audio data

	//Metadata 
	char list_header[4]; // Contains "LIST"
	int list_chunk_size;
	char info_header[4]; // Contains "INFO"
	char INAM_header[4]; // Info ID Title
	int INAM_size; // Number of characters in subchunk
	char INAM_data[];// Actual Text/data
	char IART_header[4]; //Artist
	int IART_size;
	char IART_data[]; // having trouble with this part!
	char ICMT_header[4]; //Comments
	int ICMT_size;
	char ICMT_data[];
	
} wav_header;

#endif //WAVEHEADER_H
