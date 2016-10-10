#pragma once

#include "abstract_audio.hpp"

template <uint32_t T>
class Audio : public AbstractAudio
{
public:
  Audio(const std::vector<float> & samples, uint32_t frame_rate);
};

typedef Audio<1> MonoAudio;
typedef Audio<2> StereoAudio;
