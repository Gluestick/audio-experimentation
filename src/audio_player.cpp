#include "audio_player.hpp"
#include "portaudio.h"
#include <iostream>

int paCallback(
        const void *,
        void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo*,
        PaStreamCallbackFlags,
        void *userData)
{
  MultiStream * mstream = (MultiStream *)userData;
  float *out = (float*)outputBuffer;
  for (unsigned long i = 0; i < 2 * framesPerBuffer; i++)
  {
    out[i] = mstream->next();
  }
  return 0;
}

AudioPlayer::AudioPlayer()
{
  PaError err = Pa_Initialize();
  if (err != paNoError)
  {
    printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
  }

  /* Open an audio I/O stream. */
  err = Pa_OpenDefaultStream(&pa_stream,
          0,
          2,
          paFloat32,
          44100,
          0,        /* frames per buffer, i.e. the number
                         of sample frames that PortAudio will
                         request from the callback. Many apps
                         may want to use
                         paFramesPerBufferUnspecified, which
                         tells PortAudio to pick the best,
                         possibly changing, buffer size.*/
          paCallback, /* this is your callback function */
          (void *)&mstream); /*This is a pointer that will be passed to
                     your callback*/

  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    return;
  }

  err = Pa_StartStream(pa_stream);
}

AudioPlayer::~AudioPlayer()
{
  Pa_StopStream(pa_stream);
  Pa_CloseStream(pa_stream);
  Pa_Terminate();
}

void AudioPlayer::play(const Audio audio)
{
  mstream.add_stream(audio.samples);
}

bool AudioPlayer::is_playing() const
{
  return mstream.empty();
}
