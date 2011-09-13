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

#ifndef _R0X_IMPLEMENTATION_TYPE_CONTROLFLOW_H_
#define _R0X_IMPLEMENTATION_TYPE_CONTROLFLOW_H_

#include "type/list.h"
#include "type/null.h"
#include <utility>

namespace R0x
{
  namespace Type
  {
    namespace ControlFlow
    {
			////////////////////////////
			//        Meta-If
			////////////////////////////

      template <bool condition, typename IfTrue, typename IfFalse>
      struct If
      {
        typedef IfTrue Return;
      };

      template <typename IfTrue, typename IfFalse>
      struct If<false, IfTrue, IfFalse>
      {
        typedef IfFalse Return;
      };

			////////////////////////////
			//      Meta-Foreach
			////////////////////////////

			template <typename T>
			struct MemberFunctionOperation
			{
				template <class MemberFunctionPointerType, typename... Args>
				inline static void Do(T&& object, MemberFunctionPointerType&& memberFunctionPointer, Args&& ... args)
				{
					(object.*memberFunctionPointer)(std::forward<Args>(args)...);
				}

				template <class MemberFunctionPointerType, typename... Args>
				inline static void Do(T& object, MemberFunctionPointerType&& memberFunctionPointer, Args&& ... args)
				{
					(object.*memberFunctionPointer)(std::forward<Args>(args)...);
				}
			};

      template <typename T, template <typename T> class Operation>
			struct Foreach<R0x::Type::List<T>, Operation>
			{
				template <typename... Args>
				inline static void Do(Args&& ... args)
				{
					Operation<T>::Do(std::forward<Args>(args)...);
				}
			};

      template <class TypeList, template <typename T> class Operation>
			struct Foreach
			{
				template <typename... Args>
				inline static void Do(Args&& ... args)
				{
					Operation<typename TypeList::Head>::Do(std::forward<Args>(args)...);
					Foreach<typename TypeList::Tail, Operation>::Do(std::forward<Args>(args)...);
				}
			};
		}
  }
}


#endif /* _R0X_IMPLEMENTATION_TYPE_CONTROLFLOW_H_ */
