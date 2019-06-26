
#include "MTParticles.h"

MTParticleSystem::MTParticleSystem()
{
  parts = new Particle[MAX_PARTICLES];
}

MTParticleSystem::~MTParticleSystem()
{
  delete parts;
}

void MTParticleSystem::Simulate(float dt)
{
  if (MAX_THREADS)
  {
    
    for (unsigned i = 0; i < MAX_THREADS; ++i)
    {
      threads.push_back(std::thread(&MTParticleSystem::MTSimulate, this, dt, i));
    }

    for (unsigned i = 0; i < MAX_THREADS; ++i)
    {
      threads[i].join();
    }
  }
  else
  {
    for (unsigned i = 0; i < MAX_PARTICLES; ++i)
    {
      parts[i].pos += parts[i].dir * dt;
    }
  }
}

void MTParticleSystem::Update(float dt)
{

}

void MTParticleSystem::MTSimulate(float dt, unsigned id)
{
  unsigned start = id * (MAX_PARTICLES / MAX_THREADS);
  unsigned end = MAX_PARTICLES / MAX_THREADS;

  if (end >= MAX_PARTICLES)
  {
    printf("Fix max particles / max threads error\n");
    return;
  }

  // dangerous if user is not careful
  for (unsigned i = start; i < end; ++i)
  {
    printf("%d -> thread count: %d\n", id, i);
  }
}

void MTParticleSystem::SetThreadingStyle(bool style)
{
  dynamicThreading = style;
}

void MTParticleSystem::SetThreads(unsigned maxThreads)
{
  if (dynamicThreading)
    nThreads = maxThreads;
}
