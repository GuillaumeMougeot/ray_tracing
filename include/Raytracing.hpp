#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <Eigen/Dense>

#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

class Raytracing
{
public:
  //Constructors
  Raytracing(
    Camera const* camera,
    Scene const* scene,
    unsigned int depth,
    double attenuation
  );

  // Accessors
  Eigen::Matrix<Eigen::Vector3d, m_image_width, m_image_heigth> getImageMatrix() {return m_image_matrix;}

  // Compute ray tracing
  void ThrowRays();

private:
    Camera* m_camera;
    Scene* m_scene;
    int m_image_width, m_image_heigth;
    Eigen::Matrix<Eigen::Vector3d, m_image_width, m_image_heigth> m_image_matrix;
    unsigned int m_depth;
    double attenuation;

    Eigen::Vector3d ThrowRay(Ray* ray);
};

#endif
