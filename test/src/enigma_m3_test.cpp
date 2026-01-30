#include "gtest/gtest.h"

#include <string_view>

#include "enmach/enmach.hpp"

using namespace enmach::reflector_tags;
using namespace enmach::rotor_tags;
using namespace std::literals;

namespace
{
  template<class PlugboardValue>
  struct Plugboard : public PlugboardValue
  {
    constexpr auto operator()(char letter) const -> char { return PlugboardValue::value.at(static_cast<std::size_t>(letter - 'a')); };
  };

  template<class EM>
  auto decrypt(EM &em, const std::string_view &input) -> std::string
  {
    std::string output;
    output.reserve(input.size());
    for (const auto &character : input)
    {
      em.increment();
      if (character == '.')
        output += '.';
      else
        output += em.exec(character);
    }
    return output;
  }
} // namespace

TEST(EnigmaM3Tests, I_II_III_UKWB_noPlugboard_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "yumjmzfvotepjpqditfzltartgrujaxlwlbdfqdxdluynqrmioznrebwtgqs"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, I_II_III_UKWB_noPlugboard_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "yumjmzfvotepjpqditfzltartgrujaxlwlbdfqdxdluynqrmioznrebwtgqs"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, ring_settings_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('h', 'l', 'k');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "ytwhpkbalvphboikmyhuhzfulmueyuipzmsczlhvpbbofpuyfivqblohtiuu"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, ring_settings_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('h', 'l', 'k');
  constexpr std::string_view input    = "ytwhpkbalvphboikmyhuhzfulmueyuipzmsczlhvpbbofpuyfivqblohtiuu"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, rotor_settings_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('h', 'l', 'k');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "gzbseaxdrvmddsqinjkjjqkkyiydsjfgymhcsvcupluyfakbymyezdyyuxfm"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, rotor_settings_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('h', 'l', 'k');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "gzbseaxdrvmddsqinjkjjqkkyiydsjfgymhcsvcupluyfakbymyezdyyuxfm"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, plugboard_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "zbcdrwghuylkmnopqestivfxja"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "jibgmawvodrpypvdggpaktzeggehyzxxmvbdzidxvkijgveaudznirwfnhqs"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, plugboard_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "zbcdrwghuylkmnopqestivfxja"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "jibgmawvodrpypvdggpaktzeggehyzxxmvbdzidxvkijgveaudznirwfnhqs"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, reflector_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_C, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "zgwgwykjxsziqfjrebgjmikuopebuvukrfjomipslppeuzxilwaieuxjomzi"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, reflector_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_C, I, II, III> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "zgwgwykjxsziqfjrebgjmikuopebuvukrfjomipslppeuzxilwaieuxjomzi"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, rotors_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, VI, III, VIII> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "gxtqyeixxntxjmbbmsvadvywrfxkxcjfoxlczwysuvgxibcxsskxgqkrlxur"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, rotors_decrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_B, VI, III, VIII> m3;
  m3.setInitialRotorPosition('a', 'a', 'a');
  m3.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "gxtqyeixxntxjmbbmsvadvywrfxkxcjfoxlczwysuvgxibcxsskxgqkrlxur"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, all_together_encrypt)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "zbcdrwghuylkmnopqestivfxja"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_C, VI, III, VIII> m3;
  m3.setInitialRotorPosition('h', 'l', 'k');
  m3.setRingstellung('h', 'l', 'k');
  constexpr std::string_view input    = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  constexpr std::string_view expected = "vinnjluztqxkpqlthluanqvljpankrdljtvhevnrkidyvschxisntajnacmo"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM3Tests, all_together_decrypt)

{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "zbcdrwghuylkmnopqestivfxja"sv; };
  // clang-format on
  enmach::EnigmaM3<Plugboard<PlugboardValue>, UKW_C, VI, III, VIII> m3;
  m3.setInitialRotorPosition('h', 'l', 'k');
  m3.setRingstellung('h', 'l', 'k');
  constexpr std::string_view input    = "vinnjluztqxkpqlthluanqvljpankrdljtvhevnrkidyvschxisntajnacmo"sv;
  constexpr std::string_view expected = "nvkzhgdhmangsvksyiznoxqgknszoxbuiwoqueocihvvklgkgaemkxlpwlvg"sv;
  std::string                output   = decrypt(m3, input);
  ASSERT_EQ(expected, output);
}