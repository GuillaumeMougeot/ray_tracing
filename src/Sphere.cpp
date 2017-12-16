#include "Sphere.hpp"

// https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
bool Sphere::IsIntersected(Ray* ray)
{
  Eigen::Vector3d d = ray->getOrigin() - m_center
  m_d1 = ray->getDirection().dot(d);
  m_discriminant = m_d1*m_d1 - d.squaredNorm() + m_radius*m_radius;

  return (m_discriminant > 0);
}

Eigen::Vector3d Sphere::Intersect(Ray* ray)
{
  double d = std::min(-m_d1+std::sqrt(m_discriminant), -m_d1-std::sqrt(m_discriminant));
  return (ray->getOrigin() + d*ray->getDirection());
}

Eigen::Vector3d Sphere::getNormal(Eigen::Vector3d point)
{
  return (point-m_center).normalize();
}
