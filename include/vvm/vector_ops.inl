#pragma once

#include "vector_ops.hpp"

#include <cmath>


namespace vvm {

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] + v2[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] - v2[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] * v2[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v1,
    const vector<T, D>& v2)
{
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] / v2[i];
    return result;
}

// vector-vector binary operators (+=, etc type)
// return reference to modified vector

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1[i] += v2[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1[i] -= v2[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1[i] *= v2[i];
    return v1;
}

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v1, const vector<T, D>& v2) {
    for (int i = 0; i < D; ++i) v1[i] /= v2[i];
    return v1;
}

// vector unary operators
// only negation for now
template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = -v[i];
    return result;
}

// vector-scalar binary operators
// return newly constructed vector
// pre- and post- forms have typical meanings, e.g. s * v = v * s
// but s / v =/= v / s

template<typename T, int D>
constexpr vector<T, D> operator+(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v[i] + s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v[i] - s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v[i] * s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const vector<T, D>& v, const T& s) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v[i] / s;
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator+(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = s + v[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator-(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = s - v[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator*(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = s * v[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> operator/(const T& s, const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = s / v[i];
    return result;
}

// vector-scalar in place binary operators
// only available in the post form, obviously
// ( 2.0 += v2(4.0, 5.0) ? who wants that? )

template<typename T, int D>
constexpr vector<T, D>& operator+=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v[i] += s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator-=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v[i] -= s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator*=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v[i] *= s;
    return v;
}

template<typename T, int D>
constexpr vector<T, D>& operator/=(vector<T, D>& v, const T& s) {
    for (int i = 0; i < D; ++i) v[i] /= s;
    return v;
}

template<typename T, int D>
constexpr T dot(const vector<T, D>& v1, const vector<T, D>& v2) {
    T sum = 0.0;
    for (int i = 0; i < D; ++i) sum += v1[i] * v2[i];
    return sum;
}

template<typename T>
constexpr v3<T> cross(const v3<T>& v1, const v3<T>& v2) {
    return v3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}

template<typename T>
constexpr T dot(const v2<T>& v1, const v2<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

template<typename T>
constexpr T dot(const v3<T>& v1, const v3<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
constexpr T dot(const v4<T>& v1, const v4<T>& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

template<typename T, int D>
constexpr T length(const vector<T, D>& v) {
    T sum = 0.0;
    for (int i = 0; i < D; ++i) sum += v[i] * v[i];
    return sqrt(sum);
}

template<typename T, int D>
constexpr vector<T, D> normalize(const vector<T, D>& v) {
    return v / length(v);
}

template<typename T, int D>
constexpr vector<T, D> min(const vector<T, D>& v1, const vector<T, D>& v2) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> max(const vector<T, D>& v1, const vector<T, D>& v2) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v1[i] > v2[i] ? v1[i] : v2[i];
    return result;
}

template<typename T, int D>
constexpr vector<T, D> abs(const vector<T, D>& v) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) result[i] = v[i] >= 0 ? v[i] : -v[i];
    return result;
}

}  // namespace vvm