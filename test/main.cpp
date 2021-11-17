#include <cstdio>

#include "vvm.hpp"

using namespace vvm;

int main() {
    printf("Hello World.\n");

    v2 v(1, 2);

    m2 m;
    m.cols[0] = {1, 1};
    m.cols[1] = {0, 2};

    auto v1 = m * v;

    printf("%f, %f\n", v1.x, v1.y);

    return 0;
}