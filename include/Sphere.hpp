#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <Eigen/Dense>

#include "PhysicalObject.hpp"
#include "Ray.hpp"
#include "Material.hpp"

// * Sphere:
// Inherits from PhysicalObject. Contains a center and a radius. As it inherits
// from PhysicalObject we have to override the abstract methods.
// Here I used formula that described intersection between sphere and half of a
// straight line. That's why appears two private variables: m_d1 and
// m_discriminant.

class Sphere: public PhysicalObject
{
public:
  Sphere(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d center,
    double radius,
    Material mat = Material::Default()
  ): PhysicalObject(pos, rot, mat), m_radius(radius), m_center(center), m_d1(0), m_discriminant(0) {}

  bool IsIntersected(Ray* ray);
  Eigen::Vector3d Intersect(Ray* ray);
  Eigen::Vector3d getNormal(Eigen::Vector3d point);

private:
  double m_radius;
  Eigen::Vector3d m_center;

  // Useful variables for computing intersection point
  double m_d1;
  double m_discriminant;
};

#endif
