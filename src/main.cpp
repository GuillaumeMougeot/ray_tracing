#include "PNGTest.hpp"
#include "OBJTest.hpp"

#include <iostream>

using namespace std;

int main()
{
  cout << "Homework 4 - Guillaume Mougeot - 117032990024" << endl << endl;
  cout << "Which you would like to see?" << endl;
  cout << "1 Test a scene with spheres, triangles, quadrangles and multiple lights?" << endl;
  cout << "2 Test a scene with Stanford bunny?" << endl;
  int input = 0;
  cin >> input;
  if (input == 2)
    OBJTest ();
  else
    PNGTest();
  return 0;
}
