#include <iostream>

void call_c_callback(void (*p)()) {
  p();
}

void c_print_foo() {
  static int c = 0;
  std::cout << "foo, call counter: " << ++c << std::endl;
}

using c_callback_t = void (*)();

int main() {
  call_c_callback(c_print_foo);

  c_callback_t const p_c_print_foo = c_print_foo;
  call_c_callback(p_c_print_foo);
}
