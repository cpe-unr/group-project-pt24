#ifndef MENU_H
#define MENU_H

#include "generateCSV.h"
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
	Menu();

	void subMenuMD();
	void subMenuAP();
	GenerateCSV generateCSV;
	void createCSV();
};


#endif
