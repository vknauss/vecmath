#pragma once

#include "matrix_tfm.hpp"

#include <cmath>

#include "matrix_ops.hpp"


namespace vvm {

template <typename T>
constexpr m4<T> translate(const v3<T>& v) {
    return { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, v4<T>(v, 1) };
}

template <typename T>
constexpr m4<T> translate(const v2<T>& v) {
    return { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, v4<T>(v, 0, 1) };
}

// w component of v is ignored
template <typename T>
constexpr m4<T> translate(const v4<T>& v) {
    return { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, v4<T>(v3<T>(v), 1) };
}


template<typename T>
constexpr m2<T> rotate(T angle) {
    T ca(cos(angle)), sa(sin(angle));
    return { ca, sa, -sa, ca };
}

template<typename T>
constexpr m3<T> rotateX(T angle) {
    T ca(cos(angle)), sa(sin(angle));
    return { 1, 0, 0, 0, ca, sa, 0, -sa, ca };
}

template<typename T>
constexpr m3<T> rotateY(T angle) {
    T ca(cos(angle)), sa(sin(angle));
    return { ca, 0, -sa, 0, 1, 0, sa, 0, ca };
}

template<typename T>
constexpr m3<T> rotateZ(T angle) {
    T ca(cos(angle)), sa(sin(angle));
    return { ca, sa, 0, -sa, ca, 0, 0, 0, 1 };
}

// https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle
template<typename T>
constexpr m3<T> rotate(const v3<T>& axis, T angle) {
    auto u = normalize(axis);
    T ca(cos(angle)), mca(1.0 - ca), sa(sin(angle));
    return ca * identity<m3<T>>() + sa * crossProduct(u) +
        mca * outerProduct(u, u);
}

// xyz rotation order
template<typename T>
constexpr m3<T> rotate(const v3<T>& eulerAngles) {
    return rotateZ(eulerAngles.z) * rotateY(eulerAngles.y) *
        rotateX(eulerAngles.x);
}

template<typename T>
constexpr m4<T> scale(const v3<T>& scale) {
    return m4<T>(scale.x, 0, 0, 0,
                 0, scale.y, 0, 0, 
                 0, 0, scale.z, 0,
                 0, 0, 0,       1);
}

template<typename T>
constexpr m4<T> ortho(T zoom, T aspect) {
    return m4<T>(
        zoom / aspect, 0, 0, 0,
        0, zoom, 0, 0,
        0, 0, 0, 1,
        0, 0, 0, 1);
}

// stolen from glm
// https://github.com/g-truc/glm/blob/0.9.5/glm/gtc/matrix_transform.inl#L207-L229
template<typename T>
constexpr m4<T> perspective(T fov, T aspect, T near, T far) {
    T scale = 1.0 / std::tan(0.5 * fov);
    T zscale = -1.0 / (far - near);
    return m4<T>(
        scale / aspect, 0,  0, 0,
        0, scale, 0, 0,
        0, 0, (far + near) * zscale, -1,
        0, 0, 2.0 * far * near * zscale, 0
    );
}

}