//////////////////
// Copyright (c) 2011, Jeremy Lecerf
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of R0x nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL JEREMY LECERF BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//////////////////

#ifndef _R0X_TOOLS_ITERATOR_H_
#define _R0X_TOOLS_ITERATOR_H_

#include "internal_/header.h"
#include "type/traits.h"

namespace R0x
{
  namespace Tools
  {

#define R0X_TOOLS_ITERATOR_DEFINITION(CONSTNESS, PREFIX)                \
    template <typename T>                                               \
    class PREFIX##Iterator                                              \
    {                                                                   \
      T             *container_;                                        \
      const int     *range_;                                            \
      int           index_;                                             \
    public:                                                             \
      PREFIX##Iterator(T *container, const int *range, int index = 0);  \
                                                                        \
      PREFIX##Iterator(const PREFIX##Iterator<T>& copyFrom);            \
                                                                        \
      ~PREFIX##Iterator();                                              \
                                                                        \
      PREFIX##Iterator<T>&                                              \
        operator=(const PREFIX##Iterator<T>& copyFrom);                 \
      PREFIX##Iterator<T>&    operator+=(const int i);                  \
      PREFIX##Iterator<T>&    operator-=(const int i);                  \
                                                                        \
      PREFIX##Iterator<T>&     operator++();                            \
      PREFIX##Iterator<T>     operator++(int);                          \
                                                                        \
      PREFIX##Iterator<T>&     operator--();                            \
      PREFIX##Iterator<T>     operator--(int);                          \
                                                                        \
      PREFIX##Iterator<T>     operator+(const int i) const;             \
      PREFIX##Iterator<T>     operator-(const int i) const;             \
                                                                        \
                                                                        \
      bool  operator==(const PREFIX##Iterator<T>& compareWith) const;   \
      bool  operator<(const PREFIX##Iterator<T>& compareWith) const;    \
      bool  operator>(const PREFIX##Iterator<T>& compareWith) const;    \
      bool  operator<=(const PREFIX##Iterator<T>& compareWith) const;   \
      bool  operator>=(const PREFIX##Iterator<T>& compareWith) const;   \
      bool  operator!=(const PREFIX##Iterator<T>& compareWith) const;   \
                                                                        \
      CONSTNESS typename Type::Traits::Array<T>::DataType&              \
        operator*(void) CONSTNESS;                                      \
    }

    R0X_TOOLS_ITERATOR_DEFINITION(,);
    R0X_TOOLS_ITERATOR_DEFINITION(const,Const);
  }
}

#include "implementation_/tools/iterator.hpp"

#endif /* _R0X_TOOLS_ITERATOR_H_ */
