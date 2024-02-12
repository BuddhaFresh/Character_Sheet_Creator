#include "BRP_Menu.h"
#include "BRP.h"
#include "BRP_Era.h"
#include "../../diceroller.h"
#include "../../menus.h"

//RandomSetUp NEXT;

int BRP_menu()
{
  //RANDO.randomSeed();
  
  //inputs for menu
  int BRPMainMenuInput;
  int BRPSettingsInput;
  
  while (true){//Main BRP Menu
    std::cout << "\n\n<>^v^v^v^v^v<>^v^v^^v^v^<>v^v^v^v^v^<>\n";
    std::cout << "Basic Roleplaying, Universal Game Engine\n\t\t\tMain Menu\n";
    std::cout << "6. [testing: ancient past character]Create Character, Standard\n";
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
    {//BRP Main Menu Input
      case 1:{//full random
        std::cout << "\033c";
        BRP_human_base BRPChar0(ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),TwoDSixPlusSix(),TwoDSixPlusSix(),TwoDSixPlusSix());
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
                SaveData(BRPChar0, "Characters/BRP/save_data.bin");
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
          BRP_human_base BRPChar0(ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 3),ROLL.MultiDice(1, 6, 2)+6,ROLL.MultiDice(1, 6, 2)+6,ROLL.MultiDice(1, 6, 2)+6);
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
      case 5:{
        std::cout << "\033c";
        while (true){//BRP Settings Menu
          
          std::string DistinctiveFeaturesstate = "";
          if (BRP_human_base::stateDISTINCTIVE_FEATURES() == true && BRP_human_base::stateDISTINCTIVE_FEATURES_BASIC() == true){DistinctiveFeaturesstate = "BASIC";}
          else if(BRP_human_base::stateDISTINCTIVE_FEATURES() == true && BRP_human_base::stateDISTINCTIVE_FEATURES_BASIC() == false){DistinctiveFeaturesstate = "ON";}
          else{DistinctiveFeaturesstate = "OFF";}
          
          std::string EDUstate = (BRP_human_base::stateEDUCATION_STAT() == true) ? "ON" : "OFF";

          std::string ExperiencePointsstate = (BRP_human_base::stateEXPERIENCE_BONUS() == true) ? "ON" : "OFF";
          
          std::string FatiguePointsstate = (BRP_human_base::stateFATIGUE_POINTS() == true) ? "ON" : "OFF";

          std::string HeightAndWeightstate = "";
          if (BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_METERS() == true){HeightAndWeightstate = "METRIC";}
          else if(BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_IMPERIAL() == true){HeightAndWeightstate = "IMPERIAL";}
          else{HeightAndWeightstate = "TEXT";}

          std::string HPLocationstate = (BRP_human_base::stateHIT_POINTS_PER_LOCATION() == true) ? "ON" : "OFF";

          std::string IncreasedPerSkillPointsstate = (BRP_human_base::stateINCREASED_PERSONAL_SKILL_POINTS() == true) ? "ON" : "OFF";

          std::string PowerLevelstate = "";
          if(BRP_human_base::statePOWER_LEVEL() == 1){PowerLevelstate = "HEROIC";}
          else if(BRP_human_base::statePOWER_LEVEL() == 2){PowerLevelstate = "EPIC";}
          else if(BRP_human_base::statePOWER_LEVEL() == 3){PowerLevelstate = "SUPERHUMAN";}
          else{PowerLevelstate = "NORMAL";}

          std::string Sanitystate = (BRP_human_base::stateSANITY() == true) ? "ON" : "OFF";
          
          std::string SkillCatstate = "";
          if (BRP_human_base::stateSKILL_CATEGORY() == true && BRP_human_base::stateSKILL_CATEGORY_SIMPLE() == true){SkillCatstate = "SIMPLE";}
          else if(BRP_human_base::stateSKILL_CATEGORY() == true && BRP_human_base::stateSKILL_CATEGORY_SIMPLE() == false){SkillCatstate = "ON";}
          else{SkillCatstate = "OFF";}

          std::string TotalHPstate = (BRP_human_base::stateTOTAL_HIT_POINTS() == true) ? "ON" : "OFF";

          std::string WingedCharacterstate = (BRP_human_base::stateWINGED_CHARACTER() == true) ? "ON" : "OFF";
          
          std::cout << "\n\n<>^v^v^v^v^v<>^v^v^^v^v^<>v^v^v^v^v^<>\n";
          std::cout << " Basic Roleplaying Character Creation\n\t\tOptional Settings\n";
          std::cout << " 1. Distinctive Features" << std::setw(16) << std::setfill('.') << DistinctiveFeaturesstate << "\n";
          std::cout << " 2. Education (EDU) Characteristics" << std::setw(5) << std::setfill('.') << EDUstate << "\n";
          std::cout << " 3. Experience Bonus" << std::setw(20) << std::setfill('.') << ExperiencePointsstate << "\n";
          std::cout << " 4. Fatigue Points" << std::setw(22) << std::setfill('.') << FatiguePointsstate << "\n";
          std::cout << " 5. Height and Weight" <<  std::setw(19) << std::setfill('.') << HeightAndWeightstate << "\n";
          std::cout << " 6. Hit Points per Location" << std::setw(13) << std::setfill('.') << HPLocationstate << "\n";
          std::cout << " 7. Increased Personal Skill Points" << std::setw(5) << std::setfill('.') << IncreasedPerSkillPointsstate << "\n";
          std::cout << " 8. Set Power Level" << std::setw(21) << std::setfill('.') << PowerLevelstate << "\n";
          std::cout << " 9. Sanity" << std::setw(30) << std::setfill('.') << Sanitystate << "\n";
          std::cout << "10. Skill Catagories" << std::setw(20) << std::setfill('.') << SkillCatstate << "\n";
          std::cout << "11. Total Hit Points" << std::setw(20) << std::setfill('.') << TotalHPstate << "\n";
          std::cout << "12. Winged Characters" << std::setw(19) << std::setfill('.') << WingedCharacterstate << "\n";

          std::cout << "\n0. Return to Basic Roleplaying Main Menu\n";
          std::cout << "<>v^v^v^v^v^<>v^v^vv^v^v<>^v^v^v^v^v<>\n\n";

          std::cout << "Please Enter Your Command\n";

          std::cin >> BRPSettingsInput;

          switch (BRPSettingsInput){//Options input
              case 1:{//DISTINCTIVE FEATURES        
                std::cout << "\033c";
                if (BRP_human_base::stateDISTINCTIVE_FEATURES() == true && BRP_human_base::stateDISTINCTIVE_FEATURES_BASIC() == false)
                  {BRP_human_base::flipDISTINCTIVE_FEATURES(true), BRP_human_base::flipDISTINCTIVE_FEATURES_BASIC(true);} //on to basic
                else if(BRP_human_base::stateDISTINCTIVE_FEATURES() == true && BRP_human_base::stateDISTINCTIVE_FEATURES_BASIC() == true)
                  {BRP_human_base::flipDISTINCTIVE_FEATURES(false), BRP_human_base::flipDISTINCTIVE_FEATURES_BASIC(false);} // basic to off
                else
                  {BRP_human_base::flipDISTINCTIVE_FEATURES(true), BRP_human_base::flipDISTINCTIVE_FEATURES_BASIC(false);} //off to on
                break;}
              case 2:{//EDU
                std::cout << "\033c";
                bool changeEDU = (BRP_human_base::stateEDUCATION_STAT() == true) ? false : true;
                BRP_human_base::flipEDUCATION_STAT(changeEDU);
                break;}
              case 3:{//EXPERIENCE_BONUS
                std::cout << "\033c";
                bool changeEXPBONUS = (BRP_human_base::stateEXPERIENCE_BONUS() == true) ? false : true;
                BRP_human_base::flipEXPERIENCE_BONUS(changeEXPBONUS);
                break;}
              case 4:{//FATIGUE_POINTS
                std::cout << "\033c";
                bool changeFP = (BRP_human_base::stateFATIGUE_POINTS() == true) ? false : true;
                BRP_human_base::flipFATIGUE_POINTS(changeFP);
                break;}
              case 5:{//HEIGHT_AND_WEIGHT
                std::cout << "\033c";
                if (BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_METERS() == true && BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_IMPERIAL() == false)
                  {BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_METERS(false), BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_IMPERIAL(true);} //METRIC to IMPERIAL
                else if(BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_METERS() == false && BRP_human_base::stateHEIGHT_AND_WEIGHT_IN_IMPERIAL() == true)
                  {BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_METERS(false), BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_IMPERIAL(false);} //IMPERIAL to TEXT
                else
                  {BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_METERS(true), BRP_human_base::flipHEIGHT_AND_WEIGHT_IN_IMPERIAL(false);} //TEXT to METRIC
                break;}
              case 6:{//HIT_POINTS_PER_LOCATION
                std::cout << "\033c";
                bool changeHPLOCO = (BRP_human_base::stateHIT_POINTS_PER_LOCATION() == true) ? false : true;
                BRP_human_base::flipHIT_POINTS_PER_LOCATION(changeHPLOCO);
                break;
              }
              case 7:{//INCREASED_PERSONAL_SKILL_POINTS
                std::cout << "\033c";
                bool changeINCREASED_PERSONAL_SKILL_POINTS = (BRP_human_base::stateINCREASED_PERSONAL_SKILL_POINTS() == true) ? false : true;
                BRP_human_base::flipINCREASED_PERSONAL_SKILL_POINTS(changeINCREASED_PERSONAL_SKILL_POINTS);
                break;
              }
              case 8:{//Power Level CASE 8 menu
                int PowerLevelInput;
                while(true){//Power Level Menu Loop
                  std::cout << "\033c";
                  std::cout << "\n\n<>WWWWWWWWWW<>WWWWWWWWWW<>vWWWWWWWWWW<>\n";
                  std::cout << "\t\tSelect Power Level" << "\n";
                  std::cout << "1. Normal" << "\n";
                  std::cout << "2. Heroic" << "\n";
                  std::cout << "3. Epic" << "\n";
                  std::cout << "4. Superhuman" << "\n";
                  std::cout << "\n0. Return to Optional Settings" << "\n";
                  std::cout << "<>MMMMMMMMMM<>MMMMMMMMMM<>MMMMMMMMMM<>\n\n";

                  std::cout << "Please Enter Your Command\n";
                  
                  std::cin >> PowerLevelInput;

                  switch(PowerLevelInput){//Power Level Input
                    case 1:{
                      std::cout << "\033c";
                      BRP_human_base::flipPOWER_LEVEL(0);
                      break;
                    }
                    case 2:{
                      std::cout << "\033c";
                      BRP_human_base::flipPOWER_LEVEL(1);
                      break;
                    }
                    case 3:{
                      std::cout << "\033c";
                      BRP_human_base::flipPOWER_LEVEL(2);
                      break;
                    }
                    case 4:{
                      std::cout << "\033c";
                      BRP_human_base::flipPOWER_LEVEL(3);
                      break;
                    }
                    case 0:{
                      std::cout << "\033c";
                      break;
                    }
                    default:{
                      std::cout << "\033c";
                      std::cout << "Please select one of the avalible levels or exit back to the Options Menu.";
                      //break;
                    }
                  }//Power Level Input end
                    break;
                }//Power Level Menu Loop end 
                break;
              }//Power Level menu CASE 8 end
              case 9:{//SANITY
                std::cout << "\033c";
                bool changeSAN = (BRP_human_base::stateSANITY() == true) ? false : true;
                BRP_human_base::flipSANITY(changeSAN);
                break;
              }
              case 10:{//SKILL CATEGORY
                std::cout << "\033c";
                
                if (BRP_human_base::stateSKILL_CATEGORY() == true && BRP_human_base::stateSKILL_CATEGORY_SIMPLE() == false)
                {BRP_human_base::flipSKILL_CATEGORY(true), BRP_human_base::flipSKILL_CATEGORY_SIMPLE(true);}//on to simple
                  
                else if(BRP_human_base::stateSKILL_CATEGORY() == true && BRP_human_base::stateSKILL_CATEGORY_SIMPLE() == true)
                {BRP_human_base::flipSKILL_CATEGORY(false), BRP_human_base::flipSKILL_CATEGORY_SIMPLE(false);}//simple to off
                  
                else
                {BRP_human_base::flipSKILL_CATEGORY(true), BRP_human_base::flipSKILL_CATEGORY_SIMPLE(false);}//off to on
                
                break;}
              case 11:{//TOTAL_HIT_POINTS
                std::cout << "\033c";
                bool changeTOTALHP = (BRP_human_base::stateTOTAL_HIT_POINTS() == true) ? false : true;
                BRP_human_base::flipTOTAL_HIT_POINTS(changeTOTALHP);
                break;                
              }
              case 12:{//WINGED_CHARACTER
                std::cout << "\033c";
                bool changeWINGEDCHAR = (BRP_human_base::stateWINGED_CHARACTER() == true) ? false : true;
                BRP_human_base::flipWINGED_CHARACTER(changeWINGEDCHAR);
                break;}
              case 0:
                std::cout << "\033c";
                break;
              default: 
                std::cout << "\033c";
                std::cout << "\nNot an availible command\n";
                break;
            }//Options input end
          if (BRPSettingsInput == 0){
            std::cout << "\033c";
            break;
          }; 
        }//Options sub-menu end
        break;
      } 
      case 6:{//placeholder for standard
        std::cout << "\033c";
        
        BRP_human_base* test = new BRP_human_AncientEra(ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),ThreeDSix(),TwoDSixPlusSix(),TwoDSixPlusSix(),TwoDSixPlusSix());
        test->fullrandom();
        test->consoleChar();
        
        delete test;
        
        /* Overview of current options settings
            allow chance to edit and come back to this menu
          get player name
          get character name
          menu for stats
            allow input for each stat
            allow for random roll per stat
            redo any before using stats for objet
          show calculated stats
          
        */
        //std::cout << "Not availible";
        break;
      }
      case 0:{//exit
        std::cout << "\033c";
        break;
        }
      default:{//error message
        std::cout << "\033c";
        std::cout << "Not an acceptable input.\nPlease enter only one of the number options in the menu." << std::endl;
        break;
        }
      }//BRP Main Menu Input end
    if (BRPMainMenuInput == 0){
      std::cout << "\033c";
        return 0;
    }; 
  }////Main BRP Menu end
}//All BRP Menus ends