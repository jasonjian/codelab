#include <iostream>
#include "JasonLabConfig.h"
using namespace std;

int main ( int argc, char** argv )
{
    (void)argc;
    (void)argv;
    cout<<"we have "<< argc << " parameters."<<std::endl;
    cout<<"CODELAB_VERSION_MAJOR : "<<CODELAB_VERSION_MAJOR<<endl;
    cout<<"CODELAB_VERSION_MINOR : "<<CODELAB_VERSION_MINOR<<endl;
    return 0;
}
