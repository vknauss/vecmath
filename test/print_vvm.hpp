#pragma once

#include <vvm.hpp>

namespace vvm {

template<typename T>
void print(const v2<T>& v) {
    printf("v2(%.4f, %.4f)\n",
        v.x, v.y);
}

template<typename T>
void print(const v3<T>& v) {
    printf("v3(%.4f, %.4f, %.4f)\n",
        v.x, v.y, v.z);
}

template<typename T>
void print(const v4<T>& v) {
    printf("v4(%.4f, %.4f, %.4f, %.4f)\n",
        v.x, v.y, v.z, v.w);
}

template<typename T>
void print(const m2<T>& m) {
    printf("m2((%.4f, %.4f),\n\
    (%.4f, %.4f))\n",
        m[0][0], m[0][1],
        m[1][0], m[1][1]);
}

template<typename T>
void print(const m3<T>& m) {
    printf("m3((%.4f, %.4f, %.4f),\n\
    (%.4f, %.4f, %.4f),\n\
    (%.4f, %.4f, %.4f))\n",
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2]);
}

template<typename T>
void print(const m4<T>& m) {
    printf("m4((%.4f, %.4f, %.4f, %.4f),\n\
    (%.4f, %.4f, %.4f, %.4f),\n\
    (%.4f, %.4f, %.4f, %.4f),\n\
    (%.4f, %.4f, %.4f, %.4f))\n",
        m[0][0], m[0][1], m[0][2], m[0][3],
        m[1][0], m[1][1], m[1][2], m[1][3],
        m[2][0], m[2][1], m[2][2], m[2][3],
        m[3][0], m[3][1], m[3][2], m[3][3]);
}

}