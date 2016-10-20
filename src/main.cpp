#include "audio.hpp"
#include "audio_conversion.hpp"
#include "mixers/summing_mixer.hpp"
#include <iostream>
#include <sstream>

const std::string inspect(const Audio & audio);
const std::string inspect_samples(const AudioSignal & audio);

int main(int argc, char * argv[])
{
  std::vector<float> samples(4096e3);

  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;
  Audio mono1(samples, 1, 22050);
  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;
  Audio mono_copy(mono1);
  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;
  Audio mono2 = convert_samplerate(mono1, 24000);
  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;
  Audio stereo = mono_to_stereo(mono2);
  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;

  Audio mono_sum = mix(sum_audio_signals, std::vector<Audio>{ mono1, mono_copy });
  std::cout << "HEYOOOOOOOOOOOOOOOOOOOO" << std::endl;

  std::cout << inspect(mono1) << std::endl;
  std::cout << inspect(mono_copy) << std::endl;
  std::cout << inspect(mono2) << std::endl;
  std::cout << inspect(stereo) << std::endl;
  std::cout << inspect(mono_sum) << std::endl;

  // std::cout << inspect_samples(mono1.samples) << std::endl;
  // std::cout << inspect_samples(mono_sum.samples) << std::endl;

  return 0;
}

const std::string inspect(const Audio & audio)
{
  std::ostringstream sstream;
  sstream << "#<Audio sample_count: " << audio.samples.size() << ", "
    << "channel_count: " << audio.channel_count << ", "
    << "frame_rate: " << audio.frame_rate << ", "
    << "sample_rate: " << audio.get_sample_rate() << ">";
  return sstream.str();
}

const std::string inspect_samples(const AudioSignal & audio)
{
  std::ostringstream sstream;
  sstream << "#<Audio::samples";
  for (const float & sample : audio)
  {
    sstream << " " << sample;
  }
  sstream << " >";
  return sstream.str();
}
