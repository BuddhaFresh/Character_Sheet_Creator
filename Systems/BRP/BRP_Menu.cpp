#include "BRP_Menu.h"
#include "BRP.h"
#include "../../diceroller.h"
#include "../../menus.h"

//RandomSetUp NEXT;

int BRP_menu()
{
  //RANDO.randomSeed();
  
  //inputs for menu
  int BRPMainMenuInput;
  
  while (true)
  {
    std::cout << "\n\n<>^v^v^v^v^v<>^v^v^^v^v^<>v^v^v^v^v^<>\n";
    std::cout << "Basic Roleplaying, Universal Game Engine\n\t\t\tMain Menu\n";
    std::cout << "1. Create Random Character\n";
    std::cout << "2. Create Multiple Random Charcters\n";
    std::cout << "3. Create Character, Point-Buy System\n";
    std::cout << "4. Create Character, Free-Form\n";
    std::cout << "5. Settings\n";
    
    std::cout << "\n0. Return to New Sheet Menu\n";
    std::cout << "<>v^v^v^v^v^<>v^v^vv^v^v<>^v^v^v^v^v<>\n\n";
  
    std::cout << "Please Enter Your Command\n";
    std::cin >> BRPMainMenuInput; 

    switch(BRPMainMenuInput)
    {
      case 1:{//full random
        std::cout << "\033c";
        BRP_human_base BRPChar0(ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),TwoDSixPlusSix(),TwoDSixPlusSix());
        BRPChar0.PlayerName();
        BRPChar0.fullrandom();
        BRPChar0.consoleChar();
        
        while(true)
          {//save character menu
            int charKeepInput;
            std::cout << "\n\n<>##########<>##########<>##########<>\n";
            std::cout << "\t\tSave this charcater?" << std::endl;
            std::cout << "1. Save as txt file" << std::endl;
            std::cout << "\n0. Return" << std::endl;
            std::cout << "<>##########<>##########<>##########<>\n\n";
            std::cin >> charKeepInput;
            
            switch(charKeepInput)
            {//save character input
              case 1:
                std::cout << "\033c" << std::endl;
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
        
        }
      case 2:{//multi full random
        std::cout << "\033c";
        int amounts;
        std::cout << "How many charcters do you want to make?\n";
        std::cin >> amounts;
        std::cout << "\033c";
        for (int i = 0; i < amounts; i++){
          BRP_human_base BRPChar0(ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 2)+6,ROLL.MultiDice(1, 6, 2)+6);
          BRPChar0.fullrandom();
          BRPChar0.consoleChar();
          std::cout << "\n" <<std::endl;
        }
        break;
        }
      case 3:{//pointbuy
        std::cout << "\033c";
        std::cout << "Not availible";
        break;
        }
      case 4:{//free-form
        std::cout << "\033c";
        std::cout << "Not availible";
        break;
        }
      case 5:{//settings
        std::cout << "\033c";
        std::cout << "Not availible";
        break;
        }
      case 0:{//exit
        std::cout << "\033c";
        return 0;
        }
      default:{//error message
        std::cout << "\033c";
        std::cout << "Not an acceptable input.\nPlease enter only one of the number options in the menu." << std::endl;
        break;
        }
    }//BRP Main Menu Input
  }//Main While Loop
}//All BRP Menus 