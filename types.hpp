#pragma once
#include "intrinsics.hpp"

namespace types
{

using usize  = intrin::PtrSizeT;
using isize  = intrin::PtrDiffT;

using char8 = signed char;
using uchar8 = unsigned char;
using char16 = char16_t;
using char32 = char32_t;

using int8   = intrin::Int8T;
using int16  = intrin::Int16T;
using int32  = intrin::Int32T;
using int64  = intrin::Int64T;

using uint8  = intrin::Uint8T;
using uint16 = intrin::Uint16T;
using uint32 = intrin::Uint32T;
using uint64 = intrin::Uint64T;

using real32 = float;  // not fully guaranteed
using real64 = double;  // not fully guaranteed

using nullptr_t = decltype(nullptr);


static_assert(sizeof(uchar8) == 1, "char8 must be 1 byte");
static_assert(sizeof(int8) == 1, "int8 must be 1 byte");
static_assert(sizeof(uint8) == 1, "uint8 must be 1 byte");

static_assert(sizeof(char16) == 2, "char16 must be 2 bytes");
static_assert(sizeof(int16) == 2, "int16 must be 2 bytes");
static_assert(sizeof(uint16) == 2, "uint16 must be 2 bytes");

static_assert(sizeof(char32) == 4, "char32 must be 4 bytes");
static_assert(sizeof(int32) == 4, "int32 must be 4 bytes");
static_assert(sizeof(uint32) == 4, "uint32 must be 4 bytes");
static_assert(sizeof(real32) == 4, "real32 must be 4 bytes");

static_assert(sizeof(int64) == 8, "int64 must be 8 bytes");
static_assert(sizeof(uint64) == 8, "uint64 must be 8 bytes");
static_assert(sizeof(real64) == 8, "real64 must be 8 bytes");

}
