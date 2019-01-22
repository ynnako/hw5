//
// Created by Yonatan on 1/15/2019.
//

#ifndef _SQ_MAT_IMPL_H_
#define _SQ_MAT_IMPL_H_

#endif //HW5_SQ_MAT_IMPL_H

template <class T>
unsigned int  SqMat<T>::size() const {

	return height;
}


template <class T>
T SqMat<T>::determinant() const {

	if (size() == 1) return *(this->begin());
	unsigned int size = size();
	Mat<T> tmp_SqMat(size);
	SqMat<T> SqMat_calc(size-1);
	Vec<unsigned int> ind1;
	Vec<unsigned int> ind2;
	Vec<T> row_vec;

	T det_res = 0;
	
	int i;
	auto p_first_row = this->begin();
	row_vec = this->getrows(range(0,1));
	for (i = 0 ; i < size ; i++ )
	{
		ind1 = (range( 0 , i - 1 );
		ind2 = (range( i + 1 , size - i );
		tmp_SqMat = this->get_rows( range(1 , size-1));
		SqMat_calc = tmp_SqMat->get_cols( ind1, ind2 );
		det_res += ((-1) ^ (i)) * row_vec[i] * SqMat_calc.determinant() ;
	}
}


