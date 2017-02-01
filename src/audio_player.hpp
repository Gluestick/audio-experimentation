#pragma once

#include "audio.hpp"
#include "portaudio.h"
#include "multi_stream.hpp"

class AudioPlayer
{
public:
  AudioPlayer();
  ~AudioPlayer();
  void play(const Audio audio);
  bool is_playing() const;
private:
  MultiStream mstream;
  PaStream * pa_stream;
};
