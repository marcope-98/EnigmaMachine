#include "gtest/gtest.h"

#include <string_view>

#include "enmach/enmach.hpp"

using namespace enmach::reflector_tags;
using namespace enmach::rotor_tags;
using namespace std::literals;

template<class PlugboardValue>
struct Plugboard : public PlugboardValue
{
  constexpr auto operator()(char letter) const -> char { return PlugboardValue::value.at(static_cast<std::size_t>(letter - 'a')); }
};

template<class EM>
auto decrypt(EM& em, const std::string_view& input) -> std::string
{
  std::string                output;
  output.reserve(input.size());
  for (const auto &character : input)
  {
    em.increment();
    if (character == '.')
      output += '.';
    else
      output += em.exec(character);;
  }
  return output;
}

TEST(EnigmaM4Tests, P1030659)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('y', 'v', 'o', 's');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "yupovejtbkonnfsaltwelqazjxtirjlliscsgxshejfynzqdnqsuxpgftjkwingorybjyadwnfclppnslwuybuqisxgq"sv;
  constexpr std::string_view expected = "fffddduuuausbildungvonvonzwosechsuuuflottxxtttfffzwodreiausgezqestetmitssssssgcgxtttfffzwoqi"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030660)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('i', 'g', 'z', 'q');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "twnhyazgbilshewpglbpqlwqekitiafgzhwimcwdfxpafeilqzwfnrfttqhuoadvlrlgaoqkvlwlsjhwofjjsluveynrrajaqdkqbgmfycevkpfjpkowhhqzyzeqrtqikkxixtfpoemi"sv;
  constexpr std::string_view expected = "fxdxuuuostyfuncquuufxwttxvvvuuueinseinsnuldreikkeiselekkxxistsechsstuendlichesdockenvormittagsamdreixfunfxinrendsburggemxfxdxuuuostmoeglichl"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030661)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('x', 'p', 's', 'v');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "tukaqyyoohvkjqtdvsbkrddazloyxhrdeozspzotbzmsbeiyashhjkimczwyikyjoewqhdzwfnoadoeioykauwvfpmhsynugikevfgbbaypcgotyseplsxqhkznb"sv;
  constexpr std::string_view expected = "umsueddreiyyvieginschauernbisfuenfwolkigvereinzeltschauerkkbereichdorabiseinsxfuenfxabendskksichtachtyyzehnsmseezwoybdreidbv"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030662)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('w', 'i', 'i', 'j');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "lirzmlwrcdmsnklkbebhrmfqfeqazwxbgbiexjpyfcqaawsekdeacohdzkcztovsyhfnscmaimimmavjnlfxewnpuirinozncrvdhcgkcyrvujqpvkeuivvxglqmkrjmdmlxllrlybkjwrxbqrzwgccndopmgckj"sv;
  constexpr std::string_view expected = "uuuvirsibennuleinsynachrxuuustuetzpunktluebeckvvvchefvierxuuuflottxxmituuuviersibennulzwounduuuviersibennuldreizurflenderwerftluebeckgehenxfondortfolgtweiteresx"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030663)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('o', 'd', 'b', 's');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "wjpsbiybzwezgbqmunmkcrjgricyqwbtxttuliiliwmgqzceabyuabinyqpyrnstpkmhvqsbelhrtdhybnakwlrabomvzpwr"sv;
  constexpr std::string_view expected = "uuuzwodreidreiachtvvvchefvierxuuuflottxxmituuuzwodreisechseinszumdockbetriebrendsburgentlassenxk"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030664)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('b', 's', 'o', 'j');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "snnjzfembckjqovtwhlwubcfabrbjseproqrzlbcxullvpnjdbmuxlrggdwwxkbewthcbuvrbhazamvofqffqxxwukwwjnyvrtxgntithnj"sv;
  constexpr std::string_view expected = "mituuuvirsgbennulzwoyvirsibenyuldreiyzwodreisechseinsumeinsnuluhrjsassnitzjausnachisonderburgjfahrtfueycyyz"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030665)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('d', 'i', 't', 'l');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "osjfneiddkrblzacosgapemnrkpvgvkrvpztewhnaatfvhnhyrgszvekpnfazviatvjsliqwgrgcbfss"sv;
  constexpr std::string_view expected = "uuueinseinsnuldrfikkeiselekkvodvonfduuuostingxxxsofortumfangdovkarbeithergebennm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030666)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('p', 'f', 'y', 'b');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "vxoyxwlhsgggsbklwkzoftrljzeqkomegpljuaahmzbjmrpfiybwjehdnfntlokqyxdn"sv;
  constexpr std::string_view expected = "haengemictangeleituuuvdrsibennuleinsanxxuuuzwodreidreiachtkkkaiserkk"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030667)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('h', 'y', 'k', 'k');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "zboqcpkztpxxwswxkxelbmdumwjnpkcgmxgywhtgmrlrcuqwfuyaitnfqfnpuprkovnhjnvfqbnvsgmsklmtvvvhstoikbolvekjzjwhkdwbftpoxqacjyyjqypgtoimytacobmuzszwiqxewtvupngedkpsgotzxwfnsphvcpvdfeen"sv;
  constexpr std::string_view expected = "stuekowarnemvendeyzwosechvxuuuflottxhachrxfxdxuuuausbildungvvvhevthaxxeinseinsdgeinuluhrmitetwaeineeinjnulnuofluechtlikgemarsbhwarnemuendenachjnyborgjjnyborznnannibrunobesetztq"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030668)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('r', 'x', 'c', 'i');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "uzttxodteifjumxkvlnekjqghswduibfiapyzmofczgbctxnxuefdtuiwnzqbxasiufrlsxjezrenczqsacksvqgvxcagnuunscsezdvufymzxpgigccwzrkdcwevrvkujbryzcyydmsdqrzshzosuokepvlpddqamlavqzbzgmz"sv;
  constexpr std::string_view expected = "komxadmxuuubooteyfduuuausbxyfduuuostysssmmmhhhsssostazwwfunfxuuuflottxyfunfxuuuflottxyhakaxkielvonvontorpxfangbooteinsneunxxeinszwouhrjkielweingelaufenyffftttbleibtbesetztr"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030669)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('d', 'g', 'o', 'e');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "vfofztntoqxhmhysuarpwedaeeoxnydzqzhxmfxgmrpcofervivuqngcsaovxdzwrugvadackfuootdxqzbnxdgvxbfpoevrpbecsyysiabwawgcwcfzroyaxsrgvnsluuipmtqikleztanxbanmtfkzjnoitinzvciegbxadztmkypwttdzxzkdibzitqresnhlqiittpunkraztbsomimllwtlekvdsfqmfbbecfhedcaqwipinclauvbsjkcmoxxmjgepmiofueoxpgquiyowvpdcnshw"sv;
  constexpr std::string_view expected = "ssdcheffunfxuuuflottxxeinskktttfffeinsachtmitzwostellkartenausruestungskagerrakundnorwegenmithafenplaenenundeinsexemplarlfdxbefxbbbddduuuooopppnrxsiebenvomzwovierxvierxvierfunfxsofortneustadtinmarschsetzenxzwokktttfffeinbneunvorlpeufigkielbleibenxdheikkbestartehxngerbetenxxfxdxuuuausbxkf"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030671)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('l', 'w', 'g', 'n');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "scxbdtzlxvdmeihbbhnetijldfcwbgrmthswqntyokqgvzkznjvpgakddqazagvjhkifnlqixoyakfqqubakgyahrdrxltovypnhjdzftyocltihhcsqbpftohdizjggdsjicpjdexibldycmtgyarltchjkfntnlfeygflytbillxtkfxnhpwyyofldbqvq"sv;
  constexpr std::string_view expected = "vonvonuuueinsnulnulachtkkgessnerkrtxnulneundreinuluhrvonluebecktravemuendeeinxzusatzfuerfunfuuuflottxjtreiboalverbrxvomeinsxvirxbisdreinulxvirxsechsyeinscbmxbestandameinsxfunfxxvirfunfyneuncbm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030672)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('u', 'y', 'u', 'a');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "nbayxscjpeqodzylclbkmdbsqvdvbzmoqpzttpggwtowagarfkjqoffckvbribtbaqkuzxbqmjalhkaltthdejstlzjxxzmzlzblujqesjyuxwnrldrxyefrrlqucmhzpudvzgfcoosdlnohixybuvhhpgsz"sv;
  constexpr std::string_view expected = "fxdxueuostkkingxkkvonvonuuueinseinsnuldreikkeiselekkxxeinskkundichtigkeitrohrvierxkkbeyyundentwaesserungkkzwokkschweissenkuehlwasxerleitunginvierbackbordlbq"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030673)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('a', 'w', 'g', 'i');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "uvtsjfgrcrkxqowlcbkknxiqrevqhnzdgonipkunsmorftoawnsjjjvrxzujsdlgjsakergesfpwwdmccipdunidialhzjycplztnbycedxhyddckawxsnlemebsjyzk"sv;
  constexpr std::string_view expected = "fuenfteuuuflottxananuuuzwofuedfeinssiebenxxspeziahistfuertelekinanlagewarteaufuuuleitstellexfragexxwannwirdspezialistabgeholtxbn"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030675)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('s', 'c', 'h', 'l');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "tawzzynzggmicvlsadlqfdfkhdgzlseemdffbqlyiseiwkdondwjwetkzowwyltyiiowsmcftgnlkozcaawhbhfjdrwldhfhewubpwvdezfpbocvkecvfxwzgsvbdphltvojcflsqnsodyfmbqfqulthdisgoqurabehhibnxnaaklejmxqhjwxavdlvtptstdcpwpyxcuvwafjttsfuspthosthxadwrqwzjctukwcwhyfyqtrtpkppjgpmdzqdaxaizlwcadyzutlxjjudqgmfwzrwzxbqrhncrufuzz.laldhhoibwypktsrnquhmuptfwuhwbikmasacvprelbrrmrklzwlvsfguqffxtavqihxdxrkqvgarlmzdbmdgrynwiyshwcnhiwxyfbfgxxqnptserocvytojtkklqraludqmufakrhkojcmwpszhnavvsewffpgrjtvnolsgrerkxscywboqtpxoxjlqxspytmeoxourshibybnwqefptggmcvxngcdfqiylcmpdlwooaalodswcdawozombgdzoqkzwqkfrmrwchgwfuerwpjaqfdrbvoaeyyaiynpcljdxocbazohqokvufglqnxqyduzjifxrvjdq.ooogxignonpeqlkqbtvj.danixq.fdyxrdtqtfp.zeheomxpppfggltvfodhbsqpaqmddwxmmgajzvursiygaaxdzdv"sv;
  constexpr std::string_view expected = "binefduuuausbxyvierxyzwofunfxuxzwouechsxuuuflxxhiervorliegendekkkrttbbbeinermmmsssflxzeigenimmerwiedjrschlezhtefahrdisziplinuuubooteingeleitensowiebeialleinmarschgrosszuegigeabweichungenvonzwgngswegseiesdurchfehlerhaftenavigationygrosszugigeausweichbewegungenoderleichtfertigesabschneidenbeikursaen.erungenxichmacheesdenkommandantenerneutzurpflichteinerseitszwangswegegenaueinzuhaltenywobeiabstandvonbojenstrichfunfnulbiseinsfunfnulmmmbetragensollyanderseitsbemfahrenimgeleitdievorantrittdesmarschesbeimgeleitfuehrerzuerfragendenbefehleueberfahrwniseundabstandvomgeleitpersoenlichinnezuhaltenxbeiverstoessenydiemirgemeldetwerdenybeh.lteichmirsofortigeab.oesung.esbetrxkomm.ndantenvorxxkomxadmxuuubootegkdosvierzwozwozwobefxz"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030676)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('n', 'l', 'k', 'o');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "cremrwllimbxdlotdindygyktjpyctcwdtpxxtnatvfzunacfcqlwdqrfwqnxjgmaswakgzbkmaeaknzporyahwfxyap"sv;
  constexpr std::string_view expected = "uuujagdkeineveraenderungengegwnleitnrxeinsviersiebenxxadmxwwwestlxostseeltnrxeinsfuenfzwobbv"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030679)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('j', 'd', 'p', 'c');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "qghubzapkaehqmrjtwewbtdbrisuvljmkbspdkzasgjsipxfsopblyqvppraudzxdwrwazhjnanmbjrizdyrqjvt"sv;
  constexpr std::string_view expected = "eomxadmxuuzbooteyfduuuaesbxytorpxinspektionyuuutendermosellonvonkrefeldxxeinseinsviernul"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030681)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "efmqabguinkxcjordpzthwvlys"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, BETA, V, VI, VIII> m4;
  m4.setInitialRotorPosition('y', 'o', 's', 'z');
  m4.setRingstellung('a', 'a', 'e', 'l');
  constexpr std::string_view input    = "lanotctouarbbfpmhphgczxtdygahgufxgewkblkgjwlqxxtgpjjavtoyjfgslppqihzfxoebwiiekfzlcloaqjuljoyhssmbbgwhzanvoiipyrbrtdjqdjjoqkcxwdnbbtyvxlytapgveatxsonpnynqfudbbhhvwepyeydohnlxkzdnwrhduwujumwwviiwzxiviuqdrhymncyefuapnhotkhkgdnpsaknuaghjzsmjbmhvtreqedgxhlzwifuskdqvelnmimithbhdbwvhdfyhjoqihortdjdbwxemeayxgyqxohfdmyuxxnojazrsghplwmlrecwwutlrttvlbhyoorglgowuxnxhmhyfaacqekthsjw"sv;
  constexpr std::string_view expected = "krkrallexxfolgendesistsofortbekanntzugebenxxichhabefolgendenbefehlerhaltenxxjansterledesbisherigxnreichsmarschallsjgoeringjsetztderfuehrersieyhvrrgrzssadmiralyalsseinennachfolgereinxschriftlschevollmachtunterwegsxabsofortsollensiesaemtlichemassnahmenverfuegenydiesichausdergegenwaertigenlageergebenxgezxreichsleiteikktulpekkjbormannjxxobxdxmmmdurnhfkstxkomxadmxuuubooiexkp"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030682)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('m', 'v', 'y', 'y');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "piarmjtbfrgmebdsbogcrvbcoxyohrwdlqixqycxzskflqmsimtqbnzdtxdqivfuygliatlerqyqksixmmzukztvfcjppfvgzgoe"sv;
  constexpr std::string_view expected = "fffddduuumstvinvonhakfroennelqaufgggzwonulzwoneuxuubzwovomzwoachtxvserxxjhrchtjhiernichteinzelgufenf"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030683)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('f', 'h', 'f', 'a');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "pjvsrppqdgkldenenwljlymarzjgdkdpftkrkwfbvzsvcngilvuwqrvydnqpjdhitdkodtssoqaajsjsgzwexujjwjazeycascaq"sv;
  constexpr std::string_view expected = "gruppenmarymhmituuudreinulzwovirunbuugzwofunfdreiochtnachtravemuevdevvvuuudreinuleinsvirkkmarbachkkm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030684)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('v', 'y', 'a', 'a');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "rfbywkikeldchbsxunfjfsnrrvfwasxylqcqfadyjxntbmvlrdcgulowhtbgwussoqhgayedkmjdngvznzfoxfkmibkqnxfdwfivgcymjvqckyqfbhykzscj"sv;
  constexpr std::string_view expected = "vvvuuuvirsobennuleinsxxmituuuvirsibennulzwoyvirsibennuldreiyzwodreisechseinsyzwodreidreiachteinsdreioitnachwzstenpassirt"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030685)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('q', 'x', 'f', 'w');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "fcjynblbwhtrxxwpixglgosslkcfxbfiernbtnnwdprxgbeqcxwxspalaxwzkkqgeydwajcoigvkqqchkpvldxptzofebrdoiemukgcncekiclldegcxmnpdmipuuxhjgrdzaruwdroufyfviuqfefurwgmbpvmgdlgvnunpkfkgsyahexxwurjxnjtsrqwbrdsjubvlrsydpcmelcvccmgvrnvreyqigzibwgil"sv;
  constexpr std::string_view expected = "komxadmxuuubooteysssmcmhhhsssosthfxdxufhostvonvonchefvierteuudflottxswgnemuendeankeraufxmarschnachhoerupyyhaffangetretenxstellenynswinemuendehabenxzusatzfuerleitungxxgusnavfritzuebelstelltgegenstellenverkehrabzwonullnullnulluhreinbt"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030686)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('x', 'v', 'l', 'i');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "iaaoveuexxpjyraewtcukipwratczapvsmymwtehsxrvtrhcftesboehkvgnfclvwdjxqosqnkbgzyllgzlcvuqlqbmadlqekvbfriea"sv;
  constexpr std::string_view expected = "spruchschliesselvonffftttmiluhrzeitgrupseeinszwozhoviersofortwergebenydaffftttnichtzuloesenfunkleitungxz"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030687)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('p', 'i', 'w', 'm');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "gcmalctwampleigdfczlugvywbetkrmlfnjexrzmtyscuiwqkhfyujaskiqdzpdqhzgonwvnbksfymyjpftpajzciambzpkaqysxdwsxrkkupnbcmbrfpvfkgzbvxvydaulnwlazxtghsqmdthshevlvwslu"sv;
  constexpr std::string_view expected = "neissefurkcrvxkptxheilmanndvvfangbtxzwovierxxxelabgabedurchgefuhrtxkuriermitscaluevselmitcelnochnichteeugetroffenxfrggesolliqhhierwzrtwnojsrwarnemgndqffhenm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030688)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('j', 'm', 'l', 'w');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "nzeezplzmgwwmxiubhwvclfcukvrjfvjhbsejlacvqknquhtxuqijtchsuumbcfqculagjacnzduggpmfpvbnngahbopalebvqhfbdwsbaqbgnoknbnmriydaznpunbpatlwpclildtszinjmhsngflwvtjyxbssnmohkdxcbnpifcfvdhztxycfsbhrequicsstjfamfjaqjfduzvjtcveuglmerrhlcwfsiainjonbjsacybfqtlyakghiqtnmuichacsryufirdwyidfdgwtuoqbgcisypwfcmpepcemubdxhrljibatrcrlmpjztzrvfikrndkelygicjudealjdjjheomuxauuajiuspeihjuzfmudyktkhfajsvijwlfdejnpcjvbupinrajwibpdngwlyuqgvddegdkruzkqibmdsdgbnqcbslgplhojjcnzpvornzfivudirpcoxoqxf"sv;
  constexpr std::string_view expected = "uuuyystuetzpunktwesermuendeytttfffeinsfunfyttcfffeinssibenvonvonfxdxuuuostvvvoooxxaufdortxfffttteinsfunfvierneunyyzwoneunvomzgoneunxvierxxeinskkvondenfunfnzltonmeqxerfuegbarenhrovijdtetwadreinultonnenmoeglichstvollstaendigeuuuyybootsausrupstunpenzmsammenstellenundmittttfffeinsfunfnnchhqlgolrndverlagernxzwokkrestproviantvonetwazwonultonnenmittttffftinssibenanjsaarjrenwsburgabgebenxzusatzvuertttfffeinsfunfundtttfffeinssibenxxsofortauslaufennachwesermuendexbestaetigencwq"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030689)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('k', 'p', 'v', 'g');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "dunkcanqmigsfkqxuwstqdkqesdjgkyywbskxaxcgzmutakeqbnqwxenuxtdfojnepdjmirzggaaamkwzmfkoskoyebkffpdimtlgyaqsrzgqvodylsfebcewhbvlfhywcronyfufvozvforzsqimsrcxsrzqfwzuatzdoampmfowxnmcdiyymtyxbnl"sv;
  constexpr std::string_view expected = "leitungvonvoneinsneunxuuuflottfffttteinszwozwovieryysezhszwohiergeloestxverschluesseltnachrrrhhhvvvxinhaltxxuuucaakkkvonvonwoewezwonxeinsdreieinsfuenfbhransteuerungslonnejfehmarnsuedwestju"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030690)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('t', 'b', 'f', 's');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "eqtnqsdbfjhwgkhphxefoygezpjmhzcikpcimpsiguzmgtiwbrtfwejtdiljjdpjvmbvuxkgsvxpezerjxzfwwvcpssfkxbsitwfkobjxxyzdyjs"sv;
  constexpr std::string_view expected = "uuuvirsibennuleinsananeinsnulxsssdddxxerbitteweitergeleitvonroteinsdreiaaanachhoeruphaffamzwoofunfxnuldreiuhrrlt"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030691)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('i', 'i', 'd', 'h');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "iyqmowapyiyeolewbezyrvlfrceowtryqiyfrasbsaxyymvdcejjdfuivjmonuagmswjmyitcdqfhnynpobwfaitlhnt"sv;
  constexpr std::string_view expected = "viruufflottlxvvvuuuvirsiuennuleinsxxerbittejkieljfuerschleifenfahrteinsvirtageueberfaelligtk"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030692)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('n', 'g', 'h', 'y');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "hdqqrdlcwfzvivcruicvnhdqislnmwcoixtbgpmkkqbgvhclelodactdlcjzpsxxctibewomjskpwvbvqcteijtjzsibksvikhwzovqojqttplkm"sv;
  constexpr std::string_view expected = "diefunkspruechemituhrzeitjruppeneinsneunzwoeinsyyeinsfunffunfzwosindnichtgeloestwordenxneuhergebenvvvfunkoeitung"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030693)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('l', 'p', 'w', 'j');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "nrnrsecndekhlhjimhlccoilhtwsmpxsgpgfteuburwwmszmpenlqayeojcqtzeyrmhytdufbzywmfvqesqgywtohwkdsumorbgzirjeewcqkbuzjyjrgopxdtwuenuiokvtdvnrvewkdnp.jaf.....wltpqayu.xfpx.uahktqtvyouzkmzyehvrsrgjjyizuphkxbpbpwkuruygxhgklj"sv;
  constexpr std::string_view expected = "komxadmxuuubooteyfxdxuuuausbxvonvonjottowuenschexxueberwegzwoywegdreiundwegvieralleinmarschnachjneustadtjangetretenxmarschfahrteinszwosmschaltu.ggr.....enundnnn.bbxn.rwegenkarteninwarnemuendeuedrostocknichtbekommenxp"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030694)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('r', 'c', 'p', 'o');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "vbbhsytwzeedgkycakyvwbwuuzvzigctbzlzyuhywilfyupbipcm"sv;
  constexpr std::string_view expected = "pllevonvonzehnxsidixxhafenwarnemuendefeindbesetztchv"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030695)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('v', 'i', 'n', 'v');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "wfakacriwufsrwtorgfonhjtjxwyxzbraaboiukozpzbsvnhraazpzyhavszcdejguiqgwxbbmzzgcbfuglkecwm"sv;
  constexpr std::string_view expected = "leitungvvvuuuifuexzpktxwwwhavenxxffftttzwonuleinsdreierledigtxinhaatxxfffttteinszwozwovi"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030696)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('d', 'l', 'l', 's');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "dzwssuyrttvlnzntrvslzqowrtxyrzvxrrcdttfanrwkiwkgldcjdespeeciuonjprpbzoxikpfdqboujdfaftxksjcqdccrcxvlzrpa"sv;
  constexpr std::string_view expected = "toniananchefzwosechsuuuflottxxumuzwvdreisechszwobeipositioneinszwodoragetroffenxfolgeverbandmitgggsieben"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030697)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('g', 'h', 'h', 'i');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "wtrtbzbrbwceugzrplprvioohfijhiranyqpktcwpogofzyoyyzdwjzvfcdupzifizguedvehwpv"sv;
  constexpr std::string_view expected = "fxdxuuuvstvvvtttfffeinssibenxxffftsaeinsneunzwosibenlyachtneunxicdbestaikigt"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030698)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('w', 'q', 'y', 'r');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "vidtgybspaxvedjfkonpmxhtcnaafkxiowvczxutdgfsewgfaidhpkqvaraguaupwvrbfowo"sv;
  constexpr std::string_view expected = "tttfffzwoviervvvfxdxuuuxausbxxtravemuendebleibenxweiterebefehleatwartknx"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030701)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('y', 'r', 'w', 'r');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "itwjpxtcnniwzbgaknwcpftkehwpdjlvzwtwshkumyzzamnlmhvtvptsclaoaxevaoqnoafomcsaiuglzynpdebqf"sv;
  constexpr std::string_view expected = "zwodreonulnuluhrtravemuendereedeausohnegeleitnachjkieljaufwegdreiysechsyeinsxmarschfahrte"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030702)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('m', 'd', 'a', 'f');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "byiagvwlqkwnhfiepincohsnbkwsbrhxanecjwlgsmdmodulqagnqmodyskqvkqzjogujoszjlxpfolwykkqsxtshp"sv;
  constexpr std::string_view expected = "uuufunfdreivierkknollaukkananfunfuuuflottxnuleinszwonulbeirotnulsibengeankertxzumweitermar"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030704)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('a', 'd', 'l', 'x');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "nywnbupripmnkaymlxvpmfmgtxgqekvpnxwoknkymvrhmlglqurjppsuphyzvqunkcfsxcwnefmvnfhwqwpffjcndcrgmxagwopcfqcynhwiqprooznlwqwu"sv;
  constexpr std::string_view expected = "travemuendeyyreedemitujudreinulzwovierunduuuzwofunfdreiacrtgeankertxffftttbleibubesetztpvvvuuudreinuleinsvieytdkarbachkk"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030705)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('u', 'y', 'x', 'c');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "hvjxgdxresssxplxqlkzicekwu.zhwsjtbjubrummrdopktggqzcwrayapskzxbylxhbotjakoppzhakdtxyebokmwvstwtjxymnpntxhgfebpmpiqyjhlsgmmaapmmloxvkioyxqjb.ia..umt.ftx.fkldhptqimcbmzjfrbnv........................pwjvrphvwdteat.dwphwvjfdegekbxg.ajctvvzohici"sv;
  constexpr std::string_view expected = "uuuviersiebennuleinsyuuuvp.rsiebeneinszwoyuuudreinuleinsneunyfuenfxuuuflyttxnachrxqduuuausbxxxinabaenderungffftttvomdreinulxvierxuebernimmt.bl..jra.kym.uuviersibbennuueeesn........................ebeneinszwoxxv.nvonkomxadmxuqrw.otepppeinsxo"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030706)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('m', 'd', 'a', 'f');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "byiagvwlqkwnbhiepingohsnbkwsbrhxanecjwlgsmdmodulqagnqmodyskqvkqzjogujoszjlxpfolwykkqsxtshpcgyitekustbluzcujnfdrxgfnbwuqzdvvlujzn"sv;
  constexpr std::string_view expected = "uuufunfdreivwmrkknojlaukkananfunfuuuflottxnuleinszwonulbeirotnulsibengeankertxzumweitermarschnachtrjvemuendeerwarteqeleitjlechjm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030707)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('a', 'd', 'l', 'x');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "nywnbupripmnkrumlxvpmfogtxgqekvplxwoknkymvrhmlglqurjpihupfyzvqunkcfsxcwnefmvnfhpqwpfcjcrdcrgmxagwopgfqcynhliqprooznlwq..d..."sv;
  constexpr std::string_view expected = "travemuendeyyajedemituuudreinulzoovierunduuuzwofunfdrtlacbtgeankertxffftttbleibtbeseoztxvvvuuudreinkleinsvyeytdkarbach..k..."sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030708)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('m', 'r', 'p', 'v');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "vzgljklveoeitylrohkvjomqriffcvuituztpelmtxbtbzxxaabwlkbqulyxddmugierricezrrdpzzhepalwgekczvfhjikkdkosokqddwsiuhqgdercjypukozhytjyxungnfdggp.qtm."sv;
  constexpr std::string_view expected = "fxdxuuuostvonvontttfffeinssibenxxdurchkerztegerunginderschleuseerstnulzwondlnuluhrmfttttfffexnsfuenfbuunsbuettelausxbeabsichtiyecuxhavenzug.hen."sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030709)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('t', 'h', 'n', 'r');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "vdtlyzainsdvhvdpkwygayhobiligmyxmsedqsrarvdlkalgfhandfyubejvxxnmceoidjsjysyieldayslzfuljnlocecmjcejglnpklfvfffskwacysldxjgfhunwajle.xhy.geb.qts.quu."sv;
  constexpr std::string_view expected = "funkspruchmituhrzeitgruppezwozwozwoeinshiersehrverstuemmeltundchviernulxgruppevollkommenunklarxnachpruefenusdneuverschluesseltabset.enx.fun.lei.ung."sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030710)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('g', 'c', 'x', 'o');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "dxersszklrohuryimndpiaqwwydrmeosjwtffkiptwemnufkoxtklojykighcfwfffhlosfibgwidqvqyxqkrphi.kjq"sv;
  constexpr std::string_view expected = "komxadmxuuubooteyfuenfxuuuflottxyvierxuuuflottxvvvuuudreinuldreinulkkluttmannkkxxmituuud.ein"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030711)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('w', 'h', 'b', 't');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "dlsmybzrapxzjhsegrmddu.oarwgdalkguddnrvjzilrzqnssxndgrseemnathcezbhrcekwgkozundkerarve.lxwpycumncznj"sv;
  constexpr std::string_view expected = "funfuuuflottxvonvonzwo.echsuuuflottxxvoraussichtlicheseintreffenuuuzwodreisechsfunfink.eldreixfunfxm"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030712)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "aqhijflcdepgmvukbrzyonwxts"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_b, GAMMA, IV, III, VIII> m4;
  m4.setInitialRotorPosition('f', 'u', 'r', 'o');
  m4.setRingstellung('a', 'a', 'c', 'u');
  constexpr std::string_view input    = "eflpbhcfkmrpfqyxageduvasmxlymbprytwszmjchzivdjybpmnhrapdlztabqhfiosbqiblrwowaovsciibzddrenhdgkvpczguwmco"sv;
  constexpr std::string_view expected = "xuuuflottxvvvuuufunfdreivierkknollaukkeinsachtuhrimgeleitvvvzwonuleinsviervonrotnuleinsbisrotnulsiebenfh"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}

TEST(EnigmaM4Tests, P1030713)
{
  // clang-format off
  struct PlugboardValue{ std::string_view value = "abpgjidhfetzsoncuwmkqvrxyl"sv; };
  // clang-format on
  enmach::EnigmaM4<Plugboard<PlugboardValue>, UKW_c, GAMMA, V, II, VIII> m4;
  m4.setInitialRotorPosition('z', 'p', 'e', 'u');
  m4.setRingstellung('a', 'a', 'f', 'b');
  constexpr std::string_view input    = "mpsanxaasrpbmxmnjmjyypugpfzoyaeqievwioxhrvjeckafvasoielmfybygabxmywoivimkgba"sv;
  constexpr std::string_view expected = "leitungvvvuuustuetzpktxwwwhavenxxfffttteunszwozwovierhuermitvrrhhhvvvgeloest"sv;
  std::string output = decrypt(m4, input);
  ASSERT_EQ(expected, output);
}
