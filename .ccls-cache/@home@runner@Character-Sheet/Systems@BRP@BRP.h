#pragma once
#include "../../diceroller.h"
#include "../../menus.h"
#include <map>
#include <math.h>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>


//Function declarations
void FolderOriginBRP();
int ThreeDSix();
int TwoDSixPlusSix();



//This struct takes an int argument and makes sure it is at minimum two digits starting with 0. It is set up to be able to overload the cout lines.
struct DD{
  int value;
  DD(int val) : value(val) {}

  //friend means it can be used in private methods
  //operator is for operator overloading. I don't fully grasp it yet.
  friend std::ostream& operator<<(std::ostream& os, const DD& cf){
    return os << std::setw(2) << std::setfill('0') << cf.value;
  }
};

//Skill struct
struct SkillData 
{
  std::string SkillName;
  std::string SubSkillName;
  int SkillBase;
  int SkillMod;
  int SkillCat;
};

//Weapons struct
struct WeaponsData
{
  std::string WeaponName;
  std::string WeaponSkillName;
  std::string WeaponSkillSubType;
  int WeaponSkillBase;
  std::string WeaponDMG;
  std::string WeaponAttk;
  std::string WeaponSpecial;
  std::string MeleeRng;
  int MissileRng;
  std::string WeaponHands;
  int WeaponHP;
  bool Parry;
  int STRReq;
  int DEXReq;
  std::string WeaponMal;
  int MissileAmmo;
  std::string Value;
  float WeaponSIZ;
  std::string MissileRateOfFire;
  int WeaponSkillMod;
  //std::string IDs;
};

struct Armory
{ 
  std::vector<WeaponsData> draw;
};

//Profession Wealth structs
struct WealthRange
{
  std::string WealthLevel;
  int WealthWeight;
};

struct WealthCategorys
{
  std::vector<WealthRange> range;
};



class BRP_human_base{
protected:
  virtual void Skills(int stat_dex, int stat_int, int stat_pow);
  
  std::map<std::string, SkillData>SkillTable;
  std::map<std::string, std::vector<std::string>>SubSkillTable;
  std::vector <std::string> Beliefs;
  std::vector <std::string> SkillList;
  std::vector <std::string> Art;
  std::vector <std::string> Craft;
  std::vector <std::string> Drive;
  std::vector <std::string> Heavy_Machine;
  std::vector <std::string> Knowledge;
  std::vector <std::string> Language;
  std::vector <std::string> LanguageComputerCode;
  std::vector <std::string> Pilot;
  std::vector <std::string> Preform;
  std::vector <std::string> Repair;
  std::vector <std::string> Ride;
  std::vector <std::string> Science;
  std::vector <std::string> Technical_Skill;
  std::vector <std::string> Instrument;
  std::vector <std::string> Group;
  std::vector <std::string> Region;
  std::vector <std::string> Religion;
  std::vector <std::string> Artillery;

  static bool EDUCATION_STAT;
  static bool EXPERIENCE_BONUS;
  static bool DISTINCTIVE_FEATURES;
  static bool DISTINCTIVE_FEATURES_BASIC;
  static bool FATIGUE_POINTS;
  static bool HEIGHT_AND_WEIGHT_IN_METERS;
  static bool HEIGHT_AND_WEIGHT_IN_IMPERIAL;
  static bool HIT_POINTS_PER_LOCATION;
  static bool INCREASED_PERSONAL_SKILL_POINTS;
  static int POWER_LEVEL;
  static bool SANITY;
  static bool SKILL_CATEGORY;
  static bool SKILL_CATEGORY_SIMPLE;
  static bool TOTAL_HIT_POINTS;
  static bool WINGED_CHARACTER;

  int *p_STATS[8];
  int STR;
  int CON;
  int POW;
  int DEX;
  int INT;
  int SIZ;
  int CHA;
  int EDU;
  int SAN;
  int Age;
  int HP;
  int LAH_HP;
  int Arms_HP;
  int Chest_HP;
  int MW;

  int Combat_skillcategory;
  int Communication_skillcategory;
  int Manipulation_skillcategory;
  int Mental_skillcategory;
  int Perception_skillcategory;
  int Physical_skillcategory;
  int ExperenceBonus;
  int FatiguePointsMax;
  int SanityBase;
  
private:

  int Toolong(int mod);
  std::string Convert;
  std::string DamBonus;
  std::string Profession;
  std::string Wealth;  
  std::string UnitedFeatures;
  std::string Gender;
  std::string Handedness;
  std::string Height;
  std::string Weight;
  std::string Personality;

  int TIS;
  int SanityThreshold;
  int ProSkillPtsMAX;
  int PerSkillPtsMAX;
  int SkillRatingMAX;
  int Hired;

  

  std::vector <std::string> JOBSKILLS;
  std::vector <std::string> HOBBYSKILLS;
  std::vector <std::string> PERSONALITYSKILLS; 
  std::vector <std::string> COMBATSKILLS;

  void Weapons();
  void FillSkillMod(std::map<std::string, SkillData> &SKILLLIST);
  void Faith();
  
  void ExpBonus(int E);
  int FatiguePoints(int A, int B);
  void SanityPoints(int G);
  int EDUstat();
  void SkillCategory();
    
  void SkillPointSetting(std::vector<std::string> &V_main, std::map<std::string, SkillData>&SKILLLIST, int &SkillPointsMax, int &SkillMAX);
  int CharacteristicRoll(int r);
  int Born(bool random);
    
  void HPbyLocation(int B);
  std::string DamageBonus(int T, int Z);
  int HitPoints(int C, int Z);
  void RandomProfessionSkillPick(int NumberOfPicks, std::vector<std::string> ProfessionSkills);
  void PickJobSkills();
  int MajorWounds(int H);
  std::string DistinctiveFeatures(int H);
  void Professions();
  std::string RandomCombatSkill(std::vector<std::string> &ALLSKILLS);
  void PersonalityPick(int pick);
  std::string RandGender(int X);
  std::string HandDom(int Odds);
  int SkillRatingMaximum();
  int ProSkillPointsPool();
  int PerSkillPonitsPool();
  void HeightandWeight(int z);
  int Skill_Category_Primary(int x);
  int Skill_Category_Secondary(int x);
  int Skill_Category_Negative(int x);
  void OwnLanguage(int OwnLang);
  bool IsThereADup(std::vector<std::string> LIST);
  bool IsSkillWithoutSubSkills(std::string &SKILL);
  int NumberOfSubSkills(std::string &SKILL, std::map<std::string, SkillData> &SKILLLIST);
  void RemoveDuplicates(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist);
  void CheckForDuplicatcates(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist);
  void RefillHobbySkills(std::vector<std::string> &V_main, int &MaxNumberOfSkills);
  void RemoveExtraSubSkills(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist);
  void PickHobbySkills();
  void RandomSubSkillAssignment(std::vector<std::string> &V_main);
  bool IsSubskillEmpty(std::string &SKILL, std::map<std::string, SkillData> &SKILLLIST);
  bool IsStringInVector(std::string &SKILL, std::vector<std::string> &V_main);
  void NextFreeSubskill(std::string &SKILL, int &AmountOfSubSkills, std::map<std::string, SkillData> &SKILLLIST, std::string &FreeSubSkill, std::vector<std::string> &V_main);
  void NextRandomKnownSubSkill(std::string &SKILL, int &AmountOfSubSkills, std::map<std::string, SkillData> &SKILLLIST, std::string &FreeSubSkill, std::vector<std::string> &V_main);
  bool IsThereAnyFreeSubskills(std::string &SKILL, int &AmountOfSubSkills, std::map<std::string, SkillData> &SKILLLIST, std::vector<std::string> &V_main);
  void NoFreeSubskillChoice(std::string &SKILL, int &AmountOfSubSkills, std::string &FreeSubSkill, std::vector<std::string> &V_main);
  bool NumberAtEnd(std::string &SKILL);
  void RandomSubSkillSelection(std::vector<std::string> &V_main, std::map<std::string, SkillData> &SKILLLIST, std::map<std::string, std::vector<std::string>>&SUBSKILLLIST, std::map<std::string, WeaponsData>&WEAPONSLIST);
  bool IsSkillACombatSkill(std::string &SKILL);
  bool IsSubSkillAlreadyUsed(std::string &SKILL, std::string &SUBSKILLTOCHECK, int &AmountOfSubSkills, std::map<std::string, SkillData> &SKILLLIST);
  void SubSpecialtySelection(std::string &SKILL, std::string &RAWSUBSKILL, int &AmountOfSubSkills, std::map<std::string, SkillData> &SKILLLIST, std::map <std::string, std::vector<std::string>> &SUBSKILLLIST);
  void FillCOMBATSKILLS(std::vector<std::string> &V_main, std::vector<std::string> &V_combat);
  void OnlyUniqueStringsIn(std::vector<std::string> &V_main);
  void MoveCombatSkillsToCOMBAT(std::vector<std::string> &V_combat, std::map<std::string, SkillData>&SKILLLIST);
  void RandomCombatSelecting(std::vector<std::string> &V_combat, std::map<std::string, SkillData>&SKILLLIST, std::map<std::string, WeaponsData> &WEAPONSLIST);
  void COMBATSkillModtoARMSSkillMod(std::map<std::string, SkillData>&SKILLLIST, std::map<std::string, WeaponsData> &WEAPONSLIST);

  int NumberOfHobbySkills;
  int TESTDUP;
  int SUBNUM;
  int NONSUBNUM;
  int SKILLWITHSUBNUM;
  bool TOOMANYSUBS;
  std::vector<std::string> DUPITEMS;
  std::map<std::string, int> UniqueCounts;
  std::map<std::string, int> SubskillMax;
  std::vector<std::string> SUBSTOPOP;

  
  std::map<std::string, WeaponsData>WeaponsTable;
  


public:
  BRP_human_base(int a, int b, int c, int d, int e, int x, int y, int z);


  void CharName();
  std::string CN;
  void PlayerName();
  std::string PN;

  static bool stateEDUCATION_STAT() {return EDUCATION_STAT;}
  static void flipEDUCATION_STAT(bool toggle) {EDUCATION_STAT = toggle;}

  static bool stateEXPERIENCE_BONUS() {return EXPERIENCE_BONUS;}
  static void flipEXPERIENCE_BONUS(bool toggle) {EXPERIENCE_BONUS = toggle;}

  static bool stateDISTINCTIVE_FEATURES() {return DISTINCTIVE_FEATURES;}
  static void flipDISTINCTIVE_FEATURES(bool toggle) {DISTINCTIVE_FEATURES = toggle;}
  static bool stateDISTINCTIVE_FEATURES_BASIC() {return DISTINCTIVE_FEATURES_BASIC;}
  static void flipDISTINCTIVE_FEATURES_BASIC(bool toggle) {DISTINCTIVE_FEATURES_BASIC = toggle;}

  static bool stateFATIGUE_POINTS() {return FATIGUE_POINTS;}
  static void flipFATIGUE_POINTS(bool toggle) {FATIGUE_POINTS = toggle;}

  static bool stateHIT_POINTS_PER_LOCATION() {return HIT_POINTS_PER_LOCATION;}
  static void flipHIT_POINTS_PER_LOCATION(bool toggle) {HIT_POINTS_PER_LOCATION = toggle;}

  static bool stateHEIGHT_AND_WEIGHT_IN_METERS() {return HEIGHT_AND_WEIGHT_IN_METERS;}
  static void flipHEIGHT_AND_WEIGHT_IN_METERS(bool toggle) {HEIGHT_AND_WEIGHT_IN_METERS = toggle;}
  static bool stateHEIGHT_AND_WEIGHT_IN_IMPERIAL() {return HEIGHT_AND_WEIGHT_IN_IMPERIAL;}
  static void flipHEIGHT_AND_WEIGHT_IN_IMPERIAL(bool toggle) {HEIGHT_AND_WEIGHT_IN_IMPERIAL = toggle;}  

  static bool stateSANITY() {return SANITY;}
  static void flipSANITY(bool toggle) {SANITY = toggle;}

  static bool stateSKILL_CATEGORY() {return SKILL_CATEGORY;}
  static void flipSKILL_CATEGORY(bool toggle) {SKILL_CATEGORY = toggle;}
  static bool stateSKILL_CATEGORY_SIMPLE() {return SKILL_CATEGORY_SIMPLE;}
  static void flipSKILL_CATEGORY_SIMPLE(bool toggle) {SKILL_CATEGORY_SIMPLE = toggle;}

  static bool stateINCREASED_PERSONAL_SKILL_POINTS() {return INCREASED_PERSONAL_SKILL_POINTS;}
  static void flipINCREASED_PERSONAL_SKILL_POINTS(bool toggle) {INCREASED_PERSONAL_SKILL_POINTS = toggle;}

  static int statePOWER_LEVEL() {return POWER_LEVEL;}
  static void flipPOWER_LEVEL(int toggle) {POWER_LEVEL = toggle;}

  static bool stateTOTAL_HIT_POINTS() {return TOTAL_HIT_POINTS;}
  static void flipTOTAL_HIT_POINTS(bool toggle) {TOTAL_HIT_POINTS = toggle;}

  static bool stateWINGED_CHARACTER() {return WINGED_CHARACTER;}
  static void flipWINGED_CHARACTER(bool toggle) {WINGED_CHARACTER = toggle;}

  void freebuild();
  void fullrandom();
  void consoleChar();
  void printChar();

  virtual ~BRP_human_base() {
    //delete[] p_STATS;
  };
};

class Profession{
  public:
    Profession(int JOB, int INCOME);
    int giveProfessionInt();
    std::string giveProfessionString();
    char* giveProfessionANDWealthCharArray();
    int giveWealthInt();
    std::string giveWealthString();
    ~Profession() {};
};

void SaveData(const BRP_human_base& obj, const std::string& filename);
BRP_human_base LoadData(const std::string& filename);