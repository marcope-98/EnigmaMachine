# Enigma Machine
This project provides a complete and historically accurate C++ implementation of the Enigma cipher machine, used by Germany during World War II. 

The goal is to simulate the machine's mechanical and electrical behaviour as faithfully as possible while keeping the code clean, modern, and well-tested.

Overall this process was achieved consulting [historical documentation](https://www.cryptomuseum.com/crypto/enigma/wiring.htm) about the different models of enigma machine and validating the result with a comprenhensive test suite for the [Enigma 1](https://github.com/MaxAnderson95/pyenigma), [Enigma M3](https://github.com/weavc/enigma), and [Enigma M4](https://enigma.hoerenberg.com/).

## Dependencies
- C++17 or newer
- [googletest 1.17.x](https://github.com/google/googletest/tree/v1.17.x)

## Build
```bash
$ git clone https://github.com/marcope-98/enigma-machine.git
$ cd enigma-machine
$ mkdir build && cd build
$ cmake ..
$ make -j4
$ ./test/enigma_machine_tests # Run the tests
```

## Example
```cpp
#include <iostream>
#include <string_view>

#include "enmach/enmach.hpp"

using namespace std::literals;
using namespace enmach::rotor_tags;

struct Plugboard
{
  constexpr static std::string_view value = "efmqabguinkxcjordpzthwvlys"sv;
  constexpr auto operator()(char letter) const -> char { return this->value.at(static_cast<std::size_t>(letter - 'a')); }
};

int main(void)
{
  enmach::EnigmaM1<
    Plugboard,                        /* Plugboard */
    ukw::B,                           /* Reflector */
    I, II, III>                       /* Rotor ordered left to right */ 
    m1;
  m1.setGrundstellung('a', 'a', 'a'); /* Set initial position left to right */
  m1.setRingstellung('a', 'a', 'a');  /* Set ring settings    left to right */

  constexpr std::string_view input = "abcdefghijklmnopqrstuvwxyz";
  for (const auto &character : input)
  {
    m1.increment();
    std::cout << m1.exec(character);
  }
  std::cout << "\n";
  
  return 0;
}
```

## Features
### Plugboard (Steckerbrett)
The plugboard (Steckerbrett) was the first stage of substitution in the Enigma's encryption path and one of the most important contributors to its cryptographic strength.

Located on the front panel of the machine, it allowed operators to connect pairs of letters using cables with two-pronged plugs. Each connection swapped the two letters both on input and output, creating a simple, symmetric substitution that applied before and after the rotor scrambling process.

In this implementation, the Plugboard is modeled as a Functor, and has to be passed as a template parameter to the EnigmaMachine template, as such it has no explicit constructor and has an operator() public method. The aforementioned operator accepts a character as input and returns a character.

A possible implementation of the Plugboard class is as follows:
```cpp
struct Plugboard
{
  constexpr static std::string_view value = "efmqabguinkxcjordpzthwvlys"sv;
  constexpr auto operator()(char letter) const -> char { return this->value.at(static_cast<std::size_t>(letter - 'a')); }
};
```

### Rotor (Walzen)
Rotors were the core scrambling components of the Enigma machine. Each rotor consisted of three parameters:
- The internal wiring: a fixed permutation of the 26 letters alphabet.
- A ring setting: altering the offset between the rotor's wiring and its turnover notch.
- A turnover notch: causing the rotor to the left to step at specific positions.
- A visible position: shown in the machine window either as an integer (1...26) or as a letter (A...Z).

Rotors performed a different substitution depending on their rotational position, making the cipher polyalphabetic.

#### Wiring representation
Each rotor's wiring is represented as a 26-character mapping from input contacts to output contacts. 

For example, the historical Rotor I of the Enigma M1 used the following mapping:
```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
||||||||||||||||||||||||||
EKMFLGDQVZNTOWYHXUSPAIBRCJ
```
Because the wiring is fixed, the implementation stores these permutations as static lookup tables for forward and backward traversal.
```cpp
#define EKMFLGDQVZNTOWYHXUSPAIBRCJ "\x04\x0a\x0c\x05\x0b\x06\x03\x10\x15\x19\x0d\x13\x0e\x16\x18\x07\x17\x14\x12\x0f\x00\x08\x01\x11\x02\x09"
#define UWYGADFPVZBECKMTHXSLRINQOJ "\x14\x16\x18\x06\x00\x03\x05\x0f\x15\x19\x01\x04\x02\x0a\x0c\x13\x07\x17\x12\x0b\x11\x08\x0d\x10\x0e\x09"
std::array<std::uint8_t, 27> fvalue = { EKMFLGDQVZNTOWYHXUSPAIBRCJ }, 
std::array<std::uint8_t, 27> rvalue = { UWYGADFPVZBECKMTHXSLRINQOJ };
```

The tranformation from alphabet to the offsets lookup table was performed as follows:
```cpp
constexpr std::string_view input = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"sv;
for(const auto &elem : input)
  std::cout << "\\x" << std::hex << std::setfill('0') << std::setw(2) << static_cast<std::size_t>(elem - 'A');

// output: "\x04\x0a\x0c\x05\x0b\x06\x03\x10\x15\x19\x0d\x13\x0e\x16\x18\x07\x17\x14\x12\x0f\x00\x08\x01\x11\x02\x09"
```

Similarly the backward transformation offsets lookup table was obtained as follows:
```cpp
constexpr std::string_view input = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"sv;
for(std::size_t i{}; i < input.size(); ++i)
  std::cout << "\\x" << std::hex << std::setfill('0') << std::setw(2) << input.find(i + 'A');

// output: "\x14\x16\x18\x06\x00\x03\x05\x0f\x15\x19\x01\x04\x02\x0a\x0c\x13\x07\x17\x12\x0b\x11\x08\x0d\x10\x0e\x09"
```  
#### Initial rotor position (Grundstellung) and Ring setting (Ringstellung)
The initial rotor position defines the starting orientation of each rotor when the message is encrypted or decrypted. 

This visually corresponds to the rotational offset of each rotor. During encryption the rightmost rotor rotates first, causing the entire substitution cascade to change with every keystroke.

In code, this is modeled as an index offset applied before performing the wiring substitution.

Similarly the ring setting changes the alignment between the rotor's internal wiring and its external letter markings. While the initial position rotates the rotor visibly, the ring setting rotates the internal wiring relative to the turnover notch.

This influences the turnover behavior and the effective substitution produced at each position.

In the context of the letter encoding, the ring settings modify how indices are adjusted before and after wiring substitution.

```cpp
index = (index + grundstellung - ringstellung) % enmach::ETW.size();
// index = RotorTag::fvalue[index]; or index = RotorTag::rvalue[index];
index = (index - grundstellung + ringstellung) % enmach::ETW.size();
```

#### Rotor stepping

The stepping mechanism determines how the rotors advance during encryption. The historical Enigma used a pseudo-odometer stepping mechanism with a famous flaw: the double-step.

Rules:
1. The rightmost rotor steps on every key press
2. A rotor steps the one to its left when its turnover notch aligns with the top position
3. Due to the notch alignment, the middle rotor steps again immediately afterward (this is the double step).

This behaviour was tested with real life messages to ensure the implementation faithfully reproduces the historical authenticity.

#### Extra M4 Rotors (Zusatzwalze)

The Enigma M4, used by the Kriegsmarine, introduces a frouth rotor (the Greek rotor), placed between the leftmost rotor and the reflector.
Unlike the first three rotors the Zusatzwalze does not rotate, it has its own wiring variants ($\beta$ and $\gamma$) and it works in conjunction with a special set of naval reflectors denominated thin-B and thin-C.
The idea is that in the default position of the $\beta$ rotor with the thin-B reflector will produce the Enigma M3 B reflector. The same behaviour can be observed with the $\gamma$ rotor and the thin-C reflector.

The implementation of the Enigma M4 takes into consideration all of these aspects: from the rotor position (only allowed in the 4 position next to the reflector), to the unavailability to step before keypresses, while preserving the particular double step behaviour of the rightmost three rotors.
### Reflector (Umkehrwalze)
The reflector is the component that made the Enigma machine symmetric meaning the same settings could encrypt and decrypt.

The reflector receives the signal from the leftmost rotor, maps each letter to another letter via fixed substitution (similarly to the plugboard) and sends back the signal through the rotors in reverse order.

Differently from the plugboard however, no letter maps to itself. This aspect guarantees that the encryption is involutive (i.e. $E(E(x)) = x$) and there is no fixed point (no letter ever encypts to itself).

## Tests
A comprehensive test suite for each of the enigma machines implemented (M1, M3 and M4) were written using the googletest framework.

The tests for the Enigma M1 and M3 focus on the correctness of the single components and parameters that make up the Enigma Machine, i.e. the rotor combination and order, the reflector, the ring settings, the initial position of the rotors, and the plugboard.

The tests for the Enigma M1 were retrieved from [MaxAnderson95 python implementation](https://github.com/MaxAnderson95/pyenigma) of the enigma machine.

The tests for the Enigma M3 were retrieved from [weavc python implementation](https://github.com/weavc/enigma) of the enigma machine.

The tests for the Enigma M4 focus indirectly on the correctness of the single components. They, instead, focus on decrypting [real messages from the German Navy](https://enigma.hoerenberg.com/).
