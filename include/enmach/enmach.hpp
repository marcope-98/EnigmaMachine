#ifndef ENMACH_ENMACH_HPP_
#define ENMACH_ENMACH_HPP_

#include "enmach/EnigmaMachine.hpp"
#include "enmach/Reflector.hpp"
#include "enmach/Rotor.hpp"
#include "enmach/utils.hpp"

namespace enmach
{
  using namespace enmach::rotor_tags;
  using namespace enmach::reflector_tags;

  template<class... Args>
  using EnigmaM1 = EnigmaMachine<
      EnigmaMachineConfiguration<
          Set<I, II, III, IV, V>,
          Set<UKW_A, UKW_B, UKW_C>,
          3>,
      Args...>;

  template<class... Args>
  using EnigmaM3 = EnigmaMachine<
      EnigmaMachineConfiguration<
          Set<I, II, III, IV, V, VI, VII, VIII>,
          Set<UKW_A, UKW_B, UKW_C>,
          3>,
      Args...>;

  template<class Plugboard, class Reflector, class Zusatzwalze, class... Rotors>
  using EnigmaM4 = std::enable_if_t<
      (std::is_same_v<Zusatzwalze, BETA> || std::is_same_v<Zusatzwalze, GAMMA>) && /* Zusatzwalze must be either gamma or beta*/
          !(Set<BETA, GAMMA>::template is_in_set<Rotors>() || ...) /* Other Rotors must not be of type gamma or beta */,
      EnigmaMachine<
          EnigmaMachineConfiguration<
              Set<I, II, III, IV, V, VI, VII, VIII, BETA, GAMMA>,
              Set<UKW_b, UKW_c>,
              4>,
          Plugboard, Reflector, Zusatzwalze, Rotors...>>;
} // namespace enmach

#endif // ENMACH_ENMACH_HPP_