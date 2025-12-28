#ifndef ENMACH_TYPES_HPP_
#define ENMACH_TYPES_HPP_

#include <string_view>
#include <tuple>

#include "enmach/common.hpp"

namespace enmach
{
  using RotorsConfiguration = std::tuple<std::size_t, std::size_t, std::size_t>;

  struct Rotor : public std::string_view
  {
    constexpr Rotor(std::string_view sv) : std::string_view{sv} {}
    [[nodiscard]] constexpr auto forward(char letter) const -> char { return this->at(enmach::input.find(letter)); }
    [[nodiscard]] constexpr auto inverse(char letter) const -> char { return enmach::input.at(this->find(letter)); }

    constexpr auto step(std::size_t &increment) -> void
    {
      this->rotor_position = (this->rotor_position + increment) % enmach::input.size();
      increment            = static_cast<std::size_t>(this->rotor_position == 0 && increment == 1U);
    }

    constexpr auto getConfiguration() const -> std::size_t { return this->rotor_position; }
    constexpr auto setConfiguration(std::size_t configuration) -> void { this->rotor_position = configuration; }

  private:
    std::size_t rotor_position{};
  };

  struct Reflector : public std::string_view
  {
    constexpr Reflector(std::string_view sv) : std::string_view{sv} {}
    [[nodiscard]] constexpr auto reflect(char letter) const -> char { return this->at(enmach::input.find(letter)); }
  };

} // namespace enmach

#endif // ENMACH_TYPES_HPP_