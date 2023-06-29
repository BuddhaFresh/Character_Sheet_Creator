#include "menus.h"


//Classes
RandomSetUp SEEDER;
Dice ROLL;


int menu()
{//All menus
  int mainMenuInput;
  int optionsMenuInput;
  int diceMenuInput;

  //Generate a new seed at boot
  SEEDER.randomSeed();


  while(true) 
  {//MAIN MENU
    std::cout << "\n\n<>~~~~~~~~~~<>~~~~~~~~~~<>~~~~~~~~~~<>\n";
    std::cout << "Welcome to Character Sheet Creator\n\t\t\tMain Menu\n";
    std::cout << "1. New Sheet\n";
    std::cout << "2. Load Sheet\n";
    std::cout << "3. Dice Roller\n";
    std::cout << "4. Options\n";
    std::cout << "5. Exit\n";
    std::cout << "<>~~~~~~~~~~<>~~~~~~~~~~<>~~~~~~~~~~<>\n\n";

    std::cout << "Please Enter Your Command\n";
    std::cin >> mainMenuInput;

    switch (mainMenuInput)
    {//Main menu input start    
      case 1: //New Sheet
        std::cout << "\nNew Sheet not availible\n\n";
        break;
      case 2: //Load Sheet
        std::cout << "\nLoad Sheet not availible\n\n";
        break;
      
      case 3: //Dice Roller
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
            std::cout << "8. Return to Options\n";
            std::cout << "<>++++++++++<>++++++++++<>++++++++++<>\n\n";
    
            std::cout << "Please make your selection\n";
            std::cin >> diceMenuInput;

            switch (diceMenuInput)
            {//Dice Roller input
              case 1:
                std::cout << "\nYou rolled a four-sided die and got a " << ROLL.Dfour() << std::endl;
                break;
              case 2:
                std::cout << "\nYou rolled a six-sided die and got a " << ROLL.Dsix() << std::endl;
                break;
              case 3:
                std::cout << "\nYou rolled an eight-sided die and got a " << ROLL.Deight() << std::endl;
                break;
              case 4:
                std::cout << "\nYou rolled a ten-sided die and got a " << ROLL.Dten() << std::endl;
                break;
              case 5:
                std::cout << "\nYou rolled a twelve-sided die and got a " << ROLL.Dtwelve() << std::endl;
                break;
              case 6:
                std::cout << "\nYou rolled a twenty-sided die and got a " << ROLL.Dtwenty() << std::endl;
                break;
              case 7:
                std::cout << "\nYou rolled a hundred-sided die and got a " << ROLL.Donehundred() << std::endl;
                break;
              case 8:
                break;
              default:
               std::cout << "Please enter one of the listed options";
               break;
            }//Dice Roller input end
            if (diceMenuInput == 8) break;
          }//Dice Roller menu end
          break;
      
      case 4: //Options
      while (true)  
      {//Options sub-menu start
        std::cout << "\n\n<>==========<>==========<>==========<>\n";
          std::cout << "\t\t\t\tOptions\n";
          std::cout << "1. Input Manual Seed \n(Current Seed: "<< SEEDER.currentSeed <<")\n";
          std::cout << "2. Main Menu\n";
          std::cout << "<>==========<>==========<>==========<>\n\n";

          std::cout << "Please Enter Your Command\n";
          std::cin >> optionsMenuInput;
        
          switch (optionsMenuInput)
            {//Options input
              case 1:
                SEEDER.userSeed();
                break;
              case 2:
                std::cout << "\nReturning to Main Menu\n";
                break;
              default: 
                std::cout << "\nNot an availible command\n";
                break;
            }//Options input end
        if (optionsMenuInput == 2) break; 
      }//Options sub-menu end
      break;
      case 5: //Exit
        std::cout << "\nExiting Program\nGood Bye!\n";
        return 0;
      default: 
        std::cout << "\nNot an availible command\n";
        break;
    }//Main menu input end
  }//MAIN MENU end
}//All menus end