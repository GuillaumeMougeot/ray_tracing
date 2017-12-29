#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <Eigen/Dense>
#include "CImg/CImg.h"

#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"

// * Raytracing:
// Core class of this work. It computes ray tracing with a recursive algorithm.
// Input:
//  - a Camera
//  - a Scene
// Output:
//  - an image saved in the current folder.
// Useful methods:
//  - ThrowRays: launch ray tracing algorithm. Input depth variable is depth of
//  ray tracing algorithm. 3 was the assignment requirement.
//  - Save: save image in the precised file path (current path by Default).
// Private methods:
//  - Phong: with a given light, object, ray and intersection point, return the
//  corresponding Phong color.
//  - FillPixel: fill pixels with coordinate (i,j) in image with the RGB color
//  described with Eigen::Vector3d type.
//  - ThrowRay: recursive method that's throwing rays until the max depth is
//  reached.

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

  friend Eigen::Vector3d product(Eigen::Vector3d v1, Eigen::Vector3d v2);

  // Save image
  void Save(const char *const fileName) {m_image.save(fileName);}

private:
    Camera* m_camera;
    Scene* m_scene;
    int m_image_width, m_image_heigth;
    cimg_library::CImg<double> m_image;
    // m_threshold : to not intersecting with itself
    double m_threshold;

    Eigen::Vector3d Phong(Light* light, PhysicalObject* obj, Ray* ray, Eigen::Vector3d& intersection);
    void FillPixel(unsigned int i,unsigned int j,Eigen::Vector3d& pixel);

    Eigen::Vector3d ThrowRay(Ray* ray, unsigned int depth);
};

#endif
