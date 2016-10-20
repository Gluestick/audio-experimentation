#pragma once

#include "../audio_signal.hpp"
#include "../audio.hpp"

#include <functional>
#include <vector>

typedef const std::function<const AudioSignal(const std::vector<AudioSignal> &)> Mixer;
const Audio mix(const Mixer & mixer, const std::vector<Audio> & audios);
