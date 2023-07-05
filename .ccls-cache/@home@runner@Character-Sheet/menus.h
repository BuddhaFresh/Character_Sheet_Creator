#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>
#include <time.h>
#include <string>
#include <functional>


class RandomSetUp 
{
  public:
    int currentSeed;
    std::string seedinput;
  
    void randomSeed();
    void userSeed();
};

class Dice
{
  public:
    int Dfour();
    int Dsix();
    int Deight();
    int Dten();
    int Dtwelve();
    int Dtwenty();
    int Donehundred();
};


int menu();