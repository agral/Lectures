SDL2_CFLAGS = -I/usr/include/SDL2 -D_REENTRANT
SDL2_LIBS = -pthread -lSDL2

.PHONY: all clean simple

all: legacy buzzer varbuzzer

clean:
	@rm -fv run_legacy
	@rm -fv run_buzzer
	@rm -fv run_varbuzzer


legacy:
	g++ -std=c++20 -O2 $(SDL2_CFLAGS) -o run_legacy $(SDL2_LIBS) src/legacy_SDL_waveforms.cpp

buzzer:
	g++ -std=c++20 -O2 $(SDL2_CFLAGS) -o run_buzzer $(SDL2_LIBS) src/Buzzer/Buzzer.cpp src/Buzzer/main.cpp

varbuzzer:
	g++ -std=c++20 -O2 $(SDL2_CFLAGS) -o run_varbuzzer $(SDL2_LIBS) src/VarBuzzer/Buzzer.cpp src/VarBuzzer/main.cpp
