#ifndef ENMACH_ENIGMAMACHINE_HPP_
#define ENMACH_ENIGMAMACHINE_HPP_
#include <string_view>

#include "enmach/types.hpp"

namespace enmach
{
  class EnigmaMachine
  {
  public:
    constexpr EnigmaMachine(Rotor left, Rotor middle, Rotor right,
                            Reflector reflector) : left_{left},
                                                   middle_{middle},
                                                   right_{right},
                                                   reflector_{reflector} {}

    [[nodiscard]] constexpr auto exec(char letter) -> char
    {
      this->increment_rotors();
      return this->inverse(this->reflect(this->forward(letter)));
    }
    constexpr auto setRotorsConfiguration(const RotorsConfiguration &configuration) -> void
    {
      this->left_.setConfiguration(std::get<0>(configuration));
      this->middle_.setConfiguration(std::get<1>(configuration));
      this->right_.setConfiguration(std::get<2>(configuration));
    }

    constexpr auto getRotorsConfigurations() const -> RotorsConfiguration
    {
      return {this->left_.getConfiguration(),
              this->middle_.getConfiguration(),
              this->right_.getConfiguration()};
    }

  private:
    constexpr auto increment_rotors() -> void
    {
      std::size_t increment = 1U;
      this->right_.step(increment);
      this->middle_.step(increment);
      this->left_.step(increment);
    }

    [[nodiscard]] constexpr auto forward(char letter) const -> char
    {
      letter = this->right_.forward(letter);
      letter = this->middle_.forward(letter);
      letter = this->left_.forward(letter);
      return letter;
    }

    [[nodiscard]] constexpr auto reflect(char letter) const -> char
    {
      return this->reflector_.reflect(letter);
    }

    [[nodiscard]] constexpr auto inverse(char letter) const -> char
    {
      letter = this->left_.inverse(letter);
      letter = this->middle_.inverse(letter);
      letter = this->right_.inverse(letter);
      return letter;
    }

    Rotor     left_, middle_, right_;
    Reflector reflector_;
  };

} // namespace enmach
#endif // ENMACH_ENIGMAMACHINE_HPP_