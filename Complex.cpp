//
// Created by Yonatan on 1/22/2019.
//

#include "complex.h"

Complex::Complex():
m_re(0), m_im(0)
{}

Complex::Complex(double r):
m_re(r), m_im(0)
{}

Complex::Complex(double r, double i):
m_re(r), m_im(i)
{}


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


Complex operator+(const Complex &lhs, const Complex &rhs) {
	return Complex(lhs.re() + rhs.re() , lhs.im() + rhs.im());
}


Complex operator*(const Complex &lhs, const Complex &rhs) {

    return Complex(lhs.re() * rhs.re() - lhs.im() * rhs.im() , lhs.re() * rhs.im() + lhs.im() * rhs.re());
}


Complex operator-(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.re() - rhs.re() , lhs.im() - rhs.im());
}


ostream& operator<<(ostream& ro, const Complex& comp) {
	ro << comp.re() << " + " << comp.im() << "i" ;
	return ro;
}


double abs_c_square(const Complex &c){
    return c.re() * c.re() + c.im() * c.im() ;
}
