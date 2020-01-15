#include <iostream>
#include "CodeLabConfig.h"
#include <binarytree/binarytree.hpp>
#include <cpplab/smartptr/smartptr.hpp>
#include "codelab.hpp"

using namespace std;


int main ( int argc, char** argv )
{
    (void)argc;
    (void)argv;
    SmartPtr<UserData> ptr;
    test(ptr);

    return 0;
}
