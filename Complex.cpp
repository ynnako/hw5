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
	bool equal;
	if (this->m_re != rhs.m_re || this->m_im != rhs.m_im) equal = 0;
	else equal = 1;

    return equal ;
}

bool Complex::operator<(const Complex &rhs) {
	double abs_square_left = ( this->m_re * this->m_re ) + ( this->m_im * this->m_im );
	double abs_square_right = (rhs.m_re * rhs.m_re) + (rhs.m_im * rhs.m_im);

	return abs_square_left < abs_square_right;
}

double Complex::im() const {
    return m_im;
}

double Complex::re() const {
    return m_re;
}

ostream& operator<<(ostream& ro, const Complex& comp) {
	ro << comp.re << " + " << comp.im << "i" ;

	return ro;
}
