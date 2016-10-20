#include "audio_conversion.hpp"
#include "audio_signal.hpp"
#include "samplerate.h"

Audio mono_to_stereo(const Audio & audio)
{
  const size_t doubled_size = audio.samples.size() * 2;
  std::vector<float> doubled_samples(doubled_size);

  for (uint32_t i = 0; i < doubled_size; i++)
  {
    doubled_samples.push_back(audio.samples[i / 2]);
  }
  const std::vector<float> signal = doubled_samples;
  return Audio(doubled_samples, 2, audio.frame_rate);
}

SRC_DATA create_src_data(const std::vector<float> & input, std::vector<float> & output, const double ratio)
{
  SRC_DATA data;
  data.data_in = const_cast<float *>(input.data());
  data.data_out = const_cast<float *>(output.data());
  data.input_frames = input.size();
  data.output_frames = output.size();
  data.src_ratio = ratio;
  return data;
}

Audio convert_samplerate(const Audio & src_audio, uint32_t target_frame_rate)
{
  double ratio = static_cast<double>(src_audio.get_sample_rate()) / target_frame_rate;
  const size_t target_size = src_audio.samples.size() / ratio;
  std::vector<float> target(target_size);
  SRC_DATA data = create_src_data(src_audio.samples, target, ratio);
  if (const int32_t err = src_simple(&data, SRC_SINC_FASTEST, src_audio.channel_count))
  {
    throw err;
  }
  return Audio(target, src_audio.channel_count, target_frame_rate);
}
