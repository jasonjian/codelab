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
    return !(pData < *this);
}


std::ostream& operator<<(std::ostream& pStream, UserData& pData)
{
    pStream<<pData.getId();
    return pStream;
}
