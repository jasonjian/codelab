#include <cstdint> // for std::uint32_t
#include <memory>  // for std::unique_ptr and etc

namespace smartptr {

class Investment
{
public:
    virtual ~Investment(){};
};

class Stock : public Investment
{
public:
    Stock(std::uint32_t para, void func(Investment* invest)) { (void)para; }
    ~Stock() {}
};

class Bond : public Investment
{
public:
    Bond(std::uint32_t para, void func(Investment* invest)) { (void)para; }
    ~Bond() {}
};

class RealEstate : public Investment
{
public:
    RealEstate(std::uint32_t para, void func(Investment* invest)) { (void)para; }
    ~RealEstate() {}
};

auto delInvmt = [](Investment* invest) {
    // makeLogEntry(pInvestment);
    delete invest;
};

template <typename... Ts>
auto makeInvestment(Ts&&... params)
//std::unique_ptr<Investment> makeInvestment(Ts&&... params)
{
    std::uint32_t test = 1;
    std::unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

    if (test == 1)
    {
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    }
    else if (test == 2)
    {
        pInv.reset(new Bond(std::forward<Ts>(params)...));
    }
    else if (test == 3)
    {
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    }
    return pInv;
}

} // namespace smartptr
