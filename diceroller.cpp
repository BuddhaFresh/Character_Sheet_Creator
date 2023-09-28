#include "menus.h"
#include "diceroller.h"


//RandomSetUp class functions
void RandomSetUp::randomSeed(){
  currentSeed = static_cast<unsigned int>(time(nullptr));
  mt_rando.seed(currentSeed);
  //currentSeed = time(NULL);
  //srand(currentSeed);
}

void RandomSetUp::userSeed(){
  // Prompt for user to input their seed
  std::cout << "\nEnter seed\n";
  //std::getline(std::cin >> std::ws, seedinput);
  std::cin >> seedinput;

  //Turn string into int
  currentSeed = std::stoi(seedinput);

  // Providing the custom seed value
  srand(currentSeed);
}


//Dice class functions
int Dice::Dfour(){
  return rand() % 4 + 1;
}

int Dice::Dsix(){
  return rand() % 6 + 1;
}

int Dice::Deight(){
  return rand() % 8 + 1;
}

int Dice::Dten(){
  return rand() % 10 + 1;
}

int Dice::Dtwelve(RandomSetUp& NUM){
  std::uniform_int_distribution<int> twenty(1, 20);
  int XXX = twenty(NUM.mt_rando);
  return XXX;
}

int Dice::Dtwenty(){
  return rand() % 20 + 1;
}

int Dice::Donehundred(){
  std::uniform_int_distribution<int> hundred(1, 100);
  int XXX = 99;
  return XXX;
}

//Multi-Dice Roll

/*
pick the die to roll
how many to roll


int MultiDiceRoll(){
  int InputforDice;
  int DicePicked = 0;
  using funky = 
  std::map<int,> DChoice;
  int Rolls = 0;
  std::vector RollOutcomes;
  for (int i = 0; Rolls; i++){
    
  }
  return RollOutcomes;
}*/
