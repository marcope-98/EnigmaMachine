#ifndef ENMACH_REFLECTOR_HPP_
#define ENMACH_REFLECTOR_HPP_

#include <string_view>

#include "enmach/common.hpp"

namespace enmach::reflector_tags
{
  using namespace std::literals;
  // clang-format off
  struct B      { constexpr static std::string_view value = "yruhqsldpxngokmiebfzcwvjat"sv; }; 
  struct C      { constexpr static std::string_view value = "fvpjiaoyedrzxwgctkuqsbnmhl"sv; }; 
  struct B_DUNN { constexpr static std::string_view value = "enkqauywjicopblmdxzvfthrgs"sv; }; 
  struct C_DUNN { constexpr static std::string_view value = "rdobjntkvehmlfcwzaxgyipsuq"sv; }; 
  // clang-format on 
} // namespace enmach::reflector_tags

namespace enmach
{
  template<class ReflectorTag>
  struct Reflector
  {
    [[nodiscard]] constexpr auto reflect(char letter) const -> char { return ReflectorTag::value.at(enmach::ETW.find(letter)); }
  };
} // namespace enmach

#endif // ENMACH_REFLECTOR_HPP_