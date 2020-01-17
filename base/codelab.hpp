#include <iostream>

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

#if 0
template<template<class> class Container, class V>
void test(Container<V> pData)
{
    pData.test();
    (void)pData;
}

template<class T>
void test(T pData)
{
    (void)pData;
}
#endif
