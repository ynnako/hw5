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
    w_ = vec_1d.size();
    if(w_ < 1 ) throw ExceptionEmptyOperand();
    this->push_back(vec_1d);
}
template <class T>

Mat<T>::Mat(Vec< Vec<T> > vec_2d)
{
    auto p_rows = vec_2d.begin();
    w_ = *p_rows.size();
    if(w_ < 1 ) throw ExceptionEmptyOperand();
    for(  ; p_rows != vec_2d.end(); p_rows++)
    {
        if(*p_rows.size() != w_)throw ExceptionWrongDimensions();
        this->push_back(*p_rows);
    }

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
Mat<T> Mat<T>::operator+(const Mat& rhs) const
{
    Mat<T> new_mat(width());
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
    Mat<T> new_mat(rhs.width());

    for(auto p_left_row = this->begin() ; p_left_row != this->end()  ; p_left_row++  )
    {
        Vec<T> tmp_vec;
        auto p_right_row = rhs.begin();
        for(int i = 0 ;p_right_row != rhs.end() && i < width() ; i++ , p_right_row++)
        {
            if( i == 0) tmp_vec =  ((*p_left_row)[i] * (*p_right_row));
            else tmp_vec = tmp_vec + ((*p_left_row)[i] * (*p_right_row));
        }
//        for(auto p_left_row_el = p_left_row->begin() , p_right_row = rhs.begin() ; p_left_row_el != p_left_row->end()  && p_right_row != rhs.end() ; p_right_row++ , p_left_row_el++)
//        {
//            if(p_left_row_el == p_left_row->begin()) tmp_vec = ( (*p_left_row_el) * (*p_right_row) );
//            else tmp_vec = (tmp_vec + ( (*p_left_row_el) * (*p_right_row) ));
//        }
        new_mat.push_back(tmp_vec);
    }
    return new_mat;
}


template <class T>
Mat<T> Mat<T>::operator,(const Mat<T>& rhs) const
{

    if( this->width() != rhs.width()) throw ExceptionWrongDimensions();

    Mat<T> new_mat(this->width());
    new_mat = *this;

    for(auto p_row = rhs.begin(); p_row != rhs.end() ; p_row++)
    {
        new_mat.push_back(*p_row);
    }

    return new_mat;
}

template <class T>
Mat<T> Mat<T>::get_rows(const Vec<unsigned int>& ind) const
{

    Mat<T> new_mat(ind.size());
    int h = this->height();
    unsigned int i;
    Vec<T> tmp_vec ;

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
    Mat<T> new_mat(ind.size());

    for(auto p_row = this->begin() ; p_row != this->end() ; p_row++)
    {
        new_mat.push_back((*p_row)[ind]);
    }

    return new_mat;
}

template <class T>
Mat<T>  Mat<T>::transpose() const
{
    int width = this->width();
    Mat<T> new_mat(height());

    for( unsigned int i = 0 ; i < width ; i++)
    {
        Vec<T> tmp_v;
        for(auto p_row = this->begin() ; p_row != this->end() ; p_row++ )
        {
            tmp_v.push_back((*p_row)[i]);
        }
        new_mat.push_back(tmp_v);
    }
    return new_mat;
}

template <class T>
Mat<T> operator*(const T& lhs, const Mat<T>& rhs)
{
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
    ro << "(" << endl;
    for(auto p_row = m.begin() ; p_row != m.end() && i < size ; i++ , p_row++)
    {
        if(i < size - 1) ro << *p_row << "," << endl ;
        else ro << *p_row << endl;
    }
    ro << ")";

    return ro;
}
#endif //HW5_MAT_IMPL_H
