#include "../../menus.h"

//Class declarations

class BRP_human_base
{
public:
  int STR;
  int CON;
  int POW;
  int DEX;
  int CHA;
  int INT;
  int SIZ;
  BRP_human_base(int a, int b, int c, int d, int e, int x, int y);
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