#include "Raytracing.hpp"

Raytracing::Raytracing(Camera const* camera, Scene const* scene, unsigned int depth, double attenuation)
{
  m_camera = camera;
  m_scene = scene;
  m_image_width = camera->getWidth();
  m_image_heigth = camera->getHeight();
  m_image_matrix = Eigen::Matrix<Eigen::Vector3d, m_image_width, m_image_heigth>();
  
}
