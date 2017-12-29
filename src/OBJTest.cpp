#include "OBJTest.hpp"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "CImg/CImg.h"

#include "Scene.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Raytracing.hpp"

using namespace Eigen;
using namespace cimg_library;

void OBJTest () {

  std::string inputfile = "./models/bunny.obj";
  tinyobj::attrib_t attrib;
  std::vector<tinyobj::shape_t> shapes;
  std::vector<tinyobj::material_t> materials;

  Quaterniond rot(1,0,0,0);
  Vector3d pos(0.2,-0.1,0);
  Vector3d faces[3];
  Vector3d ka(0.2,0.2,0.2);
  Vector3d kd(0.5,0.5,0.5);
  Vector3d ks(0.5,0.5,0.5);
  double n(2);
  Material mat(ka, kd, ks, n);

  Vector3d scene_ia(0.5,0.5,0.5);
  Scene scene(scene_ia);

  Quaterniond cam_rot(1,0,0,0);
  Vector3d cam_pos(0,0,0);

  Camera cam(cam_pos, cam_rot, 800, 600, 0, 20, 0.0005);

  std::string err;
  bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, inputfile.c_str());

  if (!err.empty()) { // `err` may contain warning message.
    std::cerr << err << std::endl;
  }

  if (!ret) {
    exit(1);
  }

  // Loop over shapes
  for (size_t s = 0; s < shapes.size(); s++) {
    // Loop over faces(polygon)
    size_t index_offset = 0;
    for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
      //std::cout << "face index " << f << '\n';
      int fv = shapes[s].mesh.num_face_vertices[f];
      //Vector3d* normal = new Vector3d();
      // Loop over vertices in the face.
      for (size_t v = 0; v < fv; v++) {
        // access to vertex
        //Transform<double,3,Affine> t = AngleAxisd(0.25*M_PI, Vector3d::UnitX());
        tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
        tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
        tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
        tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
        tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
        tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
        tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
        tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
        tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];

        faces[v] = pos + AngleAxisd(-0.5*M_PI, Vector3d::UnitY())*Vector3d(vx,vy,vz);
      }
      index_offset += fv;
      //Triangle* t = new Triangle(pos,rot,faces[0],faces[1],faces[2],normal,mat);
      //scene.AddPhysicalObject(t);
      scene.AddPhysicalObject(new Triangle(pos,rot,faces[0], faces[1], faces[2], mat));
      // per-face material
      //delete normal;
      shapes[s].mesh.material_ids[f];
    }
  }

  // Sphere definition
  // Sphere 1
  Quaterniond s1_rot(1,0,0,0);
  Vector3d s1_pos(0.2,0,0.15);
  Vector3d s1_center(s1_pos);
  double s1_radius(0.05);

  Vector3d s1_ka(0.2,0,0);
  Vector3d s1_kd(0.6,0,0);
  Vector3d s1_ks(0.5,0.5,0.5);
  //Vector3d s1_ks(0,0,0);
  double s1_n(30);
  Material s1_mat(s1_ka, s1_kd, s1_ks, s1_n);

  Sphere s1(s1_pos, s1_rot, s1_center, s1_radius, s1_mat);

  scene.AddPhysicalObject(&s1);

  // Lights definition
  Quaterniond l1_rot(1,0,0,0);
  Vector3d l1_pos(0,4,0);
  Vector3d l1_id(1,1,1);
  Vector3d l1_is(1,1,1);

  Light l1(l1_pos, l1_rot, l1_id, l1_is);

  scene.AddLight(&l1);

  Raytracing raytracing(&cam, &scene);

  raytracing.ThrowRays(3);
  raytracing.Save("ray_tracing_obj.png");
}
