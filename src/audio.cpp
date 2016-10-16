#include "audio.hpp"

Audio::Audio(const std::vector<float> & samples, uint32_t channel_count, uint32_t frame_rate)
  : samples(samples),
    channel_count(channel_count),
    frame_rate(frame_rate)
{
}

uint32_t Audio::get_sample_rate() const
{
  return frame_rate * channel_count;
}
