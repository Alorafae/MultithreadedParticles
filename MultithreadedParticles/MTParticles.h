#pragma once

#include <thread>
#include <vector>
#include "glm/common.hpp"

#define MAX_THREADS 4 // set to 1 for single threaded
#define MAX_PARTICLES 1024

struct Particle
{
  glm::vec3 pos;
  glm::vec3 dir;
};

class MTParticleSystem
{
public:
  MTParticleSystem();
  ~MTParticleSystem();

  void Simulate(float dt);
private:
  glm::vec3 pos;
  glm::vec3 dir;

  Particle parts[MAX_PARTICLES];
  std::vector<std::thread> threads;

  unsigned nThreads = MAX_THREADS;
};
