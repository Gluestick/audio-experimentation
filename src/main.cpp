#include "audio.hpp"
#include "audio_conversion.hpp"
#include <iostream>
#include <sstream>

const std::string inspect(const Audio & audio);

int main(int argc, char * argv[])
{
  std::vector<float> samples(256e3);
  Audio mono1(samples, 1, 22050);
  Audio mono2 = convert_samplerate(mono1, 24000);
  Audio stereo = mono_to_stereo(mono2);

  std::cout << inspect(mono1) << std::endl;
  std::cout << inspect(mono2) << std::endl;
  std::cout << inspect(stereo) << std::endl;
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
