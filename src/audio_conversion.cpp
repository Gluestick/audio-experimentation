#include "audio_conversion.hpp"

Audio audio_to_mono(const Audio & audio) {
  return audio.get_channels().front();
}

Audio audio_to_stereo(const Audio & audio) {
}
