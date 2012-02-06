#include <iostream>
#include "system/directory.h"

int main()
{
  R0x::System::Directory     test("./test/8");

  R0x::System::Directory::FileArray    files = test.List();
  for (auto file : files)
    {
      std::cout << file.Path() << std::endl;
    }
  return 0;
}
