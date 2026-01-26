#ifndef ENMACH_UTILS_HPP_
#define ENMACH_UTILS_HPP_

#include <tuple>
#include <type_traits>
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

  template<class...>
  inline constexpr auto is_unique = std::true_type{};

  template<class T, class... Args>
  inline constexpr auto is_unique<T, Args...> = std::bool_constant<(!std::is_same_v<T, Args> && ...) && is_unique<Args...>>{};

  template<class... Tags>
  struct Set
  {
    template<class Needle>
    constexpr static bool is_in_set()
    {
      return (std::is_same_v<Needle, Tags> || ...);
    }
  };

} // namespace enmach

#endif // ENMACH_UTILS_HPP_