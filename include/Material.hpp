#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <Eigen/Dense>

// * Material:
// Describes material property of PhysicalObject in Phong model. PhysicalObject
// have:
//  - m_ka: constant for ambient illumination.
//  - m_kd: constant for diffuse illumination.
//  - m_ks and m_n: constants for specular illumination.

class Material
{
public:
  Material(
    Eigen::Vector3d ka,
    Eigen::Vector3d kd,
    Eigen::Vector3d ks,
    double n
  ): m_ka(ka), m_kd(kd), m_ks(ks), m_n(n) {}

  Eigen::Vector3d getKa() {return m_ka;}
  Eigen::Vector3d getKd() {return m_kd;}
  Eigen::Vector3d getKs() {return m_ks;}
  double getN() {return m_n;}

  static Material Default()
  {
    Eigen::Vector3d ka(0.1,0.1,0.1), kd(0.5,0.5,0.5), ks(0,0,0);
    return Material(ka,kd,ks,1);
  }

private:
  Eigen::Vector3d m_ka, m_kd, m_ks;
  double m_n;
};

#endif
