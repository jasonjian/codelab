#include <iostream>
#include "CodeLabConfig.h"
#include <binarytree/binarytree.hpp>
#include <cpplab/smartptr/smartptr.hpp>
#include <cpplab/shape/shape.hpp>
#include <gtest/gtest.h>
#include "codelab.hpp"

using namespace std;


int main ( int argc, char** argv )
{
    ::testing::InitGoogleTest(&argc, argv);
    using namespace smartptr;
    (void)argc;
    (void)argv;
    test();
    return RUN_ALL_TESTS();
}
