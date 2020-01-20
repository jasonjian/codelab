#include "foreach.hpp"
#include <iostream>
#include <vector>

namespace callable {
// a function to call:
void func(int i)
{
    std::cout << "func() called for: " << i << '\n';
}

} // namespace callable
