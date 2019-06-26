#pragma once

#include <thread>
#include <vector>
#include "glm/common.hpp"

#define MAX_THREADS 4 // set to 0 for single threaded
#define MAX_PARTICLES 2048

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

  virtual void Simulate(float dt);
  virtual void Update(float dt);
  virtual void MTSimulate(float dt, unsigned id);

  void SetThreadingStyle(bool style);
  void SetThreads(unsigned maxThreads);
private:
  glm::vec3 pos;
  glm::vec3 dir;

  Particle *parts;
  std::vector<std::thread> threads;

  unsigned nThreads = MAX_THREADS;

  bool dynamicThreading = false;
};
