/****************************************
 * Title:  Ray Tracing - Homework 4     *
 * Author: Guillaume Mougeot            *
 * ID:     117032990024                 *
 * Date:   2017/12/29                   *
 ****************************************/

# Presentation
This readme file presents my work on ray tracing algorithm. How I implemented it
and several example and applications of this algorithm.

My first goal was to implement ray tracing algorithm with Sphere object.To do so
I had to define Sphere properties and how this Object should interacts with
Rays. I created a Scene which would would include Spheres and Lights Objects.

I then implement Triangle interaction and finally interaction with .OBJ files.

I mostly commented .HPP files.

# Launch this project
This project was develop on linux platform. But it can be launched from Windows
using the Makefile I created. Or by adding .CPP and .HPP files to your prefered
IDE.

On linux: open a terminal in the Makefile's folder and type: make. Then launch
the executable file by typing: ./ray_tracing.

I don't know yet how to properly use cmake, I apologize for that...

To properly work this project needs CImg, Eigen, and tinyobjloader which are
normally included in lib folder.

# Classes description
 * Object:
Base class. Define only a position and a rotation.

 * PhysicalObject:
Abstract base class, inherits from Object. Describes behaviour of objects that
could be reached by rays. A PhysicalObject have a Material property.

Contains three abstract methods:
  - bool IsIntersected(Ray* ray)
      return: True if this physical object is intersected by ray.
  - Eigen::Vector3d Intersect(Ray* ray)
      return: intersection point.
  - Eigen::Vector3d getNormal(Eigen::Vector3d point)
      return: normal of the physical object at the given point.

 * Material:
 Describes material property of PhysicalObject in Phong model. PhysicalObject
 have:
  - m_ka: constant for ambient illumination.
  - m_kd: constant for diffuse illumination.
  - m_ks and m_n: constants for specular illumination.

 * Sphere:
 Inherits from PhysicalObject. Contains a center and a radius. As it inherits
 from PhysicalObject we have to override the abstract methods.
 Here I used formula that described intersection between sphere and half of a
 straight line. That's why appears two private variables: m_d1 and
 m_discriminant.

 * Triangle:
 Inherits from PhysicalObject. Contains three vertices m_v1, m_v2 and m_v3.
 Here I used three private variables to help me for computation: m_iu, m_ir and
 m_iv.

 * Quad:
 Inherits from Triangle. A quadrangle is described by two Triangles.

 * Light:
 Inherits from Object. Here my Light object have only two parameters of Phong
 model: m_id and m_is. m_ia will be described further in Scene object.

 * Ray:
 A ray is described by an origin and a direction.

 * Scene:
 A scene object is a description of how PhysicalObject and Lights will appear
 on screen. Hence a scene is a vector of PhysicalObjects and Lights. As I used
 polymorphism these vectors have to contains pointers.
 It seems natural to include m_ia Phong ambiant illumation constant here.

 Scene contains two useful methods:
 - AddPhysicalObject
 - AddLight

 * Camera:
 My camera object contains size of output image (m_width and m_height), the near
 plan where rays will be thrown and far plan where rays would stop. Actually I
 never used far plan in my algorithm. Camera behaviour and how rays are thrown
 is description in my core class Raytracing.

 * Raytracing:
 Core class of this work. It computes ray tracing with a recursive algorithm.
 Input:
  - a Camera
  - a Scene
 Output:
  - an image saved in the current folder.
 Useful methods:
  - ThrowRays: launch ray tracing algorithm. Input depth variable is depth of
  ray tracing algorithm. 3 was the assignment requirement.
  - Save: save image in the precised file path (current path by Default).
 Private methods:
  - Phong: with a given light, object, ray and intersection point, return the
  corresponding Phong color.
  - FillPixel: fill pixels with coordinate (i,j) in image with the RGB color
  described with Eigen::Vector3d type.
  - ThrowRay: recursive method that's throwing rays until the max depth is
  reached.

 * OBJTest and PNGTest:
 Are two test classes. Uncomment the corresponding line in the main file to
 execute one of those.
 - OBJTest tests .OBJ files placed in /models folder.
 - PNGTest tests other technics like Sphere, Triangles, Quads and multiple
 Lights scenes.

# Conlusion
  This long project was all done by my own and it brings me a lot, more than I
  would never have expected. Thank you! :)
