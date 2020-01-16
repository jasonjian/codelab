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

template<template<class> class Container, class V>
void test(Container<V> pData)
{
    (void)pData;
}

template<class T>
void test(T pData)
{
    (void)pData;
}
