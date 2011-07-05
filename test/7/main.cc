#include <string>
#include <iostream>
#include "container/buffer.h"

int main(void)
{
  //test 0
  std::cout << "Test 0:" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    for (char &x: s0)
      {
        std::cout << x;
      }
    std::cout << std::endl;
  }
  {
    R0x::Container::FixedBuffer<22> s0 = "I am a testing string.";

    for (char &x: s0)
      {
        std::cout << x;
      }
    std::cout << std::endl;
  }
  return 0;
}
