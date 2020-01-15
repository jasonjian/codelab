#include <utility> // std::swap
#include "sharedcount.hpp"

template<class T>
class SmartPtr{
    template<typename U >
    friend class SmartPtr;

public:
    explicit SmartPtr(T* pPtr = nullptr)
        : mPtr(pPtr)
    {
        if(pPtr){
            mSharedCount = new SharedCount();
        }
    }

    ~SmartPtr() {
      if (mPtr && !mSharedCount->decreaseCount()) {
        delete mPtr;
        delete mSharedCount;
      }
    }

    // value copy constructor

    // move constructor
    template<typename U>
    SmartPtr(const SmartPtr<U>&& pVal){
        mPtr = pVal.mPtr;
        if(mPtr){
            mSharedCount = pVal.mSharedCount;
            pVal.mPtr = nullptr;
        }
    }

    // reference copy constructor
    SmartPtr(const SmartPtr& pVal){
        mPtr = pVal.mPtr; // inline function can use private member in this way?
        if(mPtr){
            pVal.mSharedCount->increaseCount();
            mSharedCount = pVal.mSharedCount;
        }
    }

    // how does this template instanization
    template<typename U>
    SmartPtr(const SmartPtr<U> & pVal, T* ptr){
        mPtr = ptr;
        if(mPtr){
            pVal.mSharedCount->increaseCount();
            mSharedCount = pVal.mSharedCount;
        }
    }


    
    // swap 
    void swap(SmartPtr& pVal)noexcept
    {
        using std::swap;
        swap(mPtr, pVal.mPtr);
        swap(mSharedCount, pVal.mSharedCount);
    }

    // use_count
    long useCount()const noexcept
    {
        if(mPtr){
        return mSharedCount->getCount();
        }else{
            return 0;
        }
    }

    // get()
    T* get()const noexcept
    {
        return mPtr;
    }

    // operator *
    T& operator *()const noexcept
    {
        return *mPtr;
    }

    // operator->
    // how to use this member function
    T* operator->()const noexcept
    {
        return mPtr;
    }
    
    // operator &

    // operator =
    SmartPtr& operator = (SmartPtr pVal) noexcept
    {
        pVal.swap(*this);
        return *this;
    }

    // functor? 
    operator bool() const noexcept
    {
        return mPtr;
    }

private:
    T* mPtr;
    SharedCount* mSharedCount;

};

// some global swap function
template<typename T>
void swap(SmartPtr<T> lhs, SmartPtr<T> rhs)noexcept
{
    lhs.swap(rhs);
}

// reload static_pointer_cast
template<typename T, typename U>
SmartPtr<T> static_pointer_cast(SmartPtr<U>& other)noexcept{
    T* ptr = static_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

// reload reinterpret_pointer_cast
template<typename T, typename U>
SmartPtr<T> reinterpret_pointer_cast(SmartPtr<U>& other)noexcept{
    T* ptr = reinterpret_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

// reload const_pointer_cast
template<typename T, typename U>
SmartPtr<T> const_pointer_cast(SmartPtr<U>& other)noexcept{
    T* ptr = const_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

// reload dynamic_pointer_cast
template<typename T, typename U>
SmartPtr<T> dynamic_pointer_cast(SmartPtr<U>& other)noexcept{
    T* ptr = dynamic_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}
