#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <Eigen/Dense>

#include "Object.hpp"
#include "Ray.hpp"
#include "Material.hpp"

class Sphere: public PhysicalObject
{
public:
  Sphere(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d center,
    double radius,
    Eigen::Vector3d mat = Material::Default()
  ): PhysicalObject(pos, rot, mat), m_radius(radius), m_center(center), m_d1(0), m_discriminant(0) {}

  bool IsIntersected(Ray* ray);
  Eigen::Vector3d Intersect(Ray* ray);

private:
  double m_radius;
  Eigen::Vector3d m_center;

  // Useful variables for computing intersection point
  double m_d1;
  double m_discriminant;
};

#endif
