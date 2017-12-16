#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <Eigen/Dense>
#include "CImg/CImg.h"

#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

class Raytracing
{
public:
  //Constructors
  Raytracing(
    Camera const* camera,
    Scene const* scene
  );

  // Accessors
  cimg_library::CImg getImageMatrix() {return m_image;}

  // Compute ray tracing
  void ThrowRays(unsigned int depth);

private:
    Camera* m_camera;
    Scene* m_scene;
    int m_image_width, m_image_heigth;
    cimg_library::CImg<double> m_image;

    Eigen::Vector3d ThrowRay(Ray* ray, unsigned int depth);
    Eigen::Vector3d Phong(Light* light, PhysicalObject* pObj, Ray* ray);
};

#endif
