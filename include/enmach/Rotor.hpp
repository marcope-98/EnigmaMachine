#ifndef ENMACH_ROTOR_HPP_
#define ENMACH_ROTOR_HPP_

#include <string_view>

#include "enmach/common.hpp"

namespace enmach::rotor_tags
{
  using namespace std::literals;
  // clang-format off
  struct I     { constexpr static std::string_view value = "ekmflgdqvzntowyhxuspaibrcj"sv; };
  struct II    { constexpr static std::string_view value = "ajdksiruxblhwtmcqgznpyfvoe"sv; };
  struct III   { constexpr static std::string_view value = "bdfhjlcprtxvznyeiwgakmusqo"sv; };
  struct IV    { constexpr static std::string_view value = "esovpzjayquirhxlnftgkdcmwb"sv; };
  struct V     { constexpr static std::string_view value = "vzbrgityupsdnhlxawmjqofeck"sv; };
  struct VI    { constexpr static std::string_view value = "jpgvoumfyqbenhzrdkasxlictw"sv; };
  struct VII   { constexpr static std::string_view value = "nzjhgrcxmyswboufaivlpekqdt"sv; };
  struct VIII  { constexpr static std::string_view value = "fkqhtlxocbjspdzramewniuygv"sv; };
  struct BETA  { constexpr static std::string_view value = "leyjvcnixwpbqmdrtakzgfuhos"sv; };
  struct GAMMA { constexpr static std::string_view value = "fsokanuerhmbtiycwlqpzxvgjd"sv; };
  // clang-format on
} // namespace enmach::rotor_tags

namespace enmach
{
  template<class RotorTag>
  struct Rotor
  {
  public:
    [[nodiscard]] constexpr auto forward(char letter) const -> char
    {
      return RotorTag::value.at(enmach::ETW.find(letter));
    }

    [[nodiscard]] constexpr auto inverse(char letter) const -> char
    {
      return enmach::ETW.at(RotorTag::value.find(letter));
    }

    [[nodiscard]] constexpr auto increment(bool condition) -> bool
    {
      return condition && this->position_ == 0;
    }

    constexpr auto setInitialPosition(std::size_t initial_position) -> void { this->position_ = initial_position; }
    constexpr auto setRingstellung(char ringstellung) -> void { this->ringstellung_ = ETW.find(ringstellung); }

  private:
    std::size_t position_{};
    std::size_t ringstellung_{};
  };
} // namespace enmach
#endif // ENMACH_ROTOR_HPP_