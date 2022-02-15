#pragma once

#include "vector.hpp"

namespace vvm {

template<typename T, int R, int C> struct matrix;

template<typename T> struct matrix<T, 2, 2> {
    using column_t = v2<T>;

    static constexpr int rows = 2, columns = 2;
    
    union {
        T data[4];
        column_t cols[2];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d10, T d11) :
        data {d00, d01, d10, d11} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v} { }

    constexpr matrix(const column_t& c1, const column_t& c2) :
        cols {c1, c2} { }

    explicit constexpr matrix(const matrix<T, 3, 3>& m) :
        cols {m.cols[0], m.cols[1]} { }

    explicit constexpr matrix(const matrix<T, 4, 4>& m) :
        cols {m.cols[0], m.cols[1]} { }


    constexpr const column_t& operator[](int i) const { return cols[i]; }

    column_t& operator[](int i) { return cols[i]; }
};

template<typename T> struct matrix<T, 3, 3> {
    using column_t = v3<T>;

    static constexpr int rows = 3, columns = 3;
    
    union {
        T data[9];
        column_t cols[3];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d02, T d10, T d11, T d12,
            T d20, T d21, T d22) :
        data {d00, d01, d02, d10, d11, d12, d20, d21, d22} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v, v, v, v, v, v} { }

    constexpr matrix(const column_t& c1, const column_t& c2,
            const column_t& c3) :
        cols {c1, c2, c3} { }

    explicit constexpr matrix(const matrix<T, 2, 2>& m) :
        cols {m.cols[0], m.cols[1], {0, 0, 1}} { }

    explicit constexpr matrix(const matrix<T, 4, 4>& m) :
        cols {m.cols[0], m.cols[1], m.cols[2]} { }
    
        
    constexpr const column_t& operator[](int i) const { return cols[i]; }

    column_t& operator[](int i) { return cols[i]; }
};

template<typename T> struct matrix<T, 4, 4> {
    using column_t = v4<T>;

    static constexpr int rows = 4, columns = 4;
    
    union {
        T data[16];
        column_t cols[4];
    };


    constexpr matrix() { }

    constexpr matrix(T d00, T d01, T d02, T d03, T d10, T d11, T d12, T d13,
            T d20, T d21, T d22, T d23, T d30, T d31, T d32, T d33) :
        data {d00, d01, d02, d03, d10, d11, d12, d13, d20, d21, d22, d23,
            d30, d31, d32, d33} { }

    explicit constexpr matrix(T v) :
        data {v, v, v, v,  v, v, v, v,  v, v, v, v,  v, v, v, v} { }

    constexpr matrix(const column_t& c1, const column_t& c2,
        const column_t& c3, const column_t& c4) :
        cols {c1, c2, c3, c4} { }
    
    explicit constexpr matrix(const matrix<T, 2, 2>& m) :
        cols {{m.cols[0], 0, 0}, {m.cols[1], 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}} { }

    explicit constexpr matrix(const matrix<T, 3, 3>& m) :
        cols {{m.cols[0], 0}, {m.cols[1], 0}, {m.cols[2], 0}, {0, 0, 0, 1}} { }


    constexpr const column_t& operator[](int i) const { return cols[i]; }

    column_t& operator[](int i) { return cols[i]; }
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
