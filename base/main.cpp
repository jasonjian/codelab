#include <iostream>
#include "CodeLabConfig.h"
#include <binarytree/binarytree.hpp>

using namespace std;

template<class T>
void generateTestData(T& pData)
{
    pData.generateTestData();
}

int main ( int argc, char** argv )
{
    (void)argc;
    (void)argv;

    BinaryTree lBinaryTree;
    generateTestData(lBinaryTree);
    std::cout<<lBinaryTree;
    return 0;
}
