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
private:
  static bool EDUCATION_STAT;
  static bool EXPERIENCE_BONUS;
  static bool DISTINCTIVE_FEATURES;
  static bool DISTINCTIVE_FEATURES_BASIC;
  static bool SKILL_CATEGORY;
  static bool SKILL_CATEGORY_SIMPLE;
  static bool HEIGHT_AND_WEIGHT_IN_METERS;
  static bool HEIGHT_AND_WEIGHT_IN_IMPERIAL;
  // static bool WINGED_CHARACTER;
  // static bool INCREASED_PERSONAL_SKILL_POINTS;
  // static bool SANITY;
  // static bool HIT_POINTS_PER_LOCATION;
  // static bool FATIGUE_POINTS;
  // static bool TOTAL_HIT_POINTS;
  // static int POWER_LEVEL;

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

  std::string Religion;
  std::string DamBonus;
  std::string Profession;
  std::string Wealth;  
  std::string UnitedFeatures;
  std::string Gender;
  std::string Handedness;
  std::string Height;
  std::string Weight;
  std::string Personality;

  int Combat_skillcategory;
  int Communication_skillcategory;
  int Manipulation_skillcategory;
  int Mental_skillcategory;
  int Perception_skillcategory;
  int Physical_skillcategory;
  int ExperenceBonus;
  int FatiguePointsMax;
  int SanityBase;

  int TIS;
  int SanityThreshold;
  int ProSkillPtsMAX;
  int PerSkillPtsMAX;
  int SkillRatingMAX;
  int Hired;

  std::vector <std::string> Beliefs;

  std::vector <std::string> SkillList;
  std::vector <std::string> Art;
  std::vector <std::string> Craft;
  std::vector <std::string> Heavy_Machine;
  std::vector <std::string> Knowledge;
  std::vector <std::string> Language;
  std::vector <std::string> Pilot;
  std::vector <std::string> Preform;
  std::vector <std::string> Repair;
  std::vector <std::string> Ride;
  std::vector <std::string> Science;
  std::vector <std::string> Technical;

  std::string JOBSKILLS[10];
  std::string HOBBYSKILLS[0];

  void Weapons();
  void FillSkillMod();
  void Faith();
  
  void ExpBonus(int E);
  int FatiguePoints(int A, int B);
  void SanityPoints(int G);
  int EDUstat();
  void SkillCategory();
  void Skills(int x, int i, int p);
  void ProfessionSkillSet();
  void PersonalSkillSet();
  int CharacteristicRoll(int r);
  int Born();
  void OwnLanguage();
  void HPbyLocation(int B);
  std::string DamageBonus(int T, int Z);
  int HitPoints(int C, int Z);
  void PickJobSkills();
  int MajorWounds(int H);
  std::string DistinctiveFeatures(int H);
  void Professions();
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


  std::map<std::string, SkillData>SkillTable;
  std::map<std::string, WeaponsData>WeaponsTable;


public:
  BRP_human_base(int a, int b, int c, int d, int e, int x, int y);

  void CharName();
  std::string CN;
  void PlayerName();
  std::string PN;

  //void SettingsSwitches();
  static bool stateEDUCATION_STAT() {return EDUCATION_STAT;}
  static void flipEDUCATION_STAT(bool toggle) {EDUCATION_STAT = toggle;}

  static bool stateEXPERIENCE_BONUS() {return EXPERIENCE_BONUS;}
  static void flipEXPERIENCE_BONUS(bool toggle) {EXPERIENCE_BONUS = toggle;}

  static bool stateDISTINCTIVE_FEATURES() {return DISTINCTIVE_FEATURES;}
  static void flipDISTINCTIVE_FEATURES(bool toggle) {DISTINCTIVE_FEATURES = toggle;}
  static bool stateDISTINCTIVE_FEATURES_BASIC() {return DISTINCTIVE_FEATURES_BASIC;}
  static void flipDISTINCTIVE_FEATURES_BASIC(bool toggle) {DISTINCTIVE_FEATURES_BASIC = toggle;}

  static bool stateSKILL_CATEGORY() {return SKILL_CATEGORY;}
  static void flipSKILL_CATEGORY(bool toggle) {SKILL_CATEGORY = toggle;}
  static bool stateSKILL_CATEGORY_SIMPLE() {return SKILL_CATEGORY_SIMPLE;}
  static void flipSKILL_CATEGORY_SIMPLE(bool toggle) {SKILL_CATEGORY_SIMPLE = toggle;}

  static bool stateHEIGHT_AND_WEIGHT_IN_METERS() {return HEIGHT_AND_WEIGHT_IN_METERS;}
  static void flipHEIGHT_AND_WEIGHT_IN_METERS(bool toggle) {HEIGHT_AND_WEIGHT_IN_METERS = toggle;}
  static bool stateHEIGHT_AND_WEIGHT_IN_IMPERIAL() {return HEIGHT_AND_WEIGHT_IN_IMPERIAL;}
  static void flipHEIGHT_AND_WEIGHT_IN_IMPERIAL(bool toggle) {HEIGHT_AND_WEIGHT_IN_IMPERIAL = toggle;}  

  void freebuild();
  void fullrandom();
  void consoleChar();
  void printChar();
};