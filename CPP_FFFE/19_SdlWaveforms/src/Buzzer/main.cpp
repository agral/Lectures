#include "Buzzer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <iostream>

int main()
{
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
    std::cerr << "Failed to initialize SDL. SDL_Error: " << SDL_GetError() << "\n";
  }

  Buzzer buzzer;
  buzzer.sound();
  SDL_Delay(1000);
  buzzer.nosound();

  SDL_Quit();
}
