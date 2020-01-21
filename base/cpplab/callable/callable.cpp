#include "callable.hpp"
#include "foreach.hpp"
#include <iostream>
#include <vector>

namespace callable {

void test()
{
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

    foreach (primes.begin(), primes.end(), // range
             func)
        ; // function as callable (decays to pointer)

    foreach (primes.begin(), primes.end(), // range
             &func)
        ; // function pointer as callable

    foreach (primes.begin(), primes.end(), // range
             FuncObj())
        ; // function object as callable

    foreach (primes.begin(), primes.end(), // range
             [](int i) {                   // lambda as callable
                 std::cout << "lambda called for: " << i << '\n';
             })
        ;

    MbrFuncObj obj;
    auto func = std::bind<void>(&MbrFuncObj::func, obj, std::placeholders::_1);
    foreach (primes.begin(), primes.end(), func) ;
}
} // namespace callable
