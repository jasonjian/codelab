#include <iostream>

#pragma once
namespace callable {

template <typename Iter, typename Callable>
void foreach (Iter current, Iter end, Callable op)
{
    while (current != end)
    {                 // as long as not reached the end
        op(*current); //  call passed operator for current element
        ++current;    //  and move iterator to next element
    }
}

void func(int i);

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
