#include "enmach/EnigmaMachine.hpp"
#include "enmach/utils.hpp"

int main(void)
{
  enmach::EnigmaMachine em{enmach::rotors::i, enmach::rotors::ii, enmach::rotors::iii, enmach::reflectors::b};
  char                  letter = em.exec('g');
  return static_cast<int>(letter);
}