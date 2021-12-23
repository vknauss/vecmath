#pragma once

#include "matrix.hpp"


namespace vvm {


// matrix-vector multiplication, implemented as defined in linear algebra
// vectors are interpreted exclusivly as column vectors
template<typename T, int R, int C>
constexpr vector<T, R> operator*(const matrix<T, R, C>& m, const vector<T, C>& v);


// matrix-matrix multiplication, m1 must have the same number of columns that
// m2 has rows
template<typename T, int R1, int S, int C2>
constexpr matrix<T, R1, C2> operator*(const matrix<T, R1, S>& m1, const matrix<T, S, C2>& m2);


// post multiply m1 by m2 and return m1
template<typename T, int R1, int S, int C2>
constexpr matrix<T, R1, C2>& operator*=(matrix<T, R1, S>& m1, const matrix<T, S, C2>& m2);


template<typename mat_t>
constexpr mat_t identity();

template<typename T, int D1, int D2>
constexpr matrix<T, D1, D2> outerProduct(const vector<T, D1>& v1, const vector<T, D2>& v2);

template<typename T>
constexpr m3<T> crossProduct(const v3<T>& v);

template<typename T, int R, int C>
constexpr matrix<T, R, C> abs(const matrix<T, R, C>& m);

template<typename T, int R, int C>
constexpr matrix<T, C, R> transpose(const matrix<T, R, C>& m);


};

#include "matrix_ops.inl"