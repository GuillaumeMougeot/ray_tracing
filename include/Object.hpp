#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

class Object
{
public:
  //Constructors
  Object(): m_pos(Eigen::Vector3d(0,0,0)), m_rot(Eigen::Quaterniond(0,0,0,1)) {}
  Object(Eigen::Vector3d pos): m_pos(pos), m_rot(Eigen::Quaterniond(0,0,0,1)) {}
  Object(Eigen::Quaterniond rot): m_pos(Eigen::Vector3d(0,0,0)), m_rot(rot) {}
  Object(Eigen::Vector3d pos, Eigen::Quaterniond rot): m_pos(pos), m_rot(rot) {}

  //Accessors
  Eigen::Vector3d getPos() {return m_pos;}
  Eigen::Quaterniond getRot() {return m_rot;}

protected:
  Eigen::Vector3d m_pos;
  Eigen::Quaterniond m_rot;
};

#endif
