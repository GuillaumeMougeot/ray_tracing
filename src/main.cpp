#include <iostream>
#include <Eigen/Dense>
#include "CImg/CImg.h"


#include "Object.hpp"

using namespace Eigen;
using namespace cimg_library;
using namespace std;

int main()
{
  unsigned int w(800), h(600);
  CImg<double> img(800,60,1,3,0);
  img.save("truc.png");
  return 0;
}
