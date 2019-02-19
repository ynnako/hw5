//
// Created by Yonatan on 1/22/2019.
//

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using namespace std;

class Complex
{
    private:
        double m_re;
        double m_im;

    public:
        Complex();
        Complex(double r);
        Complex(double r , double i);
        bool operator == (const Complex& rhs) const;
        bool operator < (const Complex& rhs);
        double im()const;
        double re()const;


};

Complex operator + (const Complex& lhs , const Complex& rhs);

Complex operator * (const Complex& lhs , const Complex& rhs);

Complex operator - (const Complex& lhs , const Complex& rhs);

ostream& operator<<(ostream& ro, const Complex& comp);

double abs_c_square(const Complex &c);
#endif //HW5_COMPLEX_H
