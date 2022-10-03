#include "Matrix.hpp"
#include <iostream>

template <class T>
Matrix<T>::Matrix(void) : _m(1), _m(1), _data(std::vector<std::vector<T>>{{0}}) {
    
    std::cout << "Matrix default constructor Called" << std::endl;
    return;
}


template <class T>
Matrix<T>::Matrix(std::initializer_list<T> inputs) :  _m(0), _m(0) {

    // if(m == 0 || n == 0)
    //     throw std::invalid_argument("received zero as argument");
    
    for (auto i : inputs) {
        _data.push_back(std::vector<T>(i));
        
        // if (_data.back().size() != n) {
        //     throw std::invalid_argument("Input size data doesn't match with n argument");
        // }
    }

    // if (_data.size() != n) {
    //     throw std::invalid_argument("Input size data doesn't match with n argument");
    // }
    return;
}

// template <typename T>
// Matrix<T>::Matrix(T ** data) {

//     size_t T_size = sizeof(**data);

//     _shape.second = sizeof(*data) / T_size;
//     _shape.first = sizeof(data) / _shape.first;
//     _nbElem = _shape.first*_shape.second; 

//     _data = new T[_nbElem];

//     for (size_t i = 0; i < _nbElem; i++) {
//             _data[i] = data[i / _shape.second][i % _shape.first];
//     }

//     return; 

// }

// template <typename T>
// Matrix<T>::Matrix(const Matrix<T> & src) {
    
//     *this = src;
//     return;
// }

// template <typename T>
// Matrix<T>::~Matrix(void) {

//     delete[] _data;
// }

// template <typename T>
// Matrix<T> &     Matrix<T>::operator=(const Matrix<T> & rhs) {
    
//     T * tmp = new T[rhs._nbElem];
    
//     _shape = rhs._shape;
//     for (size_t i = 0; i < rhs._nbElem; i++) {
//         tmp[i] = rhs._data[i];
//     }
//     delete[] _data;
//     _data = tmp;
    
//     return *this;
// }

template <typename T>
void            Matrix<T>::display(void) const {

    // std::cout << "Matrix shape: (" << _shape.first << ", " << _shape.second << ")" << std::endl;
    
    // for (size_t i = 0; i < _nbElem; i++) {
    //     if (i % _shape.second == 0)
    //         std::cout << "[";
        
    //     std::cout << _data[i];
        
    //     if ((i+1) % _shape.second == 0)
    //         std::cout << "]" << std::endl;
    // }

}

























