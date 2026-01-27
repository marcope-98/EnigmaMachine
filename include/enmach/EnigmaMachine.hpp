#ifndef ENMACH_ENIGMAMACHINE_HPP_
#define ENMACH_ENIGMAMACHINE_HPP_

#include <string_view>
#include <tuple>

#include "enmach/Reflector.hpp"
#include "enmach/Rotor.hpp"
#include "enmach/utils.hpp"

namespace enmach
{
  template<class AllowedRotors, class AllowedReflectors, std::size_t RequiredRotors>
  struct EnigmaMachineConfiguration
  {
    using Rotors                   = AllowedRotors;
    using Reflectors               = AllowedReflectors;
    constexpr static std::size_t N = RequiredRotors;
  };

  template<class Config, class Plugboard, class ReflectorTag, class... RotorTags>
  struct EnigmaMachine
  {
  public:
    static_assert((sizeof...(RotorTags)) == Config::N);
    static_assert(is_unique<RotorTags...>);
    static_assert((Config::Rotors::template is_in_set<RotorTags>() && ...));
    static_assert((Config::Reflectors::template is_in_set<ReflectorTag>()));

    auto increment() -> void
    {
      auto flag{true};
      std::apply([&flag](auto &&...args)
                 { ((flag = args.increment(flag)), ...); }, this->rotors);
    }

    template<class... Args>
    constexpr auto setRingstellung(Args &&...args) -> void
    {
      static_assert(Config::N == (sizeof...(Args)));
      assign_ringstellung(this->rotors, std::make_tuple(args...));
    }

    template<class... Args>
    constexpr auto setInitialRotorPosition(Args &&...args) -> void
    {
      static_assert(Config::N == (sizeof...(Args)));
      assign_initial_rotor_position(this->rotors, std::make_tuple(args...));
    }

    [[nodiscard]] constexpr auto exec(char letter) -> char
    {
      std::size_t index = static_cast<std::size_t>(this->plugboard(letter) - 'a');
      std::apply([&index](auto &&...args)
                 { ((index = args.forward(index)), ...); }, this->rotors);
      letter = static_cast<char>(index + 'a');
      letter = reflector.reflect(letter);
      index  = static_cast<std::size_t>(letter - 'a');
      std::apply([&index](auto &&...args)
                 { ((index = args.inverse(index)), ...); }, reverse_tuple(this->rotors));
      letter = static_cast<char>(index + 'a');
      letter = this->plugboard(letter);
      return letter;
    }

  private:
    decltype(reverse_tuple(std::tuple<Rotor<RotorTags>...>{})) rotors;
    Reflector<ReflectorTag>                                    reflector{};
    Plugboard                                                  plugboard{};

    template<class Tuple1, class Tuple2, std::size_t... Is>
    constexpr static auto assign_initial_rotor_position_impl(Tuple1 &&t1, Tuple2 &&t2, std::index_sequence<Is...>)
    {
      (std::get<Config::N - Is - 1>(t1).setInitialPosition(std::get<Is>(t2)), ...);
    }

    template<class Tuple1, class Tuple2>
    constexpr static auto assign_initial_rotor_position(Tuple1 &&t1, Tuple2 &&t2) -> void
    {
      assign_initial_rotor_position_impl(std::forward<Tuple1>(t1), std::forward<Tuple2>(t2), std::make_index_sequence<Config::N>{});
    }

    template<class Tuple1, class Tuple2, std::size_t... Is>
    constexpr static auto assign_ringstellung_impl(Tuple1 &&t1, Tuple2 &&t2, std::index_sequence<Is...>) -> void
    {
      (std::get<Config::N - Is - 1>(t1).setRingstellung(std::get<Is>(t2)), ...);
    }

    template<class Tuple1, class Tuple2>
    constexpr static auto assign_ringstellung(Tuple1 &&t1, Tuple2 &&t2) -> void
    {
      assign_ringstellung_impl(std::forward<Tuple1>(t1), std::forward<Tuple2>(t2), std::make_index_sequence<Config::N>{});
    }
  };
} // namespace enmach

#endif // ENMACH_ENIGMAMACHINE_HPP_