#include "diceroller.h"
#include "menus.h"

// RandomSetUp class functions
void RandomSetUp::randomSeed() {
  currentSeed = static_cast<unsigned int>(time(nullptr));
  mt_rando.seed(currentSeed);
}

void RandomSetUp::userSeed() {//see if I can't turn seedinput into a char array and convert into an int with a limit of billion and reduced if over the 2.1 billion positive int value and increase if less then -2.4 billion negittive int value.
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
int Dice::Die(int MIN, int MAX){ 
  std::uniform_int_distribution<int> diecast(MIN, MAX);
  return diecast(RANDOMCORE.mt_rando);
}

//for loop for multi rolls with vector output
void Dice::ManyDice(int MIN, int MAX, int ROLLS){
  std::vector<int> Outcome;
  for(int i = 0; i < ROLLS; i++){
    Outcome.push_back(Die(MIN, MAX));
    std::cout << Outcome[i] << " ";
  }
}

//for loop for multi rolls that combine results
int Dice::MultiDice(int MIN, int MAX, int ROLLS){
  int result = 0;
  for(int i = 0; i < ROLLS; i++){
    result += Die(MIN, MAX);
  }
  return result;
}