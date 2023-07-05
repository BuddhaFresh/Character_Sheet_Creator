#include "../../menus.h"

class BRP_human_base
{
public:
  int Roll0;//INT default
  int Roll1;//SIZ default
  int Roll2;//STR default
  int Roll3;//CON default
  int Roll4;//POW default
  int Roll5;//DEX default
  int Roll6;//CHA default
  int STR;
  int CON;
  int SIZ;
  int INT;
  int POW;
  int DEX;
  int CHA;
  int MOV;
  int Age();
  int CharacteristicRoll();
  int DamageBonus();
  int HitPoints();
  int MajorWounds();
  int ProSkillPointsPool();
  int PerSkillPonitsPool();

  std::string CharName;
  std::string PlayerName;

  void fullrandom();
  };