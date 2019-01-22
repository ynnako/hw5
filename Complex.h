//
// Created by Yonatan on 1/22/2019.
//

#ifndef _COMPLEX_H_
#define _COMPLEX_H_


class Complex
{
    private:
        double m_re;
        double m_im;

    public:
        Complex();
        Complex(double r);
        Complex(double r , double i);
        Complex operator + (const Complex& rhs) const;
        Complex operator * (const Complex& rhs) const;
        Complex operator - (const Complex& rhs) const;
        Complex operator = (const Complex& rhs) const;
        bool operator == (const Complex& rhs) const;
        bool operator < (const Complex& rhs);
        double im()const;
        double re()const;
        double abs(const Complex val) const;


};



#endif //HW5_COMPLEX_H
