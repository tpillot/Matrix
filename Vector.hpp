#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <cmath>
# include <initializer_list>


template <class T>
class Vector{
    private:
        std::vector<T>      _data;
        std::size_t         _m;
    
    public:
        Vector(void);
        Vector(std::size_t m, T val);
        Vector(std::size_t m, std::initializer_list<T> inputs);
        Vector(const Vector<T> & src);
        ~Vector(void);

        std::size_t             getM(void) const;
        const std::vector<T> &  getData(void) const;


        T &             operator[](std::size_t pos);
        const T &       operator[](std::size_t pos) const;
        Vector<T> &     operator=(const Vector<T> & rhs);
        Vector<T> &     operator+=(const Vector<T> & rhs);
        Vector<T> &     operator+=(const T rhs);
        Vector<T> &     operator-=(const Vector<T> & rhs);
        Vector<T> &     operator-=(const T rhs);
        Vector<T> &     operator*=(const T rhs);

        Vector<T>       operator+(const Vector<T> & rhs) const;
        Vector<T>       operator+(const T rhs) const;
        Vector<T>       operator-(const Vector<T> & rhs) const;
        Vector<T>       operator-(const T rhs) const;
        Vector<T>       operator*(const T rhs) const;
        T               operator*(const Vector<T> & rhs) const;

        float           norm1(void) const;
        float           norm(void) const;
        float           normInf(void) const;


        template <class U> friend std::ostream &    operator<<(std::ostream & flux, const Vector<U> & rhs);
};


/****************************************************************************************************
CONSTRUCTOR / DESTRUCTOR FUNCTIONS
****************************************************************************************************/

template <class T>
Vector<T>::Vector(void) : _data(std::vector<T>{0}), _m(1) {
    
    std::cout << "Vector default constructor Called" << std::endl;
    return;
}

template <class T>
Vector<T>::Vector(std::size_t m, T val) : _data(std::vector<T>(m,val)), _m(m) {
    
    if (m == 0) {
        throw std::invalid_argument("M can't be equal to 0");
    }
    return;
}

template <class T>
Vector<T>::Vector(std::size_t m, std::initializer_list<T> inputs) : _data(std::vector<T>{inputs}), _m(m){


    if (_data.size() != _m) {
        throw std::invalid_argument("Input size data doesn't match with m argument");
    }
    return;
}

template <class T>
Vector<T>::Vector(const Vector<T> & src) {
    
    *this = src;
    return;
}

template <class T>
Vector<T>::~Vector(void) {}

/****************************************************************************************************
ACCESORS
****************************************************************************************************/

template<class T>
std::size_t             Vector<T>::getM(void) const {
    return _m;
}

template<class T>
const std::vector<T> &  Vector<T>::getData(void) const {
    return  _data;
}

/****************************************************************************************************
OVERLOADED OPERATOR FUNCTIONS
****************************************************************************************************/


template <class T>
Vector<T> &     Vector<T>::operator=(const Vector<T> & src) {
    
    _data = std::vector<T>(src._data);
    _m = src._m;
    return *this;
}

template <class T>
T &             Vector<T>::operator[](std::size_t pos) {
    return _data[pos];
}

template <class T>
const T &       Vector<T>::operator[](std::size_t pos) const {
    return _data[pos];
}


template <class T>
Vector<T> &     Vector<T>::operator+=(const Vector<T> & rhs) {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    for (std::size_t i = 0; i < _m; i++) {
        _data[i] += rhs._data[i];
    }
    return *this;
}


template <class T>
Vector<T> &     Vector<T>::operator+=(const T rhs) {

    for (std::size_t i = 0; i < _m; i++) {
        _data[i] += rhs;
    }
    return *this;
}


template <class T>
Vector<T> &     Vector<T>::operator-=(const Vector<T> & rhs) {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    for (std::size_t i = 0; i < _m; i++) {
        _data[i] -= rhs._data[i];
    }
    return *this;
}


template <class T>
Vector<T> &     Vector<T>::operator-=(const T rhs) {

    for (std::size_t i = 0; i < _m; i++) {
        _data[i] -= rhs;
    }
    return *this;
}


template <class T>
Vector<T> &     Vector<T>::operator*=(const T rhs) {

    for (std::size_t i = 0; i < _m; i++) {
        _data[i] *= rhs;
    }
    return *this;
}


template <class T>
Vector<T>      Vector<T>::operator+(const Vector<T> & rhs) const {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    Vector<T> res(*this);
    res += rhs;
    return res;
}


template <class T>
Vector<T>      Vector<T>::operator+(const T rhs) const {

    Vector<T> res(*this);
    res += rhs;
    return res;
}


template <class T>
Vector<T>      Vector<T>::operator-(const Vector<T> & rhs) const {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    Vector<T> res(*this);
    res -= rhs;
    return res;
}


template <class T>
Vector<T>      Vector<T>::operator-(const T rhs) const {

    Vector<T> res(*this);
    res -= rhs;
    return res;
}


template <class T>
Vector<T>      Vector<T>::operator*(const T rhs) const {

    Vector<T> res(*this);
    res *= rhs;
    return res;
}

template <class T>
T               Vector<T>::operator*(const Vector<T> & rhs) const {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    T   res = static_cast<T>(0);

    for (std::size_t i = 0; i < _m; i++) {
       res += (_data[i] * rhs._data[i]);
    }
    return res;
}


/****************************************************************************************************
FRIEND OVERLOADED OPERATOR FUNCTIONS
****************************************************************************************************/



template <class U>
std::ostream &  operator<<(std::ostream & flux, const Vector<U> & rhs) {
    
    for (auto r_value: rhs._data) {
        flux << "["
                << r_value
                << "]" << std::endl;
    }
    flux << "shape: (" << rhs._m << ")" << std::endl;
    return flux;
}


/****************************************************************************************************
LINEAR COMBINAISON
****************************************************************************************************/

template <class U>
Vector<U>       linear_combinaison(std::initializer_list<Vector<U>> vect_inputs, std::initializer_list<U> coefs) {

    if (vect_inputs.size() != coefs.size() || !coefs.size()) {
        throw std::invalid_argument("Number of inputs vector is not equal to number of coefs");
    }

    std::vector<Vector<U>> v{vect_inputs};
    std::vector<U> c{coefs};

    Vector<U>   res(v[0] * c[0]);
    std::size_t m = v[0].getM();
    
    for (auto i : vect_inputs) {

        if (m != i.getM()) {
            throw std::invalid_argument("Inputs vector have not the same shape");
        }
    }
    
    for (std::size_t i = 1; i < c.size(); i++) {
        res += (v[i] * c[i]);
    }

    return res;

}

/****************************************************************************************************
NORM
****************************************************************************************************/

template <class T>
float           Vector<T>::norm1(void) const {
    
    float   res = 0.;
    
    for (std::size_t i = 0; i < _m; i++) {

        res += static_cast<float>(std::abs(_data[i]));
    }
    return res;
}

template <class T>
float           Vector<T>::norm(void) const {

    T   res = 0;

    for (std::size_t i = 0; i < _m; i++) {
        res += pow(_data[i], 2);
    }
    
    return (pow(res, 0.5));
}


template <class T>
float           Vector<T>::normInf(void) const {
    float      res;
    auto       max = std::max_element(_data.begin(), _data.end());
    auto       min = std::min_element(_data.begin(), _data.end());
    
    res = *max >= *min * -1 ? *max : *min * -1 ;
    return res;
}


/****************************************************************************************************
COSINE
****************************************************************************************************/

template <class U>
float           angle_cos(const Vector<U> & u, const Vector<U> & v) {
    
    U   dot = u * v;
    U   vec_magn = u.norm() * v.norm();

    if (vec_magn == 0) {
        throw std::invalid_argument("Inputs vertor are zero");
    }
    return (dot / vec_magn);
}

/****************************************************************************************************
CROSS PRODUCT
****************************************************************************************************/

template <class U>
Vector<U>       cross_product(const Vector<U> & u, const Vector<U> & v) {

    if (u.getM() != 3 || v.getM() != 3) {
        throw std::invalid_argument("Shape of vectors are not 3");
    }
    Vector<U>  z(3, 0);

    z[0] = u[1] * v[2] - u[2] * v[1];
    z[1] = u[2] * v[0] - u[0] * v[2];
    z[2] = u[0] * v[1] - u[1] * v[0];

    return z;
}

#endif
