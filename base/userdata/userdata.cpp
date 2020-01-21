#include "userdata.hpp"

bool UserData::operator==(const UserData& pData) const
{
    return (pData.getId() == mId);
}

bool UserData::operator!=(const UserData& pData) const
{
    return !(pData == *this);
}

bool UserData::operator<(const UserData& pData) const
{
    if (mId < pData.getId())
    {
        return true;
    }
    return false;
}

bool UserData::operator>(const UserData& pData) const
{
    return !(*this < pData);
}

std::ostream& operator<<(std::ostream& pStream, const UserData& pData)
{
    pStream << pData.getId();
    return pStream;
}
