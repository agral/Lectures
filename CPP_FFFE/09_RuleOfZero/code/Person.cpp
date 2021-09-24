#include <string>

class Person {
private:
  std::string* name_;
  int age_;

public:
  Person(std::string const& name, int age) {
    name_ = new std::string{name};
    age_ = age;
  }

  ~Person() {
    delete name_;
  }
};

int main() {
  Person john("John Doe", 42);
  Person same_john(john); // What should happen here?
  same_john = john;       // and here?
}
