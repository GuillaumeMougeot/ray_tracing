#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Object.hpp"
#include "Ray.hpp"

class PhysicalObject: public Object
{
public:
  //Constructors
  PhysicalObject(
    Eigen::Vector3d pos,
    Eigen::Quaterniond rot,
    Material mat
  ): Object(pos, rot), m_mat(mat) {}

  //Accessors
  Eigen::Vector3d getPos() {return m_pos;}
  Eigen::Quaterniond getRot() {return m_rot;}

  //Intersection with a ray
  // return: true if intersection, false otherwise
  virtual bool IsIntersected(Ray* ray)=0;
  // return: intersection point
  // Warning: use IsIntersect before to check intersection
  virtual Eigen::Vector3d Intersect(Ray* ray)=0;

  // return: normal in a point:
  virtual Eigen::Vector3d getNormal(Eigen::Vector3d point)=0;

protected:
  Material m_mat;
};

#endif
