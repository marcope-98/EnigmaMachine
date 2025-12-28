#ifndef ENMACH_UTILS_HPP_
#define ENMACH_UTILS_HPP_

#include <string_view>

#include "enmach/types.hpp"

namespace enmach::rotors
{
  using namespace std::literals;
  inline constexpr Rotor I     = "ekmflgdqvzntowyhxuspaibrcj"sv;
  inline constexpr Rotor II    = "ajdksiruxblhwtmcqgznpyfvoe"sv;
  inline constexpr Rotor III   = "bdfhjlcprtxvznyeiwgakmusqo"sv;
  inline constexpr Rotor IV    = "esovpzjayquirhxlnftgkdcmwb"sv;
  inline constexpr Rotor V     = "vzbrgityupsdnhlxawmjqofeck"sv;
  inline constexpr Rotor VI    = "jpgvoumfyqbenhzrdkasxlictw"sv;
  inline constexpr Rotor VII   = "nzjhgrcxmyswboufaivlpekqdt"sv;
  inline constexpr Rotor VIII  = "fkqhtlxocbjspdzramewniuygv"sv;
  inline constexpr Rotor BETA  = "leyjvcnixwpbqmdrtakzgfuhos"sv;
  inline constexpr Rotor GAMMA = "fsokanuerhmbtiycwlqpzxvgjd"sv;
} // namespace enmach::rotors

namespace enmach::reflectors
{
  using namespace std::literals;
  inline constexpr Reflector B      = "yruhqsldpxngokmiebfzcwvjat"sv;
  inline constexpr Reflector C      = "fvpjiaoyedrzxwgctkuqsbnmhl"sv;
  inline constexpr Reflector B_DUNN = "enkqauywjicopblmdxzvfthrgs"sv;
  inline constexpr Reflector C_DUNN = "rdobjntkvehmlfcwzaxgyipsuq"sv;
} // namespace enmach::reflectors

#endif // ENMACH_UTILS_HPP_