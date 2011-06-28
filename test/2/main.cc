#include "type/list.h"

int main(void)
{
  R0x::Type::List<int, void (*)(int),   R0x::Type::List<int, double, int> > a;

  (void)a;
  return 0;
}
