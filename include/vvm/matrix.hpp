#pragma once

#include "vector.hpp"

namespace vvm {

template<typename T, int R, int C> struct matrix;

template<typename T> struct matrix<T, 2, 2> {
    typedef v2<T> col_type;
    
    union {
        T data[4];
        col_type cols[2];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d10, T d11) :
        data {d00, d01, d10, d11} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v} { }

    constexpr matrix(const col_type& c1, const col_type& c2) :
        cols {c1, c2} { }


    const col_type& operator[](int i) const { return cols[i]; }

    col_type& operator[](int i) { return cols[i]; }
};

template<typename T> struct matrix<T, 3, 3> {
    typedef v3<T> col_type;
    
    union {
        T data[9];
        col_type cols[3];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d02, T d10, T d11, T d12,
            T d20, T d21, T d22) :
        data {d00, d01, d02, d10, d11, d12, d20, d21, d22} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v, v, v, v, v, v} { }

    constexpr matrix(const col_type& c1, const col_type& c2,
            const col_type& c3) :
        cols {c1, c2, c3} { }
    
        
    const col_type& operator[](int i) const { return cols[i]; }

    col_type& operator[](int i) { return cols[i]; }
};

template<typename T> struct matrix<T, 4, 4> {
    typedef v4<T> col_type;
    
    union {
        T data[16];
        col_type cols[4];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d02, T d03, T d10, T d11, T d12, T d13,
            T d20, T d21, T d22, T d23, T d30, T d31, T d32, T d33) :
        data {d00, d01, d02, d03, d10, d11, d12, d13, d20, d21, d22, d23,
            d30, d31, d32, d33} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v,  v, v, v, v,  v, v, v, v,  v, v, v, v} { }

    constexpr matrix(const col_type& c1, const col_type& c2,
        const col_type& c3, const col_type& c4) :
        cols {c1, c2, c3, c4} { }
        
        
    const col_type& operator[](int i) const { return cols[i]; }

    col_type& operator[](int i) { return cols[i]; }
};

// common types aliased for convenience

template<typename T> using m2 = matrix<T, 2, 2>;
template<typename T> using m3 = matrix<T, 3, 3>;
template<typename T> using m4 = matrix<T, 4, 4>;

using m2f = m2<float>;
using m3f = m3<float>;
using m4f = m4<float>;

using m2d = m2<double>;
using m3d = m3<double>;
using m4d = m4<double>;

}  // namespace vvm
