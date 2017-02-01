#include "audio_reader.hpp"

#include <sndfile.hh>

Audio load_audio(const std::string path)
{
  SndfileHandle file(path, SFM_READ);
  sf_count_t frame_count = file.seek(0, SEEK_END);
  file.seek(0, SEEK_SET);

  uint32_t channel_count = file.channels();
  uint32_t sample_rate   = file.samplerate() / channel_count;
  std::vector<float> samples(frame_count * channel_count);
  file.readf(samples.data(), frame_count);
  return Audio(samples, channel_count, sample_rate);
}
