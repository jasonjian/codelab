#include<userdata.hpp>


bool UserData::operator ==(const UserData& pData)const
{
    return (pData.getId() == mId);
}

bool UserData::operator !=(const UserData& pData)const
{
    return !(pData == *this);
}

bool UserData::operator <(const UserData& pData)const
{
    return (pData.getId() < mId);
}


bool UserData::operator > (const UserData& pData)const
{
    std::cout<<"pData = "<< pData;
    std::cout<<"*this = "<< *this;
    return !(pData < *this);
}

std::ostream& operator<<(std::ostream& pStream, const UserData& pData)
{
    pStream<<pData.getId();
    return pStream;
}

