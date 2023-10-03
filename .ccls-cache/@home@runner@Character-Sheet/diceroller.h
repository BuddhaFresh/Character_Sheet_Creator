#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h> //random number functions
#include <random> //random number generator, using a Mersenne twister
#include <cstdlib> //C standard library; std


class RandomSetUp{
  public:
    int currentSeed;
    std::string seedinput;
    std::mt19937 mt_rando;
  
    void randomSeed();
    void userSeed();
};

class Dice{
  public:
    int Die(int MIN, int MAX);
    void ManyDice(int MIN, int MAX, int ROLLS);
    int Dfour();
    int Dsix();
    int Deight();
    int Dten();
    int Dtwelve();
    int Dtwenty();
    int Donehundred();

};

extern RandomSetUp RANDOMCORE;
extern Dice ROLL;