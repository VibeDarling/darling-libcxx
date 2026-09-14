//===------------------------ verbose_abort.cpp --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include "__config"

_LIBCPP_BEGIN_NAMESPACE_STD

_LIBCPP_EXPORTED_FROM_ABI
void __libcpp_verbose_abort(char const* format, ...) {
  va_list list;
  va_start(list, format);
  vfprintf(stderr, format, list);
  va_end(list);
  abort();
}

_LIBCPP_END_NAMESPACE_STD
