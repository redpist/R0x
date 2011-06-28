#include <string>
#include <iostream>

#include "tools/iterator.h"

int main(void)
{
  //test 0
  std::cout << "Test O :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 1
  std::cout << "Test 1 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 2
  std::cout << "Test 2 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    --end;
    while (i <= end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    --end;
    while (i <= end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 3
  std::cout << "Test 3 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    --end;
    while (end >= i)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    --end;
    while (end >= i)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 4
  std::cout << "Test 4 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 5
  std::cout << "Test 5 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       i(&s0, &size, size);

    while (i > begin)
      {
        std::cout << *(--i);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       begin = s0.begin();
    std::string::iterator       i = s0.end();

    while (i > begin)
      {
        std::cout << *(--i);
      }
    std::cout << std::endl;
  }

  //test 6
  std::cout << "Test 6 :" << std::endl;

  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       i(&s0, &size, size);

    --i;
    while (i >= begin)
      {
        std::cout << *(i--);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       begin = s0.begin();
    std::string::iterator       i = s0.end();

    --i;
    while (i >= begin)
      {
        std::cout << *(i--);
      }
    std::cout << std::endl;
  }

  //test 7
  std::cout << "Test 7 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       i(&s0, &size, size);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       begin = s0.begin();
    std::string::iterator       i = s0.end();
    std::string::iterator       end = s0.end();

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 8
  std::cout << "Test 8 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    std::string s1 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       i(&s0, &size, size);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string s1 = "I am a testing string.";
    std::string::iterator       begin = s0.begin();
    std::string::iterator       i = s1.end();
    std::string::iterator       end = s0.end();

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 9
  std::cout << "Test 9 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    i = i + 3;
    i += 1;
    i = i - 2;
    i + 3;
    i -= 0;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    i = i + 3;
    i += 1;
    i = i - 2;
    i + 3;
    i -= 0;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 10
  std::cout << "Test 10 :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    *(i++) = 'U';
    *(i++) = '\'';
    *(i++) = 'r';
    *(i++) = 'e';
    i = R0x::Tools::Iterator<std::string>(&s0, &size, 0);
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::iterator       i = s0.begin();
    std::string::iterator       end = s0.end();

    *(i++) = 'U';
    *(i++) = '\'';
    *(i++) = 'r';
    *(i++) = 'e';
    i = s0.begin();
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  std::cout << "\nWith const iterators\n" << std::endl;

  //test 0 const
  std::cout << "Test O const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::Iterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::Iterator<std::string>       end(&s0, &size, size);

    while (i != end) std::cout << *(i++);
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 1 const
  std::cout << "Test 1 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }


  //test 2 const
  std::cout << "Test 2 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    --end;
    while (i <= end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    --end;
    while (i <= end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 3 const
  std::cout << "Test 3 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    --end;
    while (end >= i)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    --end;
    while (end >= i)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 4 const
  std::cout << "Test 4 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    while (i < end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 5 const
  std::cout << "Test 5 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, size);

    while (i > begin)
      {
        std::cout << *(--i);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       begin = s0.begin();
    std::string::const_iterator       i = s0.end();

    while (i > begin)
      {
        std::cout << *(--i);
      }
    std::cout << std::endl;
  }

  //test 6 const
  std::cout << "Test 6 const :" << std::endl;

  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, size);

    --i;
    while (i >= begin)
      {
        std::cout << *(i--);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       begin = s0.begin();
    std::string::const_iterator       i = s0.end();

    --i;
    while (i >= begin)
      {
        std::cout << *(i--);
      }
    std::cout << std::endl;
  }

  //test 7 const
  std::cout << "Test 7 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, size);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       begin = s0.begin();
    std::string::const_iterator       i = s0.end();
    std::string::const_iterator       end = s0.end();

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 8 const
  std::cout << "Test 8 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    std::string s1 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       begin(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, size);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string s1 = "I am a testing string.";
    std::string::const_iterator       begin = s0.begin();
    std::string::const_iterator       i = s1.end();
    std::string::const_iterator       end = s0.end();

    i = begin;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }

  //test 9 const
  std::cout << "Test 9 const :" << std::endl;
  {
    std::string s0 = "I am a testing string.";
    int size = s0.size();
    R0x::Tools::ConstIterator<std::string>       i(&s0, &size, 0);
    R0x::Tools::ConstIterator<std::string>       end(&s0, &size, size);

    i = i + 3;
    i += 1;
    i = i - 2;
    i + 3;
    i -= 0;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  {
    std::string s0 = "I am a testing string.";
    std::string::const_iterator       i = s0.begin();
    std::string::const_iterator       end = s0.end();

    i = i + 3;
    i += 1;
    i = i - 2;
    i + 3;
    i -= 0;
    while (i != end)
      {
        std::cout << *(i++);
      }
    std::cout << std::endl;
  }
  return 0;
}
