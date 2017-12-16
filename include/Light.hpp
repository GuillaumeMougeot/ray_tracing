#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Object.hpp"

class Light: public Object
{
public:
  //Constructors
  Light(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Eigen::Vector3d id,
    Eigen::Vector3d is
  ): Object(pos,rot), m_is(is), m_id(id) {}

  Eigen::Vector3d getId() {return m_id;}
  Eigen::Vector3d getIs() {return m_is;}

private:
    Eigen::Vector3d m_id, m_is;
};

#endif
