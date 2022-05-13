#include <cstdint>
#include <SDL2/SDL.h>
#include <queue>

const int SAMPLE_FREQUENCY = 44100;

struct Tune {
  Tune(double freq, int duration_ms)
    : frequency(freq)
    , duration(duration_ms)
    , samples_left(SAMPLE_FREQUENCY * duration_ms / 1000) {}
  double frequency;
  int duration;
  int samples_left;
};

class Buzzer
{
 public:
  Buzzer();
  ~Buzzer();

  void buzz(double frequency, int duration_ms);
  void play();

  const double m_frequency;
  std::size_t m_sample_pos;

 private:
  static void SdlAudioCallback(void* data, Uint8* buffer, int length);
  SDL_AudioDeviceID m_device_id;
  std::queue<Tune> m_tunes;
  void generate_waveform(Uint8* stream, int length);
  std::size_t m_waveform_counter {0};
};
