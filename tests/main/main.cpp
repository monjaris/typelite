#include <print>

#include "types.hpp"
#include "concepts.hpp"
#include "bit_types.hpp"

using namespace types;
using namespace concepts;


int main()
{
    constexpr bool same = concepts::is_same<int32, intrin::Int32T>;

    std::println("{}", same);
}
