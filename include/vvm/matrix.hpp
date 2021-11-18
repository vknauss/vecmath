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

    constexpr matrix(T a, T b, T c, T d) : data {a, b, c, d} { }

    explicit constexpr matrix(T v) : matrix(v, v, v, v) { }

    constexpr matrix(const col_type& c1, const col_type& c2) : cols {c1, c2} { }

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

    constexpr matrix(T a, T b, T c, T d, T e, T f, T g, T h, T i) :
        data {a, b, c, d, e, f, g, h, i} { }

    explicit constexpr matrix(T v) : matrix(v, v, v, v, v, v, v, v, v) { }

    constexpr matrix(const col_type& c1, const col_type& c2,
        const col_type& c3) : cols {c1, c2, c3} { }
        
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

    constexpr matrix(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l,
        T m, T n, T o, T p) :
        data {a, b, c, d, e, f, g, h, i, j, l, m, n, o, p} { }

    explicit constexpr matrix(T v) :
        matrix(v, v, v, v, v, v, v, v, v, v, v, v, v, v, v, v) { }

    constexpr matrix(const col_type& c1, const col_type& c2,
        const col_type& c3, const col_type& c4) : cols {c1, c2, c3, c4} { }
        
    const col_type& operator[](int i) const { return cols[i]; }
    col_type& operator[](int i) { return cols[i]; }
};

template<typename T> using m2 = matrix<T, 2, 2>;
template<typename T> using m3 = matrix<T, 3, 3>;
template<typename T> using m4 = matrix<T, 4, 4>;

using m2f = m2<float>;
using m3f = m3<float>;
using m4f = m4<float>;

}  // namespace vvm

#include "matrix_ops.inl"