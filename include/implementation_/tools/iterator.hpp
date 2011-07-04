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

#ifndef _R0X_IMPLEMENTATION_TOOLS_ITERATOR_H_
#define _R0X_IMPLEMENTATION_TOOLS_ITERATOR_H_

#include "type/traits.h"
#include "type/control_flow.h"

#define HAVE_THE_SAME_CONTAINER(X) (container_ == (X).container_)

// Generate member functions for operators {+=, -=}
#define CALCUL_ASSIGNEMENT_OPERATOR(OP, PREFIX)                         \
  template <typename T>                                                 \
  PREFIX##Iterator<T>&                                                  \
  PREFIX##Iterator<T>::operator OP(const int i)                         \
  {                                                                     \
    index_ OP i;                                                        \
    return *this;                                                       \
  }

// Generate member functions for operators {+, -}
#define CALCUL_OPERATOR(OP, PREFIX)                                     \
  template <typename T>                                                 \
  PREFIX##Iterator<T>                                                   \
  PREFIX##Iterator<T>::operator OP(const int i) const                   \
  {                                                                     \
    PREFIX##Iterator<T> copy(container_, index_ OP i);                  \
    return copy;                                                        \
  }

// Generate member functions for operators {==, >, <, >=, <=}
// WARNING : doesn't work with != operator
#define COMPARAISON_OPERATOR(OP, PREFIX)                                \
  template <typename T>                                                 \
  bool  PREFIX##Iterator<T>::operator OP                                \
  (const PREFIX##Iterator<T>& compareWith) const                        \
  {                                                                     \
    return (HAVE_THE_SAME_CONTAINER(compareWith) &&                     \
            (index_ OP compareWith.index_));                            \
  }

#define PRE_AND_POST_OPERATOR(OP, PREFIX)                            \
  template <typename T>                                              \
  PREFIX##Iterator<T>&    PREFIX##Iterator<T>::operator OP(void)     \
  {                                                                  \
    OP index_;                                                       \
    return *this;                                                    \
  }                                                                  \
                                                                     \
  template <typename T>                                              \
  PREFIX##Iterator<T>     PREFIX##Iterator<T>::operator OP(int)      \
  {                                                                  \
    PREFIX##Iterator<T> copy(container_, index_);                    \
    operator OP();                                                   \
    return copy;                                                     \
  }

namespace R0x
{
  namespace Tools
  {
#define R0X_TOOLS_ITERATOR_IMPLEMENTATION(CONSTNESS, PREFIX, CUSTOM)    \
                                                                        \
    template <typename T>                                               \
    PREFIX##Iterator<T>::PREFIX##Iterator(CONSTNESS T *container,       \
                                          int index) :                  \
      container_(container),                                            \
      index_(index) { }                                                 \
                                                                        \
    template <typename T>                                               \
    PREFIX##Iterator<T>::PREFIX##Iterator                               \
    (const PREFIX##Iterator<T>& copyFrom) :                             \
      container_(copyFrom.container_),                                  \
      index_(copyFrom.index_) { }                                       \
                                                                        \
    CUSTOM                                                              \
                                                                        \
    template <typename T>                                               \
    PREFIX##Iterator<T>::~PREFIX##Iterator() { }                        \
                                                                        \
    /* operator++() and operator++(int) */                              \
    PRE_AND_POST_OPERATOR(++, PREFIX)                                   \
                                                                        \
    /* operator--() and operator--(int) */                              \
    PRE_AND_POST_OPERATOR(--, PREFIX)                                   \
                                                                        \
    template <typename T>                                               \
    PREFIX##Iterator<T>&                                                \
    PREFIX##Iterator<T>::operator=(const PREFIX##Iterator<T>& copyFrom) \
    {                                                                   \
      container_ = copyFrom.container_;                                 \
      index_ = copyFrom.index_;                                         \
      return *this;                                                     \
    }                                                                   \
                                                                        \
    /* iterator& operator+=(int) */                                     \
    CALCUL_ASSIGNEMENT_OPERATOR(+=, PREFIX)                             \
                                                                        \
    /* iterator& operator-=(int) */                                     \
    CALCUL_ASSIGNEMENT_OPERATOR(-=, PREFIX)                             \
                                                                        \
    /* iterator operator+(int) */                                       \
    CALCUL_OPERATOR(+, PREFIX)                                          \
                                                                        \
    /* iterator operator-(int) */                                       \
    CALCUL_OPERATOR(-, PREFIX)                                          \
                                                                        \
    /* bool operator==(iterator) */                                     \
    COMPARAISON_OPERATOR(==, PREFIX)                                    \
                                                                        \
    /* bool operator>(iterator) */                                      \
    COMPARAISON_OPERATOR(>, PREFIX)                                     \
                                                                        \
    /* bool operator<(iterator) */                                      \
    COMPARAISON_OPERATOR(<, PREFIX)                                     \
                                                                        \
    /* bool operator>=(iterator) */                                     \
    COMPARAISON_OPERATOR(>=, PREFIX)                                    \
                                                                        \
    /* bool operator<=(iterator) */                                     \
    COMPARAISON_OPERATOR(<=, PREFIX)                                    \
                                                                        \
    template <typename T>                                               \
    bool  PREFIX##Iterator<T>::operator!=                               \
    (const PREFIX##Iterator<T>& compareWith) const                      \
    {                                                                   \
      return !operator==(compareWith);                                  \
    }                                                                   \
                                                                        \
    template <typename T>                                               \
    CONSTNESS  typename Type::Traits::Array<CONSTNESS T>::DataType      \
    PREFIX##Iterator<T>::operator*(void) CONSTNESS                      \
    {                                                                   \
      return container_->operator[](index_);                            \
    }

    R0X_TOOLS_ITERATOR_IMPLEMENTATION(,,)
    R0X_TOOLS_ITERATOR_IMPLEMENTATION(const, Const,
                                      template <typename T>
                                      ConstIterator<T>::ConstIterator
                                      (const Iterator<T>& copyFrom) :
                                      container_(copyFrom.container_)
                                      { index_ = copyFrom.index_;})
  }
}

#endif /* _R0X_IMPLEMENTATION_TOOLS_ITERATOR_H_ */
