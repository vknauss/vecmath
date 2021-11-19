#pragma once

#include "matrix.hpp"


namespace vvm {

template <typename mat_t, typename vec_t>
constexpr mat_t translate(const vec_t& v);

template<typename T>
constexpr m2<T> rotate(T angle);

template<typename T>
constexpr m3<T> rotateX(T angle);

template<typename T>
constexpr m3<T> rotateY(T angle);

template<typename T>
constexpr m3<T> rotateZ(T angle);

template<typename T>
constexpr m3<T> rotate(const v3<T>& axis, T angle);

template<typename T>
constexpr m3<T> rotate(const v3<T>& eulerAngles);

};

#include "matrix_tfm.inl"