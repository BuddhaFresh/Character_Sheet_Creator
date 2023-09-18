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



class BRP_human_base
{
private:
  bool EDUCATION_STAT;
  bool SKILL_CATEGORY;
  bool SKILL_CATEGORY_SIMPLE;
  bool WINGED_CHARACTER;
  bool INCREASED_PERSONAL_SKILL_POINTS;
  bool SANITY;
  bool HIT_POINTS_PER_LOCATION;
  bool FATIGUE_POINTS;
  bool EXPERIENCE_BONUS;
  bool TOTAL_HIT_POINTS;
  bool DISTINCTIVE_FEATURES_BASIC;
  bool DISTINCTIVE_FEATURES;
  int POWER_LEVEL;

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
  void SettingsSwitches();
  void ExpBonus(int E);
  int FatiguePoints(int A, int B);
  void SanityPoints(int G);
  int EDUstat();
  void SkillCategory();
  void Skills();
  void ProfessionSkillSet();
  void PersonalSkillSet();
  int CharacteristicRoll(int r);
  int Born();
  void OwnLanguage();
  void HPbyLocation(int B);
  std::string DamageBonus();
  int HitPoints();
  void PickJobSkills();
  int MajorWounds();
  std::string DistinctiveFeatures();
  void Professions();
  void PersonalityPick();
  std::string RandGender();
  std::string HandDom();
  int SkillRatingMaximum();
  int ProSkillPointsPool();
  int PerSkillPonitsPool();
  void HeightandWeight();
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

  void fullrandom(RandomSetUp& WOW);
  void consoleChar(RandomSetUp& WOW);
  void printChar(RandomSetUp& WOW);
};