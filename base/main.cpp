#include <iostream>
#include "CodeLabConfig.h"
#include <binarytree/binarytree.hpp>

using namespace std;

template<class T>
void generateTestData(T& pData)
{
    pData.generateTestData();
}

template<class T>
void tranverse(T& pData)
{
    pData.tranverse();
}

int main ( int argc, char** argv )
{
    (void)argc;
    (void)argv;

    BinaryTree lBinaryTree;
    generateTestData(lBinaryTree);
    tranverse(lBinaryTree);

    system("/home/jasonj/work/github/codelab/base/scripts/monitor.sh");
    return 0;
}
