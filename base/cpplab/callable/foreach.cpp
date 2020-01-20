#include "foreach.hpp"
#include <iostream>
#include <vector>

namespace callable {
// a function to call:
void func(int i)
{
    std::cout << "func() called for: " << i << '\n';
}

// a function object type (for objects that can be used as functions):
class FuncObj
{
public:
    void operator()(int i) const
    { // Note: const member function
        std::cout << "FuncObj::op() called for: " << i << '\n';
    }
};

} // namespace callable
