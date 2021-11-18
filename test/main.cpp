#include <cstdio>

#include "vvm.hpp"

using namespace vvm;

int main() {
    printf("Hello World.\n");

    v2 v(1, 2);

    m2 m;
    m.cols[0] = {1, 2};
    m.cols[1] = {3, 4};

    auto v1 = m * v;

    m2 m2;
    m2.cols[0] = {5, 6};
    m2.cols[1] = {7, 8};

    auto m3 = m * m2;

    printf("%f, %f\n", v1.x, v1.y);

    
    printf("[[%f, %f], [%f, %f]]\n", m3.cols[0].data[0], m3.cols[0].data[1], m3.cols[1].data[0], m3.cols[1].data[1]);

    return 0;
}