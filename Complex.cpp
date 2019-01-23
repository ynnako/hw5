//
// Created by Yonatan on 1/22/2019.
//

#include "Complex.h"

Complex::Complex() {

}

Complex::Complex(double r) {

}

Complex::Complex(double r, double i) {

}

Complex Complex::operator+(const Complex &rhs) const {
    return Complex();
}

Complex Complex::operator*(const Complex &rhs) const {
    return Complex();
}

Complex Complex::operator-(const Complex &rhs) const {
    return Complex();
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

