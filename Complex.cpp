//
// Created by Yonatan on 1/22/2019.
//

#include "Complex.h"

Complex::Complex():
m_re(0), m_im(0)
{}

Complex::Complex(double r):
m_re(r), m_im(0)
{}

Complex::Complex(double r, double i):
m_re(r), m_im(i)
{}

Complex Complex::operator+(const Complex &rhs) const {
    double real , img ;
    real = m_re + rhs.re();
    img = m_im + rhs.im();
    return Complex(real , img);
}

Complex Complex::operator*(const Complex &rhs) const {
    double img , real;
    real = m_re * rhs.re() - m_im * rhs.im();
    img = m_re * rhs.im() + m_im * rhs.re();
    return Complex(real , img);
}

Complex Complex::operator-(const Complex &rhs) const {
    double real , img ;
    real = m_re - rhs.re();
    img = m_im - rhs.im();
    return Complex(real , img);
}

bool Complex::operator==(const Complex &rhs) const {
    return false;
}

bool Complex::operator<(const Complex &rhs) {
    return false;
}

double Complex::im() const {
    return 0;
}

double Complex::re() const {
    return 0;
}

