//
// Created by Yonatan on 1/15/2019.
//

#ifndef _MAT_IMPL_H_
#define _MAT_IMPL_H_




template <class T>
Mat<T>::Mat(unsigned int w)
{
    for(int i = 0 ; i < w ; i++) Vec<T>::push_back(0); //dont know
    w_ = w;
}
template <class T>
Mat<T>::Mat(Vec<T> vec_1d)
{
    const Vec<T> v = vec_1d;
    Vec<T>::Vec(v);
    w_ = vec_1d.size();
}
template <class T>
Mat<T>::Mat(Vec< Vec<T> > vec_2d)
{
    for( auto p_rows = vec_2d.begin() ; p_rows != vec_2d.end(); p_rows++)
    {

    }
}
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
    Mat<T> new_mat(width());
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
    Mat<T> new_mat(width());
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
    Mat<T> new_mat(width());
    Vec<T> tmp_vec; //needs to be initialized. TBD
    for(auto p_left_row = Vec<T>::begin() , p_right_row = rhs.begin()  ; p_left_row != Vec<T>::end() && p_right_row != rhs.end() ; p_left_row++ )
    {
        for(auto p_left_row_el = p_left_row->begin() ; p_left_row_el != p_left_row->end() ; p_left_row_el++)
        {
            if(p_left_row_el == p_left_row->begin()) tmp_vec = ( (*p_left_row_el) * (*p_right_row) );
            else tmp_vec = tmp_vec + ( (*p_left_row_el) * (*p_right_row) );
        }
        tmp_vec = tmp_vec * 0;
        new_mat.push_back( tmp_vec );
    }

}


#endif //HW5_MAT_IMPL_H
