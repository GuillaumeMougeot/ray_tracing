#include "Raytracing.hpp"

using namespace cimg_library;

Raytracing::Raytracing(Camera const* camera, Scene const* scene)
{
  m_camera = camera;
  m_scene = scene;
  m_image_width = camera->getWidth();
  m_image_heigth = camera->getHeight();
  m_image = CImg(m_image_width, m_image_heigth,1,3,0);
}

Eigen::Vector3d Raytracing::ThrowRay(Ray* ray, unsigned int depth)
{
  // Determine the closest object from ray.origin
  // closestDistance = -1 if no intersection detected
  double closestDistance = -1;
  unsigned int closestObject = 0;
  Eigen::Vector3d intersection(0,0,0);
  for (unsigned int i = 0; i < m_scene->getNumberOfPhysicalObjects(); i++)
  {
    if (m_scene->getPhysicalObject(i)->IsIntersected(ray))
    {
      intersection = m_scene->getPhysicalObject(i)->Intersect(ray);
      if (closestDistance == -1 || closestDistance > (intersection-ray->getOrigin()).norm())
      {
        closestDistance = (intersection-ray->getOrigin()).norm();
        closestObject = i;
      }
    }
  }

  // If there is no intersection: end of recursion
  if (closestDistance == -1 || depth == 0)
  {
    return Eigen::Vector3d(0,0,0);
  }
  else
  {
    // compute refected and tranmitted rays
    Eigen::Vector3d op = intersection - ray->getOrigin();
    Ray rr(intersection, 2*op.dot(ray->getNormal())*ray->getNormal() - op);
    //TODO: transmitted Ray

    // compute reflected, transmitted and diffuse colors
    Eigen::Vector3d cr(ThrowRay(rr, depth-1));
    //TODO: transmitted color
    Eigen::Vector3d cd(0,0,0);

    // for all light source compute phong color
    for (unsigned int i = 0; i < m_scene->getNumberOfLigths(); i++)
    {
      Ray rd(intersection, m_scene->getLight(i)->getPos())
      // check if rd is intercepted
      bool intercepted = false;
      for (unsigned int j = 0; j < m_scene->getNumberOfPhysicalObjects(); j++)
      {
        if (j != closestObject && m_scene->getPhysicalObject(j)->Intersect(ray))
        {
          intercepted = true;
        }
      }

      if(!intercepted)
      {
        cd += Phong(m_scene->getLight(i), m_scene->getPhysicalObject(closestObject), &rd);
      }
    }
    return cr + cd;
  }
}
