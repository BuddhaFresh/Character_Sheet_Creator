#include "diceroller.h"
#include "menus.h"

// RandomSetUp class functions
void RandomSetUp::randomSeed() {
  currentSeed = static_cast<unsigned int>(time(nullptr));
  mt_rando.seed(currentSeed);
}

void RandomSetUp::userSeed() {//see if I can't turn seedinput into a char array and convert into an int with a limit of billion and reduced if over the 2.1 billion positive int value and increase if less then -2.4 billion negittive int value.
  // Prompt for user to input their seed
  std::cout << "\nEnter seed\n";
  //std::getline(std::cin >> std::ws, seedinput);
  std::cin >> seedinput;

  // Turn string into int
  currentSeed = std::stoi(seedinput);

  // Providing the custom seed value
  mt_rando.seed(currentSeed);
}


//General dice roller method
int Dice::Die(int MIN, int MAX){ 
  std::uniform_int_distribution<int> diecast(MIN, MAX);
  return diecast(RANDOMCORE.mt_rando);
}

//for loop for multi rolls with vector output
void Dice::ManyDice(int MIN, int MAX, int ROLLS){
  std::vector<int> Outcome;
  for(int i = 0; i < ROLLS; i++){
    Outcome.push_back(Die(MIN, MAX));
    std::cout << Outcome[i] << " ";
  }
}

//for loop for multi rolls that combine results
int Dice::MultiDice(int MIN, int MAX, int ROLLS){
  int result = 0;
  for(int i = 0; i < ROLLS; i++){
    result += Die(MIN, MAX);
  }
  return result;
}

void DiceRollerMenu(){
  int diceMenuInput;
  while (true){//Dice Roller menu
    std::cout << "\n\n<>++++++++++<>++++++++++<>++++++++++<>\n";
    std::cout << "\t\t\tDice Choices\n";
    std::cout << "1. Roll a D4\n";
    std::cout << "2. Roll a D6\n";
    std::cout << "3. Roll a D8\n";
    std::cout << "4. Roll a D10\n";
    std::cout << "5. Roll a D12\n";
    std::cout << "6. Roll a D20\n";
    std::cout << "7. Roll a D100\n";
    std::cout << "8. Roll many dice\n";
    std::cout << "9. Combined multi-dice roller\n";
    std::cout << "\n0. Return to Options\n";
    std::cout << "<>++++++++++<>++++++++++<>++++++++++<>\n\n";
  
    std::cout << "Please make your selection\n";
    std::cin >> diceMenuInput;
  
    switch (diceMenuInput){//Dice Roller input
      case 1:
        std::cout << "\033c";
        std::cout << "\nYou rolled a four-sided die and got a " << ROLL.Die(1,4) << std::endl;
        break;
      case 2:
        std::cout << "\033c";
        std::cout << "\nYou rolled a six-sided die and got a " << ROLL.Die(1,6) << std::endl;
        break;
      case 3:
        std::cout << "\033c";
        std::cout << "\nYou rolled an eight-sided die and got a " << ROLL.Die(1,8) << std::endl;
        break;
      case 4:
        std::cout << "\033c";
        std::cout << "\nYou rolled a ten-sided die and got a " << ROLL.Die(1,10) << std::endl;
        break;
      case 5:
        std::cout << "\033c";
        std::cout << "\nYou rolled a twelve-sided die and got a " << ROLL.Die(1,12) << std::endl;
        break;
      case 6:
        std::cout << "\033c";
        std::cout << "\nYou rolled a twenty-sided die and got a " << ROLL.Die(1,20) << std::endl;
        break;
      case 7:
        std::cout << "\033c";
        std::cout << "\nYou rolled a hundred-sided die and got a " << ROLL.Die(1,100) << std::endl;
        break;
      case 8:{
        std::cout << "\033c";
        int MINinput, MAXinput, ROLLSinput;
        std::cout << "Many Dice Roller" << std::endl;
        std::cout << "Lowest possible result per roll?" << std::endl;
        std::cin >> MINinput;
        std::cout << "Highest possible result per roll?" << std::endl;
        std::cin >> MAXinput;
        std::cout << "Finally, how many total rolls do you want?" << std::endl;
        std::cin >> ROLLSinput;
        std::cout << "\033c";
        std::cout << ROLLSinput << " dice with a random range of " << MINinput << " through " << MAXinput << " were rolled. \nHere are the results:\n\n";
        ROLL.ManyDice(MINinput, MAXinput, ROLLSinput);
        break;
      }
      case 9:{//I do not understand why I need the int total when MultiDice is an int method. Isn't it suppose to return an int when called? Without int total, the method doesn't return anything (not even 0). Program doesn't crash without int result, using cout on int total works, I'm blaming it on goblins and moving on...
        std::cout << "\033c";
        int MINinput, MAXinput, ROLLSinput;
        std::cout << "Combined Multi-roll Roller" << std::endl;
        std::cout << "Lowest possible result per roll?" << std::endl;
        std::cin >> MINinput;
        std::cout << "Highest possible result per roll?" << std::endl;
        std::cin >> MAXinput;
        std::cout << "Finally, how many total rolls do you want?" << std::endl;
        std::cin >> ROLLSinput;
        std::cout << "\033c";
        std::cout << ROLLSinput << " dice with a random range of " << MINinput << " through " << MAXinput << " were rolled. \nThe total of all rolls is:\n\n";
        int total = ROLL.MultiDice(MINinput, MAXinput, ROLLSinput);
        std::cout << total;
        break;
      }
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
}