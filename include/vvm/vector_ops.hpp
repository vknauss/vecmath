#pragma once

#include "vector.hpp"


namespace vvm {

// vector-vector binary operators

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v1, const vector<T, D>& v2);


// vector-vector binary operators (+=, etc type)
// return reference to modified vector

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v1, const vector<T, D>& v2);


// vector unary operators
// only negation for now
template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v);


// vector-scalar binary operator
// pre- and post- forms

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D> operator+(const T& s, const vector<T, D>& v);

template<typename T, int D>
constexpr vector<T, D> operator-(const T& s, const vector<T, D>& v);

template<typename T, int D>
constexpr vector<T, D> operator*(const T& s, const vector<T, D>& v);

template<typename T, int D>
constexpr vector<T, D> operator/(const T& s, const vector<T, D>& v);


// vector-scalar binary operators returning modified vector
// only available in the post form

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v, const T& s);

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v, const T& s);


// functions on arbitrary vectors, some might be specialized for 2-4D for performance
template<typename T, int D>
constexpr T dot(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr T length(const vector<T, D>& v);

template<typename T, int D>
constexpr vector<T, D> normalize(const vector<T, D>& v);

template<typename T, int D>
constexpr vector<T, D> min(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D> max(const vector<T, D>& v1, const vector<T, D>& v2);

template<typename T, int D>
constexpr vector<T, D> abs(const vector<T, D>& v);

template<typename T>
constexpr T clamp(const T& v, const T& min, const T& max);

template<typename T, int D>
constexpr vector<T, D> clamp(const vector<T, D>& v, const vector<T, D>& min, const vector<T, D>& max);

template<typename T, int D>
constexpr vector<T, D> lerp(const vector<T, D>& v1, const vector<T, D>& v2, const T& x);

// cross product for 3d
template<typename T>
constexpr v3<T> cross(const v3<T>& v1, const v3<T>& v2);

// various pseduo-cross products for 2d

// returns the z-coordinate of the result of {v1.x, v1.y, 0} x {v2.x, v2.y, 0}
template<typename T>
T cross(const v2<T>& v1, const v2<T>& v2);

// return ({v.x, v.y, 0} x {0, 0, z}).xy
template<typename T>
v2<T> cross(const v2<T>& v, const T& z);

// same as above but order reversed
template<typename T>
v2<T> cross(const T& z, const v2<T>& v);

}

#include "vector_ops.inl"