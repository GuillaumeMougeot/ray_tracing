#include "Raytracing.hpp"

using namespace cimg_library;

Raytracing::Raytracing(Camera const* camera, Scene const* scene, double attenuation_threshold)
{
  m_camera = camera;
  m_scene = scene;
  m_image_width = camera->getWidth();
  m_image_heigth = camera->getHeight();
  m_image = CImg(m_image_width, m_image_heigth,1,3,0);
  m_attenuation_threshold = attenuation_threshold;
}

Eigen::Vector3d Raytracing::ThrowRay(Ray* ray, unsigned int depth, double attenuation)
{
  Eigen::Vector3d cr, ct, cd;

  // Determine the closest object from ray.origin
  // closestDistance = -1 if no intersection detected
  double closestDistance = -1;
  unsigned int closestObject = 0;
  Eigen::Vector3d intersection(0,0,0);
  for (unsigned int i = 0; i < m_scene.getNumberOfPhysicalObjects(); i++)
  {
    if (m_scene.getPhysicalObject(i).IsIntersected(ray))
    {
      intersection = m_scene.getPhysicalObject(i).Intersect(ray);
      if (closestDistance == -1 || closestDistance > (intersection-ray->getOrigin()).norm())
      {
        closestDistance = (intersection-ray->getOrigin()).norm();
        closestObject = i;
      }
    }
  }

  // If there is no intersection: end of recursion
  if (closestDistance == -1)
  {
    return Eigen::Vector3d(0,0,0);
  }
  else
  {

  }
}
