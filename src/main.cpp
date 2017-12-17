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
#include "Triangle.hpp"
#include "Ray.hpp"

using namespace Eigen;
using namespace cimg_library;
using namespace std;

int main()
{
  // Sphere definition
  // Sphere 1
  Quaterniond s1_rot(1,0,0,0);
  Vector3d s1_pos(5,0,2);
  Vector3d s1_center(s1_pos);
  double s1_radius(2);

  Vector3d s1_ka(0.2,0,0);
  Vector3d s1_kd(0.6,0,0);
  Vector3d s1_ks(0.8,0.9,0.9);
  //Vector3d s1_ks(0,0,0);
  double s1_n(200);
  Material s1_mat(s1_ka, s1_kd, s1_ks, s1_n);

  Sphere s1(s1_pos, s1_rot, s1_center, s1_radius, s1_mat);

  // Sphere 2
  Quaterniond s2_rot(1,0,0,0);
  Vector3d s2_pos(5,0,-2);
  Vector3d s2_center(s2_pos);
  double s2_radius(2);

  Vector3d s2_ka(0,0,0.2);
  Vector3d s2_kd(0,0,0.6);
  Vector3d s2_ks(0.9,0.9,0.9);
  //Vector3d s2_ks(0,0,0);
  double s2_n(200);
  Material s2_mat(s2_ka, s2_kd, s2_ks, s2_n);

  Sphere s2(s2_pos, s2_rot, s2_center, s2_radius, s2_mat);

  // Triangle definition
  Quaterniond t1_rot(1,0,0,0);
  Vector3d t1_pos(5,0,-2);
  Vector3d t1_v1(8,0,-2), t1_v2(8,0,2), t1_v3(8,2,0);

  Vector3d t1_ka(0,0.2,0);
  Vector3d t1_kd(0,0.7,0);
  Vector3d t1_ks(0.9,0.9,0.9);
  double t1_n(200);
  Material t1_mat(t1_ka, t1_kd, t1_ks, t1_n);

  Triangle t1(t1_pos, t1_rot, t1_v1, t1_v2, t1_v3, t1_mat);

  // Light definition
  Quaterniond l1_rot(1,0,0,0);
  Vector3d l1_pos(2,20,0);
  Vector3d l1_id(1,1,1);
  Vector3d l1_is(1,1,1);

  Light l1(l1_pos, l1_rot, l1_id, l1_is);

  Quaterniond l2_rot(1,0,0,0);
  Vector3d l2_pos(2,0,-20);
  Vector3d l2_id(0.3,0.3,0.7);
  Vector3d l2_is(1,1,1);

  Light l2(l2_pos, l2_rot, l2_id, l2_is);

  // Scene definition
  Vector3d scene_ia(0.5,0.5,0.5);

  Scene scene(scene_ia);

  scene.AddPhysicalObject(&s1);
  scene.AddPhysicalObject(&s2);
  scene.AddPhysicalObject(&t1);
  scene.AddLight(&l1);
  scene.AddLight(&l2);

  // Camera definiton
  Quaterniond cam_rot(1,0,0,0);
  Vector3d cam_pos(0,0,0);

  Camera cam(cam_pos, cam_rot, 800, 600, 2, 20);

  // Ray tracing definition
  Raytracing raytracing(&cam, &scene);
  //
  // Vector3d origin(0,0,0);
  // Vector3d direction(1,0,0);
  // Ray ray(origin, direction);
  // Vector3d v = raytracing.ThrowRay(&ray, 2);
  // cout << endl << v << endl;
  //#pragma omp parallel
  raytracing.ThrowRays(1);
  raytracing.Save("ray_tracing.png");

  return 0;
}
