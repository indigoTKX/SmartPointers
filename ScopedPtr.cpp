template <class T>
struct ScopedPtr
{
    explicit ScopedPtr(T* ptr = 0) :ptr(ptr) {}
    ~ScopedPtr() {
        delete ptr;
    }

    T* get() const {
        return ptr;
    }

    //take value from pointer (without deleting it)
    T* release() {
        T* temp = ptr;
        ptr = 0;
        return temp;
    }

    void reset(T* ptr = 0) {
        delete this->ptr;
        this->ptr = ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }


private:
    //forbidding copying
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    T* ptr;
};
