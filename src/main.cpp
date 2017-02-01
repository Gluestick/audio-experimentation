#include "audio.hpp"
#include "audio_conversion.hpp"
#include "mixers/summing_mixer.hpp"
#include "io/audio_reader.hpp"
#include "audio_player.hpp"
#include <iostream>
#include <sstream>
#include "multi_stream.hpp"

const std::string inspect(const Audio & audio);
const std::string inspect_samples(const AudioSignal & audio);

int main(int argc, char * argv[])
{
  Audio src = load_audio("/Users/joep.kemperman/programming/ksp/main1.wav");
  AudioPlayer player;
  player.play(src);
  while (player.is_playing())
  {
    std::cin.get();
    player.play(src);
  }
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
