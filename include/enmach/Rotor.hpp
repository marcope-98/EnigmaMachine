#ifndef ENMACH_ROTOR_HPP_
#define ENMACH_ROTOR_HPP_

#include <string_view>

#include "enmach/common.hpp"

namespace enmach::rotor_tags
{
  using namespace std::literals;
  // clang-format off
  struct I     { constexpr static std::string_view value = "ekmflgdqvzntowyhxuspaibrcj"sv; };
  struct II    { constexpr static std::string_view value = "ajdksiruxblhwtmcqgznpyfvoe"sv; constexpr static std::string_view notch = "r"sv; };
  struct III   { constexpr static std::string_view value = "bdfhjlcprtxvznyeiwgakmusqo"sv; constexpr static std::string_view notch = "w"sv; };
  struct IV    { constexpr static std::string_view value = "esovpzjayquirhxlnftgkdcmwb"sv; };
  struct V     { constexpr static std::string_view value = "vzbrgityupsdnhlxawmjqofeck"sv; constexpr static std::string_view notch = "f"sv; };
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
      letter = enmach::ETW.at((enmach::ETW.find(letter) + this->position_ + enmach::ETW.size() - this->ringstellung_) % enmach::ETW.size());
      letter = RotorTag::value.at(enmach::ETW.find(letter));
      letter = enmach::ETW.at((enmach::ETW.find(letter) + enmach::ETW.size() - this->position_ + this->ringstellung_) % enmach::ETW.size());
      return letter;
    }

    [[nodiscard]] constexpr auto inverse(char letter) const -> char
    {
      letter = enmach::ETW.at((enmach::ETW.find(letter) + this->position_ + enmach::ETW.size() - this->ringstellung_) % enmach::ETW.size());
      letter = enmach::ETW.at(RotorTag::value.find(letter));
      letter = enmach::ETW.at((enmach::ETW.find(letter) + enmach::ETW.size() - this->position_ + this->ringstellung_) % enmach::ETW.size());
      return letter;
    }

    [[nodiscard]] constexpr auto increment(bool condition) -> bool
    {
      this->position_ = (this->position_ + static_cast<std::size_t>(condition)) % enmach::ETW.size();
      return condition && RotorTag::notch.find(ETW.at(this->position_)) != std::string_view::npos;
    }

    constexpr auto setInitialPosition(char initial_position) -> void { this->position_ = ETW.find(initial_position); }
    constexpr auto setRingstellung(char ringstellung) -> void { this->ringstellung_ = ETW.find(ringstellung); }

  private:
    std::size_t position_{};
    std::size_t ringstellung_{};
  };
} // namespace enmach
#endif // ENMACH_ROTOR_HPP_