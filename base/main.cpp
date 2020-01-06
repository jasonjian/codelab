#include <iostream>
#include "JasonLabConfig.h"
using namespace std;

int main ( int argc, char** argv )
{
    (void)argc;
    (void)argv;
    cout<<"we have "<< argc << " parameters."<<std::endl;
    cout<<"JASONLAB_VERSION_MAJOR : "<<JASONLAB_VERSION_MAJOR<<endl;
    cout<<"JASONLAB_VERSION_MINOR : "<<JASONLAB_VERSION_MINOR<<endl;
    return 0;
}
