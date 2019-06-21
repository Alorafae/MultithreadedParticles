
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
    /*
    for (unsigned i = 0; i < MAX_THREADS; ++i)
    {
      std::thread t1(&MTParticleSystem::MTSimulate, this, dt, i);
      threads.push_back(t1);
    }

    for (unsigned i = 0; i < MAX_THREADS; ++i)
    {
      threads[i].join();
    }
    */
    std::thread t1(&MTParticleSystem::MTSimulate, this, dt, 1);
    std::thread t2(&MTParticleSystem::MTSimulate, this, dt, 2);
    std::thread t3(&MTParticleSystem::MTSimulate, this, dt, 3);
    std::thread t4(&MTParticleSystem::MTSimulate, this, dt, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
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
  for (unsigned i = 0; i < MAX_PARTICLES; ++i)
  {
    printf("%d -> thread count: %d\n", id, i);
  }
}
