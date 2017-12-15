#include <iostream>
#include <Eigen/Dense>

#include "Object.hpp"

using namespace Eigen;
using namespace std;

int main()
{
  Vector3d v(1,2,3);
  cout << v << endl;
  v.normalize();
  cout << v;
  return 0;
}
