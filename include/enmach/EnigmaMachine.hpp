#ifndef ENMACH_ENIGMAMACHINE_HPP_
#define ENMACH_ENIGMAMACHINE_HPP_

#include <string_view>
#include <tuple>

#include "enmach/Reflector.hpp"
#include "enmach/Rotor.hpp"

namespace enmach
{
  template<class ReflectorTag, class... Rotors>
  struct EnigmaMachine
  {
    // TODO: Add static assert check on arguments list
    // TODO: Add plugboard
    Reflector<ReflectorTag>      reflector{};
    std::tuple<Rotor<Rotors>...> rotors; // TODO: invert tuple types (tuple types should be in the order Right -> Left)

    auto increment() -> void
    {
      auto flag{true};
      std::apply([&flag](auto &&...args)
                 { ((flag = args.increment(flag)), ...); }, this->rotors);
    }

    template<class... Args>
    constexpr auto setRingstellung(Args &&...args) -> void
    {
      // TODO: Add static assert check on arguments list
      static_assert(false && "not implemented");
    }

    template<class... Args>
    constexpr auto setRotorPosition(Args &&...args) -> void
    {
      // TODO: Add static assert check on arguments list
      static_assert(false && "not implemented");
    }

    [[nodiscard]] constexpr auto exec(char letter) -> char
    {
      // TODO: Add plugboard transformation
      std::apply([&letter](auto&& ...args) {((letter = args.forward(letter)), ...);}, this->rotors);
      letter = reflector.reflect(letter);
      std::apply([&letter](auto&& ...args) {((letter = args.inverse(letter)), ...);}, this->rotors); // TODO: reverse the tuple (inverse transformation goes from Left -> Right)
      // TODO: Add plugboard transformation
      return letter;
    }
  };
}

#endif // ENMACH_ENIGMAMACHINE_HPP_