#include "Buzzer.hpp"

#include <cmath>
#include <iostream>
#include <numbers>

Buzzer::Buzzer()
  : m_frequency(441.0)
  , m_sample_frequency(44100)
  , m_sample_pos(0)
{
  SDL_AudioSpec wantSpec, haveSpec;

  SDL_zero(wantSpec);
  wantSpec.freq = m_sample_frequency;
  wantSpec.format = AUDIO_U8;
  wantSpec.channels = 1;
  wantSpec.samples = 2048;
  wantSpec.callback = SdlAudioCallback;
  wantSpec.userdata = this;

  m_device_id = SDL_OpenAudioDevice(nullptr, 0, &wantSpec, &haveSpec, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
  if (0 == m_device_id) {
    std::cerr << "[Buzzer] Failed to open audio device. SDL_Error: " << SDL_GetError() << "\n";
  }
}

Buzzer::~Buzzer() {
  SDL_CloseAudioDevice(m_device_id);
}

void Buzzer::sound() {
  SDL_PauseAudioDevice(m_device_id, 0);
}

void Buzzer::nosound() {
  SDL_PauseAudioDevice(m_device_id, 1);
}

void Buzzer::SdlAudioCallback(void* data, Uint8* buffer, int length) {
  Buzzer *buzzer = reinterpret_cast<Buzzer*>(data);
  for (int i = 0; i < length; ++i) {
    buffer[i] = 127.5 * std::sin(2 * std::numbers::pi * buzzer->m_sample_pos
        * (buzzer->m_frequency / buzzer->m_sample_frequency));
    buzzer->m_sample_pos += 1;
  }
}
