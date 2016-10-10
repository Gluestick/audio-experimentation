#include "audio.hpp"
#include "audio_conversion.hpp"
#include <iostream>


int main(int argc, char * argv[])
{
  std::vector<float> samples = {0.0f, 0.1f, 0.4f, -0.1f, -0.4f, 0.0f};

  std::cout << "Mono" << std::endl;
  MonoAudio mono(samples, 22050);
  std::cout << mono.channel_count << std::endl;
  std::cout << mono.samples.size() << std::endl;
  std::cout << mono.frame_rate << std::endl;
  std::cout << mono.get_sample_rate() << std::endl;

  std::cout << "Stereo" << std::endl;
  StereoAudio stereo = mono_to_stereo(mono);
  std::cout << stereo.channel_count << std::endl;
  std::cout << stereo.samples.size() << std::endl;
  std::cout << stereo.frame_rate << std::endl;
  std::cout << stereo.get_sample_rate() << std::endl;
  return 0;
}
