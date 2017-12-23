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
#include "Quad.hpp"

using namespace Eigen;
using namespace cimg_library;
using namespace std;

int main()
{
  // Sphere definition
  // Sphere 1
  Quaterniond s1_rot(1,0,0,0);
  Vector3d s1_pos(3,0,3);
  Vector3d s1_center(s1_pos);
  double s1_radius(1);

  Vector3d s1_ka(0.2,0,0);
  Vector3d s1_kd(0.6,0,0);
  Vector3d s1_ks(0.5,0.5,0.5);
  //Vector3d s1_ks(0,0,0);
  double s1_n(30);
  Material s1_mat(s1_ka, s1_kd, s1_ks, s1_n);

  Sphere s1(s1_pos, s1_rot, s1_center, s1_radius, s1_mat);

  // Sphere 2
  Quaterniond s2_rot(1,0,0,0);
  Vector3d s2_pos(6,0,2);
  Vector3d s2_center(s2_pos);
  double s2_radius(1);

  Vector3d s2_ka(0,0,0.2);
  Vector3d s2_kd(0,0,0.6);
  Vector3d s2_ks(0.05,0.05,0.1);
  //Vector3d s2_ks(0,0,0);
  double s2_n(0.05);
  Material s2_mat(s2_ka, s2_kd, s2_ks, s2_n);

  Sphere s2(s2_pos, s2_rot, s2_center, s2_radius, s2_mat);

  // Triangle definition
  Quaterniond t1_rot(1,0,0,0);
  Vector3d t1_pos(5,0,-2);
  Vector3d t1_v1(8,-1,-2), t1_v2(8,-1,2), t1_v3(8,2,0);

  Vector3d t1_ka(0,0.2,0);
  Vector3d t1_kd(0,0.7,0);
  Vector3d t1_ks(0.5,0.5,0.5);
  double t1_n(200);
  Material t1_mat(t1_ka, t1_kd, t1_ks, t1_n);

  Triangle t1(t1_pos, t1_rot, t1_v1, t1_v2, t1_v3, t1_mat);

  // Quads definition
  Quaterniond q1_rot(1,0,0,0);
  Vector3d q1_pos(10,0,0);
  Vector3d q1_v1(10,-5,-5), q1_v2(10,-5,5), q1_v3(10,5,5), q1_v4(10,5,-5);

  Quad q1(q1_pos, q1_rot, q1_v1, q1_v2, q1_v3, q1_v4);

  Quaterniond q2_rot(1,0,0,0);
  Vector3d q2_pos(5,0,-5);
  Vector3d q2_v1(0,-5,-5), q2_v2(10,-5,-5), q2_v3(10,5,-5), q2_v4(0,5,-5);

  Quad q2(q2_pos, q2_rot, q2_v1, q2_v2, q2_v3, q2_v4);

  Quaterniond q3_rot(1,0,0,0);
  Vector3d q3_pos(5,0,5);
  Vector3d q3_v1(10,-5,5), q3_v2(0,-5,5), q3_v3(0,5,5), q3_v4(10,5,5);

  Quad q3(q3_pos, q3_rot, q3_v1, q3_v2, q3_v3, q3_v4);

  Quaterniond q4_rot(1,0,0,0);
  Vector3d q4_pos(5,5,0);
  Vector3d q4_v1(10,5,-5), q4_v2(10,5,5), q4_v3(0,5,5), q4_v4(0,5,-5);

  Quad q4(q4_pos, q4_rot, q4_v1, q4_v2, q4_v3, q4_v4);

  Quaterniond q5_rot(1,0,0,0);
  Vector3d q5_pos(5,-5,0);
  Vector3d q5_v1(0,-5,-5), q5_v2(0,-5,5), q5_v3(10,-5,5), q5_v4(10,-5,-5);

  Quad q5(q5_pos, q5_rot, q5_v1, q5_v2, q5_v3, q5_v4);

  // Lights definition
  Quaterniond l1_rot(1,0,0,0);
  Vector3d l1_pos(1,4,0);
  Vector3d l1_id(1,1,1);
  Vector3d l1_is(1,1,1);

  Light l1(l1_pos, l1_rot, l1_id, l1_is);

  Quaterniond l2_rot(1,0,0,0);
  Vector3d l2_pos(1,-4,0);
  Vector3d l2_id(0.1,0.1,0.5);
  Vector3d l2_is(0.2,0.2,0.2);

  Light l2(l2_pos, l2_rot, l2_id, l2_is);

  // Scene definition
  Vector3d scene_ia(0.5,0.5,0.5);

  Scene scene(scene_ia);

  scene.AddPhysicalObject(&s1);
  scene.AddPhysicalObject(&s2);
  scene.AddPhysicalObject(&t1);
  scene.AddPhysicalObject(&q1);
  scene.AddPhysicalObject(&q2);
  scene.AddPhysicalObject(&q3);
  scene.AddPhysicalObject(&q4);
  scene.AddPhysicalObject(&q5);
  scene.AddLight(&l1);
  scene.AddLight(&l2);

  // Camera definiton
  Quaterniond cam_rot(1,0,0,0);
  Vector3d cam_pos(0,0,0);

  Camera cam(cam_pos, cam_rot, 800, 600, 0, 20);

  // Ray tracing definition
  Raytracing raytracing(&cam, &scene);


  // Vector3d origin(0,0,0);
  // Vector3d direction(1,0,0);
  // Ray ray(origin, direction);
  // Vector3d v = raytracing.ThrowRay(&ray, 1);
  // cout << endl << v << endl;
  // #pragma omp parallel
  raytracing.ThrowRays(2);
  raytracing.Save("ray_tracing.png");

  return 0;
}
