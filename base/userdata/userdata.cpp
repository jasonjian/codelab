#include<userdata.hpp>

std::ostream& operator<<(std::ostream& pStream, UserData& pData)
{
    pStream<<pData.getId();
    return pStream;
}
