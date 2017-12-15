#include "Object.hpp"

Object::Object ()
{
  m_pos = Eigen::Vector3d(0,0,0);
  m_rot = Eigen::Quaterniond(0,0,0,1);
}

Object::Object (Eigen::Vector3d pos)
{
  m_pos = pos;
  m_rot = Eigen::Quaterniond(0,0,0,1);
}

Object::Object (Eigen::Quaterniond rot)
{
  m_pos = Eigen::Vector3d(0,0,0);
  m_rot = rot;
}

Object::Object (Eigen::Vector3d pos, Eigen::Quaterniond rot)
{
  m_pos = pos;
  m_rot = rot;
}
