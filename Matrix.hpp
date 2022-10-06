#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <initializer_list>
# include "Vector.hpp"


template <class T>
class Matrix{
    private:
        std::vector<std::vector<T>>     _data;
        std::size_t                     _m;
        std::size_t                     _n;
    
    
    public:
        Matrix(void);
        Matrix(std::size_t m, std::size_t n, T val);
        Matrix(std::size_t m, std::size_t n, std::initializer_list< std::initializer_list<T> > inputs);
        Matrix(const Matrix<T> & src);
        ~Matrix();

        Matrix<T> &             operator=(const Matrix<T> & rhs);
        std::vector<T> &        operator[](std::size_t pos);
        const std::vector<T> &  operator[](std::size_t pos) const;
        Matrix<T> &             operator+=(const Matrix<T> & rhs);
        Matrix<T> &             operator+=(const T rhs);
        Matrix<T> &             operator-=(const Matrix<T> & rhs);
        Matrix<T> &             operator-=(const T rhs);
        Matrix<T> &             operator*=(const Matrix<T> & rhs);
        Matrix<T> &             operator*=(const T rhs);

        Matrix<T>               operator+(const Matrix<T> & rhs) const;
        Matrix<T>               operator+(const T rhs) const;
        Matrix<T>               operator-(const Matrix<T> & rhs) const;
        Matrix<T>               operator-(const T rhs) const;
        Matrix<T>               operator*(const T rhs) const;
        Vector<T>               operator*(const Vector<T> & rhs) const;
        Matrix<T>               operator*(const Matrix<T> & rhs) const;

        template <class U> friend std::ostream &    operator<<(std::ostream & flux, const Matrix<U> & rhs);

        void            reshape(std::size_t m, std::size_t n);
        T               trace(void) const;
        Matrix<T>       transpose(void) const;

        
};


/****************************************************************************************************
CONSTRUCTOR / DESTRUCTOR FUNCTIONS
****************************************************************************************************/

template <class T>
Matrix<T>::Matrix(void) : _data(std::vector<std::vector<T>>{{0}}), _m(1), _n(1) {
    
    std::cout << "Matrix default constructor Called" << std::endl;
    return;
}


template <class T>
Matrix<T>::Matrix(std::size_t m, std::size_t n, T val) : _data(std::vector<std::vector<T>>(m, std::vector<T>(n, val))), _m(m), _n(n) {
    
    if (m == 0 || n == 0) {
        throw std::invalid_argument("M or N can't be equal to 0");
    }
    return;
}

template <class T>
Matrix<T>::Matrix(std::size_t m, std::size_t n, std::initializer_list<std::initializer_list<T>> inputs) :  _m(m), _n(n) {

    if(_m == 0 || _n == 0)
        throw std::invalid_argument("received zero as argument");
    
    for (auto i : inputs) {
        _data.push_back(std::vector<T>{i}); 
        if (_data.back().size() != _n) {
            throw std::invalid_argument("Input size data doesn't match with n argument");
        }
    }

    if (_data.size() != _m) {
        throw std::invalid_argument("Input size data doesn't match with m argument");
    }
    return;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> & src) {
    
    *this = src;
    return;
}

template <class T>
Matrix<T>::~Matrix(void) {}

/****************************************************************************************************
RESHAPE
****************************************************************************************************/

template <class T>
void            Matrix<T>::reshape(std::size_t m, std::size_t n) {
    if (n * m != _n * _m) {
        throw std::invalid_argument("New shape is not compatible");
    }
    
    std::vector<std::vector<T>> res(m, std::vector<T>(n,0));
    int                         nb_elem = m * n; 
    
    for (int i = 0; i < nb_elem; i++) {
        res[i / n][i % n] = _data[i / _n][i % _n];
    }
    _data = res;
    _m = m;
    _n = n;
    return;
    
}

/****************************************************************************************************
OVERLOADED OPERATOR FUNCTIONS
****************************************************************************************************/

template <class T>
Matrix<T> &     Matrix<T>::operator=(const Matrix<T> & src) {
    
    _data = std::vector<std::vector<T>>(src._data);
    _m = src._m;
    _n = src._n;
    return *this;
}

template <class T>
std::vector<T> &             Matrix<T>::operator[](std::size_t pos) {
    return _data[pos];
}

template <class T>
const std::vector<T> &       Matrix<T>::operator[](std::size_t pos) const {
    return _data[pos];
}


template <class T>
Matrix<T> &     Matrix<T>::operator+=(const Matrix<T> & rhs) {

    if (_m != rhs._m || _n != rhs._n) {
        throw std::runtime_error("Shape doesn't match");
    }

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        _data[i / _n][i % _n] += rhs._data[i / _n][i % _n];
    }
    return *this;
}


template <class T>
Matrix<T> &     Matrix<T>::operator+=(const T rhs) {

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        _data[i / _n][i % _n] += rhs;
    }
    return *this;
}


template <class T>
Matrix<T> &     Matrix<T>::operator-=(const Matrix<T> & rhs) {

    if (_m != rhs._m || _n != rhs._n) {
        throw std::runtime_error("Shape doesn't match");
    }

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        _data[i / _n][i % _n] -= rhs._data[i / _n][i % _n];
    }
    return *this;
}


template <class T>
Matrix<T> &     Matrix<T>::operator-=(const T rhs) {

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        _data[i / _n][i % _n] -= rhs;
    }
    return *this;
}


template <class T>
Matrix<T> &     Matrix<T>::operator*=(const T rhs) {

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        _data[i / _n][i % _n] *= rhs;
    }
    return *this;
}

template <class T>
Matrix<T> &     Matrix<T>::operator*=(const Matrix<T> & rhs) {

    if (_n != rhs._m) {
        throw std::runtime_error("Shape doesn't match"); 
    }
    
    Matrix<T>       res(_m, rhs._n, 0);
    T               val = 0;
    std::size_t     nb_elem = res._m * res._n;
    
    for (std::size_t i = 0; i < nb_elem; i++) {
        for (std::size_t j = 0; j < res._n; j++) {
            val += _data[i % _n][j] * rhs[j][i / rhs._m ];
        }
        res[i % res._n][i / res._n] = val;
        val = 0;
    }
    *this = res;
    return *this;
}


template <class T>
Matrix<T>      Matrix<T>::operator+(const Matrix<T> & rhs) const {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    Matrix<T> res(*this);
    res += rhs;
    return res;
}



template <class T>
Matrix<T>      Matrix<T>::operator+(const T rhs) const {

    Matrix<T> res(*this);
    res += rhs;
    return res;
}


template <class T>
Matrix<T>      Matrix<T>::operator-(const Matrix<T> & rhs) const {

    if (_m != rhs._m) {
        throw std::runtime_error("Shape doesn't match");
    }

    Matrix<T> res(*this);
    res -= rhs;
    return res;
}


template <class T>
Matrix<T>      Matrix<T>::operator-(const T rhs) const {

    Matrix<T> res(*this);
    res -= rhs;
    return res;
}


template <class T>
Matrix<T>      Matrix<T>::operator*(const T rhs) const {

    Matrix<T> res(*this);
    res *= rhs;
    return res;
}


template <class T>
Matrix<T>      Matrix<T>::operator*(const Matrix<T> & rhs) const {

    Matrix<T> res(*this);
    res *= rhs;
    return res;
}


template <class T>
Vector<T>       Matrix<T>::operator*(const Vector<T> & rhs) const {

    if (_n != rhs.getM()) {
        throw std::runtime_error("Shape doesn't match"); 
    }
    
    Vector<T>       res(_m, 0);
    T               val = 0;
    
    for (std::size_t i = 0; i < _m; i++) {
        for (std::size_t j = 0; j < _n; j++) {
            val += _data[i][j] * rhs[j];
        }
        res[i] = val;
        val = 0;
    }
    return res;
}


/****************************************************************************************************
FRIEND OVERLOADED OPERATOR FUNCTIONS
****************************************************************************************************/

template <class U>
std::ostream &  operator<<(std::ostream & flux, const Matrix<U> & rhs) {
    
    for (auto r_vector: rhs._data) {
        flux << "[ ";
        for (auto c_value : r_vector) {
            flux << c_value << ", ";
        }
        flux << "]" << std::endl;
    }
    flux << "shape: (" << rhs._m << ", " << rhs._n << ")" << std::endl;
    return flux;
}

/****************************************************************************************************
TRACE    
****************************************************************************************************/

template <class T>
T               Matrix<T>::trace(void) const {
    
    if (_m != _n) {
        throw std::runtime_error("Matrix is not square"); 
    }
    
    T   res = 0;
    for (std::size_t i = 0; i < _m; i++) {
        res += _data[i][i];
    }
    return res;
}

/****************************************************************************************************
TRANSPOSE    
****************************************************************************************************/

template <class T>
Matrix<T>       Matrix<T>::transpose(void) const {
    
    Matrix<T>       res(_n, _m, 0);
    int             nb_elem = _m * _n; 
    
    for (int i = 0; i < nb_elem; i++) {
        res[i % _n][i / _n] = _data[i / _n][i % _n];
    }

    return res;
}

/****************************************************************************************************
LINEAR INTERPOLATION
****************************************************************************************************/

template <class U>
U               lerp(U u, U v, float t) {
    if(sizeof(u) != sizeof(v))
        throw std::runtime_error("Shape doesn't match");
    
    return (u*(1-t) + v*(t));
}

/****************************************************************************************************
REDUCED ROW-ECHELON FORM
****************************************************************************************************/

template <class T>
std::size_t     maxColElem(std::size_t col, std::size_t start_raw) const {
    
    T               val = _data[start_raw][col];
    std::size_t     pos = start_raw
    
    for (std::size_t i = start_raw +1; i < _m; i++) {
        if (_data[i][col] > val) {
            val = _data[i][col];
            pos = i;
        }
    }
    return pos;

}

template <class T>
Matrix<T>       fer(void) const {
    
    if (_n  < _m) {
        throw std::invalid_argument("The matrix must have at least as many columns as rows.");
    }
    Matrix<T>       res(*this);
    std::size_t     r = 0;

}




#endif























