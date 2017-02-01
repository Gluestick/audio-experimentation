#include "multi_stream.hpp"

#include <deque>

void MultiStream::add_stream(std::vector<float> stream)
{
  if (stream.empty()) { return; }

  std::queue<float> samples;
  for (float sample : stream)
  {
    samples.push(sample);
  }
  streams.push_back(samples);
}

float MultiStream::next()
{
  float sample = 0.0f;
  for (int i = 0; i < streams.size(); i++)
  {
    auto & stream = streams[i];
    sample += stream.front();
    stream.pop();
    if (stream.empty())
    {
      streams.erase(streams.begin() + i);
    }
  }
  return sample;
}

bool MultiStream::empty() const
{
  return !streams.empty();
}
