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

#ifndef _R0X_CONTAINER_FIXED_BUFFER_H_
#define _R0X_CONTAINER_FIXED_BUFFER_H_

#include <cstring>

#include "container/has_iterator.h"

namespace R0x
{
  namespace Container
  {
    template <size_t size, typename T>
    class FixedBuffer : public HasIterators<FixedBuffer<size, T> >
    {
      static_assert(size, "R0x::Container::FixedBuffer<size_t Size, ...> can not have a size = 0.");
      T         data_[size];
    public:
      FixedBuffer() { }
      FixedBuffer(const T* copyFrom)
      {
        ::memmove(reinterpret_cast<void*>(&data_),
                  reinterpret_cast<const void*>(copyFrom), size);
      }
      ~FixedBuffer() { }
      T& operator[](size_t i)
      {
        return data_[i];
      }

      const T& operator[](size_t i) const
      {
        return data_[i];
      }

      size_t    Size() const { return size;}
    };
  }
}


#endif /* _R0X_CONTAINER_FIXED_BUFFER_H_ */
