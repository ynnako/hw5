#ifndef _VEC_IMP_H_
#define _VEC_IMP_H_


template <class T>
void Vec <T>::push_back(T el)
{
    vals_.push_back(el);
};

template <class T>
unsigned int Vec <T>::size() const
{
    return vals_.size();
};
template <class T>
Vec<T> Vec <T>::operator+(const Vec& rhs) const
{
        Vec<T> new_vec;
        int i = 0;
        if(vals_.size() != rhs.size()) throw ExceptionWrongDimensions();
        
        for(auto p = vals_.begin() ; p != vals_.end() ; p++ , i++)
        {
            new_vec.push_back( *p + rhs[i]);
        }

        return new_vec;

};

template <class T>
Vec<T> Vec <T>::operator*(const T& rhs) const
{
    Vec<T> res_vec;
    for ( auto p = begin(); p != end(); p++)
    {
        res_vec.push_back(*p * rhs) ;
    }
};

template <class T>
T& Vec <T>::operator[](unsigned int ind)
{
    if( ind >= size()) throw ExceptionIndexExceed();
    int i = 0;
    typename list<T>::iterator p;
    for(p = vals_.begin(); i <= ind && p != vals_.end() ; p++ , i++ )
    {
        if( i == ind) return *p;
    }
};

template <class T>
const T& Vec <T>::operator[](unsigned int ind) const
{
    if( ind >= size()) throw ExceptionIndexExceed();

    int i = 0;
    for( auto p = begin() ; i <= ind ; p++ , i++ )
    {
        if( i == ind) {
            return *p;
        }
    }
};

template <class T>
Vec<T> Vec<T>::operator,(const Vec<T>& rhs) const {
	Vec<T> res_vec;

	for (auto p = vals_.begin(); p != vals_.end(); p++) {
		res_vec.push_back(*p);

	}
	for (auto q = rhs.vals_.begin(); q != rhs.vals_.end(); q++) {
		res_vec.push_back(*q);

	}
	return res_vec;
};

template <class T>
Vec<T> Vec<T>::operator[](const Vec<unsigned int>& ind) const {
	Vec<T> res_vec;
	int i = 0 , size;
	size = size();
	for (auto p = ind.begin(); p != ind.end(); p++) {
		if (*p >= size) throw ExceptionIndexExceed();
		for (auto q = begin(); q != end(); q++, i++) {
			if (i == *p) {
				res_vec.push_back(*q);
				break;
			}
		}
	}
	returnres_vec;
}
template <class T>
Vec<T> range(T start, unsigned int size) {
	Vec<T> vec_res;
	if (size == 0) return vec_res;
	for (int  i = 0 ; i < size  < i++) {
		vec_res.vals_.push_back(i+start);
	}
	return vec_res;
}

#endif