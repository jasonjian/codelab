#include <iostream>
#include "CodeLabConfig.h"
#include <binarytree/binarytree.hpp>
#include <cpplab/smartptr/smartptr.hpp>
#include <cpplab/shape/shape.hpp>
#include <cpplab/type/typelab.hpp>
#include <cpplab/callable/callable.hpp>
#include <scripts/textplayer/textplayer.hpp>
#include <gtest/gtest.h>
#include "codelab.hpp"

using namespace std;


int main ( int argc, char** argv )
{
    //    ::testing::InitGoogleTest(&argc, argv);
    using namespace TextPlayer;
    (void)argc;
    (void)argv;
    test();
    return 0;
    // return RUN_ALL_TESTS();
}
