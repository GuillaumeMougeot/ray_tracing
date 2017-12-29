#ifndef PHYSICALOBJECT_HPP
#define PHYSICALOBJECT_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "Material.hpp"
#include "Object.hpp"
#include "Ray.hpp"

// * PhysicalObject:
// Abstract base class, inherits from Object. Describes behaviour of objects that
// could be reached by rays. A PhysicalObject have a Material property.
//
// Contains three abstract methods:
//  - bool IsIntersected(Ray* ray)
//      return: True if this physical object is intersected by ray.
//  - Eigen::Vector3d Intersect(Ray* ray)
//      return: intersection point.
//  - Eigen::Vector3d getNormal(Eigen::Vector3d point)
//      return: normal of the physical object at the given point.

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
  Material* getMaterial() {return &m_mat;}

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
