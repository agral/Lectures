#include <iostream>

struct Vec3 {
  Vec3(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) {};

  double m_x;
  double m_y;
  double m_z;

  friend std::ostream& operator<<(std::ostream&, const Vec3&);
};

std::ostream& operator<<(std::ostream& os, const Vec3& vec3)
{
  os << "Vec3(" << vec3.m_x << ", " << vec3.m_y << ", " << vec3.m_z << ")\n";
  return os;
}

int main()
{
  Vec3 niceVec3(3., 4., 5.);
  std::cout << niceVec3;

#ifdef MVP
  Vec3 myVec3();
  std::cout << myVec3;
  //std::cout << myVec3.x;
#endif

}
