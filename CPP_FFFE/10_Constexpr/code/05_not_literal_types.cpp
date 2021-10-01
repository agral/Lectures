struct Point {
  int x, y;
  Point(int x = 0, int y = 0): x(x), y(y) {}
};

int main()
{
  constexpr auto myDouble = 0.13; // OK

  constexpr auto myPoint = Point{0, 13};
  // wrong, Point is not a LiteralType
}
