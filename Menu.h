#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

#include "generateCSV.h"
#include "Filesystem.h"
#include "Wav.h"
#include "Processor.h"
#include "Limiter.h"
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalize.h"
#include "WaveHeader.h"
#include "DataManager.h"

class Menu{
public:
	
/**
 *
 * Prints sub menu asking user what they would like to do with the metadata, 
 * Creates data manager and uses appropriate method to accomplish task.
*/
	void subMenuMD();
/**
 *
 * Prints sub menu asking user what they would like to do with the audio processors, 
 * Creates Wav and uses appropriate processor to process the wav.
*/
	void subMenuAP();

	GenerateCSV generateCSV;
/**
 *
 * Takes Genrate CSV object and calls method generate to generate the CSV.
*/
	void createCSV();
};


#endif //MENU_F
