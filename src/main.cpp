#include "audio.hpp"
#include "audio_conversion.hpp"

int main(int argc, char * argv[])
{
  std::vector<float> samples(5e6);
  MonoAudio mono(samples, 22050);
  mono_to_stereo(mono);
  return 0;
}
