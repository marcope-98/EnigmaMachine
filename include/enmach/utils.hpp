#ifndef ENMACH_UTILS_HPP_
#define ENMACH_UTILS_HPP_

#include <string_view>

#include "enmach/types.hpp"

namespace enmach::rotors
{
  using namespace std::literals;
  inline constexpr Rotor i     = "ekmflgdqvzntowyhxuspaibrcj"sv;
  inline constexpr Rotor ii    = "ajdksiruxblhwtmcqgznpyfvoe"sv;
  inline constexpr Rotor iii   = "bdfhjlcprtxvznyeiwgakmusqo"sv;
  inline constexpr Rotor iv    = "esovpzjayquirhxlnftgkdcmwb"sv;
  inline constexpr Rotor v     = "vzbrgityupsdnhlxawmjqofeck"sv;
  inline constexpr Rotor vi    = "jpgvoumfyqbenhzrdkasxlictw"sv;
  inline constexpr Rotor vii   = "nzjhgrcxmyswboufaivlpekqdt"sv;
  inline constexpr Rotor viii  = "fkqhtlxocbjspdzramewniuygv"sv;
  inline constexpr Rotor beta  = "leyjvcnixwpbqmdrtakzgfuhos"sv;
  inline constexpr Rotor gamma = "fsokanuerhmbtiycwlqpzxvgjd"sv;
} // namespace enmach::rotors

namespace enmach::reflectors
{
  using namespace std::literals;
  inline constexpr Reflector b      = "yruhqsldpxngokmiebfzcwvjat"sv;
  inline constexpr Reflector c      = "fvpjiaoyedrzxwgctkuqsbnmhl"sv;
  inline constexpr Reflector b_dunn = "enkqauywjicopblmdxzvfthrgs"sv;
  inline constexpr Reflector c_dunn = "rdobjntkvehmlfcwzaxgyipsuq"sv;
} // namespace enmach::reflectors

#endif // ENMACH_UTILS_HPP_