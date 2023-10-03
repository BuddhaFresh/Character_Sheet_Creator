#include "menus.h"
#include "Systems/BRP/BRP_Menu.h"
#include "Systems/BRP/BRP.h"
#include "diceroller.h"

/*
Need to make a strut for professions!
Also a strut for the currentSeed
I also added in <random> to make a "better" pRNG
*/

/*
ROADMAP
 
0. txt file version complete
 0.1 skills [IN PROGRESS]
   0.1a selecting skills based on profession by random [DONE]
   0.1b selecting personnel skills by random
   0.1c filter skills based on era/setting
     0.1cI Eras/Settings need to be picked but expandable
     0.1cII Adjust what kind of equipment can be generated
     0.1cIII Adjust what kind of skills can be selected (maybe a tag system?)
 0.2 description
   0.2a setup simple features [DONE]
   0.2b put in bool triggers for features [DONE]
   0.2c Fix Height & Weight; have a toggle for random chance range or Stat base?(CON,APP,CHR,STR,)
   0.2d Have descriptions remove and add things from the array based on Gender. Could lead to Cultural and Setting modififyers too
 0.3 page 2
   0.3a powers
   0.3b sanity
   0.3c equipment 
     0.3cI Just 3 Weapons per? 
   0.3d fatigue
   0.3e power points
   0.3f attack powers?
 0.4 hit location [DONE]
 0.5 armor
 0.6 Point Buy System Character Creater
 0.7 Free Build Character Creater
   0.7a Maybe I should of started with this and build evertyhing else around it?
1. Move BRP Menus in BRP.cpp
 1.1 Have options adjustment menu
 1.2 Move Dice Roller menu in Diceroller.cpp
   1.2a Make a multi-dice roller too
 1.3 Clean up all headers so every script is modular  
2. Load from txt file
 2.1 need to make something that reads a code on the bottom that tells it settings for layout 
 [LOADCODE: Character Name#C0DeSy$t3m#0060180090200
 Using # to seperate sections, numbers at end are raw base rolls,selections,outcomes, etc. Two digit code system sets the parameters/context for the numbers. 
 Maybe another at the end for equipment tracking.]
3. Able to edit a blank sheet (point buy and full custom edit)
4. Able to edit randomized sheet
5. Make a user defined multi-random character (txt) sheet generater
 5.1 Make each called random charcter generate a new seed, but save old current one and reapply it after the the loop [save old seed on NEW, use pointer to replace whatever was generated during the loop. DELETE after loop is complete.].
6. basic windows GUI (can do on replit?)
7. exe file installer (need to be on own pc?)
8. PDF file output (may just skip, needs a plugin)
 8.1 Fillable PDF file output (may just skip, needs a plugin)
*/


//Classes
RandomSetUp RANDOMCORE;
//RandomSetUp SEEDER;
Dice ROLL;


int main() 
{//All menus



  
  //Inputs for menus
  int mainMenuInput;
  int optionsMenuInput;
  int diceMenuInput;
  int newMenuInput;
  int charKeepInput;

  //Generate a new seed at boot
  RANDOMCORE.randomSeed();

  //Makes a new folder in Characters for any added Systems
  FolderOriginBRP();
  
  while(true) 
  {//MAIN MENU
    //std::cout << "Hello!\033c";
    std::cout << "\n\n<>~~~~~~~~~~<>~~~~~~~~~~<>~~~~~~~~~~<>\n";
    std::cout << "Welcome to Character Sheet Creator\n\t\t\tMain Menu\n";
    std::cout << "1. New Sheet\n";
    std::cout << "2. Load Sheet\n";
    std::cout << "3. Dice Roller\n";
    std::cout << "4. Options\n";
    std::cout << "\n0. Exit\n";
    std::cout << "<>~~~~~~~~~~<>~~~~~~~~~~<>~~~~~~~~~~<>\n\n";

    std::cout << "Please Enter Your Command\n";
    std::cin >> mainMenuInput;

      switch (mainMenuInput)
      {//Main menu input start    
        case 1: //New Sheet
          std::cout << "\033c";
          while(true)
          {//New Sheet menu 
            std::cout << "\n\n<>----------<>----------<>----------<>\n";
            std::cout << "\t\t\tNew Sheet Menu\n";
            std::cout << "1. DOJO [Make 5 random BRP chars]\n\n";
            std::cout << "2. DOJO [BRP menu]\n\n";
            std::cout << "3. DOJO [make random BRP char rolls]\n";
            std::cout << "\n0. Return to Main Menu\n";
            std::cout << "<>----------<>----------<>----------<>\n\n";
  
            std::cout << "Please Enter Your Command\n";
            std::cin >> newMenuInput;
            
            switch(newMenuInput)
            {//New Sheet menu input start
              case 1://temp for testing
                std::cout << "\033c";
                for (int i = 0; i < 5; i++)
                {
                 BRP_human_base BRPChar0(ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),TwoDSixPlusSix(),TwoDSixPlusSix());
                BRPChar0.fullrandom();
                BRPChar0.consoleChar();
                }
                break;
              case 2://temp for testing
                {
                std::cout << "\033c";
                BRP_menu(); 
                break;
                }
              case 3://temp for testing
                {//case 3
                  std::cout << "\033c";
                  BRP_human_base BRPChar0(ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),TwoDSixPlusSix(),TwoDSixPlusSix());
                  BRPChar0.PlayerName();
                  BRPChar0.fullrandom();
                  BRPChar0.consoleChar();
                  
                  while(true)
                  {//save character menu
                    std::cout << "\n\n<>##########<>##########<>##########<>\n";
                    std::cout << "\t\tSave this charcater?" << std::endl;
                    std::cout << "1. Save as txt file" << std::endl;
                    std::cout << "\n0. Return" << std::endl;
                    std::cout << "<>##########<>##########<>##########<>\n\n";
                    std::cin >> charKeepInput;
                    
                    switch(charKeepInput)
                    {//save character input
                      case 1:
                        std::cout << "\033c";
                        BRPChar0.CharName();
                        BRPChar0.printChar();
                        break;
                      case 0:
                        std::cout << "\033c";
                        break;
                      default:
                        std::cout << "\033c";
                        std::cout << "\nNot one of the options";
                        break;
                    }//save character input end
                    
                    if (charKeepInput == 0 || charKeepInput == 1){
                      std::cout << "\033c";
                      break;
                    };
                    
                  }//save character menu end
                  
                break;
                  
                }//case 3 end
              default:
                std::cout << "\033c";
                std::cout << "Please enter one of the listed options";
                break;
            }//New Sheet menu input end
            if (newMenuInput == 0){
              std::cout << "\033c";
              break;
            };
          }//New Sheet menu end
          break;
          
        case 2: 
          {//Load Sheet
          std::cout << "\033c";
          std::cout << "\nLoad Sheet not availible\n\n";
          break;
          }
        
        case 3: //Dice Roller
          std::cout << "\033c";
          while (true)
            {//Dice Roller menu
              std::cout << "\n\n<>++++++++++<>++++++++++<>++++++++++<>\n";
              std::cout << "\t\t\tDice Choices\n";
              std::cout << "1. Roll a D4\n";
              std::cout << "2. Roll a D6\n";
              std::cout << "3. Roll a D8\n";
              std::cout << "4. Roll a D10\n";
              std::cout << "5. Roll a D12\n";
              std::cout << "6. Roll a D20\n";
              std::cout << "7. Roll a D100\n";
              std::cout << "\n0. Return to Options\n";
              std::cout << "<>++++++++++<>++++++++++<>++++++++++<>\n\n";
      
              std::cout << "Please make your selection\n";
              std::cin >> diceMenuInput;
  
              switch (diceMenuInput)
              {//Dice Roller input
                case 1:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a four-sided die and got a " << ROLL.Dfour() << std::endl;
                  break;
                case 2:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a six-sided die and got a " << ROLL.Dsix() << std::endl;
                  break;
                case 3:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled an eight-sided die and got a " << ROLL.Deight() << std::endl;
                  break;
                case 4:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a ten-sided die and got a " << ROLL.Dten() << std::endl;
                  break;
                case 5:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a twelve-sided die and got a " << ROLL.Dtwelve() << std::endl;
                  break;
                case 6:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a twenty-sided die and got a " << ROLL.Dtwenty() << std::endl;
                  break;
                case 7:
                  std::cout << "\033c";
                  std::cout << "\nYou rolled a hundred-sided die and got a " << ROLL.Donehundred() << std::endl;
                  break;
                case 0:
                  std::cout << "\033c";
                  break;
                default:
                std::cout << "\033c";
                 std::cout << "Please enter one of the listed options";
                 break;
              }//Dice Roller input end
              if (diceMenuInput == 0){
                std::cout << "\033c";
                break;
              };
            }//Dice Roller menu end
            break;
        
        case 4: //Options
        std::cout << "\033c";
        while (true)  
        {//Options sub-menu start
          std::cout << "\n\n<>==========<>==========<>==========<>\n";
            std::cout << "\t\t\t\tOptions\n";
            std::cout << "1. Input Manual Seed \n(Current Seed: "<< RANDOMCORE.currentSeed <<")\n";
            std::cout << "2. Generate New Seed\n";
            std::cout << "\n0. Return to Main Menu\n";
            std::cout << "<>==========<>==========<>==========<>\n\n";
  
            std::cout << "Please Enter Your Command\n";
            std::cin >> optionsMenuInput;
          
            switch (optionsMenuInput)
              {//Options input
                case 1:
                  std::cout << "\033c";
                  RANDOMCORE.userSeed();
                  break;
                case 2:
                  std::cout << "\033c";
                  std::cout << "\nNew Seed has been generated\n";
                  RANDOMCORE.randomSeed();
                  break;
                case 0:
                  std::cout << "\033c";
                  std::cout << "\nReturning to Main Menu\n";
                  break;
                default: 
                  std::cout << "\033c";
                  std::cout << "\nNot an availible command\n";
                  break;
              }//Options input end
          if (optionsMenuInput == 0){
            std::cout << "\033c";
            break;
          }; 
        }//Options sub-menu end
        break;
        case 0: //Exit
          std::cout << "\033c";
          std::cout << "\nExiting Program\nGood Bye!\n";
          return 0;
        default: 
          std::cout << "\033c";
          std::cout << "\nNot an availible command\n";
          break;
      }//Main menu input end
  }//MAIN MENU end
}//All menus end