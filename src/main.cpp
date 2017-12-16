#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "CImg/CImg.h"

#include "Scene.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Material.hpp"
#include "Raytracing.hpp"
#include "Ray.hpp"

using namespace Eigen;
using namespace cimg_library;
using namespace std;

int main()
{
  cout << "coucou";
  // Sphere definition
  Quaterniond s1_rot(1,0,0,0);
  Vector3d s1_pos(10,0,0);
  Vector3d s1_center(10,0,0);
  double s1_radius(1);

  Vector3d s1_ka(0,0,0);
  Vector3d s1_kd(1,0,0);
  Vector3d s1_ks(0.5,0.5,0.5);
  double s1_n(1);
  Material s1_mat(s1_ka, s1_kd, s1_ks, s1_n);

  Sphere s1(s1_pos, s1_rot, s1_center, s1_radius, s1_mat);

  // Light definition
  Quaterniond l1_rot(1,0,0,0);
  Vector3d l1_pos(5,10,0);
  Vector3d l1_id(1,1,1);
  Vector3d l1_is(1,1,1);

  Light l1(l1_pos, l1_rot, l1_id, l1_is);

  // Scene definition
  Vector3d scene_ia(0,0,0.1);

  Scene scene(scene_ia);

  // Camera definiton
  Quaterniond cam_rot(1,0,0,0);
  Vector3d cam_pos(0,0,0);

  Camera cam(cam_pos, cam_rot, 800, 600, 2, 20);
  cout << "coucou";
  // Ray tracing definition
  Raytracing raytracing(&cam, &scene);

  Vector3d origin(0,0,0);
  Vector3d direction(1,0,0);
  Ray ray(origin, direction);
  Vector3d v = raytracing.ThrowRay(&ray, 2);
  cout << endl << v << endl;
  // raytracing.ThrowRays(1);
  // raytracing.Save("ray_tracing.png");

  return 0;
}
