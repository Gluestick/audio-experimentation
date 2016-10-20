#include "summing_mixer.hpp"
#include <algorithm>

static Mixer mixer = sum_audio_signals;

const AudioSignal sum_audio_signals(const std::vector<AudioSignal> & audio_signals)
{
  const AudioSignal & biggest_signal = *std::max_element(
      audio_signals.begin(), audio_signals.end(),
    [](const AudioSignal & lhs, const AudioSignal & rhs)
    {
      return rhs.size() - lhs.size();
    });
  AudioSignal summed_audio_signal;
  summed_audio_signal.reserve(biggest_signal.size());
  for (uint32_t result_index = 0; result_index < biggest_signal.size(); result_index++)
  {
    float summed_sample = 0.0f;
    for (const AudioSignal & source_signal : audio_signals)
    {
      if (result_index >= source_signal.size())
      {
        break;
      }
      summed_sample += source_signal[result_index];
    }
    summed_audio_signal.push_back(summed_sample);
  }
  return summed_audio_signal;
}

const Audio mix(const Mixer & mixer, const std::vector<Audio> & audios)
{
  std::vector<AudioSignal> source_signals;
  for (const Audio & audio : audios)
  {
    source_signals.push_back(audio.samples);
  }
  const AudioSignal mixed_signal = mixer(source_signals);
  return Audio(mixed_signal, audios[0].channel_count, audios[0].frame_rate);
}
