#pragma once

#include <vector>

class Audio
{
public:
  Audio(const std::vector<float> & samples, uint32_t channels, uint32_t frame_rate);
  std::vector<Audio> get_channels() const;

  const uint32_t channel_count;
  const uint32_t frame_rate;

private:
  const std::vector<float> samples;
};
