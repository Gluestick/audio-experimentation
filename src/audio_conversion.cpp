#include "audio_conversion.hpp"

StereoAudio mono_to_stereo(const MonoAudio & mono_audio)
{
  std::vector<float> doubled_samples;
  for (float sample : mono_audio.samples)
  {
    for (int i = 0; i < 2; i++)
    {
      doubled_samples.push_back(sample);
    }
  }
  return StereoAudio(doubled_samples, mono_audio.frame_rate);
}
