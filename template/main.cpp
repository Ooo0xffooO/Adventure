#include <iostream>

//类模板
template<typename T>
class complex{
public:
    explicit complex(T r = 0,T i = 0) : re(r),im(i){}
    complex<T>& operator += (const complex& t){
        this->re += t.real();
        this->im += t.imag();
        return *this;
    };
    T real() const {return re;}
    T imag() const {return im;}
private:
    T re,im;
};

//函数模板
template <class F>
inline const F& min(const F& a,const F& b){
    return b<a?b:a;
}

class stone{
private:
    int w_,h_;
public:
    stone(int w, int h): w_(w),h_(h){}
    bool operator< (const stone& r) const{
        return this->w_<r.w_;
    }
    friend std::ostream& operator<<(std::ostream& os,const stone& f){
        return os<<"width:"<<f.w_<<","<<"height:"<<f.h_<<std::endl;
    }
};

int main() {
    complex<double> c1(1,2);    //类模板定义的时候需要<>标注
    complex<double> c2(2,3);
    c1 += c2;
    std::cout<<c1.real()<<c1.imag()<<std::endl;

    stone h1(1,2);
    stone h2(3,2);

    std::cout<<(h1<h2)<<std::endl;
    stone h3 = min(h1,h2);      //函数模板调用的时候会进行实参推导,不用标注
    std::cout<<h3<<std::endl;
}
