#include <iostream>
#pragma once

class UserData{
public:
    void setId(int pVal){mId = pVal;};
    int getId(){return mId;}
private:
    int mId;
};

std::ostream& operator<<(std::ostream& pStream, UserData& pData);
