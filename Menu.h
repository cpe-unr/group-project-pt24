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
	void subMenuMD();
	void subMenuAP();
	GenerateCSV generateCSV;
	void createCSV();
};


#endif //MENU_F
