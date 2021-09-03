#include <iostream>

template <typename T, typename Argument>
T create(Argument& arg)
{
  return T(arg);
}


int main()
{
  { // Lvalues:
    int fortytwo = 42;
    int created42 = create<int>(fortytwo);
    std::cout << "From lvalue: " << created42 << '\n';
  }

  { // Rvalues:
    /*
    int created42 = create<int>(42);
    std::cout << "From rvalue: " << created42 << '\n';
    */
  }
}
