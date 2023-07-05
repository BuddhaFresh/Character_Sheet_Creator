#include "../Systems.h"
#include "../../menus.h"
#include "BRP.h"

Dice PLAY;

//GOAL FOR SCRIPT
//everything needed to make a standard Basic Role-Playing Character
//Needs to have attrabutes, diraived stats, list of relivent features, equipment(just a basic set for now)
//class BRP char with roll inputs


//BRP_human_base class

//Constructor to hold Characteristics, 
BRP_human_base::BRP_human_base(int a, int b, int c, int d, int e, int x, int y) 
{
  STR = a;
  CON = b;
  POW = c;
  DEX = d;
  CHA = e;
  INT = x;
  SIZ = y;
}

int BRP_human_base::Age()
{
  int age = 17+PLAY.Dsix();
  return age;
}

int BRP_human_base::CharacteristicRoll()
{
  return 1;
}

int BRP_human_base::DamageBonus()
{
  return 1;
}

int BRP_human_base::HitPoints()
{
  return 1;
}

int BRP_human_base::MajorWounds()
{
  return 1;
}

int BRP_human_base::ProSkillPointsPool()
{
  return 1;
}

int BRP_human_base::PerSkillPonitsPool()
{
  return 1;
}

void BRP_human_base::fullrandom()
{
  
}