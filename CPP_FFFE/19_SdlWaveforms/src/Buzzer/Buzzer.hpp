#include <cstdint>
#include <SDL2/SDL.h>

class Buzzer
{
 public:
  Buzzer();
  ~Buzzer();

  void sound();
  void nosound();

  const double m_frequency;
  const double m_sample_frequency;
  std::size_t m_sample_pos;

 private:
  static void SdlAudioCallback(void* data, Uint8* buffer, int length);
  SDL_AudioDeviceID m_device_id;
};
