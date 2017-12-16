#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <iostream>

#include "PhysicalObject.hpp"
#include "Light.hpp"

class Scene
{
public:
  // Constructors
  Scene(Eigen::Vector3d ia): m_ia(ia) {}

  // Accessors
  unsigned int getNumberOfPhysicalObjects() {return m_physical_objects.size();}
  unsigned int getNumberOfLigths() {return m_lights.size();}
  Eigen::Vector3d getIa() {return m_ia;}

  PhysicalObject* getPhysicalObject(unsigned int index)
  {
    if (index >= m_physical_objects.size()) {std::cout << "[Error:Scene/getPhysicalObject] Index out of range!" << std::endl;}
    else {return m_physical_objects[index];}
  }

  Light* getLight(unsigned int index)
  {
    if (index >= m_lights.size()) {std::cout << "[Error:Scene/getLight] Index out of range!" << std::endl;}
    else {return m_lights[index];}
  }

  // Add physical Object
  void AddPhysicalObject(PhysicalObject* physical_object) {m_physical_objects.push_back(physical_object);}

  // Add Light
  void AddLight(Light* light) {m_lights.push_back(light);}

private:
    std::vector<PhysicalObject*> m_physical_objects;
    std::vector<Light*> m_lights;
    Eigen::Vector3d m_ia; // Ambient light
};

#endif
