#include "gtest/gtest.h"

#include <string_view>

#include "enmach/enmach.hpp"

using namespace enmach;
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

TEST(EnigmaM1Tests, no_plugboard_default_settings_same_letter)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('a', 'a', 'a');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "aaaaa"sv;
  constexpr std::string_view expected = "bdzgo"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, no_plugboard_default_settings_same_letter_decipher)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('a', 'a', 'a');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "bdzgo"sv;
  constexpr std::string_view expected = "aaaaa"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, all_settings_configured)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "jbcdmrutyaklenopqfshgvwxiz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, III, IV, I> m1;
  m1.setInitialRotorPosition('f', 'r', 'h');
  m1.setRingstellung('l', 'e', 't');
  constexpr std::string_view input    = "helloworld"sv;
  constexpr std::string_view expected = "zzaskxukih"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, middle_rotor_step)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('a', 'a', 'u');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "aaa"sv;
  constexpr std::string_view expected = "muq"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, double_rotor_step)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('b', 'd', 'u');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "aaa"sv;
  constexpr std::string_view expected = "wrl"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, long_string)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('a', 'a', 'a');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"sv;
  constexpr std::string_view expected = "bdzgowcxltksbtmcdlpbmuqofxyhcxtgyjflinhnxshiuntheorxpqpkovhcbubtzszsoostgotfsodbbzzlxlcyzxifgwfdzeeqibmgfjbwzfckpfmgbxqcivibbrncocjuvydkmvjpfmdrmtglwfozlxgjeyyqpvpbwnckvklztcbdldctsnrcoovptgbvbbisgjsoyhdenctnuukcughrevwbdjctq"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM1Tests, even_longer_string)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abcdefghijklmnopqrstuvwxyz"sv; };
  // clang-format on
  enmach::EnigmaM1<Plugboard<PlugboardValue>, ukw::B, I, II, III> m1;
  m1.setInitialRotorPosition('a', 'a', 'a');
  m1.setRingstellung('a', 'a', 'a');
  constexpr std::string_view input    = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"sv;
  constexpr std::string_view expected = "bdzgowcxltksbtmcdlpbmuqofxyhcxtgyjflinhnxshiuntheorxpqpkovhcbubtzszsoostgotfsodbbzzlxlcyzxifgwfdzeeqibmgfjbwzfckpfmgbxqcivibbrncocjuvydkmvjpfmdrmtglwfozlxgjeyyqpvpbwnckvklztcbdldctsnrcoovptgbvbbisgjsoyhdenctnuukcughrevwbdjctqxxoglebzmdbrzosxdtzszbgdcfprbzyqgsncchgyewohvjbyzgkdgynneujiwctycytuumboyvunnqukksobscorsuoscnvroqlheudsukymigibsxpihntuvgghifqtgzxlgyqcnvnsrclvpyosvrbkcexrnlgdywebfxivkktugkpvmzotuogmhhzdrekjhlefkkpoxlwbwvbyukdtquhdqtrevrqjmqwndovwljhccxcfxrppxmsjezcjuftbrzzmcssnjnylcgloycitvyqxpdiyfgefyvxsxhkegxkmmdswbcyrkizocgmfddtmwztlssfljmooluuqjmijsciqvruistltgnclgkiktzhrxenrxjhyztlxicwwmywxdyiblerbflwjqywongiqqcuuqtpphbiehtuvgcegpeymwicgkwjcufkluidmjdivpjdmpgqpwitkgviboomtnduhqphgsqrjrnoovpwmdnxllvfiimkieyizmquwydpoultuwbukvmmwrlqlqsqpeugjrcxzwpfyiyybwloewrouvkpoztceuwtfjzqwpbqldttsrmdflgxbxzryqkdgjrzezmkhjnqypdjwcjfjlfntrsncnlgssg"sv;
  std::string                output   = decrypt(m1, input);
  ASSERT_EQ(expected, output);
}