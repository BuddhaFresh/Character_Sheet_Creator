#include "../../menus.h"
#include "../../diceroller.h"
#include "BRP.h"
#include "BRP_Menu.h"




//GOAL FOR SCRIPT
//everything needed to make a standard Basic Role-Playing Character (5th ed, Universal Game Engine)
//Needs to have attrabutes, diraived stats, list of relivent features, equipment(just a basic set for now)
//class BRP char with roll inputs



//Create folder for character sheets
void FolderOriginBRP(){
  std::string foldername = "Characters/BRP";
  int result = mkdir(foldername.c_str(), 0777); //0777 is premissions for the folder, 7 is full permission and the three number posistions at the end are for different kinds of users? 
  if (result == 0){
    std::cout << "BRP Installed\n";
  }else{  }
}

//Special Dice Rolls for this system
//Rolls a 3D6, 3 six-sided dice added together
int ThreeDSix(){
  int x = 0;
  for(int i = 0; i < 3; i++){
    x += ROLL.Die(1,6);
  }
  return x;
}

//Rolls a 2D6+6, 2 six-sided dice added together plus 6
int TwoDSixPlusSix(){ 
  int x = 0;
  for(int i = 0; i < 2; i++){
    x += ROLL.Die(1,6);
  }
  return x+6;
}

//default states for optional settings
int BRP_human_base::POWER_LEVEL = 0;
bool BRP_human_base::DISTINCTIVE_FEATURES = true;
bool BRP_human_base::DISTINCTIVE_FEATURES_BASIC = false;
bool BRP_human_base::EDUCATION_STAT = true;
bool BRP_human_base::EXPERIENCE_BONUS = true;
bool BRP_human_base::FATIGUE_POINTS = false;
bool BRP_human_base::HEIGHT_AND_WEIGHT_IN_METERS = false;
bool BRP_human_base::HEIGHT_AND_WEIGHT_IN_IMPERIAL = false;
bool BRP_human_base::HIT_POINTS_PER_LOCATION = false;
bool BRP_human_base::INCREASED_PERSONAL_SKILL_POINTS = false;
bool BRP_human_base::SANITY = false;
bool BRP_human_base::SKILL_CATEGORY = true;
bool BRP_human_base::SKILL_CATEGORY_SIMPLE = false;
bool BRP_human_base::TOTAL_HIT_POINTS = false;
bool BRP_human_base::WINGED_CHARACTER = false;

//BRP_human_base class
//Constructor to hold Characteristics, 
BRP_human_base::BRP_human_base(int a, int b, int c, int d, int e, int x, int y, int z){
  STR = a;
  CON = b;
  POW = c;
  DEX = d;
  CHA = e;
  INT = x;
  SIZ = y;
  EDU = z;
}
   
  /*Setting&Era switches
  Basic?; prehistoric, medieval, modern, future?
  Basic has like 5 options
  Detailed?; 23 opitions
    Prehistoric Age                 PH
    Bronze Age                      BZ
    Iron Age                        IR
    High Medieval                   HM
    High Fantasy                    HF
    Imperial Asia                   IA
    Arabian Nights                  AN
    Enlightenment and Renaissance   ER
    Age of Exploration              EX
    Age of Sail                     SA
    Industrial Age                  ID
    Victorian Age                   VA
    Wild West                       WW
    Pulp Era                        PP
    Planetary Adventure             PV
    World War II                    WA
    Noir                            NR
    Modern                          MD
    Super World                     SW
    Postapocalyptic                 PA
    Near-Future/Cyberpunk           NF
    Space Exploration               SE
    Space Opera                     SO
    .PH.BZ.IR.HM.HF.IA.AN.ER.EX.SA.ID.VA.WW.PP.PV.WA.NR.MD.SW.PA.NF.SE.SO.
  */

//Weapons Table
void BRP_human_base::Weapons(){
/*
  WeaponsTable["Weapon Name Key"] = {"Weapon Name","Main Skill","SubSkill",Base,"dmg","Attk","Special","Melee Rng",Missile Rng,"hands",HP,Parry bool,STR,DEX,"Mal",Ammo,"Value",SIZ,"Missile Rate-of-Fire",will need to set up setting codes here};
*/
  
  //Melee
  WeaponsTable["Axe, Hand"] = {"Hand Axe","Melee Weapon","Axe",15,"1D6+1+dm","1","Bleeding","Short",0,"1H",12,true,7,9,"-",0,"Cheap",0.5,""};
  WeaponsTable["Club, Heavy"] = {"Heavy Club","Melee Weapon","Club",25,"1D8+dm","1","Crushing","Medium",0,"2H",22,true,9,7,"-",0,"Cheap",0.2,""};
  WeaponsTable["Knife"] = {"Knife","Melee Weapon","Dagger",25,"1D3+1+dm","1","Impaling","Short",0,"1H",15,true,4,4,"-",0,"",02,""};
  WeaponsTable["Spear, Long"] = {"Long Spear","Melee Weapon","Spear",15,"1D10+1+dm","1","Impaling","Long",0,"2H",15,true,11,9,"-",0,"Cheap",2.0,""};
  WeaponsTable["Blackjack"] = {"Blackjack","Melee Weapon","Hand",25,"1D8+dm","1","Crushing","Short",0,"1H",10,false,7,7,"-",0,"Inexpensive",0.2,""};
  WeaponsTable["Pike"] = {"Pike","Melee Weapon","Polearm",15,"1D10+2+dm","1","Impaling","Long",0,"2H",15,true,11,7,"-",0,"Inexpensive",3.5,""};
  WeaponsTable["Staff, Quarter-"] = {"Quarter-Staff","Melee Weapon","Staff",25,"1D8+dm","1","Crushing","All",0,"2H",20,true,9,9,"-",0,"Cheap",1.5,""};
  WeaponsTable["Sword, Short"] = {"Short Sword","Melee Weapon","Sword",15,"1D6+1+dm","1","Impaling","Medium",0,"1H",20,true,5,5,"-",0,"Cheap",1.0,""};
  WeaponsTable["Brass Knuckles"] = {"Brass Knuckles","Melee Weapon","Brawl",SkillTable["Brawl"].SkillMod,"+2","1","Crushing","Short",0,"1H",18,false,5,0,"-",0,"Cheap",0.1,""};
  WeaponsTable["Chainsaw"] = {"Chainsaw","Melee Weapon","Improvised",20,"2D8","1","Bleeding","Medium",0,"2H",20,false,11,11,"97-00",0,"Average",8.0,""}; 
  WeaponsTable["Knife, Switchblade"] = {"Switchblade Knife","Melee Weapon","Dagger",25,"1D4+dm","1","Impaling","Short",0,"1H",7,false,0,5,"99-00",0,"Cheap",0.1,""}; 
  WeaponsTable["Taser, Contact"] = {"Contact Taser","Melee Weapon","Other",SkillTable["Brawl"].SkillMod,"Stunning","1","","Short",0,"1H",7,false,5,7,"97-00",0,"Expensive",0.3,""};
  WeaponsTable["Axe, Vibro-"] = {"Vibro-Axe","Melee Weapon","Polearm",10,"2D8+4+dm","1","Bleeding","Medium",0,"2H",20,true,11,5,"98-00",0,"Average",3.0,""};
  WeaponsTable["Knife, Vibro-"] = {"Vibro-Knife","Melee Weapon","Dagger",25,"2D4+2+dm","1","Bleeding","Short",0,"1H",16,true,7,7,"99-00",0,"Average",0.5,""};
  WeaponsTable["Lance, Stun"] = {"Stun Lance","Melee Weapon","Staff",15,"1D6+dm+stun","1","Knockback","Long",0,"2H",18,true,9,5,"98-00",0,"Average",2.5,""};
  WeaponsTable["Sword, Monofilament"] = {"Monofilament Sword","Melee Weapon","Sword",20,"3D12","1","Bleeding","Medium",0,"1H",12,false,5,15,"91-00",0,"Expensive",0.5,""};

  //Missile
  WeaponsTable["Blowgun"] = {"Blowgun","Missile Weapon","Blowgun",10,"1D3","1","Impaling","",30,"2H",4,false,0,11,"-",0,"Cheap",0.5,"1/CR"};
  WeaponsTable["Bow, Self"] = {"Self Bow","Missile Weapon","Bow",10,"1D6+1+1/2dm","1","Impaling","",80,"2H",6,false,9,9,"-",0,"Cheap",0.5,"1/CR"};
  WeaponsTable["Javelin"] = {"Javelin","Missile Weapon","Javelin",15,"1D6+1/2dm","1","Impaling","",25,"1H",10,false,9,9,"-",0,"Cheap",1.5,"1/CR"};
  WeaponsTable["Sling"] = {"Sling","Missile Weapon","Sling",05,"1D8+1/2dm","1","Crushing","",80,"1H",2,false,7,11,"-",0,"Cheap",01,"1/CR"};
  WeaponsTable["Arbalest"] = {"Arbalest","Missile Weapon","Crossbow",15,"2D6+4","1/3","Impaling","",90,"2H",14,false,11,9,"93-00",0,"Average",10.0,"1/4CR"};
  WeaponsTable["Bow, Composite"] = {"Composite Bow","Missile Weapon","Bow",05,"1D8+1+1/2dm","1","Impaling","",120,"2H",12,false,13,9,"-",0,"Average",0.5,"1/CR"};
  WeaponsTable["Crossbow, Medium"] = {"Medium Crossbow","Missile Weapon","Crossbow",25,"2D4+2","1/2","Impaling","",50,"2H",14,false,11,7,"95-00",0,"Average",5.0,"1/2CR"};
  WeaponsTable["Shuriken"] = {"Shuriken","Missile Weapon","Missile",10,"1D3+1/2dm","2","Impaling","",20,"1H",5,false,0,13,"-",0,"Cheap",0.1,"1/CR"};

  //Firearm
  WeaponsTable["Pistol, Flintlock"] = {"Flintlock Pistol","Firearm","Pistol",20,"1D6+1","1/4","Impaling","",10,"1H",8,false,7,5,"95-00",1,"Average",1.0,"1/2CR"};
  WeaponsTable["Revolver, Light"] = {"Light Revolver","Firearm","Revolver",20,"1D6","2","Impaling","",10,"1H",6,false,5,5,"00",6,"Average",0.7,"1/CR"};
  WeaponsTable["Rifle, Sniper"] = {"Sniper Rifle","Firearm","Rifle",20,"2D10+4","1","Impaling","",250,"2H",10,false,12,7,"98-00",11,"Expensive",4.0,"1/CR"};
  WeaponsTable["Shotgun, Sawn-off"] = {"Sawn-off Shotgun","Firearm","Shotgun",30,"4D6/1D6","1 or 2","Impaling","",20,"1H",14,false,9,5,"00",2,"Average",2.0,"1 or 2/CR"};

  //Heavy Weapon
  WeaponsTable["Gun, Machine"] = {"Machine Gun","Heavy Weapon","Machine Gun",15,"2D6+4","1, 3, or brust","Impaling","",90,"2H",11,false,9,5,"00",40,"Expensive",3.0,"1 or 3/CR or 1/CR"};
  WeaponsTable["Gun, Mini-"] = {"Mini-Gun","Heavy Weapon","Machine Gun",15,"2D6+4","3","Impaling","",400,"2H",14,false,16,12,"98-00",4000,"Expensive",6.0,"1/CR"};
 
  //Energy Missile
  WeaponsTable["Pistol, Laser"] = {"Laser Pistol","Energy Weapon","Pistol",20,"1D8","3","Impaling","",20,"1H",14,false,5,5,"99-00",20,"Average",1.0,""};
  WeaponsTable["Pistol, Disintegrator"] = {"Disintegrator Pistol","Energy Weapon","Pistol",05,"3D4+1","1","-","",10,"1H",12,false,7,5,"96-00",10,"Expensive",1.0,""};
  WeaponsTable["Rifle, Plasma"] = {"Plasma Rifle","Energy Weapon","Rifle",10,"2D10+4","1","Impaling","",70,"2H",18,false,9,7,"98-00",16,"Expensive",2.0,""};
  WeaponsTable["Rifle, Electromagnetic Pulse"] = {"Electromagnetic Pulse Rifle","Energy Weapon","Rifle",25,"3D8 vs. tech","1","-","",75,"2H",18,false,7,5,"98-00",12,"Average",2.0,""};
}

//EDU Characteristic
int BRP_human_base::EDUstat(){
  if (EDUCATION_STAT == false)
    {
      return EDU = 0;
    }else{
      return 0;}
}

//Experience Bonus
void BRP_human_base::ExpBonus(int E){
  ExperenceBonus = ceil(E/2);
}

//Returns a STAT times 5, for a percentage roll
//This is at standard difficulty
int BRP_human_base::CharacteristicRoll(int r){
  int CharRoll = r * 5;
  return CharRoll;
}

//Generates starting age
//Will need to expand to allow input from user and modifiers for higher and lower ages
int BRP_human_base::Born(){
  int startage = 17+ROLL.Die(1,6);
  Age = startage;
  return Age;
}

//Calculates Damage Bonus
std::string BRP_human_base::DamageBonus(int T, int Z){
  int Db = T + Z;
    
  std::map<int, std::string> DamageModifierTable;
  DamageModifierTable[0] = "Error";
  DamageModifierTable[1] = "-1D6";
  DamageModifierTable[2] = "-1D4";
  DamageModifierTable[3] = "None";
  DamageModifierTable[4] = "+1D4";
  DamageModifierTable[5] = "+1D6";
  DamageModifierTable[6] = "+2D6";
  DamageModifierTable[7] = "+3D6";
  DamageModifierTable[8] = "Ea. +16"; //need to edit result 8, adding 1d6 for every 16th value above 73 (double check the book). Can I do a for loop in the else if(Db >= 73) which adds 1 to x for "+"4+x"D6"?

  int DMT;
  
  if (Db >= 2 && Db <= 12) {DMT = 1;}
  else if (Db >= 13 && Db <= 16) {DMT = 2;}
  else if (Db >= 17 && Db <= 24) {DMT = 3;}
  else if (Db >= 25 && Db <= 32) {DMT = 4;}
  else if (Db >= 33 && Db <= 40) {DMT = 5;}
  else if (Db >= 41 && Db <= 56) {DMT = 6;}
  else if (Db >= 57 && Db <= 72) {DMT = 7;}
  else if (Db >= 73) {DMT = 8;}
  else {DMT = 0;}

  DamBonus = DamageModifierTable[DMT];
  
  return DamBonus;
}

//Calculates Hit Points
int BRP_human_base::HitPoints(int C, int Z){
  if(TOTAL_HIT_POINTS == true){
    HP = C + Z;
    return HP;
  }else{
    HP = ceil((C + Z)/2); 
    return HP;
  }
}

//Calculates Major Wounds
int BRP_human_base::MajorWounds(int H){
  MW = ceil(H/2);
  return MW;
}

//Calculates Hit Points by Location
void BRP_human_base::HPbyLocation(int B){
  if(HIT_POINTS_PER_LOCATION == true){
    LAH_HP = ceil(B/3); //LAH is Legs, Abdomen, and Head
    Arms_HP = ceil(B/4);
    Chest_HP = ceil(B*0.40); //Chest HP is 4/10 total HP, rounded up
  }
}

//Calcualtes Fatigue Points
int BRP_human_base::FatiguePoints(int A, int B){
  if (FATIGUE_POINTS == true){
    FatiguePointsMax = A + B;
    return FatiguePointsMax;
  }else{
    return 0;
  }
}

//Calculates Sanity Points
void BRP_human_base::SanityPoints(int G){
  if(SANITY == true){
    //Starting Sanity Score
    SanityBase = G*5; 
    //Temporary Insanity Score, rules don't say but I assume it is rounded up.
    TIS = ceil(SanityBase/2); 
    //Current Sanity, sort of a stat
    SAN = SanityBase; 
    //Level of sanity for indefinite insanity, rules don't say but I assume it is rounded up.
    SanityThreshold = ceil(SAN/5); 
    //SAN_Max = 99 - XxX; Max Sanity is 99 or 100 minus Knoweledge: Blasphemous Knowelsdge score. Need a method to check for skills known and current value. Replace XxX with correct code. Maybe check Pro and Per Selected skills for Knowledge(Blasphemous)
  }
}

//Determines character's distinctive features based on CHA
std::string BRP_human_base::DistinctiveFeatures(int H){
  int DFs;
  std::string W;

  if (H <= 3 || H >= 17) {DFs = 4;}
  else if (H >= 4 && H <= 7) {DFs = 3;}
  else if (H >= 8 && H <= 9) {DFs = 2;}
  else if (H >= 10 && H <= 11) {DFs = 1;}
  else if (H >= 12 && H <= 14) {DFs = 2;}
  else if (H >= 15 && H <= 16) {DFs = 3;}
  else {DFs = 0;} 

  //Basic Feature List
  if (DISTINCTIVE_FEATURES == true && DISTINCTIVE_FEATURES_BASIC == true){
    std::map<int, std::string> FeatureTypeTable;
    FeatureTypeTable[0] = "Error";
    FeatureTypeTable[1] = "Hair on head";
    FeatureTypeTable[2] = "Facial hair";
    FeatureTypeTable[3] = "Facial feature";
    FeatureTypeTable[4] = "Expression";
    FeatureTypeTable[5] = "Clothes";
    FeatureTypeTable[6] = "Bearing";
    FeatureTypeTable[7] = "Speech";
    FeatureTypeTable[8] = "Arms and legs";
    FeatureTypeTable[9] = "Torso";
    FeatureTypeTable[10] = "Legs and feet";

    //Assigns random basic features
    for (int i = 0; i < DFs; i++){
      //"they have " + rand_feature + ". " + next feature...
      int Type = ROLL.Die(1,10);  
  
      std::string Sentence = " They have distinctive " + FeatureTypeTable[Type] + ".";
      UnitedFeatures += Sentence;
    }
  }
  
  //2D array of detailed features
  else if (DISTINCTIVE_FEATURES == true && DISTINCTIVE_FEATURES_BASIC == false){
    //More columns can be added for each row, but the 45 max will need to be increasded if total number of columns in a row go beyond it. Random selection counts selected row so no other code needs to be edited. Name and number at the end of each array is the row's type and current number of columns I put in at the time 
    std::string FeatureArray[10][45] = 
    {
      {"a completely bald head", "a bald spot on top of their head", "blond hair", "black hair", "braided hair", "brown hair", "a crew-cut", "curly hair", "dirty hair", "a head full of lice", "glossy hair", "gray hair", "long hair", "lustrous hair", "matted hair", "oily hair", "perfumed their hair", "receding hair", "red hair", "a shaven head", "spiky hair", "very long hair", "wavy hair", "a wig on their head"}, //Hair on head 24
      {"arched eyebrows", "a braided beard", "a bushy beard", "a curled and perfumed beard", "an enormous mustachios", "eyebrows that had grown together", "a goatee", "a long beard", "no eyebrows", "sideburns", "strange designs cut in close-trimmed beard", "thick eyebrows"}, //Facial hair 12
      {"a visable birthmark on their face", "black eyes", "blue eyes", "bright eyes", "a broken nose", "broken teeth", "brown eyes", "a deeply tanned face", "a double chin", "earrings on",  "an enormous chin", "even teeth", "an eye patch", "fleshy lips", "a gap in their teeth", "gray eyes", "hairy ears", "high cheekbones", "a hooked nose", "large eyes", "a large nose", "long eyelashes", "jagged teeth", "a nose ring on", "a pale face", "pockmarked skin", "a pointed chin", "pointed teeth", "prominent incisors", "a pug nose", "a round face", "a visable scar on their face", "sensuous lips", "stained teeth", "a tattooed face", "thin lips", "tiny ears", "a turned-up nose", "warts on their face", "a weak chin", "white teeth", "a wide-eyed look", "yellow teeth"}, //Facial feature 43
      {"an adoring expression", "an alluring expression", "an arrogant expression", "a bemused expression", "a bright-eyed expression", "a curious expression", "a cringing expression", "a dour expression", "a drunken expression", "a friendly expression", "a guarded expression", "a haughty expression", "a lecherous expression", "a leering expression", "a meek expression", "a mischievous expression", "a naïve expression", "an outgoing expression", "a piercing expression", "a pleasant expression", "a proud expression", "a seductive expression", "a sneaky expression", "a sneering expression", "a squinting expression"}, //Expression 23
      {"an ancient style of clothing on", "an armored hat on", "athletic clothing", "no footware and are barefoot", "clothes that leave the wearer too cold on", "clothes that leave the wearer too hot on.", "a conical hat on", "clothing that is embroidered with a special emblem", "expensive clothing on", "fashionable clothing on", "fine boots", "wearing clothing for the wrong sex", "formfitting clothes", "clothing that are full of holes", "garish clothes", "gaudy clothes", "ill-fitting clothes", "lots of cheap jewelry", "new clothes", "nightclothes", "little on and are partly nude", "a peaked hat on", "prim clothes on", "rich clothing", "sandals", "satiny clothing", "sexy clothing", "skintight clothes", "sporty clothing", "subdued clothing", "too much ornamentation", "a uniform on", "that is overall utilitarian", "a vulgar style of clothing", "a wide hat on"}, //Clothes 35
      {"an angry bearing", "a casual bearing", "a clumsy bearing", "a confident bearing", "an ethereal bearing", "a fearful bearing", "a graceful bearing", "a humble bearing", "a jaunty bearing", "a languid bearing", "a military bearing", "a nimble bearing", "a plodding bearing", "a pushy bearing", "a reserved bearing", "a slouching bearing", "a sprightly bearing", "a stiff bearing", "a swaggering bearing", "a sensual bearing", "a swaying bearing", "a wary bearing", "a weary bearing", "a yielding bearing"}, //Bearing 24
      {"an accented way of speech", "an affected way of speech", "an aggressive way of speech", "a deep voice", "a demanding way of speech", "a drawling way of speech", "a faint voice", "a hesitant way of speech", "a high-pitched voice", "an imperious way of speech", "a musical voice", "a mumbling way of sppech", "a nasal speech", "a raspy voice", "a sharp way of speech", "a sensual voice", "a shrill voice", "a slow way of speech", "a smooth voice", "a soft-spoken way of speech", "a strong voice", "a throaty way of speech", "an unintelligible way of speech", "a whining voice"}, //Speech 24
      {"a birthmark visible on their arm", "bracelets and other arm jewelry", "bulging biceps", "calloused hands", "deeply tanned arms", "hairless arms", "hairy arms", "knobby elbows", "large knuckles", "a birthmark visible on their hand", "long arms", "long fingernails", "muscular arms", "one arm longer than the other", "one finger missing", "one too many fingers present", "pointed elbows", "pointed fingernails", "powerful arms and hands", "rings on their fingers", "a scar on their hand", "a scar on their arm", "slender amrs", "smooth-skinned hands", "tattooed arms", "tattooed hands", "very hairy arms", "very pale skin on their hands", "very pale skin on their arms"}, //Arms and Hands 29
      {"a barrel-like like torso", "a belly ring on", "a birthmark visible on their torso", "broad-shoulders", "a curvy figure", "every bone is showing on their body", "a flat stomach", "hairless chect", "a high waist", "a lean figure", "a long torso", "many scars aross their chest", "many scars aross their back", "many scars aross their abdomen", "a muscular figure", "a narrow figure", "no navel", "one nipple missing", "a potbelly", "a prominent scar across their chest", "a prominent scar across their back", "a prominent scar across their abdomen" "a short torso", "a shrunken chest", "a sinewy figure", "a sleek figure", "a slender figure", "a slim-hipped form", "a svelte figure", "a tall figure", "tan lines visible across their chest", "tan lines visible across their back", "tan lines visible across their abdomen", "a tanned torso", "a tattooed chest", "a tattooed back", "a tattooed abdomen", "a thick torso", "a thin torso", "a very hairy back", "a very hairy chest", "a very hairy abdomen", "a very pale torso", "a willowy figure"}, //Torso 44
      {"a birthmark visible on their foot", "a birthmark visible on their leg", "bulging thighs and calves", "calloused feet", "deeply tanned legs", "deeply tanned feet", "hairless legs", "hairless feet", "hairy legs", "hairy feet", "knobby knees", "a limp in one leg", "many scars aross their legs", "many scars aross their feet", "muscular legs", "one toe missing", "one too many toes present", "a scar on their foot", "a scar on their leg", "burn scars from fire on their leg", "burn scars from fire on their foot", "burn scars from acid on their foot", "burn scars from acid on their leg", "sleek looking legs", "smooth legs", "tanned legs", "tattooed legs", "a toe ring on", "very hairy legs", "very hairy feet", "very long legs", "very pale skin on their legs", "very pale skin on their feet", "very short legs", "weathered skin on their legs", "weathered skin on their feet"} //Legs and Feet 36
  };                          

    //For loop to get the the full detailed feature discription
    for (int i = 0; i < DFs; i++){
        //"they have " + rand_feature + ". " + next feature...
        int Type = ROLL.Die(0,9);  
        int Count = 0;
        
        //counts how many choices there are in a selected array
        while (FeatureArray[Type][Count] != ""){
          Count++;
        }
        
        //Picks a random choice from the counted array that was selected and adds it to UnitedFeatures
        if (Count > 0){
          //int Feature = rand() % Count;
          int Feature = ROLL.Die(0,Count-1);
          std::string Sentence = " They have " + FeatureArray[Type][Feature] + ".";
          UnitedFeatures += Sentence;
        }
      }
  }

  //default if DISTINCTIVE_FEATURES is false, returns a blank space on the sheet
  else{
    UnitedFeatures = "";
  }
  
  return UnitedFeatures;
}

//Profession skill points
int BRP_human_base::ProSkillPointsPool(){
  ProSkillPtsMAX = 0;
  
  if (POWER_LEVEL == 1){//Heroic game
    if (EDUCATION_STAT == true){
        ProSkillPtsMAX = EDU*25;
      }else{
        ProSkillPtsMAX = 325;
      }
  }
  else if (POWER_LEVEL == 2){//Epic game
    if (EDUCATION_STAT == true){
        ProSkillPtsMAX = EDU*30;
      }else{
        ProSkillPtsMAX = 400; 
      }
  }
  else if (POWER_LEVEL == 3){//Superhuman game
    if (EDUCATION_STAT == true){
        ProSkillPtsMAX = EDU*40;
      }else{
        ProSkillPtsMAX = 500;
      }
  }
  else{//default for Nomral game
    if (EDUCATION_STAT == true){
        ProSkillPtsMAX = EDU*20;
      }else{
        ProSkillPtsMAX = 250;
      }
  }
  return ProSkillPtsMAX;
}

//Set Skill Rating Maximum
int BRP_human_base::SkillRatingMaximum(){
  SkillRatingMAX = 0;

  switch(POWER_LEVEL){
    case 1: //Heroic game
      {SkillRatingMAX = 90;}
    case 2: //Epic game
      {SkillRatingMAX = 101;}
    case 3: //Superhuman game
      {SkillRatingMAX = 999;}//No limit to skill ratings
    default: //default for Nomral game
      {SkillRatingMAX = 75;}
  }
  
  return SkillRatingMAX;
}

//Personal skill points
int BRP_human_base::PerSkillPonitsPool(){
  PerSkillPtsMAX = 0;
  
  if (INCREASED_PERSONAL_SKILL_POINTS == true){
      if (POWER_LEVEL == 1){//Heroic game
          PerSkillPtsMAX = INT*15;
        }
      else if (POWER_LEVEL == 2){//Epic game
          PerSkillPtsMAX = INT*20;
        }
      else if (POWER_LEVEL == 3){//Superhuman game
          PerSkillPtsMAX = INT*25;
        }
  }
  else{//Default Normal game
    PerSkillPtsMAX = INT*10; 
  }
  
  return PerSkillPtsMAX;
}

//Determines character's profession
void BRP_human_base::Professions(){
  std::string jobs[] = {"Artist", "Assassin", "Athlete", "Beggar", "Clerk", "Computer Tech", "Crafter", "Criminal", "Detective", "Doctor", "Engineer", "Entertainer", "Explorer", "Farmer", "Gambler", "Herder", "Hunter", "Journalist", "Laborer", "Lawkeeper", "Lawyer", "Mechanic", "Merchant", "Noble", "Occultist", "Pilot", "Politician", "Priest", "Sailor", "Scholar", "Scientist", "Servant", "Shaman", "Slave", "Soldier", "Spy", "Student", "Teacher", "Technician", "Thief", "Tribesperson", "Warrior", "Wizard", "Writer"};

  //44 total profession, elements are between 0 and 43
  //Hired = ROLL.Die(0,43); //OFF FOR TESTING, also need to replace the 44 with dynamic count of the jobs array
  Hired = 6;

  Profession = jobs[Hired];

  //std::string pay[5] = {"Destitute", "Poor", "Average", "Affluent", "Wealthy"};
 
  //int Earned = rand() % 8;

  //Wealth = "Broke";

  //Table of profession wealth, int values are weights for chances wealth levels; 00 = never, 99 = always
  
  std::map<std::string, WealthCategorys> WealthTable;
  WealthTable["Artist"] = {{ {"Destitute",20}, {"Poor",45}, {"Average",45}, {"Affluent",20}, {"Wealthy",20} }};//00
  WealthTable["Assassin"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};
  WealthTable["Athlete"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",30}, {"Affluent",30}, {"Wealthy",20} }};
  WealthTable["Beggar"] = {{ {"Destitute",95}, {"Poor",02}, {"Average",00}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Clerk"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",99}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Computer Tech"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};//05
  WealthTable["Crafter"] = {{ {"Destitute",00}, {"Poor",30}, {"Average",70}, {"Affluent",30}, {"Wealthy",00} }};
  WealthTable["Criminal"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",40}, {"Affluent",20}, {"Wealthy",05} }};
  WealthTable["Detective"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};
  WealthTable["Doctor"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};
  WealthTable["Engineer"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",00} }};//10
  WealthTable["Entertainer"] = {{ {"Destitute",20}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",20} }};
  WealthTable["Explorer"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",00}, {"Affluent",50}, {"Wealthy",50} }};
  WealthTable["Farmer"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",00} }};
  WealthTable["Gambler"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",00} }};
  WealthTable["Herder"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",05}, {"Wealthy",00} }};//15
  WealthTable["Hunter"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",00}, {"Wealthy",02} }};
  WealthTable["Journalist"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};
  WealthTable["Laborer"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Lawkeeper"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",02}, {"Wealthy",00} }};
  WealthTable["Lawyer"] = {{ {"Destitute",20}, {"Poor",20}, {"Average",20}, {"Affluent",20}, {"Wealthy",20} }};//20
  WealthTable["Mechanic"] = {{ {"Destitute",00}, {"Poor",40}, {"Average",60}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Merchant"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",30}, {"Affluent",65}, {"Wealthy",30} }};
  WealthTable["Noble"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",00}, {"Affluent",30}, {"Wealthy",65} }};
  WealthTable["Occultist"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",20}, {"Affluent",45}, {"Wealthy",20} }};
  WealthTable["Pilot"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};//25
  WealthTable["Politician"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",00}, {"Affluent",65}, {"Wealthy",30} }};
  WealthTable["Priest"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",02} }};
  WealthTable["Sailor"] = {{ {"Destitute",00}, {"Poor",30}, {"Average",65}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Scholar"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",65}, {"Affluent",30}, {"Wealthy",00} }};
  WealthTable["Scientist"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",30}, {"Affluent",65}, {"Wealthy",00} }};//30
  WealthTable["Servant"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Shaman"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Slave"] = {{ {"Destitute",50}, {"Poor",50}, {"Average",00}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Soldier"] = {{ {"Destitute",00}, {"Poor",50}, {"Average",50}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Spy"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};//35
  WealthTable["Student"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",45}, {"Affluent",20}, {"Wealthy",20} }};
  WealthTable["Teacher"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",65}, {"Affluent",30}, {"Wealthy",00} }};
  WealthTable["Technician"] = {{ {"Destitute",00}, {"Poor",00}, {"Average",50}, {"Affluent",50}, {"Wealthy",00} }};
  WealthTable["Thief"] = {{ {"Destitute",20}, {"Poor",20}, {"Average",20}, {"Affluent",20}, {"Wealthy",20} }};
  WealthTable["Tribesperson"] = {{ {"Destitute",50}, {"Poor",50}, {"Average",00}, {"Affluent",00}, {"Wealthy",00} }};//40
  WealthTable["Warrior"] = {{ {"Destitute",30}, {"Poor",65}, {"Average",30}, {"Affluent",00}, {"Wealthy",00} }};
  WealthTable["Wizard"] = {{ {"Destitute",00}, {"Poor",20}, {"Average",20}, {"Affluent",45}, {"Wealthy",20} }};
  WealthTable["Writer"] = {{ {"Destitute",00}, {"Poor",30}, {"Average",65}, {"Affluent",30}, {"Wealthy",30} }};//43

  //Generate a random number for selecting a WealthLevel
  int Income = ROLL.Die(0,99);

  //Makes a reference to WealthCategory set to the current Profession
  WealthCategorys& WC = WealthTable[Profession];

  //This fails if it gets to the end of the Wealth Level options without beign able to pick one
  //I don't get it and need to study and come up with one I know and can work with
  for (auto& range : WC.range){
      if (range.WealthWeight >= Income){
        Wealth = range.WealthLevel;
        break;
      }
      Income -= range.WealthWeight;
  }
}

//Determines character's gender 
std::string BRP_human_base::RandGender(int X){
  
  //50% Female, 49% Male, 1% Non-Binary
  if (X == 100) {Gender = "Non-Binary";}
  else if (X >= 51) {Gender = "Male";}
  else {Gender = "Female";}
  
  return Gender;
}

//Determins character's religion/who they worship
void BRP_human_base::Faith(){
  Beliefs = {"Atheist", "Agnostic", "Ignostic", "Nonreligious", "Secular", "Baha'is", "Buddhist", "Christian", "Confucian", "Hindu", "Muslim", "Jainist", "Jewish", "Shintoists", "Satanist", "Sikh", "Taoist", "Zoroastrian", "Jain", "Polytheistic", "Worshipper of Zeus", "Worshipper of Hera", "Worshipper of Atremis", "Worshipper of Hades", "Worshipper of Posidon", "Worshipper of Cthulhu", "Worshipper of Ra", "Worshipper of Set", "Druid", "Animist", "Worshipper of Bast", "Worshipper of Horus", "Worshipper of Isis", "Worshipper of Khepri", "Worshipper of Anubis", "Worshipper of Odin", "Worshipper of Thor", "Worshipper of Loki", "Worshipper of Yudi", "Worshipper of Lóngshén", "Worshipper of Doumu"};

  int Convert = ROLL.Die(0,Beliefs.size()-1);
  Religion = Beliefs.at(Convert);
}

//Determines character's hand dominance 
std::string BRP_human_base::HandDom(int Odds){
  
  //83% Right-Handed, 13% Left-Handed, 3% Ambidextrous, 1% Cross-Dominant; based on UN data
  if (Odds == 100) {Handedness = "Cross-Dominant";}
  else if (Odds >= 97) {Handedness = "Ambidextrous";}
  else if (Odds >= 1 && Odds <= 13) {Handedness = "Left-Handed";}
  else {Handedness = "Right-Handed";}
  
  return Handedness;
}

//Determines character's Height and Weight, argument is SIZ
void BRP_human_base::HeightandWeight(int z){
  int ht_raw = 0; //defaults to cm
  int wt_raw = 0; //defaults to kg

  switch(z){
    case 1: 
      ht_raw = ROLL.Die(0, 30);
      wt_raw = ROLL.Die(0, 10);
      break;
    case 2:  
      ht_raw = ROLL.Die(31, 60);
      wt_raw = ROLL.Die(5, 20);
      break;
    case 3:  
      ht_raw = ROLL.Die(61, 90);
      wt_raw = ROLL.Die(10, 30);
      break;
    case 4:  
      ht_raw = ROLL.Die(91, 105);
      wt_raw = ROLL.Die(16, 40);
      break;
    case 5:  
      ht_raw = ROLL.Die(105, 120);
      wt_raw = ROLL.Die(21, 50);
      break;
    case 6:  
      ht_raw = ROLL.Die(121, 135);
      wt_raw = ROLL.Die(26, 60);
      break;
    case 7:  
      ht_raw = ROLL.Die(136, 150);
      wt_raw = ROLL.Die(31, 70);
      break;
    case 8:  
      ht_raw = ROLL.Die(151, 155);
      wt_raw = ROLL.Die(36, 73);
      break;
    case 9:  
      ht_raw = ROLL.Die(155, 160);
      wt_raw = ROLL.Die(39, 82);
      break;
    case 10:  
      ht_raw = ROLL.Die(160, 165);
      wt_raw = ROLL.Die(41, 91);
      break;
    case 11:  
      ht_raw = ROLL.Die(165, 170);
      wt_raw = ROLL.Die(43, 100);
      break;
    case 12:  
      ht_raw = ROLL.Die(170, 175);
      wt_raw = ROLL.Die(46, 109);
      break;
    case 13:  
      ht_raw = ROLL.Die(175, 180);
      wt_raw = ROLL.Die(50, 118);
      break;
    case 14:  
      ht_raw = ROLL.Die(180, 185);
      wt_raw = ROLL.Die(55, 127);
      break;
    case 15:  
      ht_raw = ROLL.Die(185, 190);
      wt_raw = ROLL.Die(59, 136);
      break;
    case 16:  
      ht_raw = ROLL.Die(190, 195);
      wt_raw = ROLL.Die(64, 146);
      break;
    case 17:  
      ht_raw = ROLL.Die(195, 200);
      wt_raw = ROLL.Die(68, 155);
      break;
    case 18:  
      ht_raw = ROLL.Die(200, 205);
      wt_raw = ROLL.Die(73, 164);
      break;
    case 19:  
      ht_raw = ROLL.Die(205, 210);
      wt_raw = ROLL.Die(82, 173);
      break;
    case 20:  
      ht_raw = ROLL.Die(210, 215);
      wt_raw = ROLL.Die(90, 182);
      break;
    case 21:  
      ht_raw = ROLL.Die(215, 220);
      wt_raw = ROLL.Die(100, 191);
      break;
    case 22:  
      ht_raw = ROLL.Die(221, 225);
      wt_raw = ROLL.Die(106, 220);
      break;
    case 23:  
      ht_raw = ROLL.Die(226, 230);
      wt_raw = ROLL.Die(111, 230);
      break;
    case 24:  
      ht_raw = ROLL.Die(231, 235);
      wt_raw = ROLL.Die(116, 240);
      break;
    case 25:  
      ht_raw = ROLL.Die(236, 240);
      wt_raw = ROLL.Die(121, 250);
      break;
    default: break;
  }

  //converts raw cm to m in text and kg in text
  if (HEIGHT_AND_WEIGHT_IN_METERS == true){
    float ht_m = ht_raw * 0.01;
    Height = std::to_string(ht_m);
    Height = Height.substr(0, Height.find(".") + 3) + "m";
    Weight = std::to_string(wt_raw) + "kg";
  }

  //converts raw cm and kg into imperial units in text
  else if (HEIGHT_AND_WEIGHT_IN_IMPERIAL == true){
    float ht_ft_in = ht_raw / 30.48;
    Height = std::to_string(ht_ft_in);
    Height = Height.substr(0, 1) + "'" + Height.substr(Height.find(".") + 1, 1) + '"';
    float wt_lbs = (wt_raw * 35.274) / 16;
    Weight = std::to_string(wt_lbs);
    Weight = Weight.substr(0, Weight.find(".") + 3) + "lbs";
  }
  else{//default text based resutls based on BMI
      std::string HTandWT[2][5] = 
      {
        {"Tiny","Short","Average","Tall","Towering"},
        {"Frail","Thin","Average","Overweight","Obese"}
      };
    
    switch(z){
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5: 
        Height = HTandWT[0][0]; 
        break;
      case 6:
      case 7:
      case 8:
      case 9:
      case 10: 
        Height = HTandWT[0][1];
        break;
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
        Height = HTandWT[0][2];
        break;
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
        Height = HTandWT[0][3];
        break;
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
        Height = HTandWT[0][4];
        break;
      default: 
        Height = "error";
    }
    float bmi = (wt_raw / std::pow((ht_raw * 0.01), 2));
    
    if (bmi <= 16.9){Weight = HTandWT[1][0];}
    else if (bmi >= 17.0 && bmi <= 18.4){Weight = HTandWT[1][1];}
    else if (bmi >= 18.5 && bmi <= 24.9){Weight = HTandWT[1][2];}
    else if (bmi >= 25.0 && bmi <= 29.9){Weight = HTandWT[1][3];}
    else {Weight = HTandWT[1][4];}
  } 
}

//Primary Skill Category
int BRP_human_base::Skill_Category_Primary(int x){
  //argument x = one STAT, +1 for every point over 10, -1 for every point under 10, 0 at 10
  int P = 0;
  if (x >= 10){
     int z = x-10;
     for (int i = 0; i < z; i++){
       P++;}
   }
  else{
    int z = 10-x;
     for (int i = 0; i < z; i++){
       P--;}
  }
  return P;
}

//Secondary Skill Category
int BRP_human_base::Skill_Category_Secondary(int x){
  //argument x = one STAT, +1 for every 2 points over 10, -1 for every 2 points under 10, 0 at 10
  int P = 0;
  if (x >= 10){
     x = x - 10;
     int z = std::floor(x / 2);
     for (int i = 0; i < z; i++){
       P++;}
   }
  else{
    int z = std::floor((10-x) / 2);
     for (int i = 0; i < z; i++){
       P--;}
  }
  return P;
}

//Negative Skill Category
int BRP_human_base::Skill_Category_Negative(int x){
  //argument x = one STAT (SIZ is the only one), -1 for every point over 10, +1 for every point under 10, 0 at 10
  int P = 0;
  if (x >= 10){
     int z = x-10;
     for (int i = 0; i < z; i++){
       P--;}
   }
  else{
    int z = 10-x;
     for (int i = 0; i < z; i++){
       P++;}
  }
  return P;
}

//Handles the optional Skill Category system, both standard & simple
void BRP_human_base::SkillCategory(){

  //Skill Category variables
  Combat_skillcategory = 0;    
  Communication_skillcategory = 0;
  Manipulation_skillcategory = 0;
  Mental_skillcategory = 0;
  Perception_skillcategory = 0;
  Physical_skillcategory = 0;

  //Standard Skill Category rules
  if (SKILL_CATEGORY == true && SKILL_CATEGORY_SIMPLE == false){
   int Secondary_Skill_Category_EDU = 0;
   if (EDUCATION_STAT == true) 
     {int Secondary_Skill_Category_EDU = Skill_Category_Secondary(EDU);}
  
   //Mental Skill Category also addes in EDU as a secondary characteristic but ommits it if EDU is not used
   Combat_skillcategory = (Skill_Category_Primary(DEX) + Skill_Category_Secondary(INT) + Skill_Category_Secondary(STR));    
   Communication_skillcategory = (Skill_Category_Primary(INT) + Skill_Category_Secondary(POW) + Skill_Category_Secondary(CHA));
   Manipulation_skillcategory = (Skill_Category_Primary(DEX) + Skill_Category_Secondary(INT) + Skill_Category_Secondary(STR));
   Mental_skillcategory = (Skill_Category_Primary(INT) + Skill_Category_Secondary(POW) + Secondary_Skill_Category_EDU);
   Perception_skillcategory = (Skill_Category_Primary(INT) + Skill_Category_Secondary(POW) + Skill_Category_Secondary(CON));
   Physical_skillcategory = (Skill_Category_Primary(DEX) + Skill_Category_Secondary(STR) + Skill_Category_Secondary(CON) + Skill_Category_Negative(SIZ));
  }

  //Simple Skill Category rules
  if (SKILL_CATEGORY == true && SKILL_CATEGORY_SIMPLE == true){
   //Takes a relevant STAT and divides it by 2 rounded up 
   Combat_skillcategory = ceil(DEX/2);    
   Communication_skillcategory = ceil(CHA/2);
   Manipulation_skillcategory = ceil(DEX/2);
   Mental_skillcategory = ceil(INT/2);
   Perception_skillcategory = ceil(POW/2);
   Physical_skillcategory = ceil(STR/2);
  } 
}

//Handles all skills and skill categorys 
void BRP_human_base::Skills(int x, int i, int p){  
  //special base values for skills
  int DodgeBase = x*2; //Dodge
  int FlyBase = ceil(x/2); //Fly
  if (WINGED_CHARACTER == true) 
    {FlyBase = x*4;}
  int GamingBase = i+p; //Gaming
  int Language0Base = i*5; //Own Language
  if (EDUCATION_STAT == true && EDU*5 > i*5)
    {Language0Base = EDU*5;}
  int ProjectionBase = x*2; //Projection
  int PsychotherapyBase = 0; //Psychotherapy
  if (SANITY == true)
    {PsychotherapyBase = 1;}
  int LiteracyBase = 0; //Literacy, need an if statement for modern setting
    
  //map of all skills with; name, subtype, base%, a value to be modifyed, and skill category
  //This still seems too unweildly, especially with subtypes and Bases set by weapons
  //Should Each type also have skill category assigned too it as well?
  //ARMS are slots for all combat and weapon skills.  
  SkillTable["ARMS0"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["ARMS1"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["ARMS2"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["ARMS3"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["ARMS4"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["ARMS5"] = { "", "", 0, 0, Combat_skillcategory};
  SkillTable["BLANK"] = { "", "", 0, 0, 0};
  SkillTable["Appraise"] = { "Appraise", "", 15, 0, Mental_skillcategory};
  SkillTable["Art0"] = { "Art", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Art1"] = { "Art", "", 5, 0, Manipulation_skillcategory};//10
  SkillTable["Artillery0"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Artillery1"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Artillery2"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Bargain"] = { "Bargain", "", 5, 0, Communication_skillcategory};
  SkillTable["Brawl"] = { "Brawl", "", 25, 0, Combat_skillcategory};
  SkillTable["Climb"] = { "Climb", "", 40, 0, Physical_skillcategory};
  SkillTable["Command"] = { "Command", "", 5, 0, Communication_skillcategory};
  SkillTable["Craft0"] = { "Craft", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Craft1"] = { "Craft", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Demolition"] = { "Demolition", "", 1, 0, Manipulation_skillcategory};//20
  SkillTable["Disguise"] = { "Disguise", "", 1, 0, Communication_skillcategory};
  SkillTable["Dodge"] = { "Dodge", "", DodgeBase, 0, Physical_skillcategory};
  SkillTable["Drive0"] = { "Drive", "", 20, 0, Manipulation_skillcategory};
  SkillTable["Drive1"] = { "Drive", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Drive2"] = { "Drive", "", 20, 0, Manipulation_skillcategory};
  SkillTable["Drive3"] = { "Drive", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Energy Weapon0"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Energy Weapon1"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Energy Weapon2"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Etiquette"] = { "Etiquette", "", 5, 0, Communication_skillcategory};//30
  SkillTable["Fast Talk"] = { "Fast Talk", "", 5, 0, Communication_skillcategory};
  SkillTable["Fine Manipulation"] = { "Fine Manipulation", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Firearm0"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["Firearm1"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["Firearm2"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["First Aid"] = { "First Aid", "", 30, 0, Mental_skillcategory};
  SkillTable["Fly"] = { "Fly", "", FlyBase, 0, Physical_skillcategory};
  SkillTable["Gaming"] = { "Gaming", "", GamingBase, 0, Mental_skillcategory};
  SkillTable["Grapple"] = { "Grapple", "", 25, 0, Combat_skillcategory};
  SkillTable["Heavy Machine0"] = { "Heavy Machine", "", 1, 0, Manipulation_skillcategory};//40
  SkillTable["Heavy Weapon0"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon1"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon2"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Hide"] = { "Hide", "", 10, 0, Physical_skillcategory};
  SkillTable["Insight"] = { "Insight", "", 05, 0, Perception_skillcategory};
  SkillTable["Jump"] = { "Jump", "", 25, 0, Physical_skillcategory};
  SkillTable["Knowledge0"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge1"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge2"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Language0"] = { "Language", "", Language0Base, 0, Communication_skillcategory};//50
  SkillTable["Language1"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language2"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language3"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Listen"] = { "Listen", "", 25, 0, Perception_skillcategory};
  SkillTable["Literacy"] = { "Literacy", "", LiteracyBase, 0, Mental_skillcategory};
  SkillTable["Martial Arts"] = { "Martial Arts", "", 1, 0, Combat_skillcategory};
  SkillTable["Medicine"] = { "Medicine", "", 5, 0, Mental_skillcategory};
  SkillTable["Melee Weapon0"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Melee Weapon1"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Melee Weapon2"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};//60
  SkillTable["Missile Weapon0"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Missile Weapon1"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Missile Weapon2"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Navigate"] = { "Navigate", "", 10, 0, Perception_skillcategory};
  SkillTable["Parry0"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Parry1"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Parry2"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Preform"] = { "Preform", "", 5, 0, Communication_skillcategory};
  SkillTable["Persuade"] = { "Persuade", "", 15, 0, Communication_skillcategory};
  SkillTable["Pilot0"] = { "Pilot", "", 1, 0, Physical_skillcategory};//70
  SkillTable["Pilot1"] = { "Pilot", "", 1, 0, Physical_skillcategory};
  SkillTable["Pilot2"] = { "Pilot", "", 1, 0, Physical_skillcategory};
  SkillTable["Projection"] = { "Projection", "", ProjectionBase, 0, Physical_skillcategory};
  SkillTable["Psychotherapy"] = { "Psychotherapy", "", PsychotherapyBase, 0, Mental_skillcategory};
  SkillTable["Repair0"] = { "Repair", "", 15, 0, Manipulation_skillcategory};
  SkillTable["Repair1"] = { "Repair", "", 15, 0, Manipulation_skillcategory};
  SkillTable["Research"] = { "Research", "", 25, 0, Perception_skillcategory};
  SkillTable["Ride0"] = { "Ride", "", 5, 0, Communication_skillcategory};
  SkillTable["Ride1"] = { "Ride", "", 5, 0, Communication_skillcategory};
  SkillTable["Ride2"] = { "Ride", "", 5, 0, Communication_skillcategory};//80
  SkillTable["Science0"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science1"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science2"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science3"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Sense"] = { "Sense", "", 10, 0, Perception_skillcategory};
  SkillTable["Shield0"] = { "Shield", "", 0, 0, Combat_skillcategory};
  SkillTable["Shield1"] = { "Shield", "", 0, 0, Combat_skillcategory};
  SkillTable["Slight of Hand"] = { "Slight of Hand", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Spot"] = { "Spot", "", 25, 0, Perception_skillcategory};
  SkillTable["Status"] = { "Status", "", 15, 0, Communication_skillcategory};//90
  SkillTable["Stealth"] = { "Stealth", "", 10, 0, Physical_skillcategory};
  SkillTable["Strategy"] = { "Strategy", "", 1, 0, Mental_skillcategory};
  SkillTable["Swim"] = { "Swim", "", 25, 0, Physical_skillcategory};
  SkillTable["Teach"] = { "Teach", "", 10, 0, Communication_skillcategory};
  SkillTable["Technical Skill0"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Technical Skill1"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Technical Skill2"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Throw"] = { "Throw", "", 25, 0, Physical_skillcategory};
  SkillTable["Track"] = { "Track", "", 10, 0, Perception_skillcategory};//99
 /* SkillTable["SLOT00"] = { "", "", 0, 0, 0};
  SkillTable["SLOT01"] = { "", "", 0, 0, 0};
  SkillTable["SLOT02"] = { "", "", 0, 0, 0};
  SkillTable["SLOT03"] = { "", "", 0, 0, 0};
  SkillTable["SLOT04"] = { "", "", 0, 0, 0};
  SkillTable["SLOT05"] = { "", "", 0, 0, 0};
  SkillTable["SLOT06"] = { "", "", 0, 0, 0};
  SkillTable["SLOT07"] = { "", "", 0, 0, 0};
  SkillTable["SLOT08"] = { "", "", 0, 0, 0};
  SkillTable["SLOT09"] = { "", "", 0, 0, 0};
  SkillTable["SLOT10"] = { "", "", 0, 0, 0};
  SkillTable["SLOT11"] = { "", "", 0, 0, 0};
  SkillTable["SLOT12"] = { "", "", 0, 0, 0};
  SkillTable["SLOT13"] = { "", "", 0, 0, 0};
  SkillTable["SLOT14"] = { "", "", 0, 0, 0};
  SkillTable["SLOT15"] = { "", "", 0, 0, 0};
  SkillTable["SLOT16"] = { "", "", 0, 0, 0};
  SkillTable["SLOT17"] = { "", "", 0, 0, 0};
  SkillTable["SLOT18"] = { "", "", 0, 0, 0};
  SkillTable["SLOT19"] = { "", "", 0, 0, 0};
  SkillTable["SLOT20"] = { "", "", 0, 0, 0};
  SkillTable["SLOT21"] = { "", "", 0, 0, 0};
  SkillTable["SLOT22"] = { "", "", 0, 0, 0};
  SkillTable["SLOT23"] = { "", "", 0, 0, 0};
  SkillTable["SLOT24"] = { "", "", 0, 0, 0};
  SkillTable["SLOT25"] = { "", "", 0, 0, 0};
  SkillTable["SLOT26"] = { "", "", 0, 0, 0};
  SkillTable["SLOT27"] = { "", "", 0, 0, 0};
  SkillTable["SLOT28"] = { "", "", 0, 0, 0};
  SkillTable["SLOT29"] = { "", "", 0, 0, 0};
  SkillTable["SLOT30"] = { "", "", 0, 0, 0};
  SkillTable["SLOT31"] = { "", "", 0, 0, 0};
  SkillTable["SLOT32"] = { "", "", 0, 0, 0};
  SkillTable["SLOT33"] = { "", "", 0, 0, 0};
  SkillTable["SLOT34"] = { "", "", 0, 0, 0};
  SkillTable["SLOT35"] = { "", "", 0, 0, 0};
  SkillTable["SLOT36"] = { "", "", 0, 0, 0};
  SkillTable["SLOT37"] = { "", "", 0, 0, 0};
  SkillTable["SLOT38"] = { "", "", 0, 0, 0};
  SkillTable["SLOT39"] = { "", "", 0, 0, 0};
  SkillTable["SLOT40"] = { "", "", 0, 0, 0};
  SkillTable["SLOT41"] = { "", "", 0, 0, 0};
  SkillTable["SLOT42"] = { "", "", 0, 0, 0};
  SkillTable["SLOT43"] = { "", "", 0, 0, 0};
  SkillTable["SLOT44"] = { "", "", 0, 0, 0};
  SkillTable["SLOT45"] = { "", "", 0, 0, 0};
  SkillTable["SLOT46"] = { "", "", 0, 0, 0};
  SkillTable["SLOT47"] = { "", "", 0, 0, 0};
  SkillTable["SLOT48"] = { "", "", 0, 0, 0};
  SkillTable["SLOT49"] = { "", "", 0, 0, 0};
  SkillTable["SLOT50"] = { "", "", 0, 0, 0};
  SkillTable["SLOT51"] = { "", "", 0, 0, 0};
  SkillTable["SLOT52"] = { "", "", 0, 0, 0};
  SkillTable["SLOT53"] = { "", "", 0, 0, 0};
  SkillTable["SLOT54"] = { "", "", 0, 0, 0};
  SkillTable["SLOT55"] = { "", "", 0, 0, 0};
  SkillTable["SLOT56"] = { "", "", 0, 0, 0};
  SkillTable["SLOT57"] = { "", "", 0, 0, 0};
  SkillTable["SLOT58"] = { "", "", 0, 0, 0};
  SkillTable["SLOT59"] = { "", "", 0, 0, 0};
  SkillTable["SLOT60"] = { "", "", 0, 0, 0};*/

  //A vector of all Skill names.
  SkillList = {"Appraise", "Art", "Artillery", "Bargain", "Brawl", "Climb", "Command", "Craft", "Demolition", "Disguise", "Dodge", "Drive", "Energy Weapon", "Etiquette", "Fast Talk", "Fine Manipulation", "Firearm", "First Aid", "Fly", "Gaming", "Grapple", "Heavy Machine", "Heavy Weapon", "Hide", "Insight", "Jump", "Knowledge", "Language", "Listen", "Literacy", "Martial Arts", "Medicine", "Melee Weapon", "Missile Weapon", "Navigate", "Parry", "Perform", "Persuade", "Pilot", "Projection", "Psychotherapy", "Repair", "Research", "Ride", "Science", "Sense", "Shield", "Sleight of Hand", "Spot", "Status", "Stealth", "Strategy", "Swim", "Teach", "Technical Skill", "Throw", "Track"};
  
  //Skil Sub Categories
  //Art
  Art = {"Calligraphy", "Composing", "Conceptual Art", "Digital Art", "Drawing", "Painting", "Photography", "Poetry", "Sculpture", "Sketching", "Songwriting", "Writing"};

  //Craft
  Craft = {"Blacksmithing", "Carpentry", "Ceramics", "Cooking", "Leatherworking", "Locksmithing", "Metallurgy", "Stonemasonry"};
  
  //Heavy Machines
  Heavy_Machine = {"Armored Vehicles", "Boilers", "Bulldozers", "Cranes", "Drilling Machine", "Engines", "Forklift", "Street Sweeper", "Tracker", "Turbines"};

  //Knowledges
  Knowledge = {"Academic Lore", "Accounting", "Anthropology", "Archaeology", "Art History", "Blasphemous Lore", "Business", "Espionage", "Folklore", "Group (subspecialty)", "History", "Law", "Linguistics", "Literature", "Occult", "Philosophy", "Politics", "Region (subspecialty)", "Religion (subspecialty)", "Streetwise"}; //maybe make another array of subskills for Knowledge

  //Knowledge (Group)
  //std::string KnowledgeGroup[] = {"Americans","Chinese","British","Europeans",};
  //Knowledge (Region)
  //std::string KnowledgeRegion[] = {"Local", "Nation", "Country", "Desert", "Plains", "Fields", "Jungles", "Forests", "Swamps", "Mountians"};
  //Knowledge (Religion)
  //std::string KnowledgeReligion[] = {"Judisum", "Christianity", "Islam", "Folk"};
  
  //Languages
  Language = {"Amharic", "Arabic", "Bengali", "Bhojpuri", "Cebuano", "Chinese", "Czech", "Danish", "Dutch", "English", "Estonian", "Farsi", "Finnish", "French", "German", "Greek", "Hausa", "Hindi-Urdu", "Hungarian", "Igbo", "Italian", "Japanese", "Javanese", "Korean", "Latin", "Latvian", "Lithuanian", "Lolo", "Macedonian", "Malay", "Māori", "Marathi", "Navajo", "Norwegian", "Oromo", "Polish", "Portuguese", "Russian", "Shona", "Sioux", "Slovak", "Spanish", "Sundanese", "Swahili", "Swedish", "Tagalog", "Tai–Kadai", "Tibetan", "Turkic", "Ukrainian", "Vietnamese", "Yoruba", "Yumplatok", "Zulu"};

  //Languages, Computer Code
  LanguageComputerCode = {"Assembly", "BASIC", "C", "C#", "C++", "COBOL", "Delphi", "Fortran", "Java", "JavaScript", "Lua", "Python", "Ruby", "Scratch", "SQL"};

  //Preform
  Preform = {"Act", "Conduct Orchestra", "Dance", "Juggle", "Orate", "Play", "Instrument (subspeciality)", "Recite", "Ritual", "Sing"};

  //Preform (Instrument)
  //Instrument = {"Flute","Guitar","Piano","Drums","Cowbell"};

  //Pilot
  Pilot = {"Airplane", "Airship", "Balloon", "Boat", "Helicopter", "Hovercraft", "Jet Aircraft", "Jetpack", "Starship", "Submarine"};

  //Repair
  Repair = {"Electrical", "Electronic", "Engineering", "Hydroelectric", "Mechanical", "Structural", "Quantum"};

  //Ride
  Ride = {"Bull", "Camel", "Cattle", "Donkey", "Elephant", "Horse", "Llama", "Mule", "Ostrich", "Water Buffalo", "Yak"};

  //Science
  Science = {"Alchemy", "Astronomy", "Behavioral Science", "Biology", "Botany", "Chemistry", "Cryptography", "Genetics", "Geology", "Mathematics", "Meteorology", "Natural History", "Pharmacology", "Physics", "Planetology", "Psychology", "Quantum Mechanics", "Xenobiology", "Zoology"};

  //Technical
  Technical = {"Clockwork", "Computers", "Cybernetics", "Electronics", "Robotics", "Sensors", "Siege Engines", "Traps"};
}

//Picks random skills for professions with random choices of skills and populates JOBSKILLS from 0 to NumberOfPicks.
void BRP_human_base::RandomProfessionSkillPick(int NumberOfPicks, std::vector<std::string> ProfessionSkills){
  std::shuffle(ProfessionSkills.begin(), ProfessionSkills.end(), RANDOMCORE.mt_rando);
  for(int i = 0; i < NumberOfPicks; i++){
    JOBSKILLS[i] = ProfessionSkills[i];
  }
}

//Assigns skills to JOBSKILLS array based on Profession
void BRP_human_base::PickJobSkills()
{
  switch (Hired) 
  {
    case 0: //Artist NEED TO REDO
    {
      //first random art skill
      int artsubpick = rand() % Art.size();
      std::string artstyle0 = Art.at(artsubpick);
      SkillTable["Art0"].SubSkillName = artstyle0;
      JOBSKILLS[0] = "Art0";
      
      //second random art skill
      std::string artstyle1 = artstyle0;
      while (artstyle1 == artstyle0) 
      {
        int newartsubpick = rand() % Art.size();
        artstyle1 = Art.at(newartsubpick);
      }
      SkillTable["Art1"].SubSkillName = artstyle1;
      JOBSKILLS[1] = "Art1";
      
      //random craft skill
      int craftsubpick = rand() % Craft.size();
      SkillTable["Craft0"].SubSkillName = Craft.at(craftsubpick);
      JOBSKILLS[2] = "Craft0";
      
      //random (appropriate?) Knowledge skill
      int knowsubpick = rand() % Knowledge.size();
      SkillTable["Knowledge0"].SubSkillName = Knowledge.at(knowsubpick);
      JOBSKILLS[3] = "Knowledge0";
     
      //random Other Language
      std::string langspoken1 = SkillTable["Language0"].SubSkillName;
      while (SkillTable["Language0"].SubSkillName == langspoken1) 
      {
        int newlangsubpick = rand() % Language.size();
        langspoken1 = Language.at(newlangsubpick);
      }
      SkillTable["Language1"].SubSkillName = langspoken1;
      JOBSKILLS[4] = "Language1";

      //Own Language
      JOBSKILLS[5] = "Language0";
      
      //Listen
      JOBSKILLS[6] = "Listen";
      
      //Research
      JOBSKILLS[7] = "Research";
      
      //Spot
      JOBSKILLS[8] = "Spot";
      
      //Insight
      JOBSKILLS[9] = "Insight";
    break;
    }
    
    case 1: //Assassin
    {
    //any 5 based on setting:
      std::vector<std::string> AssassinSkillRando = {"Brawl","Disguise","Drive0","Technical Skill0","Grapple","Firearm0","Fine Manipulation","Martial Arts","Melee Weapon0","Missile Weapon0","Ride","Throw","Track"};
      RandomProfessionSkillPick(5, AssassinSkillRando);
      for (int i = 0; i < AssassinSkillRando.size()-1; i++){
        if (JOBSKILLS[i] == "Technical Skill0"){
          SkillTable["Technical Skill0"].SubSkillName = Technical[3];
        }
      }
      //Brawl
      //Disguise
      //Drive
      //Technical Skill (Electronics)
      //Grapple
      //Firearm (any)
      //Fine Manipulation
      //Martial Arts
      //Melee Weapon (any)
      //Missile Weapon (any)
      //Ride
      //Throw
      //Track
    //Dodge
    JOBSKILLS[5] = "Dodge";
    //Hide
    JOBSKILLS[6] = "Hide";
    //Listen
    JOBSKILLS[7] = "Listen";
    //Spot
    JOBSKILLS[8] = "Spot";
    //Stealth
    JOBSKILLS[9] = "Stealth";
    break;
    }
    
    case 2: //Athlete
    {
    //any 5 based on setting and sport
      std::vector<std::string> AthleteSkillRando = {"Brawl","First Aid","Grapple","Insight","Listen","Martial Arts","Spot","Ride0","Swim"};
      RandomProfessionSkillPick(5, AthleteSkillRando);
      //Brawl
      //First Aid
      //Grapple
      //Insight
      //Listen
      //Martial Arts
      //Spot
      //Ride
      //Swim
    //Climb
    JOBSKILLS[5] = "Climb";
    //Dodge
    JOBSKILLS[6] = "Dodge";
    //Jump
    JOBSKILLS[7] = "Jump";
    //Stealth
    JOBSKILLS[8] = "Stealth";
    //Throw
    JOBSKILLS[9] = "Throw";
    break;
    }
    
    case 3: //Beggar
    {
    //Bargain
    JOBSKILLS[0] = "Bargain";
    //Fast Talk
    JOBSKILLS[1] = "Fast Talk";
    //Hide
    JOBSKILLS[2] = "Hide";
    //Insight
    JOBSKILLS[3] = "Insight";
    //Knowledge (Region: local area)
    JOBSKILLS[4] = "Knowledge0";
    SkillTable["Knowledge0"].SubSkillName = Knowledge[17];
    //Listen
    JOBSKILLS[5] = "Listen";
    //Persuade
    JOBSKILLS[6] = "Persuade";
    //Sleight of Hand
    JOBSKILLS[7] = "Sleight of Hand";
    //Spot
    JOBSKILLS[8] = "Spot";
    //Stealth
    JOBSKILLS[9] = "Stealth";
    break;
    }
    
    case 4: //Clerk
    {
    //Bargain
    JOBSKILLS[0] = "Bargain";
    //Etiquette
    JOBSKILLS[1] = "Etiquette";
    //Knowledge (Accounting)
    JOBSKILLS[2] = "Knowledge0";
    SkillTable["Knowledge0"].SubSkillName = Knowledge[1];
    //Knowledge (Law)
    JOBSKILLS[3] = "Knowledge1";
    SkillTable["Knowledge1"].SubSkillName = Knowledge[11];
    //1 Random Knowledge skill
    JOBSKILLS[4] = "Knowledge2";
      SkillTable["Knowledge2"].SubSkillName = Knowledge[ROLL.Die(0,Knowledge.size()-1)];
    if(SkillTable["Knowledge2"].SubSkillName == "Law" || SkillTable["Knowledge2"].SubSkillName == "Accounting"){
      SkillTable["Knowledge2"].SubSkillName = Knowledge[ROLL.Die(0,Knowledge.size()-1)];}
    //Language (Own)
    JOBSKILLS[5] = "Language0";
    //Persuade
    JOBSKILLS[6] = "Persuade";
    //Research
    JOBSKILLS[7] = "Research";
    //Status
    JOBSKILLS[8] = "Status";
    //Technical Skill (Computer Use) or Literacy as appropriate by era
    if(ROLL.Die(0,1) == 0){
      JOBSKILLS[9] = "Literacy";
    }else{JOBSKILLS[9] = "Technical Skill0";
         SkillTable["Technical Skill0"].SubSkillName = Technical[1];}
    break;
    }
   
    case 5: //Computer Tech
    {
    //Pick 1 as specialty appropiate for setting
      //Accounting
      //Hide
      //Knowledge (Law)
    std::vector<std::string> ComputerTechSkillRando = {"Accounting","Hide","Knowledge0"};
    RandomProfessionSkillPick(1, ComputerTechSkillRando);
    if (JOBSKILLS[0] == "Knowledge0"){
      SkillTable["Knowledge0"].SubSkillName = Knowledge[11];}
    //Craft (Computer Hardware or Code)
    JOBSKILLS[1] = "Craft0";
    std::string TECH = (ROLL.Die(0,1) == 0) ? "Computer Hardware" : "Code";
    SkillTable["Craft0"].SubSkillName = TECH;
    //one random Knowledge
    if (JOBSKILLS[0] == "Knowledge0"){
      JOBSKILLS[2] = "Knowledge1";
      SkillTable["Knowledge1"].SubSkillName = Knowledge[ROLL.Die(0, Knowledge.size()-1)];
        if (SkillTable["Knowledge1"].SubSkillName == "Law"){
          SkillTable["Knowledge1"].SubSkillName = Knowledge[ROLL.Die(0, Knowledge.size()-1)];}}
    else {
      JOBSKILLS[2] = "Knowledge0";
      SkillTable["Knowledge0"].SubSkillName = Knowledge[ROLL.Die(0, Knowledge.size()-1)];}
    //Language (Other) (a programming language)
    JOBSKILLS[3] = "Language1";
    SkillTable["Language1"].SubSkillName = LanguageComputerCode[ROLL.Die(0, LanguageComputerCode.size()-1)];
    //Repair (Electrical)
    JOBSKILLS[4] = "Repair0";
    SkillTable["Repair0"].SubSkillName = Repair[0];
    //Repair (Electronics)
    JOBSKILLS[5] = "Repair1";
    SkillTable["Repair1"].SubSkillName = Repair[1];
    //Research
    JOBSKILLS[6] = "Research";
    //Science (Mathametics)
    JOBSKILLS[7] = "Science0";
    SkillTable["Science0"].SubSkillName = Science[9];
    //Status
    JOBSKILLS[8] = "Status";
    //Technical (Computer Use)
    JOBSKILLS[9] = "Technical Skill0";
    SkillTable["Technical Skill0"].SubSkillName = Technical[1];
    break;
    }
    
    case 6: //Crafter
    {
    //pick 2 as appropiate for setting and trade
    std::vector<std::string> CrafterSkillRando = {"Fine Manipulation","Repair","Repair","Repair","Heavy Machine"};
    RandomProfessionSkillPick(2, CrafterSkillRando);
    std::vector<std::string> CrafterRandomRepairSubSkills = {"Electrtical", "Electronics", "Mechanical"};
    if(JOBSKILLS[0] == "Repair" && JOBSKILLS[1] == "Repair"){
      JOBSKILLS[0] = "Repair0";
      SkillTable["Repair0"].SubSkillName = CrafterRandomRepairSubSkills[ROLL.Die(0,CrafterRandomRepairSubSkills.size()-1)];
      JOBSKILLS[1] = "Repair1";
      SkillTable["Repair1"].SubSkillName = SkillTable["Repair0"].SubSkillName;
      while(SkillTable["Repair1"].SubSkillName == SkillTable["Repair0"].SubSkillName){
        SkillTable["Repair1"].SubSkillName = CrafterRandomRepairSubSkills[ROLL.Die(0,CrafterRandomRepairSubSkills.size()-1)];
      }
    }else if(JOBSKILLS[1] == "Repair"){
      JOBSKILLS[1] = "Repair0";
      SkillTable["Repair0"].SubSkillName = CrafterRandomRepairSubSkills[ROLL.Die(0,CrafterRandomRepairSubSkills.size()-1)];
    }else if(JOBSKILLS[0] == "Repair"){
      JOBSKILLS[0] = "Repair0";
      SkillTable["Repair0"].SubSkillName = CrafterRandomRepairSubSkills[ROLL.Die(0,CrafterRandomRepairSubSkills.size()-1)];}
      //Fine Manipulation
      //Repair (Electrtical)
      //Repair (Electronics)
      //Repair (Mechanical)
      //Heavy Machine
    //Appraise
    JOBSKILLS[2] = "Appraise";
    //any one Art
    JOBSKILLS[3] = "Art0";
    SkillTable["Art0"].SubSkillName = Art[ROLL.Die(0,Art.size()-1)];
    //Bargain
    JOBSKILLS[4] = "Bargain";
    //any two Craft
    JOBSKILLS[5] = "Craft0";
    SkillTable["Craft0"].SubSkillName = Craft[ROLL.Die(0,Craft.size()-1)];
    JOBSKILLS[6] = "Craft1";
    SkillTable["Craft1"].SubSkillName = SkillTable["Craft0"].SubSkillName;
    while(SkillTable["Craft1"].SubSkillName == SkillTable["Craft0"].SubSkillName){
      SkillTable["Craft1"].SubSkillName = Craft[ROLL.Die(0,Craft.size()-1)];
    }
    //Spot
    JOBSKILLS[7] = "Spot";
    //Research
    JOBSKILLS[8] = "Research";
    //Status
    JOBSKILLS[9] = "Status";
    break;
    }
    
    case 7: //Criminal
    {
    break;
    }
    case 8: //Detective
    {
    break;
    }
    case 9: //Doctor
    {
    break;
    }
    case 10: //Engineer
    {
    break;
    } 
    case 11: //Entertainer
    {
    break;
    }
    case 12: //Explorer
    {
    break;
    }
    case 13: //Farmer
    {
    break;
    }
    case 14: //Gambler
    {
    break;
    }
    case 15: //Herder
    {
    break;
    }
    case 16: //Hunter
    {
    break;
    }
    case 17: //Journalist
    {
    break;
    }
    case 18: //Laborer
    {
    break;
    }
    case 19: //Lawkeeper
    {
    break;
    }
    case 20: //Lawyer
    {
    break;
    }
    default:
    {
      break;
    }
  }
}

//Repopulates HOBBYSKILLS after removal of duplicates
void BRP_human_base::RefillHobbySkills(std::vector<std::string> &V_main, int &MaxNumberOfSkills){
  int CurrentSize = V_main.size();
  for(int i = 0; i < MaxNumberOfSkills-CurrentSize; i++){
    V_main.push_back(SkillList[ROLL.Die(0, SkillList.size()-1)]);
  }
}

//counts number of duplicates for both skilsls with and without subskills in HOBBYSKILLS and fills in DUPITEMS vector
void BRP_human_base::CheckForDuplicatcates(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist){
  std::unordered_set<std::string> UniqueElements;
  for (int i = 0; i < V_main.size(); i++) {
    if(UniqueElements.find(V_main[i]) == UniqueElements.end()){
      UniqueElements.insert(V_main[i]);
    } else {
        TESTDUP++;
        if (IsSkillWithoutSubSkills(V_main[i])) {
          NONSUBNUM++;
            V_banlist.push_back(V_main[i]);
        } else {
          SKILLWITHSUBNUM++;
          SUBNUM += NumberOfSubSkills(V_main[i]);
        }
    }
  }
}

//takes HOBBYSKILLS and checks if there are too many skills w/ subskills
//refine vector down to what is extra and add it to ban list for removal?
void BRP_human_base::RemoveExtraSubSkills(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist){
  
  std::vector<std::string> ListOfSkills = V_main;
  UniqueCounts.clear();
  SubskillMax.clear();
  
  //remove non-subskill skills
  for(int i = 0; i < V_main.size(); i++){
    if(IsSkillWithoutSubSkills(V_main[i]) == true){
      ListOfSkills[i].erase();
    } else {continue;}
  }
  
  //count remaining number of skills with subskills
  //and count how many subskills is in a skill in UniqueCounts
  for (int a = 0; a < ListOfSkills.size(); a++) {
    if(ListOfSkills[a] == ""){
      continue;
    } else {
        if(UniqueCounts.find(ListOfSkills[a]) == UniqueCounts.end()){
          UniqueCounts.insert(std::pair<std::string,int>(ListOfSkills[a],1));
          SubskillMax.insert(std::pair<std::string,int>(ListOfSkills[a],NumberOfSubSkills(ListOfSkills[a])));
        } else {UniqueCounts[ListOfSkills[a]]++;}
      }
  }

  
  //check and compare maps then apply to DUPITEMS
  std::map<std::string,int>::iterator Iuc = UniqueCounts.begin();
  std::map<std::string,int>::iterator Ism = SubskillMax.begin();
  while(Iuc != UniqueCounts.end() && Ism != SubskillMax.end()){
    if(Iuc->second > Ism->second){
      TOOMANYSUBS = true;
      int difference = Iuc->second - Ism->second;
      for(int w = 0; w < difference; w++){
        V_banlist.push_back(Iuc->first);
      }
    }
    Iuc++;
    Ism++;
  }
  
  
}


//Takes in a string and returns true if it is a skill without a subskill
bool BRP_human_base::IsSkillWithoutSubSkills(std::string &SKILL){
  //vector of skills without any subskills
  std::vector<std::string> NonSubSkills = {"Appraise", "Bargain", "Brawl", "Climb", "Command", "Demolition", "Disguise", "Dodge", "Etiquette", "Fast Talk", "Fine Manipulation", "First Aid", "Fly", "Gaming", "Grapple", "Hide", "Insight", "Jump", "Listen", "Literacy", "Martial Arts", "Medicine", "Navigate", "Parry", "Persuade", "Projection", "Psychotherapy", "Research", "Sense", "Sleight of Hand", "Spot", "Status", "Stealth", "Strategy", "Swim", "Teach", "Throw", "Track"};
  bool OUTCOME;
  for(int i = 0; i < NonSubSkills.size(); i++){
    if(SKILL == NonSubSkills[i]){
        OUTCOME = true;
        break;}
    else{
        OUTCOME = false;
        continue;}
  }
  return OUTCOME;
}

//checks number of subskills for a given skill
int BRP_human_base::NumberOfSubSkills(std::string &SKILL){
  int AMOUNT = 0;
  for(int j = 0; j < 10; j++){
    //if find() doesn't reach end() of SkillTable, then it found a subskill and increses the count for AMOUNT.
    if(SkillTable.find(SKILL+std::to_string(j)) != SkillTable.end()){
      AMOUNT++;
    }else{break;}
  }
  return AMOUNT;
}

//Returns true if duplicates of non-subskill skills are present
bool BRP_human_base::IsThereADup(std::vector<std::string> LIST){
  bool OUTCOME = false;
  for(int i = 1; i < LIST.size(); i++){
    if(LIST[i-1] == LIST[i]){
      if(IsSkillWithoutSubSkills(LIST[i-1]) != true){
        OUTCOME = true;
        break;
      }else{continue;}
    }
  }
  return OUTCOME;
}

//removes duplicate elements from main vector using V_banlist vector
void BRP_human_base::RemoveDuplicates(std::vector<std::string> &V_main, std::vector<std::string> &V_banlist){
  int MAINSIZE = V_main.size();
  std::vector<std::string> BANLIST = V_banlist;
  while(BANLIST.empty() != true){
    for(int i = 0; i < MAINSIZE; i++){
      if(BANLIST.empty() != true){
        if(V_main[i] == BANLIST[0]){
          V_main.erase(V_main.begin()+i);
          BANLIST.erase(BANLIST.begin());} 
      }else{break;}
    }
  }
  V_banlist.clear();
  TESTDUP = 0;
  NONSUBNUM = 0;
  SUBNUM = 0;
  SKILLWITHSUBNUM = 0;
  TOOMANYSUBS = false;
}

//Assigns skills to HOBBYSKILLS array based on random chance
void BRP_human_base::PickHobbySkills(){
  TESTDUP = 0; //number of duplicates
  NONSUBNUM = 0; //number of duplicates without subskills
  SKILLWITHSUBNUM = 0; //number of duplicate skills with subskills
  SUBNUM = 0; //number of subskills in duplicate skills
  DUPITEMS = {}; //vector containing each duplicate skill to be removed
  TOOMANYSUBS = false; //true if the number of skills with subskills is greater then the total number of skills with subskills in the SkillTable
      
  //random numbre of hobby skills to have
  NumberOfHobbySkills = ROLL.Die(8, 10);
 
  //Populates HOBBYSKILLS and checks for duplicates
  RefillHobbySkills(HOBBYSKILLS, NumberOfHobbySkills);
  CheckForDuplicatcates(HOBBYSKILLS, DUPITEMS);
  RemoveExtraSubSkills(HOBBYSKILLS, DUPITEMS);
  
  //Removes duplicates and replaces them till HOBBYSKILL has no more nun-subskill duplicates
  while(NONSUBNUM > 0 || TOOMANYSUBS == true){
    RemoveDuplicates(HOBBYSKILLS, DUPITEMS);
    RefillHobbySkills(HOBBYSKILLS, NumberOfHobbySkills);
    CheckForDuplicatcates(HOBBYSKILLS, DUPITEMS);
    RemoveExtraSubSkills(HOBBYSKILLS, DUPITEMS);
  }
  
  //sort alphabetically
  std::sort(HOBBYSKILLS.begin(),HOBBYSKILLS.end());

 
}

//Randomly assigns skill points to the Character's personnal skills 
/*
void BRP_human_base::PersonalSkillSet()
{

  Make a random list of skills (How many? Has to be more then 0 but whats the min and max?)
  INT can be 8-18; Pts 80-180 for NORMAL limit: 75%
  INT can be 8-18; Pts 120-270 for HEROIC limit: 90%
  INT can be 8-18; Pts 160-360 for EPIC limit: 101%
  INT can be 8-18; Pts 200-450 for SUPERHUMAN limit: 999%
  maybe try 6 to 10 skills for all level?
  Maybe adjust total number of personl skills by power level
  Compare to Profession Skill List to check for duplications and check that skill's MAX
  Then run a For Loop to randomlly assign points from PerSkillPtsMAX
  
  
  //Number of Personal Skills, between 8 to 10
  int TotalPersonalSkillsKnown = rand() % 8 + 10;

  //array of string to hold the Personal Skills
  std::string PerSkillKnown[TotalPersonalSkillsKnown];

  for(int i = 0; i < TotalPersonalSkillsKnown; i++)
  {
    ;
  }

  \\This should be its own funciton
  \\
  int CurrentPoints = PerSkillPtsMAX;
  
  while (CurrentPoints > 0)
  {
    
  }
}*/

//Loop through all skills and add a skill's base value and a skill's category value to the skill's mod value
void BRP_human_base::FillSkillMod(){
  for (auto& X : SkillTable){
    X.second.SkillMod += X.second.SkillBase + X.second.SkillCat;
  }
}

//Assign Own Language
void BRP_human_base::OwnLanguage(){
  int OwnLang = ROLL.Die(0,Language.size()-1);
  SkillTable["Language0"].SubSkillName = Language.at(OwnLang);
}

//Personality
void BRP_human_base::PersonalityPick(int pick){
  Personality = "";
  
  switch (pick){//need to add skill points asigning for each case
  case 1:{
    Personality = "They have a brutal personality, thinking first of solving problems by means of physical force and brawn.";
    SkillTable["Brawl"].SkillMod += 20;
    SkillTable["Climb"].SkillMod += 20;
    SkillTable["Dodge"].SkillMod += 20;
    SkillTable["Grapple"].SkillMod += 20;
    SkillTable["Insight"].SkillMod += 20;
    SkillTable["Jump"].SkillMod += 20;
    SkillTable["Ride0"].SkillMod += 20;//need to pick one Ride
    SkillTable["Ride1"].SkillMod += 20;
    SkillTable["Sense"].SkillMod += 20;
    SkillTable["Stealth"].SkillMod += 20;
    SkillTable["Swim"].SkillMod += 20;
    SkillTable["Throw"].SkillMod += 20;
    //SkillTable["ARMS"].SkillMod += 20;
    //SkillTable["ARMS"].SkillMod += 20;
    break;}
    
  case 2:{
    Personality = "They have a skilled personality, beliving that technique, craft, and expertise are the secrets of success.";
    SkillTable["Disguise"].SkillMod += 20;
    SkillTable["Dodge"].SkillMod += 20;
    SkillTable["Fine Manipulation"].SkillMod += 20;
    SkillTable["First Aid"].SkillMod += 20;
    SkillTable["Navigate"].SkillMod += 20;
    SkillTable["Pilot0"].SkillMod += 20;//need to pick one Pilot
    SkillTable["Ride0"].SkillMod += 20;//need to pick one Ride
    SkillTable["Pilot1"].SkillMod += 20;
    SkillTable["Ride1"].SkillMod += 20;
    SkillTable["Slight of Hand"].SkillMod += 20;
    SkillTable["Stealth"].SkillMod += 20;
    //SkillTable["ARMS"].SkillMod += 20;
    //SkillTable["Knowledge"].SkillMod += 20;
    //SkillTable["Craft"].SkillMod += 20;
    break;}
    
  case 3:{
    Personality = "They have a cunning personality, trying first to outsmart an opponent to gain an advantage.";
    SkillTable["Appraise"].SkillMod += 20;
    SkillTable["Bargain"].SkillMod += 20;
    SkillTable["Disguise"].SkillMod += 20;
    SkillTable["Insight"].SkillMod += 20;
    SkillTable["Listen"].SkillMod += 20;
    SkillTable["Research"].SkillMod += 20;
    SkillTable["Sense"].SkillMod += 20;
    SkillTable["Spot"].SkillMod += 20;
    SkillTable["Stealth"].SkillMod += 20;
    //SkillTable["Technical"].SkillMod += 20; //setting approate
    //SkillTable["Knowledge"].SkillMod += 20;
    //SkillTable["Knowledge"].SkillMod += 20;
    //SkillTable["ARMS"].SkillMod += 20;
    break;}
    
  case 4:{
    Personality = "They have a charming personality, enjoying persuading other people to work, while they make the decisions.";
    SkillTable["Appraise"].SkillMod += 20;
    SkillTable["Bargain"].SkillMod += 20;
    SkillTable["Command"].SkillMod += 20;
    SkillTable["Etiquette"].SkillMod += 20;
    SkillTable["Fast Talk"].SkillMod += 20;
    SkillTable["Insight"].SkillMod += 20;
    SkillTable["Preform"].SkillMod += 20;
    SkillTable["Persuade"].SkillMod += 20;
    SkillTable["Language0"].SkillMod += 20;
    SkillTable["Sense"].SkillMod += 20;
    SkillTable["Status"].SkillMod += 20;
    //SkillTable["Language1"].SkillMod += 20;
    //SkillTable["ARMS"].SkillMod += 20;
    break;}  
  }
}

//Randomly assigns skill points to the Profession's Skills
//REDO THIS METHOD SO IT CAN TAKE JOBSKILLS AND HOBBYSKILL ALONG WITH THEIR SKILLPOINTSMAX
//MAY NEED TO REDO HOW JOBSKILLS WORKS
void BRP_human_base::ProfessionSkillSet(){
  //Sets up the Current Skill Points to be spent for the following loop.
  int CurrentSkillPoints = ProSkillPtsMAX;

  //Function ends when all CurrentSkillPoints are used up.
  while (CurrentSkillPoints > 0){
    /*This loops 10 times through the JOBSKILLS array because there are 10 skills for each Profession. 
    If there is a different number skills per profession it is recommended to adjust 10 in the for loop argument by that amount. 
    I could run a check for how long the JOBSKILLS is and make that a veriable so the max JOBSKILL array can be changed without issues*/
    for (int i = 0; i < 10; i++){
    
    //Gets the name of the skill to be increased.
    std::string ROLE = JOBSKILLS[i];
      
    //Skip any skill already at max rating.
    if (SkillTable[ROLE].SkillMod >= SkillRatingMAX){
      continue;
    }
    else {
      
      //Assigns 0 to 10 points.
      int LEARNED = ROLL.Die(0,10);
      
      //If the Current Skill Points are less then what was rolled, this reduces the LEARNED points to what is left in the CurrentSkillPoints.
      while (LEARNED > CurrentSkillPoints){
        LEARNED--;
      }
      
      //If LEARNED will bring the current skill above the max, just reduce the points down till it hits the max.
      while (SkillTable[ROLE].SkillMod + LEARNED > SkillRatingMAX){
        LEARNED--;
      }
      
      //Add and remove points to the skill and from the CurrentSkillPoints availible.
      SkillTable[ROLE].SkillMod += LEARNED; 
      CurrentSkillPoints -= LEARNED;
      
      //Ends the loop if all the current skill points are spent, the while loop should be false and end as well.
      if (CurrentSkillPoints == 0){
        break;
      }else{continue;}
      }
    }
  }
}

//Gets the character's name
void BRP_human_base::CharName(){
  std::cout << "\nWhat is the character's name?\n";
  std::getline(std::cin >> std::ws, CN); 
}

//Gets the user's name
void BRP_human_base::PlayerName(){
  std::cout << "\nWhat is your, the player's, name?\n";
  std::getline(std::cin >> std::ws, PN);
  std::cout << "\n";
}

//Generates a fully randomized character
void BRP_human_base::fullrandom(){
  EDUstat();
  ExpBonus(INT);
  SanityPoints(POW);
  FatiguePoints(STR, CON);
  HitPoints(CON, SIZ);
  HPbyLocation(HP);
  MajorWounds(HP);
  DamageBonus(STR, SIZ);
  Weapons();
  Born();
  RandGender(ROLL.Die(1,100));
  HandDom(ROLL.Die(1,100));
  Faith();
  DistinctiveFeatures(CHA);
  HeightandWeight(SIZ);
  ProSkillPointsPool();
  PerSkillPonitsPool();
  SkillRatingMaximum();
  SkillCategory();
  Skills(DEX, INT, POW);
  PersonalityPick(ROLL.Die(1,4));
  FillSkillMod();
  OwnLanguage();
  Professions();
  PickJobSkills();
  ProfessionSkillSet();
  PickHobbySkills();
  //PersonalSkillSet();

}

//Adjust length of spacing for charcter sheet if skill is over 99%
int BRP_human_base::Toolong(int mod){
  return (mod > 99 || mod < -9) ? 1:0;
}

//Free build a full character
void BRP_human_base::freebuild()
{
  ;
}

//Prints character sheet to console
void BRP_human_base::consoleChar(){
  std::cout << "===========================================================" << std::endl;
  std::cout << "\t\t\tPERSONAL" << std::endl;
  std::cout << "===========================================================" << std::endl;
  std::cout << "Culture: " << "Human" << std::setw(13) << std::setfill(' ') << "Gender: " << Gender << std::endl;
  std::cout << "Height: " << Height << std::setw(19-Height.length()) << std::setfill(' ') << "Weight: " << Weight << std::endl;
  std::cout << "Wealth: " << Wealth << std::setw(23-Wealth.length()) << std::setfill(' ') << "Profession: " << Profession << std::endl;
  std::cout << "Handedness: " << Handedness << std::endl;
  std::cout << "Religion: " << Religion << std::endl;
  std::cout << "Move (MOV): " << 10 << std::setw(10) << std::setfill(' ') << "Age: " << Age << std::endl;
  std::cout << "\n" << UnitedFeatures << std::endl;
  std::cout << "\n" << " " << Personality << std::endl;
  std::cout << "\n";
  std::cout  << "STR " << DD(STR) << std::setw(2) << std::setfill(' ') << "" << "Effort roll " << CharacteristicRoll(STR) << "%" << std::setw(9) << std::setfill(' ') << "" << "INT " << DD(INT) << std::setw(2) << std::setfill(' ') << "" << "Idea roll " << CharacteristicRoll(INT) << "%" << std::endl; 
  std::cout << "CON " << DD(CON) << std::setw(2) << std::setfill(' ') << "" << "Stamina roll " << CharacteristicRoll(CON) << "%" << std::setw(8) << std::setfill(' ') << "" << "CHA " << DD(CHA) << std::setw(2) << std::setfill(' ') << "" << "Charm roll " << CharacteristicRoll(CHA) << "%" << std::endl;
  std::cout << "DEX " << DD(DEX) << std::setw(2) << std::setfill(' ') << "" << "Agility roll " << CharacteristicRoll(DEX) << "%" << std::setw(8) << std::setfill(' ') << "" << "POW " << DD(POW) << std::setw(2) << std::setfill(' ') << "" << "Luck roll " << CharacteristicRoll(POW) << "%" << std::endl;  
  if (EDUCATION_STAT == true) 
  {std::cout << "EDU " << DD(EDU) << std::setw(2) << std::setfill(' ') << "" << "Knowledge roll " << CharacteristicRoll(EDU) << "%" << std::setw(10) << std::setfill(' ') << "SIZ " << DD(SIZ) << std::setw(2) << std::setfill(' ') << "" << "Damage Bonus of " << DamBonus << "\n" <<  std::endl;}
  else
  {std::cout << "SIZ " << DD(SIZ) << std::setw(2) << std::setfill(' ') << "" << "Damage Bonus of " << DamBonus << "\n" << std::endl;}
  
  std::cout << "===========================================================" << std::endl;
  std::cout << "\t\t\tHIT POINTS" << std::endl;
  std::cout << "===========================================================" << std::endl;
  std::cout << "HP: " << DD(HP) << " with Major Wound occuring at " << DD(MW) << " HP" << "\n" << std::endl;
  
  std::cout << "===========================================================" << std::endl;
  std::cout << "\t\t\tSKILLS" << std::endl;
  std::cout << "===========================================================" << std::endl;
  std::cout << "Professional Skill Points Pool: " << ProSkillPtsMAX << "\t\t" << "Personal Skill Points Pool: " << PerSkillPtsMAX << "\n" << std::endl;

  //START OF SKILLS
  //COMMUNICATION    MENTAL    PHYSICAL
  std::cout << "COMMUNICATION " << DD(Communication_skillcategory) << "%" << std::setw(25) << std::setfill(' ') << "" << "MENTAL " << DD(Mental_skillcategory) << "%" << std::setw(32) << std::setfill(' ') << "" << "PHYSICAL " << DD(Physical_skillcategory) << "%" << std::endl;

  //Bargain    Appraise    Climb
  std::cout << SkillTable["Bargain"].SkillName << " (" << DD(SkillTable["Bargain"].SkillBase) << ")" << std::setw(18-Toolong(SkillTable["Bargain"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Bargain"].SkillMod) << "% [ ]" << std::setw(13) << std::setfill(' ') << SkillTable["Appraise"].SkillName << " (" << DD(SkillTable["Appraise"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Appraise"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Appraise"].SkillMod) << "% [ ]" << std::setw(10) << std::setfill(' ') << SkillTable["Climb"].SkillName << " (" << DD(SkillTable["Climb"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Climb"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Climb"].SkillMod) << "% [ ]" <<  std::endl;

  //Command    First Aid    Drive(subskill0)
  std::cout << SkillTable["Command"].SkillName << " (" << DD(SkillTable["Command"].SkillBase) << ")" << std::setw(18-Toolong(SkillTable["Command"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Command"].SkillMod) << "% [ ]" << std::setw(14) << std::setfill(' ') << SkillTable["First Aid"].SkillName << " (" << DD(SkillTable["First Aid"].SkillBase) << ")" << std::setw(16-Toolong(SkillTable["First Aid"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["First Aid"].SkillMod) << "% [ ]" << std::setw(10) << std::setfill(' ') << SkillTable["Drive0"].SkillName << " (" << DD(SkillTable["Drive0"].SkillBase) << ")" << " " << SkillTable["Drive0"].SubSkillName << std::setw(19-SkillTable["Drive0"].SubSkillName.length()-Toolong(SkillTable["Drive0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Drive0"].SkillMod) << "% [ ]" << std::endl;

  //Disguise    Gaming    Drive(subskill1)
  std::cout << SkillTable["Disguise"].SkillName << " (" << DD(SkillTable["Disguise"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Disguise"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Disguise"].SkillMod) << "% [ ]" << std::setw(11) << std::setfill(' ') << SkillTable["Gaming"].SkillName << " (" << DD(SkillTable["Gaming"].SkillBase) << ")" << std::setw(19-Toolong(SkillTable["Gaming"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Gaming"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Drive1"].SubSkillName << std::setw(28-SkillTable["Drive1"].SubSkillName.length()-Toolong(SkillTable["Drive1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Drive1"].SkillMod) << "% [ ]" << std::endl;

  //Etiquette    Knowledge(name)    Drive(subskill2)
  std::cout << SkillTable["Etiquette"].SkillName << " (" << DD(SkillTable["Etiquette"].SkillBase) << ")" << std::setw(16-Toolong(SkillTable["Etiquette"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Etiquette"].SkillMod) << "% [ ]" << std::setw(14) << std::setfill(' ') << SkillTable["Knowledge0"].SkillName << " (" << DD(SkillTable["Knowledge0"].SkillBase) << ")" << std::setw(28) << std::setfill(' ') << "" << "  " << SkillTable["Drive2"].SubSkillName << std::setw(28-SkillTable["Drive2"].SubSkillName.length()-Toolong(SkillTable["Drive2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Drive2"].SkillMod) << "% [ ]" << std::endl;

  //Fast Talk    Knowledge(subskill0)    Fly
  std::cout << SkillTable["Fast Talk"].SkillName << " (" << DD(SkillTable["Fast Talk"].SkillBase) << ")" << std::setw(16-Toolong(SkillTable["Fast Talk"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Fast Talk"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Knowledge0"].SubSkillName << std::setw(28-SkillTable["Knowledge0"].SubSkillName.length()-Toolong(SkillTable["Knowledge0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Knowledge0"].SkillMod) << "% [ ]" << std::setw(8) << std::setfill(' ') << SkillTable["Fly"].SkillName << " (" << DD(SkillTable["Fly"].SkillBase) << ")" << std::setw(22-Toolong(SkillTable["Fly"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Fly"].SkillMod) << "% [ ]" << std::endl;

  //Lanugae(name)    Knowledge(subskill1)    Hide
  std::cout << SkillTable["Language0"].SkillName << " (" << SkillTable["Language0"].SkillBase << ")" << std::setw(29) << std::setfill(' ') << "" << "  " << SkillTable["Knowledge1"].SubSkillName << std::setw(28-SkillTable["Knowledge1"].SubSkillName.length()-Toolong(SkillTable["Knowledge1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Knowledge1"].SkillMod) << "% [ ]" << std::setw(9) << std::setfill(' ') << SkillTable["Hide"].SkillName << " (" << DD(SkillTable["Hide"].SkillBase) << ")" << std::setw(21-Toolong(SkillTable["Hide"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Hide"].SkillMod) << "% [ ]" << std::endl;

  //Language(subskill0)    Knowledge(subskill2)    Jump
  std::cout << "  " << SkillTable["Language0"].SubSkillName << std::setw(28-SkillTable["Language0"].SubSkillName.length()-Toolong(SkillTable["Language0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Language0"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Knowledge2"].SubSkillName << std::setw(28-SkillTable["Knowledge2"].SubSkillName.length()-Toolong(SkillTable["Knowledge2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Knowledge2"].SkillMod) << "% [ ]" << std::setw(9) << std::setfill(' ') << SkillTable["Jump"].SkillName << " (" << DD(SkillTable["Jump"].SkillBase) << ")" << std::setw(21-Toolong(SkillTable["Jump"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Jump"].SkillMod) << "% [ ]" << std::endl;

  //Language(subskill1)    Literacy    Pilot(subskill0)
  std::cout << "  " << SkillTable["Language1"].SubSkillName << std::setw(28-SkillTable["Language1"].SubSkillName.length()-Toolong(SkillTable["Language1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Language1"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Literacy"].SkillName << " (" << DD(SkillTable["Literacy"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Literacy"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Literacy"].SkillMod) << "% [ ]" << std::setw(10) << std::setfill(' ') << SkillTable["Pilot0"].SkillName << " (" << DD(SkillTable["Pilot0"].SkillBase) << ")" << " " << SkillTable["Pilot0"].SubSkillName << std::setw(19-SkillTable["Pilot0"].SubSkillName.length()-Toolong(SkillTable["Pilot0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Pilot0"].SkillMod) << "% [ ]" << std::endl;

  //Language(subskill2)    Medicine    Pilot(subskill1)
  std::cout << "  " << SkillTable["Language2"].SubSkillName << std::setw(28-SkillTable["Language2"].SubSkillName.length()-Toolong(SkillTable["Language2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Language2"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Medicine"].SkillName << " (" << DD(SkillTable["Medicine"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Medicine"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Medicine"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << "  " << SkillTable["Pilot1"].SubSkillName << std::setw(28-SkillTable["Pilot1"].SubSkillName.length()-Toolong(SkillTable["Pilot1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Pilot1"].SkillMod) << "% [ ]" << std::endl;

  //Language(subskill3)    Psychotherapy    Pilot(subskill2)
  std::cout << "  " << SkillTable["Language3"].SubSkillName << std::setw(28-SkillTable["Language3"].SubSkillName.length()-Toolong(SkillTable["Language3"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Language3"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Psychotherapy"].SkillName << " (" << DD(SkillTable["Psychotherapy"].SkillBase) << ")" << std::setw(12-Toolong(SkillTable["Psychotherapy"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Psychotherapy"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << "  " << SkillTable["Pilot2"].SubSkillName << std::setw(28-SkillTable["Pilot2"].SubSkillName.length()-Toolong(SkillTable["Pilot2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Pilot2"].SkillMod) << "% [ ]" << std::endl;

  //Preform - NEED TO ADD SUBSKILLS OUTPUT!    Science(subskill0)    Projection
  std::cout << SkillTable["Preform"].SkillName << " (" << DD(SkillTable["Preform"].SkillBase) << ")" << " " << std::setw(17-Toolong(SkillTable["Preform"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Preform"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Science0"].SkillName << " (" << DD(SkillTable["Science0"].SkillBase) << ")" << " " << SkillTable["Science0"].SubSkillName << std::setw(17-SkillTable["Science0"].SubSkillName.length()-Toolong(SkillTable["Science0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Science0"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Projection"].SkillName << " (" << DD(SkillTable["Projection"].SkillBase) << ")" << std::setw(15-Toolong(SkillTable["Projection"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Projection"].SkillMod) << "% [ ]" << std::endl;

  //Persuade    Science(subskill1)    Ride(subskill0)
  std::cout << SkillTable["Persuade"].SkillName << " (" << DD(SkillTable["Persuade"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Persuade"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Persuade"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Science1"].SubSkillName << std::setw(28-SkillTable["Science1"].SubSkillName.length()-Toolong(SkillTable["Science1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Science1"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Ride0"].SkillName << " (" << DD(SkillTable["Ride0"].SkillBase) << ")" << " " << SkillTable["Ride0"].SubSkillName << std::setw(20-SkillTable["Ride0"].SubSkillName.length()-Toolong(SkillTable["Ride0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Ride0"].SkillMod) << "% [ ]" << std::endl;

  //Status    Science(subskill2)    Ride(subskill1)
  std::cout << SkillTable["Status"].SkillName << " (" << DD(SkillTable["Status"].SkillBase) << ")" << std::setw(19-Toolong(SkillTable["Status"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Status"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Science2"].SubSkillName << std::setw(28-SkillTable["Science2"].SubSkillName.length()-Toolong(SkillTable["Science2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Science2"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << "  " << SkillTable["Ride1"].SubSkillName << std::setw(28-SkillTable["Ride1"].SubSkillName.length()-Toolong(SkillTable["Ride1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Ride1"].SkillMod) << "% [ ]" << std::endl;

  //Teach    Science(subskill3)    Stealth
  std::cout << SkillTable["Teach"].SkillName << " (" << DD(SkillTable["Teach"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Teach"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Teach"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Science3"].SubSkillName << std::setw(28-SkillTable["Science3"].SubSkillName.length()-Toolong(SkillTable["Science3"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Science3"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Stealth"].SkillName << " (" << DD(SkillTable["Stealth"].SkillBase) << ")" << std::setw(18-Toolong(SkillTable["Stealth"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Stealth"].SkillMod) << "% [ ]" << std::endl;

  //BLANK_SPACE    Strategy    Swim
  std::cout << std::setw(42) << std::setfill(' ') << "" << SkillTable["Strategy"].SkillName << " (" << DD(SkillTable["Strategy"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Strategy"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Strategy"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Swim"].SkillName << " (" << DD(SkillTable["Swim"].SkillBase) << ")" << std::setw(21-Toolong(SkillTable["Swim"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Swim"].SkillMod) << "% [ ]" << std::endl;

  //MANIPULATION    Technical Skill(subskill0)    Throw
  std::cout << "MANIPULATION " << DD(Manipulation_skillcategory) << "%" << std::setw(26) << std::setfill(' ') << "  " << SkillTable["Technical Skill0"].SkillName << " (" << DD(SkillTable["Technical Skill0"].SkillBase) << ")" << " " << SkillTable["Technical Skill0"].SubSkillName << std::setw(15-SkillTable["Technical Skill0"].SubSkillName.length()-Toolong(SkillTable["Technical Skill0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Technical Skill0"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Throw"].SkillName << " (" << DD(SkillTable["Throw"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Throw"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Throw"].SkillMod) << "% [ ]" << std::endl;

  //Art(subskill0)    Technical Skill(subskill1)    BLANK_SPACE
  std::cout << SkillTable["Art0"].SkillName << " (" << DD(SkillTable["Art0"].SkillBase) << ")" << " " << SkillTable["Art0"].SubSkillName << std::setw(21-SkillTable["Art0"].SubSkillName.length()-Toolong(SkillTable["Art0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Art0"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Technical Skill1"].SubSkillName << std::setw(28-SkillTable["Technical Skill1"].SubSkillName.length()-Toolong(SkillTable["Technical Skill1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Technical Skill1"].SkillMod) << "% [ ]" << std::endl;

  //Art(subskill1)    Technical Skill(subskill2)    COMBAT
  std::cout << "  " << SkillTable["Art1"].SubSkillName << std::setw(28-SkillTable["Art1"].SubSkillName.length()-Toolong(SkillTable["Art1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Art1"].SkillMod) << "% [ ]" << std::setw(7) << std::setfill(' ') << "  " << SkillTable["Technical Skill2"].SubSkillName << std::setw(28-SkillTable["Technical Skill2"].SubSkillName.length()-Toolong(SkillTable["Technical Skill2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Technical Skill2"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << "COMBAT " << DD(Combat_skillcategory) << "%" << std::endl;

  //Craft(subskill0)    BLANK_SPACE    Dodge
  std::cout << SkillTable["Craft0"].SkillName << " (" << DD(SkillTable["Craft0"].SkillBase) << ")" << " " << SkillTable["Craft0"].SubSkillName << std::setw(19-SkillTable["Craft0"].SubSkillName.length()-Toolong(SkillTable["Craft0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Craft0"].SkillMod) << "% [ ]" << std::setw(52) << std::setfill(' ') << SkillTable["Dodge"].SkillName << " (" << DD(SkillTable["Dodge"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Dodge"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Dodge"].SkillMod) << "% [ ]" << std::endl;

  //Craft(subskill1)    PERCEPTION    Martial Arts
  std::cout << "  " << SkillTable["Craft1"].SubSkillName << std::setw(28-SkillTable["Craft1"].SubSkillName.length()-Toolong(SkillTable["Craft1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Craft1"].SkillMod) << "% [ ]" << std::setw(16) << std::setfill(' ') << "PERCEPTION " << DD(Perception_skillcategory) << "%" << std::setw(40) << std::setfill(' ') << SkillTable["Martial Arts"].SkillName << " (" << DD(SkillTable["Martial Arts"].SkillBase) << ")" << std::setw(13-Toolong(SkillTable["Martial Arts"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Martial Arts"].SkillMod) << "% [ ]" << std::endl;

  //Demolition    Insight    TEXT
  std::cout << SkillTable["Demolition"].SkillName << " (" << DD(SkillTable["Demolition"].SkillBase) << ")" << std::setw(15-Toolong(SkillTable["Demolition"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Demolition"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Insight"].SkillName << " (" << DD(SkillTable["Insight"].SkillBase) << ")" << std::setw(18-Toolong(SkillTable["Insight"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Insight"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << "See Weapons below for more Combat skills" << std::endl;

  //Fine Manipulation    Listen    BLANK_SPACE
  std::cout << SkillTable["Fine Manipulation"].SkillName << " (" << DD(SkillTable["Fine Manipulation"].SkillBase) << ")" << std::setw(8-Toolong(SkillTable["Fine Manipulation"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Fine Manipulation"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Listen"].SkillName << " (" << DD(SkillTable["Listen"].SkillBase) << ")" << std::setw(19-Toolong(SkillTable["Listen"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Listen"].SkillMod) << "% [ ]" << std::endl;

  //Heavy Machine(name)    Navigate    Combat Skill(ARMS0)
  std::cout << SkillTable["Heavy Machine0"].SkillName << " (" << DD(SkillTable["Heavy Machine0"].SkillBase) << ")" << std::setw(24) << std::setfill(' ') << "" << SkillTable["Navigate"].SkillName << " (" << DD(SkillTable["Navigate"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Navigate"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Navigate"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["ARMS0"].SkillName << " (" << DD(SkillTable["ARMS0"].SkillBase) << ")" << " " << SkillTable["ARMS0"].SubSkillName << std::setw(24-SkillTable["ARMS0"].SkillName.length()-SkillTable["ARMS0"].SubSkillName.length()-Toolong(SkillTable["ARMS0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["ARMS0"].SkillMod) << "% [ ]" << std::endl;

  //Heavy Machine(subskill0)    Research    Combat Skill(ARMS1)
  std::cout << "  " << SkillTable["Heavy Machine0"].SubSkillName << std::setw(28-SkillTable["Heavy Machine0"].SubSkillName.length()-Toolong(SkillTable["Heavy Machine0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Heavy Machine0"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Research"].SkillName << " (" << DD(SkillTable["Research"].SkillBase) << ")" << std::setw(17-Toolong(SkillTable["Research"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Research"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["ARMS1"].SkillName << " (" << DD(SkillTable["ARMS1"].SkillBase) << ")" << " " << SkillTable["ARMS1"].SubSkillName << std::setw(24-SkillTable["ARMS1"].SkillName.length()-SkillTable["ARMS1"].SubSkillName.length()-Toolong(SkillTable["ARMS1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["ARMS1"].SkillMod) << "% [ ]" << std::endl;

  //Repair(subskill0)    Sense    Combat Skill(ARMS2)
  std::cout << SkillTable["Repair0"].SkillName << " (" << DD(SkillTable["Repair0"].SkillBase) << ")" << " " << SkillTable["Repair0"].SubSkillName << std::setw(18-SkillTable["Repair0"].SubSkillName.length()-Toolong(SkillTable["Repair0"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Repair0"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Sense"].SkillName << " (" << DD(SkillTable["Sense"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Sense"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Sense"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["ARMS2"].SkillName << " (" << DD(SkillTable["ARMS2"].SkillBase) << ")" << " " << SkillTable["ARMS2"].SubSkillName << std::setw(24-SkillTable["ARMS2"].SkillName.length()-SkillTable["ARMS2"].SubSkillName.length()-Toolong(SkillTable["ARMS2"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["ARMS2"].SkillMod) << "% [ ]" << std::endl;

  //Repair(subskill1)    Spot    Combat Skill(ARMS3)
  std::cout << "  " << SkillTable["Repair1"].SubSkillName << std::setw(28-SkillTable["Repair1"].SubSkillName.length()-Toolong(SkillTable["Repair1"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Repair1"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Spot"].SkillName << " (" << DD(SkillTable["Spot"].SkillBase) << ")" << std::setw(21-Toolong(SkillTable["Spot"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Spot"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["ARMS3"].SkillName << " (" << DD(SkillTable["ARMS3"].SkillBase) << ")" << " " << SkillTable["ARMS3"].SubSkillName << std::setw(24-SkillTable["ARMS3"].SkillName.length()-SkillTable["ARMS3"].SubSkillName.length()-Toolong(SkillTable["ARMS3"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["ARMS3"].SkillMod) << "% [ ]" << std::endl;

  //Slight of Hand    Track    EXPERENCE BONUS
  std::cout << SkillTable["Slight of Hand"].SkillName << " (" << DD(SkillTable["Slight of Hand"].SkillBase) << ")" << std::setw(11-Toolong(SkillTable["Slight of Hand"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Slight of Hand"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << "" << SkillTable["Track"].SkillName << " (" << DD(SkillTable["Track"].SkillBase) << ")" << std::setw(20-Toolong(SkillTable["Track"].SkillMod)) << std::setfill('.') << "" << DD(SkillTable["Track"].SkillMod) << "% [ ]" << std::setw(5) << std::setfill(' ') << ""; if(EXPERIENCE_BONUS == true){std::cout << "EXPERENCE BONUS " << DD(ExperenceBonus) << "%"<< std::endl;} else{std::cout << "" << std::endl;}
  //END OF SKILLS

  //TESTING
  std::cout << "\n" << "Total number of Hobby Skills: " << NumberOfHobbySkills << std::endl;
  for(int i = 0; i < HOBBYSKILLS.size(); i++){
    std::cout << HOBBYSKILLS[i];
    if(i == HOBBYSKILLS.size()-1){
      std::cout << ".\n";}
    else{std::cout << ", ";}
  }
  
  std::cout << "\nNumber of duplications: " << TESTDUP << std::endl;
  
  std::cout << "\nNumber of duplicates that don't have SubSkills: " << NONSUBNUM << std::endl;

  for(int i = 0; i < DUPITEMS.size(); i++){
    std::cout << DUPITEMS[i];
    if(i == DUPITEMS.size()-1){
      std::cout << ".\n";}
    else{std::cout << ", ";}
  }

  std::cout << "\nNumber of duplicate skills that have subskills: " << SKILLWITHSUBNUM << std::endl;
  
  std::cout << "\nNumber of subskills the duplicate skill(s) have: " << SUBNUM << std::endl;

  std::cout << "\nMap of skills with subskills\n ";
  for(auto itr = UniqueCounts.begin(); itr != UniqueCounts.end(); itr++){
    std::cout << '\t' << itr->first << "\t\t\t\t" << itr->second << '\n';
  }
  
  std::cout << "\nMap of skills with subskills max\n ";
  for(auto itr = SubskillMax.begin(); itr != SubskillMax.end(); itr++){
    std::cout << '\t' << itr->first << "\t\t\t\t" << itr->second << '\n';
  }
  
  
  std::cout << "\n\nSeed: " << RANDOMCORE.currentSeed;
}

//Prints a txt file character sheet
void BRP_human_base::printChar(){
  std::string BRPFilePath = "Characters/BRP/";
  
  std::string BRPCharFileName = BRPFilePath + CN + "_by_" + PN + ".txt";

  std::ofstream outputFile(BRPCharFileName);
  std::streambuf* original = std::cout.rdbuf();
  std::cout.rdbuf(outputFile.rdbuf());

  consoleChar();

  std::cout.rdbuf(original);
}