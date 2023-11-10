#include "menus.h"
#include "Systems/BRP/BRP_Menu.h"
#include "Systems/BRP/BRP.h"
#include "diceroller.h"

/*
Need to make a strut for professions!
Maybe weapons as classes?
Items as classes can allow for materials composition, condition, and possible unique qualities or identifiers (kind of like my weapon/equipment maker for Iridis)
Should experiment with Inheritance... break up the BRP_Char.
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
   0.2c Fix Height & Weight; have a toggle for random chance range or Stat base?(CON,APP,CHR,STR,) [DONE]
   0.2d Have descriptions remove and add things from the array based on Gender. Could lead to Cultural and Setting modififyers too
 0.3 page 2
   0.3a powers
   0.3b sanity
   0.3c equipment 
     0.3cI Just 3 Weapons per? [DONE]
   0.3d fatigue
   0.3e power points
   0.3f attack powers?
 0.4 hit location [DONE]
 0.5 armor
 0.6 Point Buy System Character Creater
 0.7 Free Build Character Creater
   0.7a Maybe I should of started with this and build evertyhing else around it?
1. Move BRP Menus in BRP.cpp [DONE, made it's own cpp file]
 1.1 Have options adjustment menu [DONE]
 1.2 Move Dice Roller menu in Diceroller.cpp [DONE]
   1.2a Make a multi-dice roller too [DONE]
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
Dice ROLL;


int main() 
{//All menus

  //Inputs for menus
  int mainMenuInput;
  int optionsMenuInput;
  int newMenuInput;
  int charKeepInput;

  //Generate a new seed at boot
  RANDOMCORE.randomSeed();

  //Makes a new folder in Characters for any added Systems
  FolderOriginBRP();

  
  
  while(true){//MAIN MENU

    
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

      switch (mainMenuInput){//Main menu input start    
        case 1: //New Sheet
          std::cout << "\033c";
          while(true){//New Sheet menu 
            std::cout << "\n\n<>----------<>----------<>----------<>\n";
            std::cout << "\t\t\tNew Sheet Menu\n";
            std::cout << "1. Basic Roleplaying, Universal Game Engine\n";
            
            std::cout << "\n0. Return to Main Menu\n";
            std::cout << "<>----------<>----------<>----------<>\n\n";
  
            std::cout << "Please Enter Your Command\n";
            std::cin >> newMenuInput;
            
            switch(newMenuInput){//New Sheet menu input start
              case 1:
                std::cout << "\033c";
                BRP_menu(); 
                break;
              case 2:
              case 3:
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
          
        case 2:{//Load Sheet
          std::cout << "\033c";
          std::cout << "\nLoad Sheet not availible\n\n";
          break;
          }
        
        case 3: //Dice Roller
          std::cout << "\033c";
          DiceRollerMenu();
          break;
        
        case 4: //Options
        std::cout << "\033c";
        while (true){//Options sub-menu start
          std::cout << "\n\n<>==========<>==========<>==========<>\n";
            std::cout << "\t\t\t\tOptions\n";
            std::cout << "1. Input Manual Seed \n(Current Seed: "<< RANDOMCORE.currentSeed <<")\n";
            std::cout << "2. Generate New Seed\n";
            std::cout << "\n0. Return to Main Menu\n";
            std::cout << "<>==========<>==========<>==========<>\n\n";
  
            std::cout << "Please Enter Your Command\n";
            std::cin >> optionsMenuInput;
          
            switch (optionsMenuInput){//Options input
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