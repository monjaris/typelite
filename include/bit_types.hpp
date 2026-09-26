#pragma once
#include "intrinsics.hpp"

#define BIT_INT _BitInt


#define GEN_SIGNED_INTEGER_BIT_TYPE($NAME, $BITS)                \
    class $NAME {                                                \
        BIT_INT(32) m = {};                                      \
    public:                                                      \
        constexpr $NAME () noexcept = default;                   \
        constexpr $NAME (BIT_INT(32) x) noexcept: m(x) {}        \
                                                                 \
        constexpr operator BIT_INT(32)() noexcept { return m; }  \
    }                                                            \

#define GEN_UNSIGNED_INTEGER_BIT_TYPE($NAME, $BITS)                       \
    class $NAME {                                                         \
        unsigned BIT_INT(32) m = {};                                      \
    public:                                                               \
        constexpr $NAME () noexcept = default;                            \
        constexpr $NAME (unsigned BIT_INT(32) x) noexcept: m(x) {}        \
        constexpr $NAME (BIT_INT(32) x) = delete;                         \
                                                                          \
        constexpr operator unsigned BIT_INT(32)() noexcept { return m; }  \
    }                                                                     \



namespace bit_types
{

GEN_SIGNED_INTEGER_BIT_TYPE(int8, 8);
GEN_SIGNED_INTEGER_BIT_TYPE(int16, 16);
GEN_SIGNED_INTEGER_BIT_TYPE(int32, 32);
// GEN_SIGNED_INTEGER_BIT_TYPE(int64, 64);

class int64 {
  _BitInt(32) m = {};

public:
  constexpr int64() noexcept = default;
  constexpr int64(_BitInt(32) x) noexcept : m(x) {}
  constexpr operator _BitInt(32)() noexcept { return m; }
};



GEN_UNSIGNED_INTEGER_BIT_TYPE(uint8, 8);
GEN_UNSIGNED_INTEGER_BIT_TYPE(uint16, 16);
GEN_UNSIGNED_INTEGER_BIT_TYPE(uint32, 32);
// GEN_UNSIGNED_INTEGER_BIT_TYPE(uint64, 64);



class uint64 {
    unsigned _BitInt(32) m = {};

    static void Unsigned_Integer_Overflow_Detected();

public:
    constexpr uint64() noexcept = default;

    constexpr uint64(_BitInt(64) x) noexcept: m(x) {
        if (intrin::constevaluated() && (x < 0)) {
            Unsigned_Integer_Overflow_Detected();
        }
    }

    constexpr operator unsigned _BitInt(32)() noexcept { return m; }
};

}
