#include "BRP_Menu.h"

int BRP_menu()
{
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
      case 1://full random
        {
          std::cout << "Not availible";
          break;
        }
      case 2://multi full random
        {
          std::cout << "Not availible";
          break;
        }
      case 3://pointbuy
        {
          std::cout << "Not availible";
          break;
        }
      case 4://free-form
        {
          std::cout << "Not availible";
          break;
        }
      case 5://settings
        {
          std::cout << "Not availible";
          break;
        }
      case 0://exit
        {
          return 0;
        }
      default://error message
        {
          std::cout << "Not an acceptable input.\nPlease enter only one of the number options in the menu." << std::endl;
          break;
        }
    }//BRP Main Menu Input
  }//Main While Loop
}//All BRP Menus 