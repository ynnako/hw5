//
// Created by Yonatan on 1/15/2019.
//

#ifndef _MAT_IMPL_H_
#define _MAT_IMPL_H_




template <class T>
Mat<T>::Mat(unsigned int w):
w_(w)
{
    if(w < 1) throw ExceptionEmptyOperand();
}


template <class T>
Mat<T>::Mat(Vec<T> vec_1d)
{
    this->push_back(vec_1d);
    w_ = vec_1d.size();
    if(w_ < 1 ) throw ExceptionEmptyOperand();
}
template <class T>

Mat<T>::Mat(Vec< Vec<T> > vec_2d)
{
    for( auto p_rows = vec_2d.begin() ; p_rows != vec_2d.end(); p_rows++)
    {
        this->push_back(*p_rows);
    }
    w_ = vec_2d.width();
    if(w_ < 1 ) throw ExceptionEmptyOperand();
}
template <class T>
unsigned int Mat<T>::width() const
{
    return w_;
}

template <class T>
unsigned int Mat<T>::height() const
{
    return this->size();
}

template <class T>
Mat<T> Mat<T>::operator+(const Mat<T>& rhs) const
{
    Mat<T> new_mat(w_);
    Vec<T> new_vec;
    if(rhs.width() < 1 || rhs.height < 1 || height() < 1 || width() < 1 ) throw ExceptionEmptyOperand();
    if(width() != rhs.width() || height() != rhs.height())throw ExceptionWrongDimensions();
    for(auto p = this->begin() , r = rhs.begin() ; p != this->end() && r != rhs.end() ; p++ , r++)
    {
        new_mat.push_back(*p + *r);
    }
    return new_mat;
}

template <class T>
Mat<T> Mat<T>::operator*(const T& rhs) const
{
    Mat<T> new_mat(width());
    for(auto p = this->begin() ; p != this->end() ; p++)
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

    for(auto p_left_row = this->begin() ; p_left_row != this->end()  ; p_left_row++ )
    {
        Vec<T> tmp_vec;
        for(auto p_left_row_el = p_left_row->begin() , p_right_row = rhs.begin() ; p_left_row_el != p_left_row->end()  && p_right_row != rhs.end() ; p_right_row++ , p_left_row_el++)
        {
            if(p_left_row_el == p_left_row->begin()) tmp_vec = ( (*p_left_row_el) * (*p_right_row) );
            else tmp_vec = (tmp_vec + ( (*p_left_row_el) * (*p_right_row) ));
        }
        new_mat.push_back( tmp_vec );
    }
    return new_mat;
}


template <class T>
Mat<T> Mat<T>::operator,(const Mat<T>& rhs) const
{

    if(w_ < 1 ) throw ExceptionEmptyOperand();
    if( w_ != rhs.width()) throw ExceptionWrongDimensions();

    Mat<T> new_mat(*this);

    for(auto p_row = rhs.begin(); p_row != rhs.end() ; p_row++)
    {
        new_mat.push_back(*p_row);
    }

    return new_mat;
}

template <class T>
Mat<T> Mat<T>::get_rows(const Vec<unsigned int>& ind) const
{
    if(ind.size() < 1 )throw ExceptionEmptyOperand();
    Mat<T> new_mat(ind.size());
    int h = height();
    unsigned int i;
    for(auto p_vec_el = ind.begin() ; p_vec_el != ind.end() ; p_vec_el ++)
    {
        if(*p_vec_el >= h)throw ExceptionIndexExceed();
        i = *p_vec_el;
        for(auto p_mat_row = this->begin() ; p_mat_row != this->end() && i >= 0 ; p_mat_row++, i--)
        {
            if(i == 0) new_mat.push_back(*p_mat_row);
        }
    }
    return new_mat;
}

template <class T>
Mat<T> Mat<T>::get_cols(const Vec<unsigned int>& ind) const
{
    if(ind.size() < 1 )throw ExceptionEmptyOperand();
    Mat<T> new_mat(ind.size());

    unsigned int i;

    for(auto p_row = this->begin() ; p_row != this->end() ; p_row++)
    {
        Vec<T> tmp_v;
        for(auto p_vec_el = ind.begin() ; p_vec_el != ind.end(); p_vec_el++)
        {
            if(*p_vec_el >= w_)throw ExceptionIndexExceed();
            i = *p_vec_el;
            for(auto p_row_el = p_row->begin() ; p_row_el != p_row->end() && i >= 0 ; p_row_el++ , i--)
            {
                if (i == 0)tmp_v.push_back(*p_row_el);
            }
        }
        new_mat.push_back(tmp_v);
    }
    return new_mat;
}

template <class T>
Mat<T>  Mat<T>::transpose() const
{
    int wdth = this->width();
    if( wdth < 1 ) throw ExceptionEmptyOperand();

    Mat<T> new_mat(wdth);


    for( unsigned int i = 0 ; i < wdth ; i++)
    {
        Vec<T> tmp_v;
        for(auto p_row = this->begin() ; p_row != this->end() ; p_row++)
        {
            int j = 0 ;
            for(auto p_row_el = p_row->begin() ; p_row_el != p_row->end() && i >= j ; p_row_el++ , j++)
            {
                if(i == j) tmp_v.push_back(*p_row_el);
            }
        }
        new_mat.push_back(tmp_v);
    }
    return new_mat;
}

template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs)
{
    if(rhs.width() < 1 || rhs.height() < 1) throw ExceptionEmptyOperand();
    Mat<T> new_mat(rhs.width());
    for(auto p_row = rhs.begin() ; p_row != rhs.end() ; p_row++)
    {
        new_mat.push_back(*p_row * lhs);
    }
    return new_mat;
}

template <class T>
ostream& operator<<(ostream& ro, const Mat<T>& m)
{
    unsigned int  i =0 , size = m.size();
    if(size < 1) throw ExceptionEmptyOperand();
    ro << "(" << endl;
    for(auto p_row = m.begin() ; p_row != m.end() && i < size ; i++ , p_row++)
    {
        if(i < size - 1) ro << *p_row << "," << endl ;
        else ro << *p_row << endl;
    }
    ro << ")" << endl ;

    return ro;
}
#endif //HW5_MAT_IMPL_H
