#include "Triangle.hpp"
#include "Material.hpp"

Triangle::Triangle(
  Eigen::Vector3d pos,
  Eigen::Quaterniond rot,
  Eigen::Vector3d v1,
  Eigen::Vector3d v2,
  Eigen::Vector3d v3,
  Eigen::Vector3d normal,
  Material mat
): PhysicalObject(pos, rot, mat)
{
  Eigen::Vector3d n = (v2 - v1).cross(v3 - v1).normalized();
  if (n.dot(normal) < 0)
  {
    m_v1 = v2;
    m_v2 = v1;
    m_v3 = v3;
  }
  else
  {
    m_v1 = v1;
    m_v2 = v2;
    m_v3 = v3;
  }
  m_iu = 0;
  m_ir = 0;
  m_iv = 0;
}

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
