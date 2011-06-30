#include <string>
#include <iostream>
#include "container.h"


int main(void)
{
  //test 0
  std::cout << "Test O :" << std::endl;
  {
    R0x::Container::FixedBuffer<22> s0 = "I am a testing string.";
    R0x::Container::FixedBuffer<22>::Iterator       i = s0.Begin();
    R0x::Container::FixedBuffer<22>::Iterator       end = s0.End();

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  //test 1
  std::cout << "Test 1 :" << std::endl;
  {
    const R0x::Container::FixedBuffer<22> s0 = "I am a testing string.";
    R0x::Container::FixedBuffer<22>::ConstIterator       i = s0.Begin();
    R0x::Container::FixedBuffer<22>::ConstIterator       end(s0.End());

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  {
    const std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }

  //test 2
  std::cout << "Test 2 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  {
    R0x::Container::FixedBuffer<22> s0 = "I am a testing string.";
    R0x::Container::FixedBuffer<22>::ConstIterator       i = s0.Begin();
    R0x::Container::FixedBuffer<22>::ConstIterator       end = s0.End();

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  return 0;
}
