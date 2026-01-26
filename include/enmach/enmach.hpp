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
  using Enigma1 = EnigmaMachine<
      EnigmaMachineConfiguration<
          Set<I, II, III, IV, V>,
          Set<UKW_A, UKW_B, UKW_C>,
          3>,
      Args...>;

} // namespace enmach

#endif // ENMACH_ENMACH_HPP_