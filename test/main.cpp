#include <cstdio>

#include "matrix_ops.hpp"
#include "vvm.hpp"
#include "matrix_tfm.hpp"

using namespace vvm;

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

int main() {
    
    printf("Test printing vectors.\n");
    print(v2f(0, 1));
    print(v3f(2, 3, 4));
    print(v4f(5, 6, 7, 8));

    printf("Test printing matrices.\n");
    print(m2f(0, 1, 2, 3));
    print(m3f(1, 2, 3, 4, 5, 6, 7, 8, 9));
    print(m4f(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));

    printf("Test printing matrices constructed from columns.\n");
    print(m2f({0, 1}, {2, 3}));
    print(m3f({1, 2, 3}, {4, 5, 6}, {7, 8, 9}));
    print(m4f({1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}));

    printf("Test identity matrices.\n");
    print(identity<m2f>());
    print(identity<m3f>());
    print(identity<m4f>());

    printf("Test transformations.\n");
    print(translate(v3d(1, 2, 3)));

    return 0;
}