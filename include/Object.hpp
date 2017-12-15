#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <../Eigen/Dense>
#include <../Eigen/Geometry>

class Object:
{
public:
  //Constructors
  Object();
  // Object(Eigen::Vector3d pos);
  // Object(Eigen::Quaternion rot);
  // Object(Eigen::Vector3d pos, Eigen::Quaternion rot);

protected:
  Eigen::Vector3d m_pos;
  Eigen::Quaternion m_rot;
};

#endif
