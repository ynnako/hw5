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
    try{
        Vec new_vec;
        if(vals_.size() != rhs.size()) throw ExceptionWrongDimensions;
        
        for(auto p = vals_.begin() ; p != vals_.end() ; p++ i++)
        {
            new_vec.push_back( *p + rhs[i]);
        }

        return new_vec;
    }
};

template <class T>
Vec<T> Vec <T>::operator*(const T& rhs) const
{
    Vec res_vec;
    for ( auto p = this.begin(); p != this.end(); p++)
    {
        res_vec.push_back(*p * rhs) ;
    }
};

template <class T>
T& Vec <T>::operator[](unsigned int ind)
{
    if( ind >= this.size()) throw ExceptionIndexExceed;
    int i = 0;
    for( auto p = this.begin() ; i <= ind ; p++ , i++ )
    {
        if( i == ind) return *p;
    }
};

template <class T>
const T& Vec <T>::operator[](unsigned int ind) const
{
    if( ind >= vals_.size()) throw ExceptionIndexExceed;
    int i = 0;
    for( auto p = this.begin() ; i <= ind ; p++ , i++ )
    {
        if( i == ind) return const *p;
    }
};




#endif