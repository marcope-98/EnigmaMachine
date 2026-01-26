#ifndef ENMACH_UTILS_HPP_
#define ENMACH_UTILS_HPP_

#include <tuple>
#include <utility>

namespace enmach
{
  template<class Tuple, std::size_t... Is>
  constexpr auto reverse_tuple_impl(Tuple &&t, std::index_sequence<Is...>)
  {
    return std::make_tuple(std::get<sizeof...(Is) - 1 - Is>(std::forward<Tuple>(t))...);
  }

  template<class Tuple>
  constexpr auto reverse_tuple(Tuple &&t)
  {
    constexpr std::size_t N = std::tuple_size<std::decay_t<Tuple>>::value;
    return reverse_tuple_impl(std::forward<Tuple>(t), std::make_index_sequence<N>{});
  }
} // namespace enmach

#endif // ENMACH_UTILS_HPP_