#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Object.hpp"

class Camera: public Object
{
public:
  //Constructors
  Camera(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    unsigned int width,
    unsigned int height,
    double near,
    double far
  ): Object(pos,rot), m_width(width), m_height(height), m_near(near), m_far(far) {}

  //Accessors
  unsigned int getWidth() {return m_width;}
  unsigned int getHeight() {return m_heigth;}

private:
    unsigned int m_width, m_height;
    double m_near, m_far;
};

#endif
