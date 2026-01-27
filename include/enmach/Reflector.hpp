#ifndef ENMACH_REFLECTOR_HPP_
#define ENMACH_REFLECTOR_HPP_

#include <string_view>

#include "enmach/common.hpp"

namespace enmach::reflector_tags
{
  using namespace std::literals;
  // clang-format off
  struct UKW_A  { constexpr static std::string_view value = "ejmzalyxvbwfcrquontspikhgd"sv; };
  struct UKW_B  { constexpr static std::string_view value = "yruhqsldpxngokmiebfzcwvjat"sv; }; 
  struct UKW_C  { constexpr static std::string_view value = "fvpjiaoyedrzxwgctkuqsbnmhl"sv; }; 
  struct B_DUNN { constexpr static std::string_view value = "enkqauywjicopblmdxzvfthrgs"sv; }; 
  struct C_DUNN { constexpr static std::string_view value = "rdobjntkvehmlfcwzaxgyipsuq"sv; }; 
  // clang-format on 
} // namespace enmach::reflector_tags

namespace enmach
{
  template<class ReflectorTag>
  struct Reflector
  {
    [[nodiscard]] constexpr auto reflect(std::size_t index) const -> std::size_t { return static_cast<std::size_t>(ReflectorTag::value.at(index) - 'a'); }
  };
} // namespace enmach

#endif // ENMACH_REFLECTOR_HPP_