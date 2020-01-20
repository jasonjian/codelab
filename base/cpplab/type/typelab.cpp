#include "typelab.hpp"
#include <codelab.hpp>
#include <iostream>
#include <userdata/userdata.hpp>

namespace typelab{

using namespace std;

void test()
{
    int&& val1 {0};
    const int val2 {0};
    // int&& val3 = val1 ;
    auto&& val4 {val1};
    volatile int val5 {9};

    std::cout<<"[const int val1 = 1] : type of val1= "<< getType<decltype(val1)>()<<std::endl;
    std::cout<<"[int&& val2 = 15] : type of val2 = "<< getType<decltype(val2)>()<<std::endl;

    //error: cannot bind 'const int' lvalue to 'int&&'
    //std::cout<<"[int&& val1 = 15; int&& val3 = val1] : type of val3 = "<< getType<decltype(val3)>()<<std::endl;

    std::cout<<"[int&& val1 = 15; auto&& val4 {val1}] : type of val4 = "<< getType<decltype(val4)>()<<": reference collapsing"<<std::endl;

    std::cout<<"[volatile val5 {9};] : type of val5 = "<< getType<decltype(val5)>()<<std::endl;


    std::cout<<"[const int val1 = 1; add_rvalue_referenct_t] : type of val1= "<< getType<decltype(val1)>()<<std::endl;

#if 0
    char&& cint  = 1;
    char&& rhv2  = std::move(cint);
    auto val  = 4;
    auto lVal = val;
    // if val is lvalue, rhlVal will be deduced to lvalut reference
    // effective mordern c++ item1 case2
    auto&& rhlVal = val;

    // if val is rvalue, rhlVal2 will be deduced to rvalue
    // effective mordern c++ item1 case2
    auto&& rhlVal2       = 4;
    auto& lhlVal         = val;
    const auto& constVal = val;


     std::cout<<"address of rhv = "<< std::hex<<&rhv <<std::endl;
     std::cout<<"type of rhv  = "<< getType<decltype(cv)>() <<std::endl;
    // std::cout<<"type of rhv  = "<< getType<decltype(rhv2)>() <<std::endl;
    // std::is_rvalue_reference<int&&>::value;
    // std::cout<<"typeid(cv).name() = "<< typeid(cv).name() <<std::endl;
    // std::cout<<"typeid(cv).name() = "<< typeid(rhv2).name() <<std::endl;
    std::cout << "rhv2 type = " << getType<decltype(rhv2)>() << std::endl;

    // std::cout<<"is_rvalue_reference = "<<std::boolalpha<<
    // std::is_rvalue_reference<int&>::value <<std::endl; std::cout<<"is_rvalue_reference =
    // "<<std::boolalpha<< std::is_rvalue_reference<A&&>::value <<std::endl;
    // std::cout<<"is_lvalue_reference = "<<std::boolalpha<<
    // std::is_lvalue_reference<int&&>::value <<std::endl; std::cout<<"is_lvalue_reference
    // = "<<std::boolalpha<< std::is_lvalue_reference<A&>::value <<std::endl;


    cout << "type of (val) = " << getType<decltype(val)>() << endl;
    cout << "type of (lVal) = " << getType<decltype(lVal)>() << endl;
    cout << "type of (rhlVal) = " << getType<decltype(rhlVal)>() << endl;
    cout << "type of (rhlVal2) = " << getType<decltype(rhlVal2)>() << endl;
    cout << "type of (lhlVal) = " << getType<decltype(lhlVal)>() << endl;
    cout << "type of (constVal) = " << getType<decltype(constVal)>() << endl;
    #endif

}

} // namespace smartptr
