#ifndef ENMACH_ROTOR_HPP_
#define ENMACH_ROTOR_HPP_

#include <string_view>

#include "enmach/common.hpp"

namespace enmach::rotor_tags
{
  using namespace std::literals;
  // clang-format off
  struct I     { constexpr static std::string_view fvalue = "ekmflgdqvzntowyhxuspaibrcj"sv, rvalue = "uwygadfpvzbeckmthxslrinqoj"sv; };
  struct II    { constexpr static std::string_view fvalue = "ajdksiruxblhwtmcqgznpyfvoe"sv, rvalue = "ajpczwrlfbdkotyuqgenhxmivs"sv, notch = "r"sv; };
  struct III   { constexpr static std::string_view fvalue = "bdfhjlcprtxvznyeiwgakmusqo"sv, rvalue = "tagbpcsdqeufvnzhyixjwlrkom"sv, notch = "w"sv; };
  struct IV    { constexpr static std::string_view fvalue = "esovpzjayquirhxlnftgkdcmwb"sv, rvalue = "hzwvartnlgupxqcejmbskdyoif"sv; };
  struct V     { constexpr static std::string_view fvalue = "vzbrgityupsdnhlxawmjqofeck"sv, rvalue = "qcylxwenftzosmvjudkgiarphb"sv, notch = "f"sv; };
  struct VI    { constexpr static std::string_view fvalue = "jpgvoumfyqbenhzrdkasxlictw"sv, rvalue = "skxqlhcnwarvgmebjptyfdzuio"sv; };
  struct VII   { constexpr static std::string_view fvalue = "nzjhgrcxmyswboufaivlpekqdt"sv, rvalue = "qmgyvpedrcwtianuxfkzoslhjb"sv; };
  struct VIII  { constexpr static std::string_view fvalue = "fkqhtlxocbjspdzramewniuygv"sv, rvalue = "qjinsaydvkbfruhmcplewztgxo"sv; };
  struct BETA  { constexpr static std::string_view fvalue = "leyjvcnixwpbqmdrtakzgfuhos"sv, rvalue = "rlfobvuxhdsangykmpzqwejict"sv; };
  struct GAMMA { constexpr static std::string_view fvalue = "fsokanuerhmbtiycwlqpzxvgjd"sv, rvalue = "elpzhaxjnydrkfctsibmgwqvou"sv; };
  // clang-format on
} // namespace enmach::rotor_tags

namespace enmach
{
  template<class RotorTag>
  struct Rotor
  {
  public:
    [[nodiscard]] constexpr auto forward(std::size_t index) const -> std::size_t
    {
      index = (index + this->position_ + enmach::ETW.size() - this->ringstellung_) % enmach::ETW.size();
      index = static_cast<std::size_t>(RotorTag::fvalue.at(index) - 'a');
      index = (index + enmach::ETW.size() - this->position_ + this->ringstellung_) % enmach::ETW.size();
      return index;
    }

    [[nodiscard]] constexpr auto inverse(std::size_t index) const -> std::size_t
    {
      index = (index + this->position_ + enmach::ETW.size() - this->ringstellung_) % enmach::ETW.size();
      index = static_cast<std::size_t>(RotorTag::rvalue.at(index) - 'a');
      index = (index + enmach::ETW.size() - this->position_ + this->ringstellung_) % enmach::ETW.size();
      return index;
    }

    [[nodiscard]] constexpr auto increment(bool condition) -> bool
    {
      this->position_ = (this->position_ + static_cast<std::size_t>(condition)) % enmach::ETW.size();
      return condition && RotorTag::notch.find(ETW.at(this->position_)) != std::string_view::npos;
    }

    constexpr auto setInitialPosition(char initial_position) -> void { this->position_ = static_cast<std::size_t>(initial_position - 'a'); }
    constexpr auto setRingstellung(char ringstellung) -> void { this->ringstellung_ = static_cast<std::size_t>(ringstellung - 'a'); }

  private:
    std::size_t position_{};
    std::size_t ringstellung_{};
  };
} // namespace enmach
#endif // ENMACH_ROTOR_HPP_