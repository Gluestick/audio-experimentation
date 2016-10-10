#include "audio.hpp"

template <uint32_t T>
Audio<T>::Audio(const std::vector<float> & samples, uint32_t frame_rate)
  : AbstractAudio(samples, frame_rate, T)
{
}

template class Audio<1>;
template class Audio<2>;
