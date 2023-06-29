#include "menus.h"


int currentSeed;
std::string seedinput;

//RandomSetUp class functions
void RandomSetUp::randomSeed() 
{
  currentSeed = time(NULL);
  srand(time(NULL));
}

void RandomSetUp::userSeed()
{
  // Prompt for user to input their seed
  std::cout << "\nEnter seed\n";
  std::cin >> seedinput;

  // Use std::hash to convert the input string into an integer
  std::hash<std::string> strtohash;
  int seed = static_cast<int>(strtohash(seedinput));
  currentSeed = seed;

  // Providing the custom seed value
  srand(seed);
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