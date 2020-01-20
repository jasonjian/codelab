namespace smartptr {
class SharedCount
{
public:
    long getCount() noexcept { return mCount; }

    // prefer "--mCount" to "count--"";
    long decreaseCount() noexcept { return --mCount; }

    // only use mCount++ when you need use the originale value of mCount;
    long increaseCount() noexcept { return ++mCount; }

private:
    long mCount;
};
} // namespace smartptr
