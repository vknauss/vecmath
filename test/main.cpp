#include <cstdio>

#include "vm/vm.hpp"

int main() {
    printf("Hello World.\n");

    vm::v2 v(1, 2);

    vm::m2 m;
    m.cols[0] = {1, 1};
    m.cols[1] = {0, 2};

    auto v1 = m * v;

    printf("%f, %f\n", v1.x, v1.y);

    return 0;
}