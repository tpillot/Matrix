#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
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

        bool                    operator==(const Matrix<T> & rhs) const;

        template <class U> friend std::ostream &    operator<<(std::ostream & flux, const Matrix<U> & rhs);

        void            reshape(std::size_t m, std::size_t n);
        T               trace(void) const;
        Matrix<T>       transpose(void) const;
        std::size_t     maxColElem(std::size_t col, std::size_t start_raw) const;
        void            swapRaw(std::size_t pos1, std::size_t pos2);
        void            multRaw(std::size_t pos, T scal);
        void            sub2Raw(std::size_t pos1, std::size_t pos2, T scal);
        Matrix<T>       fer(void) const;
        T               determinant(void) const;
        Matrix<T>       inverse(void) const;
        Matrix<T>       identity(std::size_t n) const;
        bool            rawIsNull(std::size_t pos) const;
        std::size_t     rank(void) const;

        
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

template <class T>
bool            Matrix<T>::operator==(const Matrix<T> & rhs) const {
    
    if (_m != rhs._m || _n != rhs._n) {
        return false;
    }

    int     nb_elem = _m * _n;
    
    for (int i = 0; i < nb_elem; i++) {
        if (_data[i / _n][i % _n] != rhs[i / _n][i % _n]) {
            return false;
        }
        
    }
    return true;
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
std::size_t     Matrix<T>::maxColElem(std::size_t col, std::size_t start_raw) const {
    
    T               val = _data[start_raw][col];
    std::size_t     pos = start_raw;
    
    for (std::size_t i = (start_raw + 1); i < _m; i++) {
        if (_data[i][col] > val || (_data[i][col] * -1) > val) {
            val = _data[i][col];
            pos = i;
        }
    }
    return pos;

}

template <class T>
void            Matrix<T>::swapRaw(std::size_t pos1, std::size_t pos2) {

    T       tmp;

    for (std::size_t i = 0; i < _n; i++) {
        
        tmp = _data[pos1][i];
        _data[pos1][i] = _data[pos2][i];
        _data[pos2][i] = tmp;
    }
    return;

}

template <class T>
void            Matrix<T>::multRaw(std::size_t pos, T scal) {

    for (std::size_t i = 0; i < _n; i++) {
        if (_data[pos][i] != 0)
            _data[pos][i] = _data[pos][i] * scal;
    }
    return; 

}

template <class T>
void            Matrix<T>::sub2Raw(std::size_t pos1, std::size_t pos2, T scal) {
    
    for (std::size_t i = 0; i < _n; i++) {
        if (_data[pos2][i] - 1 < std::numeric_limits<T>::epsilon() && _data[pos2][i] - 1 > -std::numeric_limits<T>::epsilon()) {
            _data[pos2][i] = 1;
        }

        _data[pos1][i] -= _data[pos2][i] * scal;
        
    }
    return;
}


template <class T>
Matrix<T>       Matrix<T>::fer(void) const {
    
    // if (_n  < _m) {
    //     throw std::invalid_argument("The matrix must have at least as many columns as rows.");
    // }
    Matrix<T>       res(*this);
    std::size_t     r = -1;
    std::size_t     k = 0;

    for (std::size_t i = 0; i < _n && r+1 < _m ; i++) {
        
        k = res.maxColElem(i, r+1);
        if (res[k][i] != 0) {
            r++;
            if (k != r) {
                res.swapRaw(r, k);
            }
            
            res.multRaw(r, (1 /res[r][i]));
            
            for (std::size_t j = 0; j < _m; j++) {
                if (j != r || res[j][i] == 0) {
                    res.sub2Raw(j, r, res[j][i]);
                }
            }
            
        }
    }
    return res;

}

/****************************************************************************************************
DETERMINANT
****************************************************************************************************/

template <class T>
T               Matrix<T>::determinant(void) const {
    if (_m != _n)
        throw std::runtime_error("Matrix is not square");
    
    T               d = 1;
    int             swap_count = 0;
    Matrix<T>       res(*this);
    std::size_t     k;


    for (std::size_t i = 0; i < _n ; i++) {

        if (res[i][i] == 0) {
            k = res.maxColElem(i,i);
            if (k != i) {
                res.swapRaw(i,k);
                swap_count++;
            }
        }

        for (std::size_t j = i+1; j < _m ; j++) {
            if (res[j][i] != 0) {
                res.sub2Raw(j, i, res[j][i] / res[i][i]);
            }
        }

        d *= res[i][i];
    }
    d = (swap_count % 2 == 0) ? d : d * -1;
    return d;
}

/****************************************************************************************************
INVERSE
****************************************************************************************************/

template <class T>
Matrix<T>       Matrix<T>::identity(std::size_t n) const {
    if (n < 2) {
        throw std::invalid_argument("Identity matrix must have at least 2 raw and 2 columns");
    }
    Matrix<T>   id(n, n, 0);

    for (std::size_t i = 0 ; i < n; i++) {
        id[i][i] = 1;
    }
    return id;

}

template <class T>
Matrix<T>       Matrix<T>::inverse(void) const {
    
    if (_n  != _m) {
        throw std::invalid_argument("Matrix is not square");
    }
    Matrix<T>       res(*this);
    Matrix<T>       id;
    std::size_t     r = -1;
    std::size_t     k = 0;

    id = id.identity(_n);
    // std::cout << id;
    std::cout << res;
    for (std::size_t i = 0; i < _n && r+1 < _m ; i++) {
        
        k = res.maxColElem(i, r+1);
        if (res[k][i] != 0) { 
            r++;
            if (k != r) {
                res.swapRaw(r, k);
                id.swapRaw(r, k);

            }
            id.multRaw(r, (1 /res[r][i]));
            res.multRaw(r, (1 /res[r][i]));
            
            // std::cout << id;
            std::cout << res;
            
            for (std::size_t j = 0; j < _m; j++) {
                if (j != r || res[j][i] == 0) {
                    
                    // std::cout << res[j][i] << std::endl;
                    // std::cout << r << std::endl;
                    // std::cout << id;
                    // std::cout << "id : " << std::endl;
                    id.sub2Raw(j, r, res[j][i]);
                    
                    // std::cout << "res : " << std::endl;
                    // std::cout << res;
                    res.sub2Raw(j, r, res[j][i]);
                    // std::cout << res[j][i] << std::endl;
                    std::cout << res;
                }
            }
            
        }
    }
    std::cout << id ;
    if (!(res == res.identity(_n)))
        throw std::runtime_error("Matrix is not inversible");
    return id;

}

/****************************************************************************************************
RANK
****************************************************************************************************/

template <class T>
bool            Matrix<T>::rawIsNull(std::size_t pos) const {

    for (std::size_t i = 0; i < _n; i++) {
        if (_data[pos][i] != 0)
            return false;
    }
    return true;
}

template <class T>
std::size_t     Matrix<T>::rank(void) const {
    
    std::size_t     rank = 0;
    auto mf =       *this;
    
    // if (_m > _n)
    //     mf = mf.transpose();
    
    mf = mf.fer();
    for (std::size_t i = 0; i < mf._m; i++) {
        if (!mf.rawIsNull(i))
            rank++;
    }
    std::cout << mf;
    return rank;
}

#endif























