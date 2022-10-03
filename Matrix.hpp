#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <utility>
# include <iostream>
# include <vector>

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

        // Matrix<T> &     operator=(const Matrix & rhs);

        void            display(void) const;

};

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
void            Matrix<T>::reshape(std::size_t m, std::size_t n) {
    if (n * m != _n * _m) {
        throw std::invalid_argument("New shape is not compatible");
    }
    std::vector<std::vector<T>> res(m, std::vector<T>(n,0));
    int                         nb_elem = m * n; 
    
    for (int i = 0; i < nb_elem, i++) {
        res[i / n][i % n] = _data[i / _n][i % _n];
    }
    _data = res;
    _m = m;
    _n = n;
    return;
    
}

template <class T>
void            Matrix<T>::display(void) const {

    std::cout << "Matrix shape: (" << _m << ", " << _n << ")" << std::endl;
    
    // for (size_t i = 0; i < _nbElem; i++) {
    //     if (i % _shape.second == 0)
    //         std::cout << "[";
        
    //     std::cout << _data[i];
        
    //     if ((i+1) % _shape.second == 0)
    //         std::cout << "]" << std::endl;
    // }

}

#endif