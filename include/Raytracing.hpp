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
    Camera* camera,
    Scene* scene
  );

  // Accessors
  cimg_library::CImg<double> getImageMatrix() {return m_image;}

  // Compute ray tracing
  void ThrowRays(unsigned int depth);
  Eigen::Vector3d ThrowRay(Ray* ray, unsigned int depth);

  friend Eigen::Vector3d product(Eigen::Vector3d v1, Eigen::Vector3d v2);

  // Save image
  void Save(const char *const fileName) {m_image.save(fileName);}

private:
    Camera* m_camera;
    Scene* m_scene;
    int m_image_width, m_image_heigth;
    cimg_library::CImg<double> m_image;


    Eigen::Vector3d Phong(Light* light, PhysicalObject* obj, Ray* ray, Eigen::Vector3d& intersection);
    void FillPixel(unsigned int i,unsigned int j,Eigen::Vector3d& pixel);
};

#endif
