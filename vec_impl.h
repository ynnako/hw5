#ifndef _VEC_IMP_H_
#define _VEC_IMP_H_


const char* ExceptionWrongDimensions::what() const throw()
{
    return "operand dimensions must agree";
}

const char* ExceptionEmptyOperand::what() const throw()
{
    return "empty operand";
}

const char* ExceptionIndexExceed::what() const throw()
{
    return "index exeeds operand dimensions";
}



template <class T>
Vec<T>::Vec(const T& el)
{
    vals_.push_back(el);
}

template <class T>
void Vec <T>::push_back(T el)
{
    vals_.push_back(el);
}

template <class T>
unsigned int Vec <T>::size() const
{
    return static_cast<unsigned int>(vals_.size());
}

template <class T>
Vec<T> Vec <T>::operator+(const Vec<T>& rhs) const
{
        Vec<T> new_vec;
        int i = 0;
        if(size() != rhs.size()) throw ExceptionWrongDimensions();
        if(size() == 0) throw ExceptionEmptyOperand();

        for(auto p = vals_.begin() ; p != vals_.end() ; p++ , i++)
        {
            new_vec.push_back( *p + rhs[i]);
        }

        return new_vec;

}

template <class T>
Vec<T> Vec <T>::operator*(const T& rhs) const
{
    if(size() == 0) throw ExceptionEmptyOperand();
    Vec<T> res_vec;
    for ( auto p = begin(); p != end(); p++)
    {
        res_vec.push_back(*p * rhs) ;
    }
    return res_vec;
}

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
    throw ExceptionIndexExceed();
}

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
    throw ExceptionIndexExceed();
};

template <class T>
Vec<T> Vec<T>::operator,(const Vec<T>& rhs) const {
    Vec<T> res_vec;

    for (auto p = vals_.begin(); p != vals_.end(); p++) {
        res_vec.push_back(*p);

    }
    for (auto q = rhs.begin(); q != rhs.end(); q++) {
        res_vec.push_back(*q);

    }
    return res_vec;
}



template <class T>
Vec<T> Vec<T>::operator[](const Vec<unsigned int>& ind) const {
	Vec<T> res_vec;
	int i = 0 , size ;
	size = vals_.size();
	for (auto p = ind.begin(); p != ind.end(); p++) {
		if (*p >= size) throw ExceptionIndexExceed();
		for (auto q = begin(); q != end(); q++, i++) {
			if (i == *p) {
				res_vec.push_back(*q);
				i = 0;
				break;
			}
		}
	}
	return res_vec;
}


template <class T>
Vec<T> operator*(const T& lhs, const Vec<T>& rhs)
{
    if(rhs.size() == 0) throw ExceptionEmptyOperand();
    Vec<T> new_vec;
    for( auto p = rhs.begin() ; p != rhs.end() ; p++)
    {
        new_vec.push_back(*p * lhs);
    }

    return new_vec;
}


template <class T>
ostream& operator<<(ostream& ro, const Vec<T>& v)
{
    int i = 0 ,size;
    size = v.size();
    if(size == 0) throw ExceptionEmptyOperand();
    ro << "(";
    for(auto p = v.begin() ; p != v.end() ; p++ , i++)
    {
        if(i < size - 1 ) ro << *p << ",\t" ;
        else ro << *p ;
    }
    ro << ")";
    return ro ;
}


template <class T>
Vec<T> range(T start, unsigned int size) {
	Vec<T> vec_res;
	if (size == 0) return vec_res;
	for (int  i = 0 ; i < size  ; i++) {
		vec_res.push_back( i + start);
	}
	return vec_res;
}

template <class T>
class norm_inf_comp
{
public:
    bool operator()(const Vec<T> lhs , const Vec<T> rhs )
    {
        T max_l = 0 , max_r = 0 ;
        for(auto left_el = lhs.begin() ; left_el != lhs.end() ; left_el++)
        {
            if(max_l < abs(*left_el)) max_l = abs(*left_el);
        }

        for(auto right_el = rhs.begin() ; right_el != rhs.end() ; right_el++)
        {
            if(max_r < abs(*right_el)) max_r = abs(*right_el);
        }
        return max_l < max_r ;
    }
};


#endif