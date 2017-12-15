#include "Object.hpp"

Object::Object ()
{
  m_pos = Eigen::Vector3d(0,0,0);
  m_rot = Eigen::Quaternion(0,0,0,1);
}
