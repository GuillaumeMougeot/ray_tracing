#ifndef RAY_HPP
#define RAY_HPP

#include <Eigen/Dense>

class Ray
{
public:
  //Constructors
  Ray(Eigen::Vector3d origin, Eigen::Vector3d direction) : m_origin(origin), m_direction(direction) {}

  //Accessors
  Eigen::Vector3d getOrigin() {return m_origin;}
  Eigen::Vector3d getDirection() {return m_direction;}

  void setOrigin(Eigen::Vector3d origin) {m_origin=origin;}
  void setDirection(Eigen::Vector3d direction) {m_direction=direction;}

private:
    Eigen::Vector3d m_origin;
    Eigen::Vector3d m_direction;
};

#endif
