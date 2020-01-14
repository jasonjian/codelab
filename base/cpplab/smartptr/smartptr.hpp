#include <utility> // std::swap
template<clase T>
class SmartPtr{
    template<typename U >
    friend class SmartPtr;

    explicit SmartPtr(T* pPtr = nullptr)
        : mPtr(pPtr)
    {
        if(pPtr){
            mCount = new SharedCount();
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

    // reference copy constructor

    // swap 

    // use_count

    // get()

    // operator *

    // operator &

    // operator =

    // operator bool
private:
    T* mPtr;
    SharedCount* mSharedCount;

};

// reload static_pointer_cast

// reload reinterpret_pointer_cast

// reload const_pointer_cast

// reload dynamic_pointer_cast
