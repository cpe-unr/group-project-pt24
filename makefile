audiomanagement: main.cpp wav.o  echo.o wavdata.o mdprint.o
	g++ -std=c++17 -o audiomanagement main.cpp Wav.cpp Processor.cpp Echo.cpp WavData.cpp MetadataPrinter.cpp -lstdc++fs
main.o: main.cpp
	g++ -std=c++17 main.cpp -lstdc++fs
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
clean:
	rm *.o audiomanagement *.wav
