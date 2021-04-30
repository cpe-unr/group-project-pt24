audiomanagement: main.cpp wav.o limiter.o echo.o noisegate.o normalize.o
	g++ -std=c++17 -o audiomanagement main.cpp Wav.cpp Processor.cpp Limiter.cpp Echo.cpp NoiseGate.cpp Normalize.cpp -lstdc++fs
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
clean:
	rm *.o audiomanagement
