#pragma once

#include <thread>
#include "glm/common.hpp"

class MTParticleSystem
{
  public:
    MTParticleSystem();
    ~MTParticleSystem();

    void Simulate(float dt);
  private:
    glm::vec3 pos;
    glm::vec3 dir;
};
