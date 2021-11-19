#pragma once

#include "matrix_ops.hpp"


namespace vvm {

// matrix-vector multiplication, implemented as defined in linear algebra
// vectors are interpreted exclusivly as column vectors
template<typename T, int R, int C>
constexpr vector<T, R> operator*(const matrix<T, R, C>& m,
    const vector<T, C>& v)
{
    vector<T, R> result;
    for (int i = 0; i < C; ++i) result += m[i] * v[i];
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
            result[i][j] = 0.0;
            for (int k = 0; k < S; ++k) {
                result[i][j] += m1[k][j] * m2[i][k];
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
    matrix<T, D, D> result;
    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < D; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < D; ++k) {
                result[i][j] += m1[k][j] * m2[i][k];
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
    return (m1 *= m2);
}

template<typename T>
constexpr v2<T> operator*(const m2<T>& m, const v2<T>& v) {
    return v.x * m[0] + v.y * m[1];
}

template<typename T>
constexpr v3<T> operator*(const m3<T>& m, const v3<T>& v) {
    return v.x * m[0] + v.y * m[1] + v.z * m[2];
}

template<typename T>
constexpr v4<T> operator*(const m4<T>& m, const v4<T>& v) {
    return v.x * m[0] + v.y * m[1] + v.z * m[2] + v.w * m[3];
}

template<>
constexpr m2f identity() {
    return m2f(1.0, 0.0,  0.0, 1.0);
}

template<>
constexpr m3f identity() {
    return m3f(1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0);
}

template<>
constexpr m4f identity() {
    return m4f(1.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0, 0.0,  0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0);
}

template<typename T, int D1, int D2>
constexpr matrix<T, D1, D2> outerProduct(const vector<T, D1>& v1, const vector<T, D2>& v2) {
    matrix<T, D1, D2> result;
    for (int i = 0; i < D2; ++i) result[i] = v2[i] * v1;
    return result;
}

// https://en.wikipedia.org/wiki/Cross_product#Conversion_to_matrix_multiplication
template<typename T>
constexpr m3<T> crossProduct(const v3<T>& v) {
    return { 0, v.z, -v.y, -v.z, 0, v.x, v.y, -v.x, 0 };
}

}  // namespace vvm