#include "Sphere.hpp"

// https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
bool Sphere::IsIntersect(Ray* ray)
{
  Eigen::Vector3d d = ray->getOrigin() - m_center
  m_d1 = ray->getDirection().dot(d);
  m_discriminant = m_d1*m_d1 - d.squaredNorm() + m_radius*m_radius;

  return(m_discriminant >= 0)
}
