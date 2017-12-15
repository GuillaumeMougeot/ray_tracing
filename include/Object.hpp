#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <../Eigen/Dense>
#include <../Eigen/Geometry>

class Object
{
public:
  //Constructors
  Object();
  Object(Eigen::Vector3d pos);
  Object(Eigen::Quaterniond rot);
  Object(Eigen::Vector3d pos, Eigen::Quaterniond rot);

  //Accessors
  Eigen::Vector3d getPos() {return m_pos;}
  Eigen::Quaterniond getRot() {return m_rot;}

protected:
  Eigen::Vector3d m_pos;
  Eigen::Quaterniond m_rot;
};

#endif
