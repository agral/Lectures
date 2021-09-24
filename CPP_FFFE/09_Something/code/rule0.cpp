#include <string>
#include <memory>

class Person {
private:
  std::shared_ptr<std::string> name_;
  int age_;

public:
  Person(std::string const& name, int age) {
    name_ = std::make_shared<std::string>(name);
    age_ = age;
  }

  // (1) NO copy constructor
  // (Person is copy-able)

  // (2) NO move constructor

  // (3) NO copy assignment operator
  // (Person is copy-able)

  // (4) NO move assignment operator

  // (5) And finally, NO destructor
};

int main() {
  Person john("John Doe", 42);
  Person same_john(john); // OK, well defined.
  same_john = john;       // OK, also well defined.

  Person lenny{"Lenny", 43};
  Person moved = std::move(lenny);
}
