#include "BRP_Era.h"
#include <iostream>

BRP_human_AncientEra::BRP_human_AncientEra(int a, int b, int c, int d, int e, int x, int y, int z) : BRP_human_base(a,b,c,d,e,x,y,z){}

void BRP_human_AncientEra::OwnLanguage(){
  std::vector<std::string>AncientLanguage = {"Ug-Ugh", "Ogga-Booga", "Bam-Bam", "Yaba-Daba", "Zug-Zug", "Chi-Chi"};

  int OwnLang = ROLL.Die(0,AncientLanguage.size()-1);
  SkillTable["Language0"].SubSkillName = AncientLanguage.at(OwnLang);
  std::cout << "\n\nNumber of characters in " << AncientLanguage.at(OwnLang) << " is "<< SkillTable["Language0"].SubSkillName.length() <<"\n\n"; //testing
}