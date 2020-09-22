#include <iostream>
using namespace std;

template <typename T>
class UniquePtr {
private:
    T* data;
public:
    UniquePtr(T* pointer) {
        data = pointer;
    }

    UniquePtr(UniquePtr <T> &other) {
        data = other.data;
        other.data = nullptr;
    }

    ~UniquePtr(void) {
        delete data;
    }

    T* operator->() {
        return data;
    }

    T& operator*() {
        return *data;
    }

    void ChangePtr(T* pointer) {
        delete data;
        data = pointer;
    }

    UniquePtr& operator=(UniquePtr <T> &other) {
        data = other.data;
        other.data = nullptr;
        return *this;
    }

    void PrintData(void) {
        cout << data << endl;
    }

    void Copy(UniquePtr <T> other) {
        data = other.data;
    }
};

template <typename T>
void g(UniquePtr <T> A) {
    A.PrintData();
}

int main(void) {
    UniquePtr<int>ptr1(new int);
    UniquePtr<int>ptr2(new int);

    cout << "1st ptr starting:\t\t\t";
    ptr1.PrintData();
    cout << "2nd ptr starting:\t\t\t";
    ptr2.PrintData();

    cout << "using = operator to assign ptr1 to ptr2" << endl;
    ptr2 = ptr1;

    cout << "1st ptr, should be null:\t\t";
    ptr1.PrintData();
    cout << "2nd ptr, should be 1st:\t\t\t";
    ptr2.PrintData();
    cout << "2nd ptr from g func:\t\t\t";
    g(ptr2);
    cout << "2nd ptr, should be null:\t\t";
    ptr2.PrintData();
    return 0;
}