
#include "MTParticles.h"

MTParticleSystem::MTParticleSystem()
{
}

MTParticleSystem::~MTParticleSystem()
{
}

void MTParticleSystem::Simulate(float dt)
{
  for (unsigned i = 0; i < MAX_PARTICLES; ++i)
  {
    parts[i].pos += parts[i].dir * dt;
  }
}
