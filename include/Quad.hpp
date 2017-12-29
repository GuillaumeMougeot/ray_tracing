#ifndef QUAD_HPP
#define QUAD_HPP

#include "Triangle.hpp"

// * Quad:
// Inherits from Triangle. A quadrangle is described by two Triangles.

class Quad: public PhysicalObject
{
public:
  Quad(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d v1,
    Eigen::Vector3d v2,
    Eigen::Vector3d v3,
    Eigen::Vector3d v4,
    Material mat = Material::Default()
  ): PhysicalObject(pos, rot, mat), m_t1(pos, rot, v1, v2, v3, mat), m_t2(pos, rot, v1, v3, v4, mat) {}

  bool IsIntersected(Ray* ray) {return (m_t1.IsIntersected(ray) || m_t2.IsIntersected(ray));}
  Eigen::Vector3d Intersect(Ray* ray)
  {
    if (m_t1.IsIntersected(ray))
    {return m_t1.Intersect(ray);}
    else if (m_t2.IsIntersected(ray))
    {return m_t2.Intersect(ray);}
    else
    {return Eigen::Vector3d(0,0,0);}
  }
  Eigen::Vector3d getNormal(Eigen::Vector3d point) {return m_t1.getNormal(point);}

private:
  Triangle m_t1, m_t2;
};

#endif
