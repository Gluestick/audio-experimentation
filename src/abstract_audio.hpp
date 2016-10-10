#pragma once

#include <vector>

class AbstractAudio
{
public:
  AbstractAudio(const std::vector<float> & samples, uint32_t channels, uint32_t frame_rate);
  uint32_t get_sample_rate() const;

  const std::vector<float> samples;
  const uint32_t channel_count;
  const uint32_t frame_rate;
};
