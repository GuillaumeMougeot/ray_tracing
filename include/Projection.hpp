#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Object.hpp"

class Projection: public Object
{
public:
  //Constructors
  Projection(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    unsigned int width,
    unsigned int height,
    double near,
    double far
  ): Object(pos,rot), m_width(width), m_height(height), m_near(near), m_far(far) {}

private:
    unsigned int m_width, m_height;
    double m_near, m_far;
};

#endif
