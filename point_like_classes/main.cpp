#include <iostream>

template<class T>
class shared_ptr{
public:
    T& operator*() const{
        return *px;
    }
    T* operator->() const{
        return px;
    }
    explicit shared_ptr(T* p): px(p){};
private:
    T* px;
};

struct Foo{
    static void method(){
        std::cout<<"call method"<<std::endl;
    }
};

int main() {
    shared_ptr<Foo> sp(new Foo());
    sp->method();
    Foo::method();
}
