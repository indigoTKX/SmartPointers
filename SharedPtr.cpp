template <class T>
struct SharedPtr
{
    // реализуйте следующие методы
    //
    explicit SharedPtr(T* ptr = 0) :ptr(ptr) {
        if (ptr != 0)count = new int(1);
    }
    ~SharedPtr() {
        if (ptr == 0)return;
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
    SharedPtr(const SharedPtr& sptr) :ptr(sptr.ptr) {
        if (ptr != 0) {
            count = sptr.count;
            (*count)++;
        }
    }
    SharedPtr& operator=(const SharedPtr& sptr) {
        if (ptr == sptr.ptr)return *this;
        if (ptr != 0) {
            (*count)--;
            if (*count == 0) {
                delete count;
                delete ptr;
            }
        }
        ptr = sptr.ptr;
        if (sptr.ptr != 0) {
            count = sptr.count;
            (*count)++;
        }
        return *this;
    }
    T* get() const {
        return ptr;
    }
    void reset(T* ptr = 0) {
        if (this->ptr == ptr)return;
        if (this->ptr != 0) {
            (*count)--;
            if (*count == 0) {
                delete count;
                delete this->ptr;
            }
        }
        this->ptr = ptr;
        if (ptr != 0)count = new int(1);
    }
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }

private:
    T* ptr;
    int* count;
};
