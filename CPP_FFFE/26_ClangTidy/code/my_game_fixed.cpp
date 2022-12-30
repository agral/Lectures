#include <iostream>
#include <memory>

class GameObject {
 public:
   virtual void draw() {
     // Reimplement this method in derived classes.
   }
};

class Starship: public GameObject {
 public:
  void draw() override {
    // Draw the engine(s) and engine exhaust
    // Draw the chassis
    // Draw the weapons
  }
};

int main() {
  Starship my_ship{};
  my_ship.draw();
}
