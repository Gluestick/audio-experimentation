#pragma once

#include "audio.hpp"

Audio mono_to_stereo(const Audio & audio);

Audio convert_samplerate(const Audio & src_audio, uint32_t target_samplerate);
