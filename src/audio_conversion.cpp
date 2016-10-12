#include "audio_conversion.hpp"

StereoAudio mono_to_stereo(const MonoAudio & mono_audio)
{
  const size_t doubled_size = mono_audio.samples.size() * 2;
  std::vector<float> doubled_samples;
  doubled_samples.reserve(doubled_size);

  for (uint32_t i = 0; i < doubled_size; i++)
  {
    doubled_samples.push_back(mono_audio.samples[i / 2]);
  }
  return StereoAudio(doubled_samples, mono_audio.frame_rate);
}
