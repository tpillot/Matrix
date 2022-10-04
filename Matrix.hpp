#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <algorithm> 

template <class T>
class Matrix{
    private:
        std::vector<std::vector<T>>     _data;
        std::size_t                     _m;
        std::size_t                     _n;
    
    
    public:
        Matrix(void);
        Matrix(int n, int m, std::initializer_list<std::initializer_list<T>> inputs);
        Matrix(const Matrix<T> & src);
        ~Matrix();

        Matrix<T> &     operator=(const Matrix<T> & rhs);
        Matrix<T> &     operator+=(const Matrix<T> & rhs);
        Matrix<T> &     operator+=(const T rhs);
        Matrix<T> &     operator-=(const Matrix<T> & rhs);
        Matrix<T> &     operator-=(const T rhs);
        // Matrix<T>       operator*=(const Matrix & rhs);
        Matrix<T> &      operator*=(const T rhs);
        
        template <class U> friend std::ostream &    operator<<(std::ostream & flux, const Matrix<U> & rhs);

        void            reshape(std::size_t m, std::size_t n);

        
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
Matrix<T>::Matrix(int m, int n, std::initializer_list<std::initializer_list<T>> inputs) :  _m(m), _n(n) {

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
PUBLIC MEMBER FUNCTIONS
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

template <class U>
std::ostream &  operator<<(std::ostream & flux, const Matrix<U> & rhs) {
    
    for (auto r_vector: rhs._data) {
        flux << "[ ";
        for (auto c_value : r_vector) {
            flux << c_value << " ";
        }
        flux << "]" << std::endl;
    }
    flux << "shape: (" << rhs._m << ", " << rhs._n << ")" << std::endl;
    return flux;
}

#endif























