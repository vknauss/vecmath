#pragma once

#include "matrix.hpp"
#include "vector.hpp"

#include <string>

namespace vvm {

template<typename T>
std::string to_string(const T&);

// inl

template<typename T, int D>
std::string to_string(const vector<T, D>& v) {
    std::string r("vec");
    r += std::to_string(D) + "(";
    for (int i = 0; i < D; ++i) {
        r += std::to_string(v[i]);
        if (i < D-1) r += ", ";
    }
    r += ")";
    return r;
}

template<typename T, int R, int C>
std::string to_string(const matrix<T, R, C>& m) {
    std::string r("mat");
    r += std::to_string(R) + "x" + std::to_string(C) + "(";
    for (int i = 0; i < C; ++i) {
        r += to_string(m[i]);
        if (i < C-1) r += ", ";
    }
    r += ")";
    return r;
}

}  // namespace vvm