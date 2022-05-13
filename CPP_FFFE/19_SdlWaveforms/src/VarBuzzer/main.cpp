#include "Buzzer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <iostream>

const double H3 {246.94};
const double C4 {261.63};
const double E4 {329.63};
const double F4C {369.99};
const double G4 {349.23};
const double A4C {466.16};
const double H4 {493.88};


int main()
{
  if (SDL_Init(SDL_INIT_AUDIO) != 0) {
    std::cerr << "Failed to initialize SDL. SDL_Error: " << SDL_GetError() << "\n";
  }

  /*
  Buzzer buzzer;
  buzzer.buzz(441.0, 1000);
  buzzer.play();
  */

  Buzzer buzzer;
  buzzer.buzz(H3, 400);
  buzzer.buzz(0, 200);
  buzzer.buzz(H3, 200);
  buzzer.buzz(F4C, 200);
  buzzer.buzz(H4, 200);

  buzzer.buzz(A4C, 400);
  buzzer.buzz(F4C, 400);
  buzzer.play();

  SDL_Quit();
}
