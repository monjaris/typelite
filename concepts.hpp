#pragma once
#include "types.hpp"

namespace concepts
{

// only function in the header. casts a value(should be an lvalue) to T
template<class T> consteval auto& cast(const auto& value) { return static_cast<T>(value); }


// check if T and U are same type
template<class T, class U> inline constexpr bool is_same = false;
template<class T> inline constexpr bool is_same<T, T> = true;
template<class T, class U> concept SameConcept = is_same<T, U>;


// check if T and U are same type (variadic)
template<class T, class... U> inline constexpr bool is_any_same = (is_same<T, U> || ...);
template<class T, class... U>
concept AnySameConcept = is_any_same<T, U...>;


// get underlying type via compiler instrinct
template<class T> using EnumValueT = __underlying_type(T);
// get integral value of an enum class member
template<class EnumT, EnumValueT<EnumT> x>
EnumT enum_v = cast<EnumT>(x);


template<class T> struct IsRef { constexpr static bool value = false; };
template<class T> struct IsRef<T&> { constexpr static bool value = true; };
template<class T> struct IsRef<T&&> { constexpr static bool value = false; };
//
template<class T> struct IsRvRef { constexpr static bool value = false; };
template<class T> struct IsRvRef<T&> { constexpr static bool value = false; };
template<class T> struct IsRvRef<T&&> { constexpr static bool value = true; };
//
template<class T> struct IsConst { constexpr static bool value = false; };
template<class T> struct IsConst<T&> { constexpr static bool value = false; };
template<class T> struct IsConst<T&&> { constexpr static bool value = true; };


template<class T> struct RemoveReferenceImpl { using Type = T; };
template<class T> struct RemoveReferenceImpl<T&> { using Type = T; };
template<class T> struct RemoveReferenceImpl<T&&> { using Type = T; };
//
template<class T> struct RemoveRvalueReferenceImpl { using Type = T; };
template<class T> struct RemoveRvalueReferenceImpl<T&&> { using Type = T; };
//
template<class T> struct RemoveConstImpl { using Type = T; };
template<class T> struct RemoveConstImpl<const T> { using Type = T; };


// Remove reference from T
template<class T> using UnRef = RemoveReferenceImpl<T>::Type;
// Remove rvalue reference from T
template<class T> using UnRvRef = RemoveRvalueReferenceImpl<T>::Type;
// Remove const from T
template<class T> using UnConst = RemoveConstImpl<T>::Type;
// Remove const and reference from T
template<class T> using UnRefConst = RemoveConstImpl<RemoveReferenceImpl<T>>::Type;


template<class T> struct UnDeduceImpl { using Type = T; };
template<class T> using UnDeduce = UnDeduceImpl<T>::Type;


template<class CharT>
concept CharConcept = (
    is_any_same<CharT,
        types::char8, types::uchar8, types::char16, types::char32
    >
);

template<class IntT>
concept IntConcept = (
    is_any_same<IntT,
        types::int8, types::int16, types::int32, types::int64
    >
);

template<class UintT>
concept UintConcept = (
    is_any_same<UintT, types::uint8, types::uint16, types::uint32, types::uint64>
);

template<class FloatT>
concept FloatConcept = (
    is_any_same<FloatT, types::real32, types::real64>
);


}
