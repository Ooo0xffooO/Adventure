#include <iostream>

class Fraction{
private:
    int m_numerator;
    int m_denominator;
public:
    explicit Fraction(int num, int den=1): m_numerator(num),m_denominator(den){}
    operator double() const{            //这里不能加explicit,如果加了下面4+f就不能进行隐式转换
        return (double (m_numerator)/m_denominator);
    }
};


class Fraction1{
private:
    int m_numerator1;
    int m_denominator1;
public:
    Fraction1(int num1,int den1=1): m_numerator1(num1),m_denominator1(den1){};
    Fraction1 operator+(const Fraction1& f) const{
        int den = m_denominator1*f.m_denominator1;
        return Fraction1( m_numerator1*(den/m_denominator1)+f.m_numerator1*(den/f.m_denominator1),den);
    }
    friend std::ostream& operator <<(std::ostream& os, const Fraction1& a){     //重载输出分数形式
        return os<<a.m_numerator1<<"/"<<a.m_denominator1<<std::endl;
    }
};


int main() {
    Fraction f(3,5);
    double  d = 4 + f;
    std::cout<<d<<std::endl;

    Fraction1 z(3,5);
    Fraction1 z1 = z+4;             //如果我将构造函数定义为explicit,那么在这里的4就不能被隐式转换为Fraction1类型
    std::cout<<z1<<std::endl;
}
