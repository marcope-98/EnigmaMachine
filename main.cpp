#include "enmach/enmach.hpp"
#include <iostream>
#include <string_view>


using namespace std::literals;
struct Plugboard

{
  constexpr static std::string_view value = "dbcatuqmilkjhvozgrsefnwxyp"sv;
  constexpr auto                    operator()(char letter) const -> char { return this->value.at(enmach::ETW.find(letter)); }
};

int main(void)
{
  enmach::Enigma1<Plugboard,
                  enmach::reflector_tags::UKW_B,
                  enmach::rotor_tags::II, enmach::rotor_tags::V, enmach::rotor_tags::III>
      em;
  em.setRingstellung('d', 'k', 'x');
  em.setInitialRotorPosition('y', 'w', 'y');
  constexpr std::string_view message = "znapq";
  for (const auto &elem : message)
  {
    em.increment();
    std::cout << em.exec(elem);
  }
  std::cout << "\n";
  return 0;
}