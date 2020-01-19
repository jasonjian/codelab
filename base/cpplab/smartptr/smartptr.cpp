#include "smartptr.hpp"
#include "uniptrsample.hpp"
#include <codelab.hpp>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <userdata/userdata.hpp>

namespace smartptr {
using namespace std;
void test()
{
    auto deleter      = [](Investment* invest) { (void)invest; };
    auto investUniPtr = makeInvestment(32, deleter);
    std::cout << "the returntype of makeInvestment is " << typeid(investUniPtr).name()
              << '\n';
    //std::cout << "the returntype of makeInvestment is "
    //         << type_name<decltype(investUniPtr)>() << '\n';
}

} // namespace smartptr
