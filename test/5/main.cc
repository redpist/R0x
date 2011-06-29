#include <iostream>
#include <typeinfo>

#include "type/control_flow.h"

int main(void)
{
  std::cout << typeid(R0x::Type::ControlFlow::If<true, int, char>::Return).name() << std::endl;
  std::cout << typeid(R0x::Type::ControlFlow::If<false, int, char>::Return).name() << std::endl;
  return 0;
}
