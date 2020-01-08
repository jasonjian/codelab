#include <iostream>
#pragma once

class UserData{
public:
    void setId(int pVal){mId = pVal;};
    std::uint64_t getId()const{return mId;}
    bool operator ==(const UserData& pData)const;
    bool operator < (const UserData& pData)const;
    bool operator > (const UserData& pData)const;
    bool operator != (const UserData& pData)const;
private:
    std::uint64_t mId;
};

std::ostream& operator<<(std::ostream& pStream, const UserData& pData);
