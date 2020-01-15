#include "smartptr.hpp"
#include <userdata/userdata.hpp>
#include <codelab.hpp>

extern template void test(SmartPtr<UserData>);

void test(SmartPtr<UserData> pVal)
{
    std::cout<<"running smartPtr test";
    return;
}

