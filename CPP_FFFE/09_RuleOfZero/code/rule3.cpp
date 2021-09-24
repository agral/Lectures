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

  // (1) Copy constructor
  Person(const Person& other) {
    name_ = new std::string{*other.name_};
    age_ = other.age_;
  }

  // (2) Copy assignment operator
  Person& operator=(const Person& other) {
    name_ = new std::string{*other.name_};
    age_ = other.age_;
    return *this;
  }

  // (3) Destructor
  ~Person() {
    delete name_;
  }
};

int main() {
  Person john("John Doe", 42);
  Person same_john(john); // OK, well defined.
  same_john = john;       // OK, also well defined.
}
