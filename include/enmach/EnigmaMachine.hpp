#ifndef ENMACH_ENIGMAMACHINE_HPP_
#define ENMACH_ENIGMAMACHINE_HPP_

#include <string_view>
#include <tuple>

#include "enmach/utils.hpp"
#include "enmach/Reflector.hpp"
#include "enmach/Rotor.hpp"

namespace enmach
{
  template<class AllowedRotors, class AllowedReflectors, std::size_t RequiredRotors>
  struct EnigmaMachineConfiguration
  {
    using Rotors                   = AllowedRotors;
    using Reflectors               = AllowedReflectors;
    constexpr static std::size_t N = RequiredRotors;
  };

  template<class Config, class ReflectorTag, class... RotorTags>
  struct EnigmaMachine
  {
    static_assert((sizeof...(Rotors)) == Config::N);
    // TODO: Add static assert check on arguments list
    // TODO: Add plugboard
    Reflector<ReflectorTag>      reflector{};
    decltype(std::tuple<Rotor<RotorTags>...>{}) rotors;

    auto increment() -> void
    {
      auto flag{true};
      std::apply([&flag](auto &&...args)
                 { ((flag = args.increment(flag)), ...); }, this->rotors);
    }

    template<class... Args>
    constexpr auto setRingstellung(Args &&...args) -> void
    {
      ((void)(args), ...);
      // TODO: Add static assert check on arguments list
      static_assert(false && "not implemented");
    }

    template<class... Args>
    constexpr auto setRotorPosition(Args &&...args) -> void
    {
      ((void)(args), ...);
      // TODO: Add static assert check on arguments list
      static_assert(false && "not implemented");
    }

    [[nodiscard]] constexpr auto exec(char letter) -> char
    {
      // TODO: Add plugboard transformation
      std::apply([&letter](auto &&...args)
                 { ((letter = args.forward(letter)), ...); }, this->rotors);
      letter = reflector.reflect(letter);
      std::apply([&letter](auto &&...args)
                 { ((letter = args.inverse(letter)), ...); }, reverse_tuple(this->rotors));
      // TODO: Add plugboard transformation
      return letter;
    }
  };
} // namespace enmach

#endif // ENMACH_ENIGMAMACHINE_HPP_