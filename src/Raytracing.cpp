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

// Component by component product for Eigen::Vector3d
Eigen::Vector3d product(Eigen::Vector3d v1, Eigen::Vector3d v2)
{
  return Eigen::Vector(v1[0]*v2[0], v1[1]*v2[1], v1[2]*v2[2]);
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
    Eigen::Vector3d cd = product(m_scene->getPhysicalObject(closestObject)->getMaterial().getKa(), m_ia);

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
        cd += Phong(m_scene->getLight(i), m_scene->getPhysicalObject(closestObject), &rd, intersection);
      }
    }
    return cr + cd;
  }
}

Eigen::Vector3d Raytracing::Phong(Light* light, PhysicalObject* obj, Ray* ray, Eigen::Vector3d& intersection)
{
  Eigen::Vector3d normal = obj->getNormal(intersection);
  Eigen::Vector3d L = light->getPos()-intersection;
  double LN = normal.dot(L);
  Eigen::Vector3d result = product(light->getId(), obj->getKd()) * LN;
  result += product(light->getIs(), obj->getKs()) * (intersection-ray->getOrigin()).dot(2*LN*normal - L);
  return result;
}

void Raytracing::FillPixel(unsigned int i,unsigned int j,Eigen::Vector3d& pixel)
{
  for (int k = 0; k < 3; k++)
  {
    if (pixel[k]>255) {m_image(i, j, k) = 255;}
    else {m_image(i, j, k) = pixel[k];}
  }
}

void Raytracing::ThrowRays(unsigned int depth)
{
  Eigen::Vector3d imageOrigin(m_camera->getNear(), m_image_heigth/2, m_image_width/2);
  Eigen::Vector3d y(0,1,0);
  Eigen::Vector3d z(0,0,1);
  for (unsigned int i = 0; i < m_image_heigth; i++)
  {
    for (unsigned int j = 0; j < m_image_width; j++)
    {
      Eigen::Vector3d rayOrign = imageOrigin + camera->getConversion()*(j*y+i*z);
      // potential bug: take camera position and rotation into account
      Eigen::Vector3d rayDirection = rayOrign - camera->getPos();
      Ray ray(rayOrign, rayDirection);
      Eigen::Vector3d pixelColor = ThrowRay(&ray, depth);
      FillPixel(i, j, pixelColor);
    }
  }
}
