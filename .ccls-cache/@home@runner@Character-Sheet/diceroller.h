#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h> //random number fucntions
#include <random>
#include <cstdlib> //C standard library; std

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