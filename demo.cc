#include <iostream>

void call_c_callback(void (*p)()) {
  p();
}

void c_print_foo() {
  static int c = 0;
  std::cout << "foo, call counter: " << ++c << std::endl;
}

using c_callback_t = void (*)();

struct CppClassWithData final {
  std::string const s_;
  c_callback_t const c_callback;

  explicit CppClassWithData(std::string s) : s_(std::move(s)), c_callback(StaticF) {}

  static void StaticF() {
    std::cout << "CppClassWithData::StaticF() called, stateless so far." << std::endl;
  }
};

int main() {
  call_c_callback(c_print_foo);

  c_callback_t const p_c_print_foo = c_print_foo;
  call_c_callback(p_c_print_foo);

  CppClassWithData bar("bar");
  CppClassWithData baz("bar");
  call_c_callback(bar.c_callback);
  call_c_callback(baz.c_callback);
}
