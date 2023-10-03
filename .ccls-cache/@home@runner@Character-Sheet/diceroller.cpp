#include "diceroller.h"
#include "menus.h"

// RandomSetUp class functions
void RandomSetUp::randomSeed() {
  currentSeed = static_cast<unsigned int>(time(nullptr));
  mt_rando.seed(currentSeed);
}

void RandomSetUp::userSeed() {
  // Prompt for user to input their seed
  std::cout << "\nEnter seed\n";
  //std::getline(std::cin >> std::ws, seedinput);
  std::cin >> seedinput;

  // Turn string into int
  currentSeed = std::stoi(seedinput);

  // Providing the custom seed value
  mt_rando.seed(currentSeed);
}

// Dice class methods

//General dice roller method
/*
int Dice::Die(int MIN, int MAX) { 
  std::uniform_int_distribution<int> diecast(MIN, MAX);
  return diecast(RANDOMCORE.mt_rando);
}

//for loop for multi rolls
void Dice::ManyDice(int MIN, int MAX, int ROLLS) {
  std::vector<int> Outcome;
  for(; ROLLS > 0; ROLLS--){
    int X = Die(MIN, MAX);
    Outcome.push_back(X);
  }
  std::cout << Outcome << " ";
}
*/

int Dice::Dfour() { 
  std::uniform_int_distribution<int> four(1, 4);
  return four(RANDOMCORE.mt_rando);
}

int Dice::Dsix() { 
  std::uniform_int_distribution<int> six(1, 6);
  return six(RANDOMCORE.mt_rando);
}

int Dice::Deight() { 
  std::uniform_int_distribution<int> eight(1, 8);
  return eight(RANDOMCORE.mt_rando);
}

int Dice::Dten() { 
  std::uniform_int_distribution<int> ten(1, 10);
  return ten(RANDOMCORE.mt_rando);
}

int Dice::Dtwelve() {
  std::uniform_int_distribution<int> twelve(1, 12);
  return twelve(RANDOMCORE.mt_rando); 
}

int Dice::Dtwenty() { 
  std::uniform_int_distribution<int> twenty(1, 20);
  return twenty(RANDOMCORE.mt_rando); 
}

int Dice::Donehundred() {
  std::uniform_int_distribution<int> onehundred(1, 100);
  return onehundred(RANDOMCORE.mt_rando); 
}
/*{
  std::uniform_int_distribution<int> hundred(1, 100);
  return hundred(NUM.mt_rando);
}*/

// Multi-Dice Roll

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
