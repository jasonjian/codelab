#include "smartptr.hpp"
#include "uniptrsample.hpp"
#include <codelab.hpp>
#include <iostream>
#include <userdata/userdata.hpp>

namespace smartptr {

void test()
{
    auto deleter      = [](Investment* invest) { (void)invest; };
    auto investUniPtr = makeInvestment(32, deleter);
    std::cout << "test smartptr";
}

} // namespace smartptr
