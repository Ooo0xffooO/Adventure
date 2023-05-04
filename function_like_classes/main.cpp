#include <iostream>

template <class T>
struct identity{
    const T& operator() (const T& x) const {std::cout<<"ccc";return x;}
};
//第三个const用来修饰函数，即函数不改变对象状态，第二个const用来修饰x，既函数不能修改x的值
//当我们将函数对象声明为常量对象时，只能调用它的 const 成员函数，而不能调用非
// const 成员函数，从而避免对象的状态被修改。
class student{
private:
    int id;
public:
    explicit student(int i):id(i){};
};
int main() {
    identity<student> a;
    student b(1);
    a(b);
}
