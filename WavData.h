//Authors: Jamie Lee, Nikhil Sharma
//Group Project
//4/30/2021

#ifndef WAVDATA_H
#define WAVDATA_H

/** 
* This is the WavData class that will be used store data of wave files
*/
class WavData{
	int fileSize, sampleRate, dataBytes;
	short int audioFormat, numChannels, bitsPerSample;
	char *title, *artist, *comments;
public:
/**
* Default constructor of WavData
*/
	WavData();
/**
* Parameterized constructor that takes in and sets info read from wave file
* @param newFileSize - size of wave file in integer bytes
* @param newSampleRate - sample rate; 32 byte integer
* @param newDataBytes - size of data in integer bytes
* @param newAudioFormat - format of wave file (1 is PCM); 2 byte integer
* @param newNumChannels - number of channels; 2 byte integer
* @param newBitsPerSample - bits per sample
* @param newTitle - title
* @param newArtist - artist
* @param newComments - comments
*/
	WavData(int newFileSize, int newSampleRate, int newDataBytes, short int newAudioFormat, short int newNumChannels, short int newBitsPerSample, char *newTitle, char *newArtist, char *newComments){
		fileSize = newFileSize;
		sampleRate = newSampleRate;
		dataBytes = newDataBytes;
		audioFormat = newAudioFormat;
		numChannels = newNumChannels;
		bitsPerSample = newBitsPerSample;
		title = newTitle;
		artist = newArtist;
		comments = newComments;
	}
	
	/** 
	* Get file size in WavData object
	*/
	int getFileSize();
	/** 
	* Sets file size to store in WavData object
	*@param  newFileSize - file size
	*/
	void setFileSize(int newFileSize);
	
	/** 
	* Get sample rate in WavData object
	*/
	int getSampleRate();
	/** 
	* Sets sample rate to store in WavData
	*@param  newSampleRate - sample rate
	*/
	void setSampleRate(int newSampleRate);
	
	/** 
	* Get size of data in WavData object
	*/
	int getDataBytes();
	/** 
	* Sets size of data to store in WavData object
	*@param  newDataBytes - size of data
	*/
	void setDataBytes(int newDataBytes);
	
	/** 
	* Get audio format in WavData object
	*/
	short int getAudioFormat();
	/** 
	* Sets audio format to store in WavData object
	*@param  newAudioFormat - audio format
	*/
	void setAudioFormat(short newAudioFormat);
	
	/** 
	* Get number of channels in WavData object
	*/
	short int getNumChannels();
	/** 
	* Sets number of channels to store in WavData object
	*@param  newNumChannels - number of channels
	*/
	void setNumChannels(short newNumChannels);
	
	/** 
	* Get bits per sample in WavData object
	*/
	short int getBitsPerSample();
	/** 
	* Sets bits per sample to store in WavData object
	*@param  newBitsPerSample - bits per sample
	*/
	void setBitsPerSample(short newBitsPerSample);
	
	/** 
	* Get title in WavData object
	*/
	char *getTitle();
	/** 
	* Sets title to store in WavData object
	*@param  newTitle - title
	*/
	void setTitle(char* newTitle);
	
	/** 
	* Get artist in WavData object
	*/
	char *getArtist();
	/** 
	* Sets artist to store in WavData object
	*@param  newArtist - artist
	*/
	void setArtist(char* newArtist);
	
	/** 
	* Get comments in WavData object
	*/
	char *getComments();
	/** 
	* Sets comments to store in WavData object
	*@param  newComments - comments
	*/
	void setComments(char* newComments);
};

#endif //WAVDATA_H
