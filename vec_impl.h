#ifndef _VEC_IMP_H_
#define _VEC_IMP_H_


template <class T>
void Vec::push_back(T el)
{
    vals_.push_back(el);
}

unsigned int Vec::size() const
{
    unsigned int size = 0;
    for(auto p = this.begin() ; p != this.end() ; p++ , i++);
    return i;
}

Vec Vec::operator+(const Vec& rhs) const
{
    try{
        T new_vec;
        int size = this.size();
        if(size != rhs.size()) throw ExceptionWrongDimensions;
        
        for(int i = 0 ; i < size ; i++)
        {
            new_vec.push_back(this[i] + rhs[i]);
        }
    }
};

Vec Vec::operator*(const T& rhs) const
{
    Vec res_vec;
    for ( auto p = this.begin(); p != this.end(); p++)
    {
        res_vec.push_back(*p * rhs) ;
    }
}

T& Vec::operator[](unsigned int ind)
{
    if( ind >= this.size()) throw ExceptionIndexExceed;
    int i = 0;
    for( auto p = this.begin() ; i <= ind ; p++ , i++ )
    {
        if( i == ind) return *p;
    }
};

const T& Vec::operator[](unsigned int ind) const
{
    if( ind >= this.size()) throw ExceptionIndexExceed;
    int i = 0;
    for( auto p = this.begin() ; i <= ind ; p++ , i++ )
    {
        if( i == ind) return const *p;
    }
}




#endif