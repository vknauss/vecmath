#pragma once

namespace vvm {

template<typename T, int D> struct vector;

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

    const T& operator[](int i) const { return data[i]; };
    T& operator[](int i) { return data[i]; };

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
        
    const T& operator[](int i) const { return data[i]; };
    T& operator[](int i) { return data[i]; };
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
        
    const T& operator[](int i) const { return data[i]; };
    T& operator[](int i) { return data[i]; };
};

// typedefs for very common specializations

template<typename T>
using v2 = vector<T, 2>;
using v2f = v2<float>;

template<typename T>
using v3 = vector<T, 3>;
using v3f = v3<float>;

template<typename T>
using v4 = vector<T, 4>;
using v4f = v4<float>;

}  // namespace vvm

#include "vector_ops.inl"