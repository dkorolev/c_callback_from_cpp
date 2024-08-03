#include <iostream>

void call_c_callback(void (*p)()) {
  p();
}

void c_print_foo() {
  std::cout << "foo" << std::endl;
}

int main() {
  call_c_callback(c_print_foo);
}
