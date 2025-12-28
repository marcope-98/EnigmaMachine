#include "enmach/EnigmaMachine.hpp"
#include "enmach/utils.hpp"

#include <iostream>

int main(void)
{
  enmach::EnigmaMachine em{enmach::rotors::i, enmach::rotors::ii, enmach::rotors::iii, enmach::reflectors::b};
  for (std::size_t i{}; i < 32; ++i)
  {
    char                        letter = em.exec('g');
    enmach::RotorsConfiguration a      = em.getRotorsConfigurations();
    std::cerr << std::get<0>(a) << " " << std::get<1>(a) << " " << std::get<2>(a) << "\n";
    (void)letter;
  }
  return 0;
}