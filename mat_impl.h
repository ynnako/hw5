//
// Created by Yonatan on 1/15/2019.
//

#ifndef _MAT_IMPL_H_
#define _MAT_IMPL_H_

template <class T>
unsigned int Mat<T>::width() const
{
    auto p = Vec<T>::begin();
    return *p->size();
}

template <class T>
unsigned int Mat<T>::height() const
{
    return Vec<T>::size();
}

template <class T>
Mat<T> Mat<T>::operator+(const Mat<T>& rhs) const
{
    Mat<T> new_mat;
    Vec<T> new_vec;
    if(width() != rhs.width() || height() != rhs.height())throw ExceptionWrongDimensions();
    for(auto p = Vec<T>::begin() , r = rhs.begin() ; p != Vec<T>::end() && r != rhs.end() ; p++ , r++)
    {
        new_mat.push_back(*p + *r);
    }
    return new_mat;
}

template <class T>
Mat<T> Mat<T>::operator*(const T& rhs) const
{
    Mat<T> new_mat;
    for(auto p = Vec<T>::begin() ; p != Vec<T>::end() ; p++)
    {
        new_mat.push_back(*p * rhs);
    }
    return new_mat;
}

template <class T>
Mat<T> Mat<T>::operator*(const Mat<T>& rhs) const
{
    if(width() != rhs.height())throw ExceptionWrongDimensions();

}
#endif //HW5_MAT_IMPL_H
