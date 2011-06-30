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

#ifndef _R0X_CONTAINER_HAS_ITERATOR_H_
# define _R0X_CONTAINER_HAS_ITERATOR_H_

# include "tools/iterator.h"

namespace R0x
{
  namespace Container
  {
# define R0X_BEGIN_AND_END_MEMBER_FN(CONSTNESS, PREFIX)                 \
                                                                        \
      PREFIX##Iterator  Begin() CONSTNESS                               \
      {                                                                 \
        return PREFIX##Iterator(static_cast<CONSTNESS T*>(this), 0);    \
      }                                                                 \
                                                                        \
      PREFIX##Iterator  End() CONSTNESS                                 \
      {                                                                 \
        return PREFIX##Iterator                                         \
          (static_cast<CONSTNESS T*>(this),                             \
           static_cast<CONSTNESS T*>(this)->Size());                    \
      }

    template <typename T>
    class HasIterator
    {
    protected:
      HasIterator() { }
      ~HasIterator() { }
    public:
      typedef R0x::Tools::Iterator<T>           Iterator;

      R0X_BEGIN_AND_END_MEMBER_FN(,)
    };

    template <typename T>
    class HasConstIterator
    {
    protected:
      HasConstIterator() { }
      ~HasConstIterator() { }
    public:
      typedef R0x::Tools::ConstIterator<T>      ConstIterator;

      R0X_BEGIN_AND_END_MEMBER_FN(const,Const)
    };

    namespace internal_
    {
      template <typename I, typename T>
      struct HasIteratorDispatch;

      template <typename T>
      struct HasIteratorDispatch<R0x::Tools::ConstIterator<T>, T>
      {
        typedef R0x::Container::HasConstIterator<T>  Type;
      };

      template <typename T>
      struct HasIteratorDispatch<R0x::Tools::Iterator<T>, T>
      {
        typedef R0x::Container::HasIterator<T>  Type;
      };

    }

    template <typename T>
    class HasIterators : public HasConstIterator<T>, public HasIterator<T>
    {
    protected:
      HasIterators() { }
      ~HasIterators() { }

    public:
      using HasIterator<T>::Begin;
      using HasConstIterator<T>::Begin;

      using HasIterator<T>::End;
      using HasConstIterator<T>::End;
    };

# undef R0X_BEGIN_AND_END_MEMBER_FN

  }
}

#endif /* _R0X_CONTAINER_HAS_ITERATOR_H_ */
