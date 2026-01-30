#ifndef ENMACH_REFLECTOR_HPP_
#define ENMACH_REFLECTOR_HPP_

#include <array>

#define EJMZALYXVBWFCRQUONTSPIKHGD "\x04\x09\x0c\x19\x00\x0b\x18\x17\x15\x01\x16\x05\x02\x11\x10\x14\x0e\x0d\x13\x12\x0f\x08\x0a\x07\x06\x03"
#define YRUHQSLDPXNGOKMIEBFZCWVJAT "\x18\x11\x14\x07\x10\x12\x0b\x03\x0f\x17\x0d\x06\x0e\x0a\x0c\x08\x04\x01\x05\x19\x02\x16\x15\x09\x00\x13"
#define FVPJIAOYEDRZXWGCTKUQSBNMHL "\x05\x15\x0f\x09\x08\x00\x0e\x18\x04\x03\x11\x19\x17\x16\x06\x02\x13\x0a\x14\x10\x12\x01\x0d\x0c\x07\x0b"
#define ENKQAUYWJICOPBLMDXZVFTHRGS "\x04\x0d\x0a\x10\x00\x14\x18\x16\x09\x08\x02\x0e\x0f\x01\x0b\x0c\x03\x17\x19\x15\x05\x13\x07\x11\x06\x12"
#define RDOBJNTKVEHMLFCWZAXGYIPSUQ "\x11\x03\x0e\x01\x09\x0d\x13\x0a\x15\x04\x07\x0c\x0b\x05\x02\x16\x19\x00\x17\x06\x18\x08\x0f\x12\x14\x10"

namespace enmach::ukw
{
  // clang-format off
  struct A  { constexpr static std::array<std::uint8_t, 27> value = { EJMZALYXVBWFCRQUONTSPIKHGD }; };
  struct B  { constexpr static std::array<std::uint8_t, 27> value = { YRUHQSLDPXNGOKMIEBFZCWVJAT }; }; 
  struct C  { constexpr static std::array<std::uint8_t, 27> value = { FVPJIAOYEDRZXWGCTKUQSBNMHL }; }; 
  struct b  { constexpr static std::array<std::uint8_t, 27> value = { ENKQAUYWJICOPBLMDXZVFTHRGS }; }; 
  struct c  { constexpr static std::array<std::uint8_t, 27> value = { RDOBJNTKVEHMLFCWZAXGYIPSUQ }; }; 
  // clang-format on 
} // namespace enmach::ukw

namespace enmach
{
  template<class ReflectorTag>
  struct Reflector
  {
    [[nodiscard]] constexpr auto reflect(std::uint8_t index) const -> std::uint8_t { return ReflectorTag::value[index]; }
  };
} // namespace enmach

#endif // ENMACH_REFLECTOR_HPP_