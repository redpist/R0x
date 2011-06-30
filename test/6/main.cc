#include <iostream>
#include <typeinfo>

#include "type/traits.h"

int main(int, char**)
{
  std::cout << "test &main : " << R0x::Type::Traits::Function<decltype(&main)>::NbOfArgs << std::endl;
  return 0;
}
