#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <Eigen/Dense>
#include "Object.hpp"

class Sphere: public PhysicalObject
{
public:
  Sphere();
  Sphere(Eigen::Vector3d center, Eigen::Vector3d radius);

private:
  Eigen::Vector3d m_radius;
  Eigen::Vector3d m_center;
};

#endif
