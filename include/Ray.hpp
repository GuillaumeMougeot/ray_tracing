#ifndef RAY_HPP
#define RAY_HPP

#include <Eigen/Dense>

class Ray
{
public:
  //Constructors
  Ray(Eigen::Vector3d start, Eigen::Vector3d end) : m_start(start), m_end(end) {}

  //Accessors
  Eigen::Vector3d getStart() {return m_start;}
  Eigen::Vector3d getEnd() {return m_end;}

  void setStart(Eigen::Vector3d start) {m_start=start;}
  void setEnd(Eigen::Vector3d end) {m_end=end;}

private:
    Eigen::Vector3d m_start;
    Eigen::Vector3d m_end;
};

#endif
