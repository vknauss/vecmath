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


// cross product only defined for 3D
template<typename T>
constexpr v3<T> cross(const v3<T>& v1, const v3<T>& v2);

}

#include "vector_ops.inl"