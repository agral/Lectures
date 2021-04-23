module;
#include <stdio.h>

export module helloworld;
export void hello();

module :private;
void hello() {
  puts("Hello, World!");
}
