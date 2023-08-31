#pragma once
#include <iostream>
#include <time.h>
#include <string>

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