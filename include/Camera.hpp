#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Object.hpp"

// * Camera:
// My camera object contains size of output image (m_width and m_height), the near
// plan where rays will be thrown and far plan where rays would stop. Actually I
// never used far plan in my algorithm. Camera behaviour and how rays are thrown
// is description in my core class Raytracing.

// Convention adopted: 1 pixel = 0.01 unit

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
    double far,
    double conversion
  ): Object(pos,rot), m_width(width), m_height(height), m_near(near), m_far(far), m_conversion(conversion) {}

  //Accessors
  unsigned int getWidth() {return m_width;}
  unsigned int getHeight() {return m_height;}
  double getNear() {return m_near;}
  double getFar() {return m_far;}
  double getConversion() {return m_conversion;}

private:
    unsigned int m_width, m_height;
    double m_near, m_far;
    // Convention adopted: 1 pixel = 0.01 unit
    double m_conversion;
};

#endif
