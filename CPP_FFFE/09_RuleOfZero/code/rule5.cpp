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

  // (2) Move constructor
  Person(Person&& from) {
    std::swap(name_, from.name_);
    age_ = from.age_;
  }

  // (3) Copy assignment operator
  Person& operator=(const Person& other) {
    name_ = new std::string{*other.name_};
    age_ = other.age_;
    return *this;
  }

  // (4) Move assignment operator
  Person& operator=(Person&& from) {
    std::swap(name_, from.name_);
    age_ = from.age_;
    return *this;
  }

  // (5) Destructor
  ~Person() {
    if (name_ != nullptr) {
      delete name_;
      name_ = nullptr;
    }
  }
};

int main() {
  Person john("John Doe", 42);
  Person same_john(john); // OK, well defined.
  same_john = john;       // OK, also well defined.

  Person lenny{"Lenny", 43};
  Person moved = std::move(lenny);
}
