#ifndef ENMACH_ROTOR_HPP_
#define ENMACH_ROTOR_HPP_

#include <array>
#include <iostream>
#include <cstdint>

#include "enmach/common.hpp"

namespace enmach::rotor_tags
{
  using namespace std::literals;
  // clang-format off
  struct I     { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x04\x0a\x0c\x05\x0b\x06\x03\x10\x15\x19\x0d\x13\x0e\x16\x18\x07\x17\x14\x12\x0f\x00\x08\x01\x11\x02\x09" }, 
                                                               rvalue = { "\x14\x16\x18\x06\x00\x03\x05\x0f\x15\x19\x01\x04\x02\x0a\x0c\x13\x07\x17\x12\x0b\x11\x08\x0d\x10\x0e\x09" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 16U; }                                                                                  };
  struct II    { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x00\x09\x03\x0a\x12\x08\x11\x14\x17\x01\x0b\x07\x16\x13\x0c\x02\x10\x06\x19\x0d\x0f\x18\x05\x15\x0e\x04" }, 
                                                               rvalue = { "\x00\x09\x0f\x02\x19\x16\x11\x0b\x05\x01\x03\x0a\x0e\x13\x18\x14\x10\x06\x04\x0d\x07\x17\x0c\x08\x15\x12" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position ==  4U; }                                                                                  };
  struct III   { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x01\x03\x05\x07\x09\x0b\x02\x0f\x11\x13\x17\x15\x19\x0d\x18\x04\x08\x16\x06\x00\x0a\x0c\x14\x12\x10\x0e" }, 
                                                               rvalue = { "\x13\x00\x06\x01\x0f\x02\x12\x03\x10\x04\x14\x05\x15\x0d\x19\x07\x18\x08\x17\x09\x16\x0b\x11\x0a\x0e\x0c" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 21U; }                                                                                  };
  struct IV    { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x04\x12\x0e\x15\x0f\x19\x09\x00\x18\x10\x14\x08\x11\x07\x17\x0b\x0d\x05\x13\x06\x0a\x03\x02\x0c\x16\x01" }, 
                                                               rvalue = { "\x07\x19\x16\x15\x00\x11\x13\x0d\x0b\x06\x14\x0f\x17\x10\x02\x04\x09\x0c\x01\x12\x0a\x03\x18\x0e\x08\x05" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position ==  9U; }                                                                                  };
  struct V     { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x15\x19\x01\x11\x06\x08\x13\x18\x14\x0f\x12\x03\x0d\x07\x0b\x17\x00\x16\x0c\x09\x10\x0e\x05\x04\x02\x0a" }, 
                                                               rvalue = { "\x10\x02\x18\x0b\x17\x16\x04\x0d\x05\x13\x19\x0e\x12\x0c\x15\x09\x14\x03\x0a\x06\x08\x00\x11\x0f\x07\x01" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 25U; }                                                                                  };
  struct VI    { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x09\x0f\x06\x15\x0e\x14\x0c\x05\x18\x10\x01\x04\x0d\x07\x19\x11\x03\x0a\x00\x12\x17\x0b\x08\x02\x13\x16" }, 
                                                               rvalue = { "\x12\x0a\x17\x10\x0b\x07\x02\x0d\x16\x00\x11\x15\x06\x0c\x04\x01\x09\x0f\x13\x18\x05\x03\x19\x14\x08\x0e" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 25U || position == 12U; }                                                               };
  struct VII   { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x0d\x19\x09\x07\x06\x11\x02\x17\x0c\x18\x12\x16\x01\x0e\x14\x05\x00\x08\x15\x0b\x0f\x04\x0a\x10\x03\x13" }, 
                                                               rvalue = { "\x10\x0c\x06\x18\x15\x0f\x04\x03\x11\x02\x16\x13\x08\x00\x0d\x14\x17\x05\x0a\x19\x0e\x12\x0b\x07\x09\x01" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 25U || position == 12U; }                                                               };
  struct VIII  { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x05\x0a\x10\x07\x13\x0b\x17\x0e\x02\x01\x09\x12\x0f\x03\x19\x11\x00\x0c\x04\x16\x0d\x08\x14\x18\x06\x15" }, 
                                                               rvalue = { "\x10\x09\x08\x0d\x12\x00\x18\x03\x15\x0a\x01\x05\x11\x14\x07\x0c\x02\x0f\x0b\x04\x16\x19\x13\x06\x17\x0e" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { return position == 25U || position == 12U; }                                                               };
  struct BETA  { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x0b\x04\x18\x09\x15\x02\x0d\x08\x17\x16\x0f\x01\x10\x0c\x03\x11\x13\x00\x0a\x19\x06\x05\x14\x07\x0e\x12" }, 
                                                               rvalue = { "\x11\x0b\x05\x0e\x01\x15\x14\x17\x07\x03\x12\x00\x0d\x06\x18\x0a\x0c\x0f\x19\x10\x16\x04\x09\x08\x02\x13" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { (void)position; return false; }                                                                            };
  struct GAMMA { constexpr static std::array<std::uint8_t, 27> fvalue = { "\x05\x12\x0e\x0a\x00\x0d\x14\x04\x11\x07\x0c\x01\x13\x08\x18\x02\x16\x0b\x10\x0f\x19\x17\x15\x06\x09\x03" }, 
                                                               rvalue = { "\x04\x0b\x0f\x19\x07\x00\x17\x09\x0d\x18\x03\x11\x0a\x05\x02\x13\x12\x08\x01\x0c\x06\x16\x10\x15\x0e\x14" }; 
                 constexpr static auto turn(std::uint8_t position) -> bool { (void)position; return false; }                                                                            };
  // clang-format on
} // namespace enmach::rotor_tags

namespace enmach
{
  template<class RotorTag>
  struct Rotor
  {
  public:
    [[nodiscard]] constexpr auto forward(std::uint8_t index) const -> std::uint8_t
    {
      index = (index + this->internal_difference) % enmach::ETW.size();
      index = RotorTag::fvalue[index];
      index = (index + enmach::ETW.size() - this->internal_difference) % enmach::ETW.size();
      return index;
    }

    [[nodiscard]] constexpr auto inverse(std::uint8_t index) const -> std::uint8_t
    {
      index = (index + this->internal_difference) % enmach::ETW.size();
      index = RotorTag::rvalue[index];
      index = (index + enmach::ETW.size() - this->internal_difference) % enmach::ETW.size();
      return index;
    }

    [[nodiscard]] constexpr auto increment(bool condition) -> bool
    {
      const bool result = RotorTag::turn((this->internal_difference + this->ringstellung_) % ETW.size());
      if constexpr (!std::is_same_v<RotorTag, enmach::rotor_tags::GAMMA> && !std::is_same_v<RotorTag, enmach::rotor_tags::BETA>)
        this->internal_difference = (this->internal_difference + static_cast<std::uint8_t>(condition || result)) % enmach::ETW.size();
      return result;
    }

    constexpr auto setInitialPosition(char initial_position) -> void
    {
      this->position_ = static_cast<std::uint8_t>(initial_position - 'a');
      this->setInternalDifference();
    }
    constexpr auto setRingstellung(char ringstellung) -> void
    {
      this->ringstellung_ = static_cast<std::uint8_t>(ringstellung - 'a');
      this->setInternalDifference();
    }

  private:
    constexpr auto setInternalDifference() -> void { this->internal_difference = (this->position_ + enmach::ETW.size() - this->ringstellung_) % enmach::ETW.size(); }

    std::uint8_t position_{};
    std::uint8_t ringstellung_{};
    std::uint8_t internal_difference{};
  };
} // namespace enmach
#endif // ENMACH_ROTOR_HPP_