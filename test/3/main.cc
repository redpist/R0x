#include <iostream>
#include "type/traits.h"

int main(void)
{
  std::cout << std::boolalpha;
  std::cout << R0x::Type::Traits::IsRef<int>::value << std::endl;
  std::cout << R0x::Type::Traits::IsRef<int&>::value << std::endl;
  std::cout << R0x::Type::Traits::IsRef<double&>::value << std::endl;
  std::cout << R0x::Type::Traits::IsRef<int&&>::value << std::endl;
  std::cout << R0x::Type::Traits::IsRef<int & (*)(int)>::value << std::endl;
  std::cout << R0x::Type::Traits::IsRef<std::ostream&>::value << std::endl;
  return 0;
}
