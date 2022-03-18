#include <span>

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::string;
using std::vector;

void int_print(std::span<int> container) {
  cout << "[";
  for (const auto& item: container) {
    cout << item << ", ";
  }
  cout << "]\n";
}

void string_print(std::span<char> str) {
  for (const auto& character: str) {
    cout << character;
  }
  cout << "\n";
}

int main()
{
  int cstyle_arr[] = {11, 12, 13, 14, 15};
  vector<int> v = {21, 22, 23, 24, 25, 26};
  array arr = {31, 32, 33, 34};

  // note: int_print automatically deduces the size of the printed container.
  int_print(cstyle_arr);
  int_print(v);
  int_print(arr);


  /// Instantiating from a pointer and a size:
  int* p12 = cstyle_arr+1;
  cout << *p12 << '\n';
  std::span cstyle_arr_fragment{p12, 3};
  int_print(cstyle_arr_fragment);

  std::span v_fragment{v.begin()+1, 3};
  int_print(v_fragment);


  /// Modifying the spans:
  cout << "Modifications' demo\n";
  v_fragment[0] = 101;
  int_print(v);

  // requires <algorithm>
  std::transform(v_fragment.begin(), v_fragment.end(), v_fragment.begin(),
      [](int n) -> int { return n * n; }
  );
  int_print(v);


  /// Works for any container, including strings:
  string cpp_friends = {"C++ Friends"};
  cout << cpp_friends << '\n';
  std::span friends = {cpp_friends.begin()+4, cpp_friends.size()-4};
  string_print(friends);


  /// but unlike std::string_view, std::span allows modification of the container:
  // requires <cctype>
  std::transform(friends.begin(), friends.end(), friends.begin(),
      [](char c) -> char { return std::toupper(c); }
  );
  cout << cpp_friends << "\n";
}
