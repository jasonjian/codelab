#include <iostream>
#pragma once

class UserData{
public:
    void setId(int pVal){mId = pVal;};
    int getId()const{return mId;}
    bool operator ==(const UserData& pData)const;
    bool operator < (const UserData& pData)const;
    bool operator > (const UserData& pData)const;
    bool operator != (const UserData& pData)const;
private:
    int mId;
};

std::ostream& operator<<(std::ostream& pStream, UserData& pData);
