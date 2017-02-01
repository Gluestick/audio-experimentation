#pragma once

#include <vector>
#include <queue>

class MultiStream
{
public:
  void add_stream(std::vector<float> stream);
  float next();
  bool empty() const;
private:
  std::vector<std::queue<float>> streams;
};
