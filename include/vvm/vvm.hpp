#pragma once

#include <cstdio>

namespace vvm {

// basic templated vector and matrix types

template<typename T, int D>
struct vector {
    T data[D];
};

// matrices are all column-major because i'm used to opengl and glm
template<typename T, int R, int C>
struct matrix {
    vector<T, R> cols[C];
};


// specializations for common vector sizes
// constructors are there to make these easy to build and convert between

template<typename T>
struct vector<T, 2> {
    union {
        T data[2];
        struct {
            T x, y;
        };
    };

    constexpr vector(T x, T y) :
        x(x), y(y) { }

    explicit constexpr vector(T v) :
        vector(v, v) { }

    constexpr vector() :
        vector((T) 0.0) { }

    explicit constexpr vector(const vector<T, 3>& v) :
        vector(v.x, v.y) { }

    explicit constexpr vector(const vector<T, 4>& v) :
        vector(v.x, v.y) { }

};

template<typename T>
struct vector<T, 3> {
    union {
        T data[3];
        struct {
            T x, y, z;
        };
    };

    constexpr vector(T x, T y, T z) :
        x(x), y(y), z(z) { }

    explicit constexpr vector(T v) :
        vector(v, v, v) { }

    constexpr vector() :
        vector((T) 0.0) { }
        
    constexpr vector(const vector<T, 2>& v, T z) :
        vector(v.x, v.y, z) { }

    explicit constexpr vector(const vector<T, 4>& v) :
        vector(v.x, v.y, v.z) { }
};

template<typename  T>
struct vector<T, 4> {
    union {
        T data[4];
        struct {
            T x, y, z, w;
        };
    };

    constexpr vector(T x, T y, T z, T w) :
        x(x), y(y), z(z), w(w) { }

    explicit constexpr vector(T v) :
        vector(v, v, v, v) { }

    constexpr vector() :
        vector((T) 0.0) { }

    constexpr vector(const vector<T, 2>& v, T z, T w) :
        vector(v.x, v.y, z, w) { }

    constexpr vector(const vector<T, 3>& v, T w) :
        vector(v.x, v.y, v.z, w) { }
};

// typedefs for very common specializations

typedef vector<float, 2> v2;
typedef vector<float, 3> v3;
typedef vector<float, 4> v4;

typedef matrix<float, 2, 2> m2;
typedef matrix<float, 3, 3> m3;
typedef matrix<float, 4, 4> m4;


// free functions for basic operations

// vector-vector binary operators
// return newly constructed vector

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v1.data[i] + v2.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v1.data[i] - v2.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v1.data[i] * v2.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v1.data[i] / v2.data[i];
    return result;
}

// vector-vector binary operators (+=, etc type)
// return reference to modified vector

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1.data[i] += v2.data[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1.data[i] -= v2.data[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1.data[i] *= v2.data[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1.data[i] /= v2.data[i];
    return v1;
}

// vector unary operators
// only negation for now
template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = -v.data[i];
    return result;
}

// vector-scalar binary operators
// return newly constructed vector
// pre- and post- forms have typical meanings, e.g. s * v = v * s
// but s / v =/= v / s

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v.data[i] + s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v.data[i] - s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v.data[i] * s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = v.data[i] / s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator+(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = s + v.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = s - v.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = s * v.data[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result.data[i] = s / v.data[i];
    return result;
}

// vector-scalar in place binary operators
// only available in the post form, obviously
// ( 2.0 += v2(4.0, 5.0) ? who wants that? )

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v.data[i] += s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v.data[i] -= s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v.data[i] *= s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v.data[i] /= s;
    return v;
}

// matrix-vector multiplication, implemented as defined in linear algebra
// vectors are interpreted exclusivly as column vectors
template<typename T, int R, int C>
constexpr vector<T, R> operator*(const matrix<T, R, C>& m,
    const vector<T, C>& v)
{
    vector<T, R> result;
    for (int i = 0; i < C; ++i) result += m.cols[i] * v.data[i];
    return result;
}

// matrix-matrix multiplication, implemented as defined in linear algebra

template<typename T, int R1, int S, int C2>
constexpr matrix<T, R1, C2> operator*(const matrix<T, R1, S>& m1,
    const matrix<T, S, C2>& m2)
{
    matrix<T, R1, C2> result;
    for (int i = 0; i < C2; ++i) {
        for (int j = 0; j < R1; ++j) {
            result.cols[i].data[j] = (T) 0.0;
            for (int k = 0; k < S; ++k) {
                result.cols[i].data[j] += m1.cols[k].data[j] *
                    m2.cols[i].data[k];
            }
        }
    }
    return result;
}

// specialized matrix-matrix multiplication for square matrices
template<typename T, int D>
constexpr matrix<T, D, D> operator*(const matrix<T, D, D>& m1,
    const matrix<T, D, D>& m2)
{
    printf("using specialized square matrix mul\n");
    matrix<T, D, D> result;
    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j) {
            result.cols[i].data[j] = 0;
            for (int k = 0; k < D; ++k) {
                result.cols[i].data[j] += m1.cols[k].data[j] *
                    m2.cols[i].data[k];
            }
        }
    }
    return result;
}

// matrix-matrix multiplication, implemented as defined in linear algebra
// in-place version (but implemented via copy/move so not really in-place)
template<typename T, int R1, int S, int C2>
constexpr matrix<T, R1, C2>& operator*=(matrix<T, R1, S>& m1,
    const matrix<T, S, C2>& m2)
{
    return (m1 = m1 * m2);
}
};