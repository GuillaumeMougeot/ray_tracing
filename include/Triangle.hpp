#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <Eigen/Dense>

#include "PhysicalObject.hpp"
#include "Ray.hpp"
#include "Material.hpp"

class Triangle: public PhysicalObject
{
public:
  Triangle(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d v1,
    Eigen::Vector3d v2,
    Eigen::Vector3d v3,
    Material mat = Material::Default()
  ): PhysicalObject(pos, rot, mat), m_v1(v1), m_v2(v2), m_v3(v3), m_iu(0), m_ir(0), m_iv(0) {}

  bool IsIntersected(Ray* ray);
  Eigen::Vector3d Intersect(Ray* ray);
  Eigen::Vector3d getNormal(Eigen::Vector3d point);

private:
  Eigen::Vector3d m_v1;
  Eigen::Vector3d m_v2;
  Eigen::Vector3d m_v3;

  // Useful variables for computing intersection point
  double m_iu, m_ir, m_iv;
};

#endif
