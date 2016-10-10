#include "abstract_audio.hpp"

AbstractAudio::AbstractAudio(const std::vector<float> & samples, uint32_t frame_rate, uint32_t channel_count)
  : samples(samples),
    channel_count(channel_count),
    frame_rate(frame_rate)
{
}

uint32_t AbstractAudio::get_sample_rate() const
{
  return frame_rate * channel_count;
}
