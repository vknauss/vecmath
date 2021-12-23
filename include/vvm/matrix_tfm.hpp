#pragma once

#include "matrix.hpp"


namespace vvm {

template <typename mat_t, typename vec_t>
constexpr mat_t translate(const vec_t& v);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotate(T angle);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotateX(T angle);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotateY(T angle);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotateZ(T angle);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotate(const v3<T>& axis, T angle);

template<typename T, template<typename TT> typename m>
constexpr m<T> rotate(const v3<T>& eulerAngles);

template<typename T, template<typename TT> typename m>
constexpr m<T> scale(const v3<T>& scale);

template<typename T>
constexpr m4<T> ortho(T zoom, T aspect);

};

#include "matrix_tfm.inl"