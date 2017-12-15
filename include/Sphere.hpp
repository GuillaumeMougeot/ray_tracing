#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <Eigen/Dense>

#include "Object.hpp"
#include "Ray.hpp"

class Sphere: public PhysicalObject
{
public:
  Sphere(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d center,
    Eigen::Vector3d radius,
    Eigen::Vector3d mat = Material::Default()
  ): PhysicalObject(pos, rot, mat), m_radius(radius), m_center(center) {}

  bool IsIntersect(Ray* ray);
  Eigen::Vector3d Intersect(Ray* ray);

private:
  Eigen::Vector3d m_radius;
  Eigen::Vector3d m_center;
};

#endif
