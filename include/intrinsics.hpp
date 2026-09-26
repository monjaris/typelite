#pragma once


#define _HAS_BUILTIN($BUILTIN) \
    (defined(__has_builtin) && __has_builtin(__builtin_is_constant_evaluated))


namespace intrinsics
{

using PtrSizeT = __SIZE_TYPE__;
using PtrDiffT = __PTRDIFF_TYPE__;

using Int8T  = __INT8_TYPE__;
using Int16T = __INT16_TYPE__;
using Int32T = __INT32_TYPE__;
using Int64T = __INT64_TYPE__;

using Uint8T  = __UINT8_TYPE__;
using Uint16T = __UINT16_TYPE__;
using Uint32T = __UINT32_TYPE__;
using Uint64T = __UINT64_TYPE__;


template<class T> using UnderlyingT = __underlying_type(T);


constexpr bool constevaluated() {
    return
        #if _HAS_BUILTIN(__builtin_is_constant_evaluated)
            __builtin_is_constant_evaluated()
        #else
            false
        #endif
    ;
}


}


namespace intrin = intrinsics;
