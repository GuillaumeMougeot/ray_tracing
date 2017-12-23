#include "Triangle.hpp"

bool Triangle::IsIntersected(Ray* ray)
{
  Eigen::Vector3d u = m_v2 - m_v1;
  Eigen::Vector3d v = m_v3 - m_v1;
  Eigen::Vector3d Otr = ray->getOrigin() - m_v1;
  Eigen::Vector3d n = u.cross(v).normalized();

  double den1 = n.dot(ray->getDirection());
  m_ir = 0;

  if (den1 != 0)
  {
    m_ir = -n.dot(Otr)/den1;

    m_iu = 0;
    double den2 = u.dot(Otr.cross(v));
    if (den2 != 0)
    {
      m_iu = m_ir*ray->getDirection().dot(Otr.cross(v))/den2;

      m_iv = 0;
      double den3 = v.dot(Otr.cross(u));
      m_iv = m_ir*ray->getDirection().dot(Otr.cross(u))/den3;
    }

    return (m_iu>=0 && m_iu<=1 && m_iv>=0 && m_iv<=1 && m_ir>=0 && m_iu+m_iv<=1);
  }
  else
  {
    return false;
  }
}

Eigen::Vector3d Triangle::Intersect(Ray* ray)
{
  if(IsIntersected(ray))
  {
    return (ray->getOrigin() + m_ir*ray->getDirection());
  }
}

Eigen::Vector3d Triangle::getNormal(Eigen::Vector3d point)
{
  Eigen::Vector3d u = m_v2 - m_v1;
  Eigen::Vector3d v = m_v3 - m_v1;
  return (u.cross(v).normalized());
}
