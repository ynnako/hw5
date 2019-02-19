//
// Created by Yonatan on 1/15/2019.
//

#ifndef _SQ_MAT_IMPL_H_
#define _SQ_MAT_IMPL_H_

#endif //HW5_SQ_MAT_IMPL_H

template <class T>
SqMat<T>::SqMat(Mat<T> m):
Mat<T>(m.width())
{
    if(m.height() != m.width()) throw ExceptionWrongDimensions();
    for(auto p_row = m.begin() ; p_row != m.end() ; p_row++)
    {
        this->push_back(*p_row);
    }
}

template <class T>
unsigned int  SqMat<T>::size() const {

	return this->width();
}


template <class T>
T SqMat<T>::determinant() const {

	if (size() == 1) return *(this->begin()->begin());
	unsigned int size = this->size();
	Mat<T> tmp_SqMat(size);
	//SqMat<T> SqMat_calc(size-1);
	Vec<unsigned int> ind1;
	Vec<unsigned int> ind2;
    int i , exp;
	T det_res = 0;

	for (i = 0 ; i < size ; i++ )
	{
		ind1 = (range((unsigned int) 0 , i));
		ind2 = (range((unsigned int) i + 1 , size - 1 -i ));
		tmp_SqMat = this->get_rows( range((unsigned int)1 , size-1));
        SqMat<T> SqMat_calc (tmp_SqMat.get_cols( (ind1, ind2) ));
        if(i % 2) exp = -1 ;
        else exp = 1 ;
		det_res = det_res + (*(this->begin()))[i] * SqMat_calc.determinant() * exp ;
	}
	return det_res;
}


