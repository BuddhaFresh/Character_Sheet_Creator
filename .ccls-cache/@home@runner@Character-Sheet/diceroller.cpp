#include "menus.h"
#include "diceroller.h"


//RandomSetUp class functions
void RandomSetUp::randomSeed() 
{
  currentSeed = time(NULL);
  srand(currentSeed);
}

void RandomSetUp::userSeed()
{
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
int Dice::Dfour()
{
  int x = rand() % 4 + 1;
  return x;
}

int Dice::Dsix()
{
  int x = rand() % 6 + 1;
  return x;
}

int Dice::Deight()
{
  int x = rand() % 8 + 1;
  return x;
}

int Dice::Dten()
{
  int x = rand() % 10 + 1;
  return x;
}

int Dice::Dtwelve()
{
  int x = rand() % 12 + 1;
  return x;
}

int Dice::Dtwenty()
{
  int x = rand() % 20 + 1;
  return x;
}

int Dice::Donehundred()
{
  int x = rand() % 100 + 1;
  return x;
}