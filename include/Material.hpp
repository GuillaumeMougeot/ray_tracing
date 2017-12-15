#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <Eigen/Dense>

class Material
{
public:
  Material(
    Eigen::Vector3d ka,
    Eigen::Vector3d kd,
    Eigen::Vector3d ks,
    double n
  ): m_ka(ka), m_kd(kd), m_ks(ks), m_n(n) {}

private:
  Eigen::Vector3d m_ka, m_kd, m_ks;
  double m_n;
};

#endif
