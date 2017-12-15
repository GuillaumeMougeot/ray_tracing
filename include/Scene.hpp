#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "PhysicalObject.hpp"
#include "Light.hpp"

class Scene
{
public:
  // Constructors
  Scene() {}

  // Add physical Object
  void AddPhysicalObject(PhysicalObject* physical_object) {m_physical_objects.push_back(physical_object);}

  // Add Light
  void AddLight(Light* light) {m_lights.push_back(light);}

private:
    std::vector<PhysicalObject*> m_physical_objects;
    std::vector<Light*> m_lights;
};

#endif
