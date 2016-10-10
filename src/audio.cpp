#include "audio.hpp"

Audio::Audio(
  const std::vector<float> & samples,
  uint32_t channel_count,
  uint32_t frame_rate)
    : channel_count(channel_count),
      frame_rate(frame_rate),
      samples(samples)
{
}

std::vector<Audio> Audio::get_channels() const {
  std::vector<std::vector<float>> samples_per_channel;
  while (samples_per_channel.size() < channel_count) {
    samples_per_channel.push_back(std::vector<float>());
  }
  for (uint32_t i = 0; i < samples.size(); i++) {
    samples_per_channel[i % channel_count].push_back(samples[i]);
  }
  std::vector<Audio> channels;
  for (std::vector<float> channel_samples : samples_per_channel) {
    channels.push_back(Audio(channel_samples, 1, frame_rate));
  }
  return std::vector<Audio>();
}
