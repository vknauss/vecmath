#pragma once

namespace vvm {

template<typename T, int D> struct vector;

// specializations for common vector sizes
// constructors are there to make these easy to build and convert between

template<typename T>
struct vector<T, 2> {

    using component_t = T;
    
    static constexpr int dimension = 2;

    union {
        T data[2];
        struct {
            T x, y;
        };
    };


    constexpr vector() { }

    constexpr vector(T x, T y) :
        data {x, y} { }

    explicit constexpr vector(T v) :
        data {v, v} { }

    explicit constexpr vector(const vector<T, 3>& v) :
        data {v.x, v.y} { }

    explicit constexpr vector(const vector<T, 4>& v) :
        data {v.x, v.y} { }
    

    constexpr const T& operator[](int i) const { return data[i]; };

    T& operator[](int i) { return data[i]; };

};

template<typename T>
struct vector<T, 3> {
    
    using component_t = T;
    
    static constexpr int dimension = 3;

    union {
        T data[3];
        struct {
            T x, y, z;
        };
    };


    constexpr vector() { }

    constexpr vector(T x, T y, T z) :
        data {x, y, z} { }

    explicit constexpr vector(T v) :
        data {v, v, v} { }

    constexpr vector(const vector<T, 2>& v, T z) :
        data {v.x, v.y, z} { }

    constexpr vector(const vector<T, 4>& v) :
        data {v.x, v.y, v.z} { }


    constexpr const T& operator[](int i) const { return data[i]; };

    T& operator[](int i) { return data[i]; };
};

template<typename  T>
struct vector<T, 4> {
    
    using component_t = T;
    
    static constexpr int dimension = 4;

    union {
        T data[4];
        struct {
            T x, y, z, w;
        };
    };


    constexpr vector() { }

    constexpr vector(T x, T y, T z, T w) :
        data {x, y, z, w} { }

    explicit constexpr vector(T v) :
        data {v, v, v, v} { }

    constexpr vector(const vector<T, 2>& v, T z, T w) :
        data {v.x, v.y, z, w} { }

    constexpr vector(const vector<T, 3>& v, T w) :
        data {v.x, v.y, v.z, w} { }
        

    constexpr const T& operator[](int i) const { return data[i]; };

    T& operator[](int i) { return data[i]; };
};

// aliases for very common specializations

template<typename T> using v2 = vector<T, 2>;
template<typename T> using v3 = vector<T, 3>;
template<typename T> using v4 = vector<T, 4>;

using v2f = v2<float>;
using v3f = v3<float>;
using v4f = v4<float>;

using v2d = v2<double>;
using v3d = v3<double>;
using v4d = v4<double>;

}  // namespace vvm
