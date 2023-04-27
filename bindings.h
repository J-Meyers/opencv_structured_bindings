#pragma once

#ifndef OPENCV_STRUCTURED_BINDINGS_H
#define OPENCV_STRUCTURED_BINDINGS_H

#include <type_traits>

namespace cv {

template <typename T, int cn> class Vec;

template <std::size_t I, typename T, int cn>
constexpr T &get(Vec<T, cn> &v) noexcept {
  static_assert(I < cn, "Vec index is within bounds");
  return v[I];
}

template <std::size_t I, typename T, int cn>
constexpr T &&get(Vec<T, cn> &&v) noexcept {
  static_assert(I < cn, "Vec index is within bounds");
  return std::move(v[I]);
}

template <std::size_t I, typename T, int cn>
constexpr const T &get(const Vec<T, cn> &v) noexcept {
  static_assert(I < cn, "Vec index is within bounds");
  return v[I];
}

template <std::size_t I, typename T, int cn>
constexpr const T &&get(const Vec<T, cn> &&v) noexcept {
  static_assert(I < cn, "Vec index is within bounds");
  return std::move(v[I]);
}
} // namespace cv

namespace std {

template <typename T, int cn>
struct tuple_size<cv::Vec<T, cn>> : std::integral_constant<std::size_t, cn> {};

template <std::size_t I, typename T, int cn>
struct tuple_element<I, cv::Vec<T, cn>> {
  using type = T;
};

} // namespace std

#endif // OPENCV_STRUCTURED_BINDINGS_H
