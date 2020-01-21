
namespace singleton {

typedef void (*AtExitFuncionPtrType)();

/**
 *  @brief Default Lifetime policy class for a Singleton Design Pattern.
 *
 *  This class implements the default Lifetime policy class for a singleton
 *  object.
 *
 *  @note This policy schedules singletons destruction in a reverse creation
 *        order.
 */
template <class T>
struct DefaultLifetime
{
    /**
     *  @brief Schedules singletons destruction in a reverse creation order.
     */
    static void scheduleDestruction(T*, AtExitFuncionPtrType pFunctionPtr)
    {
        std::atexit(pFunctionPtr);
    }

    /**
     *  @brief Throws an exception on a attempt to access a dead reference.
     */
    static void onDeadReference() { throw std::logic_error("Dead Reference Detected"); }
};

/**
 *  @brief Stub lifetime policy used to relay on default object lifetime.
 */
template <class T>
struct NoDestroy
{
    /**
     *  @brief Empty
     */
    static void scheduleDestruction(T* /*obj*/, AtExitFuncionPtrType /*pFunctionPtr*/) {}

    /**
     *  @brief Empty
     */
    static void onDeadReference() {}
};

/**
 *  @brief Default Creation policy class for a TLS Singleton.
 */
template <typename T>
class CreateUsingThreadLocal
{
public:
    /**
     *  @brief Creates singleton as a TLS static.
     */
    static T* create()
    {
        static thread_local T instance;

        return &instance;
    }

    /**
     *  @brief Empty.
     */
    static void destroy(T* /*pThatPtr*/) {}
};

/**
 *  @brief Default Creation policy class for a Singleton Design Pattern.
 *
 *  This class implements the default creation policy class for a singleton
 *  object.
 *
 *  @note This policy creates singletons via @p new operator.
 */
template <typename T>
class CreateUsingNew
{
public:
    /**
     *  @brief Creates singletons via @p new operator.
     */
    static T* create() { return new T; }

    /**
     *  @brief Releases singletons via @p delete operator.
     */
    static void destroy(T* pThatPtr) { delete pThatPtr; }
};

/**
 *  @brief A Multi-Threaded policy class for a Singleton Design Pattern.
 *
 *  @note This implementation uses @p std::call_once() function.
 */
template <typename T>
class ClassLevelLockable
{
public:
    class LockGuard;

public: // Types
    typedef std::mutex MutexType;
    typedef LockGuard LockGuardType;
    typedef volatile T VolatileType;

public:
    struct Initializer
    {
    private:
        Initializer() : mInit(false), mMutex() { mInit = true; }

        ~Initializer() { assert(mInit); }

        // all should be uncopyable
    public:
        static Initializer& get()
        {
            static Initializer initializer;
            return initializer;
        }

        inline bool IsInitialized() { return mInit; }

        MutexType& getMutex() { return mMutex; }

    private: // Member data
        bool mInit;
        MutexType mMutex;
    };

public:
    class LockGuard
    {
    public:
        LockGuard()
        {
            Initializer& initializer = Initializer::get();
            assert(initializer.IsInitialized());
            initializer.getMutex().lock();
        }

        ~LockGuard()
        {
            Initializer& initializer = Initializer::get();
            assert(initializer.IsInitialized());
            initializer.getMutex().unlock();
        }

        // set this class as un copyable
    };
};

/**
 *  @brief A Thread Local Storage based policy class for a Singleton Design
 *         Pattern.
 */
template <typename T>
class SingleThreaded
{
public: // Nested types
    class LockGuard
    {
    public:
        LockGuard() = default;
    };

public: // Types
    typedef LockGuard LockGuardType;
    typedef T VolatileType;
};

/**
 *  @brief This class implements a Singleton Design Pattern.
 *
 *  This class implements a Singleton Design Pattern with a policy
 *  support. Currently flowing policies are supported:
 *  - Creation Policy
 *  - Lifetime Policy
 *  - Threading Model
 */
template <typename T,
          template <typename> class CreationPolicyT = CreateUsingNew,
          template <typename> class LifetimePolicyT = DefaultLifetime,
          template <typename> class ThreadingModelT = ClassLevelLockable>
class Singleton
{
private: // Types
    typedef CreationPolicyT<T> CreationPolicyType;
    typedef LifetimePolicyT<T> LifetimePolicyType;
    typedef ThreadingModelT<T*> ThreadingModelType;

    typedef typename ThreadingModelType::VolatileType InstancePointerType;

private: // Constructors and destructor.
         /**
          *  @brief A default constructor.
          */
    Singleton();

    /**
     *  @brief Disallows @p Singleton copy construction and copy
     * assignment
     */

public: // Class interface
    /**
     *  @brief Returns a reference to a single instance of a @p T class.
     *  @return A reference to a singleton.
     *
     *  This static member function returns a reference to a instance of
     *  a @p T type.
     */
    static T& instance();

private: // Private member functions
         /**
          *  @brief Instantiates a object of @p T type.
          *
          *  @note This function is required for std::call_once() initialization.
          */
    static void initializeInstance();

    /**
     *  @brief Releases a singular object.
     */
    static void destroy();

private:                      // Member data
    static bool sIsDestroyed; ///< Keeps an information if a signleton has been detroyed
    static InstancePointerType sInstance;
};

template <typename T,
          template <typename>
          class CreationPolicyT,
          template <typename>
          class LifetimePolicyT,
          template <typename>
          class ThreadingModelT>
bool Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::sIsDestroyed =
    false;

template <typename T,
          template <typename>
          class CreationPolicyT,
          template <typename>
          class LifetimePolicyT,
          template <typename>
          class ThreadingModelT>
typename Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::InstancePointerType
    Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::sInstance =
        nullptr;

template <typename T,
          template <typename>
          class CreationPolicyT,
          template <typename>
          class LifetimePolicyT,
          template <typename>
          class ThreadingModelT>
T& Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::instance()
{
    if (sInstance == nullptr)
    {
        initializeInstance();
    }

    return *sInstance;
}

template <typename T,
          template <typename>
          class CreationPolicyT,
          template <typename>
          class LifetimePolicyT,
          template <typename>
          class ThreadingModelT>
void Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::initializeInstance()
{
    typename ThreadingModelT<Singleton>::LockGuardType guard;

    if (sInstance == nullptr)
    {
        if (sIsDestroyed)
        {
            sIsDestroyed = false;
            LifetimePolicyType::onDeadReference();
        }

        sInstance = CreationPolicyType::create();

        LifetimePolicyType::scheduleDestruction(sInstance, &destroy);
    }
}

template <typename T,
          template <typename>
          class CreationPolicyT,
          template <typename>
          class LifetimePolicyT,
          template <typename>
          class ThreadingModelT>
void Singleton<T, CreationPolicyT, LifetimePolicyT, ThreadingModelT>::destroy()
{
    assert(!sIsDestroyed);
    CreationPolicyType::destroy(sInstance);
    sInstance    = nullptr;
    sIsDestroyed = true;
}

template <typename T>
class Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>
{
private: // Types
    typedef CreateUsingThreadLocal<T> CreationPolicyType;
    typedef NoDestroy<T> LifetimePolicyType;
    typedef SingleThreaded<T*> ThreadingModelType;
    typedef typename ThreadingModelType::VolatileType InstancePointerType;

private: // Constructors and destructor.
         /**
          *  @brief A default constructor.
          */
    Singleton();

    Singleton(Singleton& val) = delete;
    Singleton(Singleton&& val) = delete;

    Singleton& operator=(Singleton& val) = delete;
    Singleton& operator=(const Singleton& val) = delete;
    Singleton& operator=(Singleton&& val) = delete;
    Singleton& operator=(const Singleton&& val) = delete;

public: // Class interface
    /**
     *  @brief Returns a reference to a single instance of a @p T class.
     *  @return A reference to a singleton.
     *
     *  This static member function returns a reference to a instance of
     *  a @p T type.
     */
    static T& instance();

private: // Private member functions
         /**
          *  @brief Instantiates a object of @p T type.
          *
          *  @note This function is required for std::call_once() initialization.
          */
    static void initializeInstance();

    /**
     *  @brief Releases a singular object.
     */
    static void destroy();

private: // Member data
    static thread_local InstancePointerType sInstance;
};

template <typename T>
thread_local
    typename Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>::InstancePointerType
        Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>::sInstance =
            nullptr;

template <typename T>
T& Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>::instance()
{
    initializeInstance();
    return *sInstance;
}

template <typename T>
void Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>::initializeInstance()
{
    if (!sInstance)
    {
        sInstance = CreationPolicyType::create();
    }
}

template <typename T>
void Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>::destroy()
{
}

template <typename T>
using TlsSingleton =
    Singleton<T, CreateUsingThreadLocal, NoDestroy, SingleThreaded>;

} // namespace singleton
