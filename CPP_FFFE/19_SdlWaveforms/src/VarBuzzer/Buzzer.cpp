#include "Buzzer.hpp"

#include <cmath>
#include <iostream>
#include <numbers>

Buzzer::Buzzer()
  : m_frequency(441.0)
  , m_sample_pos(0)
{
  SDL_AudioSpec wantSpec, haveSpec;

  SDL_zero(wantSpec);
  wantSpec.freq = SAMPLE_FREQUENCY;
  wantSpec.format = AUDIO_U8;
  wantSpec.channels = 1;
  wantSpec.samples = 2048;
  wantSpec.callback = SdlAudioCallback;
  wantSpec.userdata = this;

  m_device_id = SDL_OpenAudioDevice(nullptr, 0, &wantSpec, &haveSpec, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
  if (0 == m_device_id) {
    std::cerr << "[Buzzer] Failed to open audio device. SDL_Error: " << SDL_GetError() << "\n";
    throw;
  }
}

Buzzer::~Buzzer() {
  SDL_CloseAudioDevice(m_device_id);
}

void Buzzer::buzz(double frequency, int duration_ms) {
  Tune t {frequency, duration_ms};
  SDL_LockAudio();
  m_tunes.push(t);
  SDL_UnlockAudio();
}

void Buzzer::play() {
  SDL_PauseAudioDevice(m_device_id, 0);
  bool isDonePlaying {false};
  do {
    SDL_Delay(10);
    SDL_LockAudio();
    isDonePlaying = m_tunes.empty();
    SDL_UnlockAudio();
  } while (!isDonePlaying);
}

void Buzzer::SdlAudioCallback(void* data, Uint8* buffer, int length) {
  Buzzer *buzzer = reinterpret_cast<Buzzer*>(data);
  buzzer->generate_waveform(buffer, length);
}

void Buzzer::generate_waveform(Uint8* stream, int length) {
  int i {0};
  while (i < length) {
    if (m_tunes.empty()) {
      for (int j = i; j < length; ++j) {
        stream[j] = 0;
      }
      return;
    }

    Tune& tune = m_tunes.front();
    int num_samples = std::min(i + tune.samples_left, length);
    //std::cout << "[Buzzer] generating " << num_samples << " new samples.\n";
    tune.samples_left -= (num_samples - i);

    while (i < num_samples) {
      stream[i] = 127.5 * std::sin(2 * std::numbers::pi * m_waveform_counter *
            (tune.frequency / SAMPLE_FREQUENCY));
      i++;
      m_waveform_counter++;
    }

    if (0 == tune.samples_left) {
      m_tunes.pop();
    }
  }
}
