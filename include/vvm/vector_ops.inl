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

template<typename T>
constexpr T clamp(const T& v, const T& min, const T& max) {
    return v < min ? min : (v > max ? max : v);
}

template<typename T, int D>
constexpr vector<T, D> clamp(const vector<T, D>& v, const vector<T, D>& min, const vector<T, D>& max) {
    vector<T, D> result;
    for (int i = 0; i < D; ++i) {
        result[i] = clamp(v[i], min[i], max[i]);
    }
    return result;
}

template<typename T1, typename T2>
constexpr T1 lerp(const T1& v1, const T1& v2, const T2& x) {
    return ((T2) 1.0 - x) * v1 + x * v2;
}

template<typename T, int D>
constexpr vector<T, D> lerp(const vector<T, D>& v1, const vector<T, D>& v2, const T& x) {
    vector<T, D> result;
    T x0 = (T) 1.0 - x;
    for (int i = 0; i < D; ++i) {
        result[i] = v1[i] * x0 + v2[i] * x;
    }
    return result;
}

template<typename T>
constexpr v3<T> cross(const v3<T>& v1, const v3<T>& v2) {
    return v3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

template<typename T>
constexpr T cross(const v2<T>& v1, const v2<T>& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

template<typename T>
constexpr v2<T> cross(const v2<T>& v, const T& z) {
    return v2<T>(v.y * z, -v.x * z);
}

template<typename T>
constexpr v2<T> cross(const T& z, const v2<T>& v) {
    return v2<T>(-v.y * z, v.x * z);
}
}  // namespace vvm