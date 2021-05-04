audiomanagement: filesystem.o menu.o wav.o  echo.o wavdata.o mdprint.o data_manager.o generatecsv.o editMD.o main.cpp
	g++ -std=c++17 -o audiomanagement generateCSV.cpp Wav.cpp MetadataPrinter.cpp WavData.cpp DataManager.cpp Filesystem.cpp Menu.cpp ModifyMD.cpp main.cpp -lstdc++fs
main.o: main.cpp
	g++ -std=c++17 main.cpp
wav.o: Wav.cpp Wav.h
	g++ -c -std=c++17 Wav.cpp
limiter.o: Limiter.cpp Limiter.h
	g++ -c -std=c++17 Limiter.cpp
echo.o: Echo.cpp Echo.h
	g++ -c -std=c++17 Echo.cpp
noisegate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++17 NoiseGate.cpp
normalize.o: Normalize.cpp Normalize.h
	g++ -c -std=c++17 Normalize.cpp
wavdata.o: WavData.cpp WavData.h
	g++ -c -std=c++17 WavData.cpp
mdprint.o: MetadataPrinter.cpp MetadataPrinter.h
	g++ -c -std=c++17 MetadataPrinter.cpp
data_manager.o: DataManager.cpp DataManager.h
	g++ -c -std=c++17 DataManager.cpp
editMD.o: ModifyMD.cpp ModifyMD.h
	g++ -c -std=c++17 ModifyMD.cpp
menu.o: Menu.cpp Menu.h
	g++ -c -std=c++17 Menu.cpp
generatecsv.o: generateCSV.cpp generateCSV.h
	g++ -c -std=c++17 generateCSV.cpp
filesystem.o: Filesystem.cpp Filesystem.h
	g++ -c -std=c++17 Filesystem.cpp
clean:
	rm *.o audiomanagement *.csv
