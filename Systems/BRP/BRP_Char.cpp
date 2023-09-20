#include "../../menus.h"
#include "../../diceroller.h"
#include "BRP.h"




//GOAL FOR SCRIPT
//everything needed to make a standard Basic Role-Playing Character (5th ed, Universal Game Engine)
//Needs to have attrabutes, diraived stats, list of relivent features, equipment(just a basic set for now)
//class BRP char with roll inputs


//Classes
Dice PLAY;


//Create folder for character sheets
void FolderOriginBRP()
{
  std::string foldername = "Characters/BRP";
  int result = mkdir(foldername.c_str(), 0777); //0777 is premissions for the folder, 7 is full permission and the three number posistions at the end are for different kinds of users? 
  if (result == 0) 
  {
    std::cout << "BRP Installed\n";
  }
  else {  }
}

//Special Dice Rolls for this system
//Rolls a 3D6, 3 six-sided dice added together
int ThreeDSix() 
{
  int x = 0;
  for(int i = 0; i < 3; i++)
  {
    x += PLAY.Dsix();
  }
  return x;
}

//Rolls a 2D6+6, 2 six-sided dice added together plus 6
int TwoDSixPlusSix() 
{ 
  int x = 0;
  for(int i = 0; i < 2; i++)
  {
    x += PLAY.Dsix();
  }
  return x+6;
}


//BRP_human_base class
//Constructor to hold Characteristics, 
BRP_human_base::BRP_human_base(int a, int b, int c, int d, int e, int x, int y) 
{
  STR = a;
  CON = b;
  POW = c;
  DEX = d;
  CHA = e;
  INT = x;
  SIZ = y;
}

//Optional settings 
void BRP_human_base::SettingsSwitches()
{
  EDUCATION_STAT = true;
  SKILL_CATEGORY = true;
  SKILL_CATEGORY_SIMPLE = false;
  INCREASED_PERSONAL_SKILL_POINTS = false;
  WINGED_CHARACTER = false;
  SANITY = false;
  EXPERIENCE_BONUS = true;
  FATIGUE_POINTS = false;
  HIT_POINTS_PER_LOCATION = false;
  TOTAL_HIT_POINTS = false;
  DISTINCTIVE_FEATURES = true;
  DISTINCTIVE_FEATURES_BASIC = false;
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
  POWER_LEVEL = 0;
}

//Weapons Table
void BRP_human_base::Weapons()
{
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
int BRP_human_base::EDUstat()
{
  if (EDUCATION_STAT == true)
    {
      EDU = 0;
      EDU = TwoDSixPlusSix();
      return EDU;
    }
  else 
    {
      return 0;
    }
}

//Experience Bonus
void BRP_human_base::ExpBonus(int E)
{
  ExperenceBonus = ceil(E/2);
}

//Returns a STAT times 5, for a percentage roll
//This is at standard difficulty
int BRP_human_base::CharacteristicRoll(int r)
{
  int CharRoll = r * 5;
  return CharRoll;
}

//Generates starting age
//Will need to expand to allow input from user and modifiers for higher and lower ages
int BRP_human_base::Born()
{
  int startage = 17+PLAY.Dsix();
  Age = startage;
  return Age;
}

//Calculates Damage Bonus
std::string BRP_human_base::DamageBonus()
{
  int Db = STR + SIZ;
    
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
int BRP_human_base::HitPoints()
{
  if(TOTAL_HIT_POINTS == true)
  {
    HP = CON+SIZ;
    return HP;
  }
  else
  {
    HP = ceil((CON + SIZ)/2); 
    return HP;
  }
}

//Calculates Major Wounds
int BRP_human_base::MajorWounds()
{
  MW = ceil(HP/2);
  return MW;
}

//Calculates Hit Points by Location
void BRP_human_base::HPbyLocation(int B)
{
  if(HIT_POINTS_PER_LOCATION == true)
  {
    LAH_HP = ceil(B/3); //LAH is Legs, Abdomen, and Head
    Arms_HP = ceil(B/4);
    Chest_HP = ceil(B*0.40); //Chest HP is 4/10 total HP, rounded up
  }
}

//Calcualtes Fatigue Points
int BRP_human_base::FatiguePoints(int A, int B)
{
  if (FATIGUE_POINTS == true)
  {
    FatiguePointsMax = A + B;
    return FatiguePointsMax;
  }
  else
  {
    return 0;
  }
}

//Calculates Sanity Points
void BRP_human_base::SanityPoints(int G)
{
  if(SANITY == true)
  {
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
std::string BRP_human_base::DistinctiveFeatures()
{
  int DFs;
  std::string W;

  if (CHA <= 3 || CHA >= 17) {DFs = 4;}
  else if (CHA >= 4 && CHA <= 7) {DFs = 3;}
  else if (CHA >= 8 && CHA <= 9) {DFs = 2;}
  else if (CHA >= 10 && CHA <= 11) {DFs = 1;}
  else if (CHA >= 12 && CHA <= 14) {DFs = 2;}
  else if (CHA >= 15 && CHA <= 16) {DFs = 3;}
  else {DFs = 0;} 

  //Basic Feature List
  if (DISTINCTIVE_FEATURES == true && DISTINCTIVE_FEATURES_BASIC == true)
  {
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
    for (int i = 0; i < DFs; i++) 
    {
      //"they have " + rand_feature + ". " + next feature...
      int Type = PLAY.Dten();  
  
      std::string Sentence = " They have distinctive " + FeatureTypeTable[Type] + ".";
      UnitedFeatures += Sentence;
    }
  }
  
  //2D array of detailed features
  if (DISTINCTIVE_FEATURES == true && DISTINCTIVE_FEATURES_BASIC == false)
  {
    //More columns can be added for each row, but the 45 max will need to be increasded if total number of columns in a row go beyond it. Random selection counts selected row so no other code needs to be edited. Name and number at the end of each array is the row's type and current number of columns I put in at the time 
    std::string FeatureArray[10][45] = 
    {
      {"a completely bald head", "a bald spot on top of their head", "blond hair", "black hair", "braided hair", "brown hair", "a crew-cut", "curly hair", "dirty hair", "a head full of lice", "glossy hair", "gray hair", "long hair", "lustrous hair", "matted hair", "oily hair", "perfumed their hair", "receding hair", "red hair", "a shaven head", "spiky hair", "very long hair", "wavy hair", "a wig on their head"}, //Hair on head 24
      {"arched eyebrows", "a braided beard", "a bushy beard", "a curled and perfumed beard", "an enormous mustachios", "eyebrows that had grown together", "a goatee", "a long beard", "no eyebrows", "sideburns", "strange designs cut in close-trimmed beard", "thick eyebrows"}, //Facial hair 12
      {"a visable birthmark on their face", "black eyes", "blue eyes", "bright eyes", "a broken nose", "broken teeth", "brown eyes", "a deeply tanned face", "a double chin", "earrings on",  "an enormous chin", "even teeth", "an eye patch", "fleshy lips", "a gap in their teeth", "gray eyes", "hairy ears", "high cheekbones", "a hooked nose", "large eyes", "a large nose", "long eyelashes", "jagged teeth", "a nose ring on", "a pale face", "pockmarked skin", "a pointed chin", "pointed teeth", "prominent incisors", "a pug nose", "a round face", "a visable scar on their face", "sensuous lips", "stained teeth", "a tattooed face", "thin lips", "tiny ears", "a turned-up nose", "warts on their face", "a weak chin", "white teeth", "a wide-eyed look", "yellow teeth"}, //Facial feature 43
      {"an adoring expression", "an alluring expression", "an arrogant expression", "a bemused expression", "a bright-eyed expression", "a curious expression", "a cringing expression", "a dour expression", "a drunken expression", "a friendly expression", "a guarded expression", "a haughty expression", "a lecherous expression", "a leering expression", "a meek expression", "a mischievous expression", "a naïve expression", "an outgoing expression", "a piercing expression", "a pleasant expression", "a proud expression", "a seductive expression", "a sneaky expression", "a sneering expression", "a squinting expression"}, //Expression 23
      {"an ancient style of clothing on", "an armored hat on", "athletic clothing", "no footware and are barefoot", "clothes that leave the wearer too hot or too cold on", "a conical hat on", "clothing that is embroidered with a special emblem", "expensive clothing on", "fashionable clothing on", "fine boots", "wearing clothing for the wrong sex", "formfitting clothes", "clothing that are full of holes", "garish clothes", "gaudy clothes", "ill-fitting clothes", "lots of cheap jewelry", "new clothes", "nightclothes", "little on and are partly nude", "a peaked hat on", "prim clothes on", "rich clothing", "sandals", "satiny clothing", "sexy clothing", "skintight clothes", "sporty clothing", "subdued clothing", "too much ornamentation", "a uniform on", "that is overall utilitarian", "a vulgar style of clothing", "a wide hat on"}, //Clothes 34
      {"an angry bearing", "a casual bearing", "a clumsy bearing", "a confident bearing", "an ethereal bearing", "a fearful bearing", "a graceful bearing", "a humble bearing", "a jaunty bearing", "a languid bearing", "a military bearing", "a nimble bearing", "a plodding bearing", "a pushy bearing", "a reserved bearing", "a slouching bearing", "a sprightly bearing", "a stiff bearing", "a swaggering bearing", "a sensual bearing", "a swaying bearing", "a wary bearing", "a weary bearing", "a yielding bearing"}, //Bearing 24
      {"an accented way of speech", "an affected way of speech", "an aggressive way of speech", "a deep voice", "a demanding way of speech", "a drawling way of speech", "a faint voice", "a hesitant way of speech", "a high-pitched voice", "an imperious way of speech", "a musical voice", "a mumbling way of sppech", "a nasal speech", "a raspy voice", "a sharp way of speech", "a sensual voice", "a shrill voice", "a slow way of speech", "a smooth voice", "a soft-spoken way of speech", "a strong voice", "a throaty way of speech", "an unintelligible way of speech", "a whining voice"}, //Speech 24
      {"a birthmark visible on their arm", "bracelets and other arm jewelry", "bulging biceps", "calloused hands", "deeply tanned arms", "hairless arms", "hairy arms", "knobby elbows", "large knuckles", "a birthmark visible on their hand", "long arms", "long fingernails", "muscular arms", "one arm longer than the other", "one finger missing", "one too many fingers present", "pointed elbows", "pointed fingernails", "powerful arms and hands", "rings on their fingers", "a scar on their hand", "a scar on their arm", "slender amrs", "smooth-skinned hands", "tattooed arms", "tattooed hands", "very hairy arms", "very pale skin on their hands", "very pale skin on their arms"}, //Arms and Hands 29
      {"a barrel-like like torso", "a belly ring on", "a birthmark visible on their torso", "broad-shoulders", "a curvy figure", "every bone is showing on their body", "a flat stomach", "hairless chect", "a high waist", "a lean figure", "a long torso", "many scars aross their chest", "many scars aross their back", "many scars aross their abdomen", "a muscular figure", "a narrow figure", "no navel", "one nipple missing", "a potbelly", "a prominent scar across their chest", "a prominent scar across their back", "a prominent scar across their abdomen" "a short torso", "a shrunken chest", "a sinewy figure", "a sleek figure", "a slender figure", "a slim-hippedform", "a svelte figure", "a tall figure", "tan lines visible across their chest", "tan lines visible across their back", "tan lines visible across their abdomen", "a tanned torso", "a tattooed chest", "a tattooed back", "a tattooed abdomen" "a thick torso", "a thin torso", "a very hairy back", "a very hairy chest", "a very hairy abdomen", "a very pale torso", "a willowy figure"}, //Torso 44
      {"a birthmark visible on their foot", "a birthmark visible on their leg", "bulging thighs and calves", "calloused feet", "deeply tanned legs", "deeply tanned feet", "hairless legs", "hairless feet", "hairy legs", "hairy feet", "knobby knees", "a limp in one leg", "many scars aross their legs", "many scars aross their feet", "muscular legs", "one toe missing", "one too many toes present", "a scar on their foot", "a scar on their leg", "burn scars from fire on their leg", "burn scars from fire on their foot", "burn scars from acid on their foot", "burn scars from acid on their leg", "sleek looking legs", "smooth legs", "tanned legs", "tattooed legs", "a toe ring on", "very hairy legs", "very hairy feet", "very long legs", "very pale skin on their legs", "very pale skin on their feet", "very short legs", "weathered skin on their legs", "weathered skin on their feet"} //Legs and Feet 36
  };                          

    //For loop to get the the full detailed feature discription
    for (int i = 0; i < DFs; i++) 
      {
        //"they have " + rand_feature + ". " + next feature...
        int Type = rand() % 10;  
        int Count = 0;
        
        //counts how many choices their are in a selected array
        while (FeatureArray[Type][Count] != "") 
        {
          Count++;
        }
        
        //Picks a random choice from the counted array that was selected and adds it to UnitedFeatures
        if (Count > 0) 
        {
          int Feature = rand() % Count;
          std::string Sentence = " They have " + FeatureArray[Type][Feature] + ".";
          UnitedFeatures += Sentence;
        }
      }
  }

  //default if DISTINCTIVE_FEATURES is false, returns a blank space on the sheet
  else
  {
    UnitedFeatures = "";
  }
  
  return UnitedFeatures;
}

//Profession skill points
int BRP_human_base::ProSkillPointsPool()
{
  ProSkillPtsMAX = 0;
  
  if (POWER_LEVEL == 1) //Heroic game
  {
    if (EDUCATION_STAT == true) 
      {
        ProSkillPtsMAX = EDU*25;
      }
    else
      {
        ProSkillPtsMAX = 325;
      }
  }
  else if (POWER_LEVEL == 2) //Epic game
  {
    if (EDUCATION_STAT == true) 
      {
        ProSkillPtsMAX = EDU*30;
      }
    else
      {
        ProSkillPtsMAX = 400; 
      }
  }
  else if (POWER_LEVEL == 3) //Superhuman game
  {
    if (EDUCATION_STAT == true) 
      {
        ProSkillPtsMAX = EDU*40;
      }
    else
      {
        ProSkillPtsMAX = 500;
      }
  }
  else //default for Nomral game
  {
    if (EDUCATION_STAT == true) 
      {
        ProSkillPtsMAX = EDU*20;
      }
    else
      {
        ProSkillPtsMAX = 250;
      }
  }
  return ProSkillPtsMAX;
}

//Set Skill Rating Maximum
int BRP_human_base::SkillRatingMaximum()
{
  SkillRatingMAX = 0;

  if (POWER_LEVEL == 1) //Heroic game
    {
      SkillRatingMAX = 90;
    }
  else if (POWER_LEVEL == 2) //Epic game
    {
      SkillRatingMAX = 101;
    }
  else if (POWER_LEVEL == 3) //Superhuman game
    {
      SkillRatingMAX = 999; //No limit to skill ratings
    }
  else //default for Nomral game
    {
      SkillRatingMAX = 75;
    }
  
  return SkillRatingMAX;
}

//Personal skill points
int BRP_human_base::PerSkillPonitsPool()
{
  PerSkillPtsMAX = 0;
  if (INCREASED_PERSONAL_SKILL_POINTS == true)
    {
      if (POWER_LEVEL == 1) //Heroic game
        {
          PerSkillPtsMAX = INT*15;
        }
      else if (POWER_LEVEL == 2) //Epic game
        {
          PerSkillPtsMAX = INT*20;
        }
      else if (POWER_LEVEL == 3) //Superhuman game
        {
          PerSkillPtsMAX = INT*25;
        }
    }
  else
    {
      PerSkillPtsMAX = INT*10; //Default Normal game
    }
  return PerSkillPtsMAX;
}

//Determines character's profession
void BRP_human_base::Professions()
{
  std::string jobs[] = {"Artist", "Assassin", "Athlete", "Beggar", "Clerk", "Computer Tech", "Crafter", "Criminal", "Detective", "Doctor", "Engineer", "Entertainer", "Explorer", "Farmer", "Gambler", "Herder", "Hunter", "Journalist", "Laborer", "Lawkeeper", "Lawyer", "Mechanic", "Merchant", "Noble", "Occultist", "Pilot", "Politician", "Priest", "Sailor", "Scholar", "Scientist", "Servant", "Shaman", "Slave", "Soldier", "Spy", "Student", "Teacher", "Technician", "Thief", "Tribesperson", "Warrior", "Wizard", "Writer"};

  // Hired = rand() % 44; OFF FOR TESTING, alos need to replace the 44 with dynamic count of the jobs array
  Hired = 0;

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
  int Income = rand() % 100;

  //Makes a reference to WealthCategory set to the current Profession
  WealthCategorys& WC = WealthTable[Profession];

  //This fails if it gets to the end of the Wealth Level options without beign able to pick one
  //I don't get it and need to study and come up with one I know and can work with
  for (auto& range : WC.range)
  {
      if (range.WealthWeight >= Income)
      {
        Wealth = range.WealthLevel;
        break;
      }
      Income -= range.WealthWeight;
  }
}

//Determines character's gender 
std::string BRP_human_base::RandGender()
{
  int X = PLAY.Donehundred();

  //50% Female, 49% Male, 1% Non-Binary
  if (X == 100) {Gender = "Non-Binary";}
  else if (X >= 51) {Gender = "Male";}
  else {Gender = "Female";}
  
  return Gender;
}

//Determins character's religion/who they worship
void BRP_human_base::Faith()
{
  std::string Beliefs[] = {"Atheist", "Agnostic", "Ignostic", "Nonreligious", "Secular", "Baha'is", "Buddhist", "Christian", "Confucian", "Hindu", "Muslim", "Jainist", "Jewish", "Shintoists", "Satanist", "Sikh", "Taoist", "Zoroastrian", "Jain", "Polytheistic", "Worshipper of Zeus", "Worshipper of Hera", "Worshipper of Atremis", "Worshipper of Hades", "Worshipper of Posidon", "Worshipper of Cthulhu", "Worshipper of Ra", "Worshipper of Set", "Druid", "Animist", "Worshipper of Bast", "Worshipper of Horus", "Worshipper of Isis", "Worshipper of Khepri", "Worshipper of Anubis", "Worshipper of Odin", "Worshipper of Thor", "Worshipper of Loki", "Worshipper of Yudi", "Worshipper of Lóngshén", "Worshipper of Doumu"};

  int Convert = rand() % sizeof(Beliefs)/sizeof(std::string);
  Religion = Beliefs[Convert];
}

//Determines character's hand dominance 
std::string BRP_human_base::HandDom()
{
  int Odds = PLAY.Donehundred();

  //83% Right-Handed, 13% Left-Handed, 3% Ambidextrous, 1% Cross-Dominant; based on UN data
  if (Odds == 100) {Handedness = "Cross-Dominant";}
  else if (Odds >= 97) {Handedness = "Ambidextrous";}
  else if (Odds >= 1 && Odds <= 13) {Handedness = "Left-Handed";}
  else {Handedness = "Right-Handed";}
  
  return Handedness;
}

//Determines character's Height and Weight 
void BRP_human_base::HeightandWeight()
{
  //2D-array of height and weight outcomes
  std::string HTandWT[2][5] = 
{
  {"Tiny","Short","Average","Tall","Towering"},
  {"Frail","Thin","Average","Overweight","Obese"}
};

  //poor if statement just to use the array. should adjust results based on CON and maybe random chance
  //this is a pretty subjective thing. Maybe just pure random picks within SIZ based boundries
    //Average outcome
  if (SIZ >= 10 && SIZ <= 13) 
    {Height = HTandWT[0][2], Weight = HTandWT[1][2];}
    //Low end outcome, Tiny/Frail
  else if (SIZ < 10) 
    {Height = HTandWT[0][1], Weight = HTandWT[1][1];}
    //High end outcome, Tall/Overweight
  else if (SIZ >= 14 && SIZ <= 17) 
    {Height = HTandWT[0][3], Weight = HTandWT[1][3];}
    //Default outcome, Towering/Obese
  else 
    {Height = HTandWT[0][4], Weight = HTandWT[1][4];}
}

//Primary Skill Category
int BRP_human_base::Skill_Category_Primary(int x)
{
  //argument x = one STAT, +1 for every point over 10, -1 for every point under 10, 0 at 10
  int P = 0;
  if (x >= 10)
   {
     int z = x-10;
     for (int i = 0; i < z; i++)
     {
       P++;
     }
   }
  else 
  {
    int z = 10-x;
     for (int i = 0; i < z; i++)
     {
       P--;
     }
  }
  return P;
}

//Secondary Skill Category
int BRP_human_base::Skill_Category_Secondary(int x)
{
  //argument x = one STAT, +1 for every 2 points over 10, -1 for every 2 points under 10, 0 at 10
  int P = 0;
  if (x >= 10)
   {
     x = x - 10;
     int z = std::floor(x / 2);
     for (int i = 0; i < z; i++)
     {
       P++;
     }
   }
  else 
  {
    int z = std::floor((10-x) / 2);
     for (int i = 0; i < z; i++)
     {
       P--;
     }
  }
  return P;
}

//Negative Skill Category
int BRP_human_base::Skill_Category_Negative(int x)
{
  //argument x = one STAT (SIZ is the only one), -1 for every point over 10, +1 for every point under 10, 0 at 10
  int P = 0;
  if (x >= 10)
   {
     int z = x-10;
     for (int i = 0; i < z; i++)
     {
       P--;
     }
   }
  else 
  {
    int z = 10-x;
     for (int i = 0; i < z; i++)
     {
       P++;
     }
  }
  return P;
}

//Handles the optional Skill Category system, both standard & simple
void BRP_human_base::SkillCategory()
{

  //Skill Category variables
  Combat_skillcategory = 0;    
  Communication_skillcategory = 0;
  Manipulation_skillcategory = 0;
  Mental_skillcategory = 0;
  Perception_skillcategory = 0;
  Physical_skillcategory = 0;

  //Standard Skill Category rules
  if (SKILL_CATEGORY == true && SKILL_CATEGORY_SIMPLE == false) 
  {
   //Takes a relevant STAT and returns the appropriate value to be added for the Skill Category 
   int A = Skill_Category_Primary(DEX);
   int B = Skill_Category_Primary(INT);
    
   int E = Skill_Category_Secondary(INT);
   int F = Skill_Category_Secondary(STR);
   int G = Skill_Category_Secondary(POW);
   int J = Skill_Category_Secondary(CHA);
   int H = Skill_Category_Secondary(CON);
   int I = 0;
   if (EDUCATION_STAT == true) 
     {int I = Skill_Category_Secondary(EDU);}
    
   int Z = Skill_Category_Negative(SIZ);
  
   //Mental Skill Category also addes in EDU as a secondary characteristic but ommits it if EDU is not used
   Combat_skillcategory = (A + B + F);    
   Communication_skillcategory = (B + G + J);
   Manipulation_skillcategory = (A + E + F);
   Mental_skillcategory = (B + G + I);
   Perception_skillcategory = (B + G + H);
   Physical_skillcategory = (A + F + H + Z);
  }

  //Simple Skill Category rules
  if (SKILL_CATEGORY == true && SKILL_CATEGORY_SIMPLE == true) 
  {
   //Takes a relevant STAT and divides it by 2 rounded up
   int Dx = ceil(DEX/2);
   int Ca = ceil(CHA/2);
   int It = ceil(INT/2);
   int Pw = ceil(POW/2);
   int Sr = ceil(STR/2);
     
   Combat_skillcategory = Dx;    
   Communication_skillcategory = Ca;
   Manipulation_skillcategory = Dx;
   Mental_skillcategory = It;
   Perception_skillcategory = Pw;
   Physical_skillcategory = Sr;
  } 
}

//Handles all skills and skill categorys 
void BRP_human_base::Skills()
{  
  //special base values for skills
  int DodgeBase = DEX*2; //Dodge
  int FlyBase = ceil(DEX/2); //Fly
  if (WINGED_CHARACTER == true) 
    {FlyBase = DEX*4;}
  int GamingBase = INT+POW; //Gaming
  int Language0Base = INT*5; //Own Language
  if (EDUCATION_STAT == true && EDU*5 > INT*5)
    {Language0Base = EDU*5;}
  int ProjectionBase = DEX*2; //Projection
  int PsychotherapyBase = 0; //Psychotherapy
  if (SANITY == true)
    {PsychotherapyBase = 1;}
    
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
  SkillTable["Art1"] = { "Art", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Artillery0"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Artillery1"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Artillery2"] = { "Artillery", "", 0, 0, Combat_skillcategory};
  SkillTable["Bargain"] = { "Bargain", "", 5, 0, Communication_skillcategory};
  SkillTable["Brawl"] = { "Brawl", "", 25, 0, Combat_skillcategory};
  SkillTable["Climb"] = { "Climb", "", 40, 0, Physical_skillcategory};
  SkillTable["Command"] = { "Command", "", 5, 0, Communication_skillcategory};
  SkillTable["Craft0"] = { "Craft", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Craft1"] = { "Craft", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Demolition"] = { "Demolition", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Disguise"] = { "Disguise", "", 1, 0, Communication_skillcategory};
  SkillTable["Dodge"] = { "Dodge", "", DodgeBase, 0, Physical_skillcategory};
  SkillTable["Drive0"] = { "Drive", "", 20, 0, Manipulation_skillcategory};
  SkillTable["Drive1"] = { "Drive", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Drive2"] = { "Drive", "", 20, 0, Manipulation_skillcategory};
  SkillTable["Drive3"] = { "Drive", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Energy Weapon0"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Energy Weapon1"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Energy Weapon2"] = { "Energy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Etiquette"] = { "Etiquette", "", 5, 0, Communication_skillcategory};
  SkillTable["Fast Talk"] = { "Fast Talk", "", 5, 0, Communication_skillcategory};
  SkillTable["Fine Manipulation"] = { "Fine Manipulation", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Firearm0"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["Firearm1"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["Firearm2"] = { "Firearm", "", 0, 0, Combat_skillcategory};
  SkillTable["First Aid"] = { "First Aid", "", 30, 0, Mental_skillcategory};
  SkillTable["Fly"] = { "Fly", "", FlyBase, 0, Physical_skillcategory};
  SkillTable["Gaming"] = { "Gaming", "", GamingBase, 0, Mental_skillcategory};
  SkillTable["Grapple"] = { "Grapple", "", 25, 0, Combat_skillcategory};
  SkillTable["Heavy Machine0"] = { "Heavy Machine", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Heavy Machine1"] = { "Heavy Machine", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Heavy Machine2"] = { "Heavy Machine", "", 1, 0, Manipulation_skillcategory};
  SkillTable["Heavy Weapon0"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon1"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon2"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Hide"] = { "Hide", "", 10, 0, Physical_skillcategory};
  SkillTable["Insight"] = { "Insight", "", 05, 0, Perception_skillcategory};
  SkillTable["Jump"] = { "Jump", "", 25, 0, Physical_skillcategory};
  SkillTable["Knowledge0"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge1"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge2"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Language0"] = { "Language", "", Language0Base, 0, Communication_skillcategory};
  SkillTable["Language1"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language2"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language3"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Listen"] = { "Listen", "", 25, 0, Perception_skillcategory};
  SkillTable["Literacy"] = { "Literacy", "", 0, 0, Mental_skillcategory};
  SkillTable["Martial Arts"] = { "Martial Arts", "", 1, 0, Combat_skillcategory};
  SkillTable["Medicine"] = { "Medicine", "", 5, 0, Mental_skillcategory};
  SkillTable["Melee Weapon0"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Melee Weapon1"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Melee Weapon2"] = { "Melee Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Missile Weapon0"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Missile Weapon1"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Missile Weapon2"] = { "Missile Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Navigate"] = { "Navigate", "", 10, 0, Perception_skillcategory};
  SkillTable["Parry0"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Parry1"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Parry2"] = { "Parry", "", 0, 0, Combat_skillcategory};
  SkillTable["Preform"] = { "Preform", "", 5, 0, Communication_skillcategory};
  SkillTable["Persuade"] = { "Persuade", "", 15, 0, Communication_skillcategory};
  SkillTable["Pilot0"] = { "Pilot", "", 1, 0, Physical_skillcategory};
  SkillTable["Pilot1"] = { "Pilot", "", 1, 0, Physical_skillcategory};
  SkillTable["Pilot2"] = { "Pilot", "", 1, 0, Physical_skillcategory};
  SkillTable["Projection"] = { "Projection", "", ProjectionBase, 0, Physical_skillcategory};
  SkillTable["Psychotherapy"] = { "Psychotherapy", "", PsychotherapyBase, 0, Mental_skillcategory};
  SkillTable["Repair0"] = { "Repair", "", 15, 0, Manipulation_skillcategory};
  SkillTable["Repair1"] = { "Repair", "", 15, 0, Manipulation_skillcategory};
  SkillTable["Research"] = { "Research", "", 25, 0, Perception_skillcategory};
  SkillTable["Ride0"] = { "Ride", "", 5, 0, Communication_skillcategory};
  SkillTable["Ride1"] = { "Ride", "", 5, 0, Communication_skillcategory};
  SkillTable["Ride2"] = { "Ride", "", 5, 0, Communication_skillcategory};
  SkillTable["Science0"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science1"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science2"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Science3"] = { "Science", "", 1, 0, Mental_skillcategory};
  SkillTable["Sense"] = { "Sense", "", 10, 0, Perception_skillcategory};
  SkillTable["Shield0"] = { "Shield", "", 0, 0, Combat_skillcategory};
  SkillTable["Shield1"] = { "Shield", "", 0, 0, Combat_skillcategory};
  SkillTable["Slight of Hand"] = { "Slight of Hand", "", 5, 0, Manipulation_skillcategory};
  SkillTable["Spot"] = { "Spot", "", 25, 0, Perception_skillcategory};
  SkillTable["Status"] = { "Status", "", 15, 0, Communication_skillcategory};
  SkillTable["Stealth"] = { "Stealth", "", 10, 0, Physical_skillcategory};
  SkillTable["Strategy"] = { "Strategy", "", 1, 0, Mental_skillcategory};
  SkillTable["Swim"] = { "Swim", "", 25, 0, Physical_skillcategory};
  SkillTable["Teach"] = { "Teach", "", 10, 0, Communication_skillcategory};
  SkillTable["Technical Skill0"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Technical Skill1"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Technical Skill2"] = { "Technical", "", 5, 0, Mental_skillcategory};
  SkillTable["Throw"] = { "Throw", "", 25, 0, Physical_skillcategory};
  SkillTable["Track"] = { "Track", "", 10, 0, Perception_skillcategory};
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
  //std::string KnowledgeGroup[] = {Americans,Chinese,British,Europeans,};
  //Knowledge (Region)
  //std::string KnowledgeRegion[] = {Local, };
  //Knowledge (Religion)
  //std::string KnowledgeReligion[] = {Judisum, Christianity, Islam, Folk};
  
  //Languages
  Language = {"Amharic", "Arabic", "Bengali", "Bhojpuri", "Cebuano", "Chinese", "Czech", "Danish", "Dutch", "English", "Estonian", "Farsi", "Finnish", "French", "German", "Greek", "Hausa", "Hindi-Urdu", "Hungarian", "Igbo", "Italian", "Japanese", "Javanese", "Korean", "Latin", "Latvian", "Lithuanian", "Lolo", "Macedonian", "Malay", "Māori", "Marathi", "Navajo", "Norwegian", "Oromo", "Polish", "Portuguese", "Russian", "Shona", "Sioux", "Slovak", "Spanish", "Sundanese", "Swahili", "Swedish", "Tagalog", "Tai–Kadai", "Tibetan", "Turkic", "Ukrainian", "Vietnamese", "Yoruba", "Yumplatok", "Zulu"};

  //Preform
  Preform = {"Act", "Conduct Orchestra", "Dance", "Juggle", "Orate", "Play", "Instrument (subspeciality)", "Recite", "Ritual", "Sing"};

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

//Assigns skills to JOBSKILLS array based on Profession
void BRP_human_base::PickJobSkills()
{
  switch (Hired) 
  {
    case 0: //Artist
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
      //Brawl
      //Disguise
      //Drive
      //Electronics
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
    //Dodge
    //Jump
    //Stealth
    //Throw
    break;
    }
    case 3:
    {
    break;
    }
    case 4:
    {
    break;
    }
    case 5:
    {
    break;
    }
    case 6:
    {
    break;
    }
    case 7:
    {
    break;
    }
    case 8:
    {
    break;
    }
    case 9:
    {
    break;
    }
    case 10:
    {
    break;
    } 
    case 11:
    {
    break;
    }
    case 12:
    {
    break;
    }
    case 13:
    {
    break;
    }
    case 14:
    {
    break;
    }
    case 15:
    {
    break;
    }
    case 16:
    {
    break;
    }
    case 17:
    {
    break;
    }
    case 18:
    {
    break;
    }
    case 19:
    {
    break;
    }
    case 20:
    {
    break;
    }
    default:
    {
      break;
    }
  }
}

//Assigns skills to HOBBYSKILLS array based on random chance
/*
void BRP_human_base::PickHobbySkills()
{
   //Picking Personnal Skills and assigns them to the HOBBYSKILL array
  //Number of Personal Skills, between 8 to 10
  int TotalPersonalSkillsKnown = rand() % (10 + 1 - 8) + 8;

  //array of strings to hold the Personal Skills
  HOBBYSKILLS[TotalPersonalSkillsKnown];

  //arrays of the results for skills with multiple skill subtypes on the sheet; slots are just spaces on the charater sheet where subskill names can be written
  int twoslot[4] = {1,7,41,43}; //Art,Craft,Repair,Ride
  int threeslot[5] = {11,26,38,43,54}; //Drive,Knowledge,Pilot,Ride,Technical Skill
  int fourslot[2] = {27,44}; //Language,Science
  int combatskillslot[8] = {2,12,16,22,32,33,35,46}; //Artillery,Energy Weapons,Firearms,Heavy Weapons,Melee Weapon,Missile Weapon,Parry,Shield
  //All other skills lack a subskill and can just be added to HOBBYSKILLS.

  //Redo loop to reduce KnownSkillLeft whenever it does 
  //Loop adding skill names to HOBBYSKILL array also assigns SubSkills when needed
  for(int i = 0; i < TotalPersonalSkillsKnown; i++)
  {
    //Randomlly picked skill from SkillList
    int SkillPicked = rand() % SkillList.size();
    
    //Bools for confirming if the skill picked is one that requires checking subtypes
    bool SkillwithTwoSlots = std::find(std::begin(twoslot),std::end(twoslot),SkillPicked) != std::end(twoslot);
    bool SkillwithThreeSlots = std::find(std::begin(threeslot),std::end(threeslot),SkillPicked) != std::end(threeslot);
    bool SkillwithFourSlots = std::find(std::begin(fourslot),std::end(fourslot),SkillPicked) != std::end(fourslot);
    bool SkillinCombat = std::find(std::begin(combatskillslot),std::end(combatskillslot),SkillPicked) != std::end(combatskillslot);

    //String making the picked skill into something matching a skill from SkillTable that has subskills
    std::string SkillSlotZERO = SkillList[SkillPicked] + "0"; //skill0
    std::string SkillSlotONE = SkillList[SkillPicked] + "1"; //skill1
    std::string SkillSlotTWO = SkillList[SkillPicked] + "2"; //skill2
    std::string SkillSlotTHREE = SkillList[SkillPicked] + "3"; //skill3

    //Checks if picked skill is already in HOBBYSKILLS[]
    //How does this loop effect the one it's in? This also doesn't check for ARMS which have tons of subtypes
    for (int i = 0; i < TotalPersonalSkillsKnown; i++)
    {
      if (HOBBYSKILLS[i] == SkillList[SkillPicked] || HOBBYSKILLS[i] == SkillSlotZERO || HOBBYSKILLS[i] == SkillSlotONE || HOBBYSKILLS[i] == SkillSlotTWO || HOBBYSKILLS[i] == SkillSlotTHREE)
      {}
    }
    
    //For subskills;  
    if (SkillwithTwoSlots == true) //Selected skill has 2 slots
    {
      int SIT = 0;
      
      switch (SIT)
      {
        case 0: //Slot 0 used, slot 1 is free
        {
          break;
        }; 
        case 1: //Slot 0 and 1 are used
        {
          break;
        };
        default: //Slots 0 and 1 are free
        {
          break;
        };
      }
      break;
      // if (SkillTable[SkillSlotZERO].SubSkillName != "" && SkillTable[SkillSlotONE].SubSkillName != "") //if this skill hasn't been selected yet
      // {
      //   HOBBYSKILLS[i] = SkillSlotZERO;
      // }
      // else 
      // {
      //   int coin = rand() % 1; //Do I increase skill in slot 0 or add new one?
      //   if (coin == 0)
      //   {
      //     SkillTable[SkillSlotZERO].SubSkillName = ""; //Stopped working here till I come up with a better system
      //     HOBBYSKILLS[i] = SkillSlotZERO;
      //   }
      //   else {HOBBYSKILLS[i] = SkillSlotONE;}
      // }
    }
    else if(SkillwithThreeSlots == true) //Selected skill has 3 slots
    {
      //no code, need to fill
      break;
    }
    else if(SkillwithFourSlots == true) //Selected skill has 4 slots
    {
      //no code, need to fill
      break;
    }
    else if(SkillinCombat == true) //Selected skill is a combat skill
    {
      //no code, need to fill
      break;
    }
    else //Selected skill has 1 slot
    {
      HOBBYSKILLS[i] = SkillList[SkillPicked];
      //set up condional for Heavy Machine
    }
  }
}*/

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
void BRP_human_base::FillSkillMod()
{
  for (auto& X : SkillTable)
  {
    X.second.SkillMod += X.second.SkillBase + X.second.SkillCat;
  }
}

//Assign Own Language
void BRP_human_base::OwnLanguage() 
{
  int OwnLang = rand() % Language.size();
  SkillTable["Language0"].SubSkillName = Language.at(OwnLang);
}

//Personality
void BRP_human_base::PersonalityPick()
{
  int pick = PLAY.Dfour();
  Personality = "";
  switch (pick)
  {//need to add skill points asigning for each case
  case 1:
    {
    Personality = "They have a brutal personality, thinking first of solving problems by means of physical force and brawn.";
    break;
    }
  case 2:
    {
    Personality = "They have a skilled personality, beliving that technique, craft, and expertise are the secrets of success.";
    break;
    }
  case 3:
    {
    Personality = "They have a cunning personality, trying first to outsmart an opponent to gain an advantage.";
    break;
    }
  case 4:
    {
    Personality = "They have a charming personality, enjoying persuading other people to work, while they make the decisions.";
    break;
    }
  }
}

//Randomly assigns skill points to the Profession's Skills
void BRP_human_base::ProfessionSkillSet()
{
  //Sets up the Current Skill Points to be spent for the following loop.
  int CurrentSkillPoints = ProSkillPtsMAX;

  //Function ends when all CurrentSkillPoints are used up.
  while (CurrentSkillPoints > 0)
  {
    /*This loops 10 times through the JOBSKILLS array because there are 10 skills for each Profession. 
    If there is a different number skills per profession it is recommended to adjust 10 in the for loop argument by that amount. 
    I could run a check for how long the JOBSKILLS and make that a veriable so the max JOBSKILL array can be changed without issues*/
    for (int i = 0; i < 10; i++)
    {
    //Gets the name of the skill to be increased.
    std::string ROLE = JOBSKILLS[i];
    //Skip any skill already at max rating.
    if (SkillTable[ROLE].SkillMod >= SkillRatingMAX)
      {continue;}
    else 
      {
      //Assigns 0 to 10 points.
      int LEARNED = rand() % 11;
      //If the Current Skill Points are less then what was rolled, this reduces the LEARNED points to what is left in the CurrentSkillPoints.
      while (LEARNED > CurrentSkillPoints)
        {LEARNED--;}
      //If LEARNED will bring the current skill above the max, just reduce the points down till it hits the max.
      while (SkillTable[ROLE].SkillMod + LEARNED > SkillRatingMAX) 
        {LEARNED--;}
      //Add and remove points to the skill and from the CurrentSkillPoints availible.
      SkillTable[ROLE].SkillMod += LEARNED; 
      CurrentSkillPoints -= LEARNED;
      //Ends the loop if all the current skill points are spent, the while loop should be false and end as well.
      if (CurrentSkillPoints == 0)
        {break;}
      else
        {continue;}
      }
    }
  }
}

//Gets the character's name
void BRP_human_base::CharName()
{
  std::cout << "\nWhat is the character's name?\n";
  std::getline(std::cin >> std::ws, CN); 
}

//Gets the user's name
void BRP_human_base::PlayerName()
{
  std::cout << "\nWhat is your name?\n";
  std::getline(std::cin >> std::ws, PN);
}

//Generates a fully randomized character
void BRP_human_base::fullrandom(RandomSetUp& WOW)
{
  SettingsSwitches();
  EDUstat();
  ExpBonus(INT);
  SanityPoints(POW);
  FatiguePoints(STR, CON);
  HitPoints();
  HPbyLocation(HP);
  MajorWounds();
  DamageBonus();
  Weapons();
  Born();
  RandGender();
  HandDom();
  Faith();
  DistinctiveFeatures();
  HeightandWeight();
  ProSkillPointsPool();
  PerSkillPonitsPool();
  SkillRatingMaximum();
  SkillCategory();
  Skills();
  FillSkillMod();
  PersonalityPick();
  OwnLanguage();
  Professions();
  PickJobSkills();
  ProfessionSkillSet();
  //PersonalSkillSet();
  


} 

//Free build a full character
void BRP_human_base::freebuild()
{
  ;
}

//Prints character sheet to console
void BRP_human_base::consoleChar(RandomSetUp& WOW)
{
  std::cout << "\n" << std::endl;
  std::cout << WeaponsTable["Sword, Short"].WeaponName << std::endl;
  std::cout << "Starting Age: " << Age << "\t" << "Works as ";
  if(Wealth[0] == 'A'){std::cout << "an ";}else{std::cout << "a ";}; 
  std::cout <<  Wealth << " " << Profession << std::endl;
  std::cout <<  "Religion: " << Religion << std::endl;
  std::cout << "Gender: " << Gender << "\t" << "Handedness: " << Handedness << std::endl;
  std::cout << "Height: " << Height << "\t" << "Weight: " << Weight << std::endl;
  std::cout << "STR " << STR << "\t" << "Effort roll " << CharacteristicRoll(STR) << "%\t\t\t" << "INT " << INT << "\t" << "Idea roll " << CharacteristicRoll(INT) << "%" << std::endl; 
  std::cout << "CON " << CON << "\t" << "Stamina roll " << CharacteristicRoll(CON) << "%\t\t" << "CHA " << CHA << "\t" << "Charm roll " << CharacteristicRoll(CHA) << "%" << std::endl;
  std::cout << "DEX " << DEX << "\t" << "Agility roll " << CharacteristicRoll(DEX) << "%\t\t" << "POW " << POW << "\t" << "Luck roll " << CharacteristicRoll(POW) << "%" << std::endl;  
  if (EDUCATION_STAT == true) 
  {std::cout << "EDU " << EDU << "\t" << "Knoweledge roll " << CharacteristicRoll(EDU) << "%\t\t" << "SIZ " << SIZ << "\t" << "Damage Bonus of " << DamBonus << std::endl;}
  else
  {std::cout << "SIZ " << SIZ << "\t" << "Damage Bonus of " << DamBonus << std::endl;}
  std::cout << "HP: " << HP << " with Major Would occuring at " << MW << " HP" << std::endl;
  std::cout << "\n" << UnitedFeatures <<std::endl;
  std::cout <<"\n"<<" "<< Personality << std::endl;
  std::cout << "\nProfessional Skill Points Pool: "  << ProSkillPtsMAX << "\t\t" << "Personal Skill Points Pool: "  << PerSkillPtsMAX << std::endl;

  //START OF SKILLS
  //COMMUNICATION    MENTAL    PHYSICAL
  std::cout << "COMMUNICATION " << Communication_skillcategory << "%" << "\t\t\t" << "MENTAL " << Mental_skillcategory << "%" << "\t\t\t" << "PHYSICAL " << Physical_skillcategory << "%" << "\t\t\t" << std::endl;

  //Bargain    Appraise    Climb
  std::cout << SkillTable["Bargain"].SkillName << " (" << SkillTable["Bargain"].SkillBase << ")" << "\t\t" << SkillTable["Bargain"].SkillMod << "%" << "\t\t" << SkillTable["Appraise"].SkillName << " (" << SkillTable["Appraise"].SkillBase << ")" << "\t" << SkillTable["Appraise"].SkillMod << "%" << "\t\t" << SkillTable["Climb"].SkillName << " (" << SkillTable["Climb"].SkillBase << ")" << "\t" << SkillTable["Climb"].SkillMod << "%" << "\t\t" << std::endl;

  //Command    First Aid    Drive(subskill0)
  std::cout << SkillTable["Command"].SkillName << " (" << SkillTable["Command"].SkillBase << ")" << "\t\t" << SkillTable["Command"].SkillMod << "%" << "\t\t" << SkillTable["First Aid"].SkillName << " (" << SkillTable["First Aid"].SkillBase << ")" << "\t" << SkillTable["First Aid"].SkillMod << "%" << "\t\t" << SkillTable["Drive0"].SkillName << " (" << SkillTable["Drive0"].SkillBase << ")" << "\t" << SkillTable["Drive0"].SkillMod << "%" << "\t\t" << std::endl;

  //Disguise    Gaming    Drive(subskill1)
  std::cout << SkillTable["Disguise"].SkillName << " (" << SkillTable["Disguise"].SkillBase << ")" << "\t" << SkillTable["Disguise"].SkillMod << "%" << "\t\t" << SkillTable["Gaming"].SkillName << " (" << SkillTable["Gaming"].SkillBase << ")" << "\t" << SkillTable["Gaming"].SkillMod << "%" << "\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Etiquette    Drive(subskill2)
  std::cout << SkillTable["Etiquette"].SkillName << " (" << SkillTable["Etiquette"].SkillBase << ")" << "\t" << SkillTable["Etiquette"].SkillMod << "%" << "\t\t" << SkillTable["Knowledge0"].SkillName << " (" << SkillTable["Knowledge0"].SkillBase << ")" << "\t\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Fast Talk    Knowledge(subskill0)    Fly
  std::cout << SkillTable["Fast Talk"].SkillName << " (" << SkillTable["Fast Talk"].SkillBase << ")" << "\t" << SkillTable["Fast Talk"].SkillMod << "%" << "\t\t" << "  " << SkillTable["Knowledge0"].SubSkillName << "\t" << SkillTable["Knowledge0"].SkillMod << "%" << "\t\t" << SkillTable["Fly"].SkillName << " (" << SkillTable["Fly"].SkillBase << ")" << "\t" << SkillTable["Fly"].SkillMod << "%" << "\t\t" << std::endl;

  //Knowledge(subskill1)    Hide
  std::cout << SkillTable["Language0"].SkillName << " (" << SkillTable["Language0"].SkillBase << ")" << "\t\t" << "  " << SkillTable["Knowledge1"].SubSkillName << "\t" << SkillTable["Knowledge1"].SkillMod << "%" << "\t\t" << SkillTable["Hide"].SkillName << " (" << SkillTable["Hide"].SkillBase << ")" << "\t" << SkillTable["Hide"].SkillMod << "%" << "\t\t" << std::endl;

  //Language(subskill0)    Knowledge(subskill2)    Jump
  std::cout << "  " << SkillTable["Language0"].SubSkillName << "\t\t" << SkillTable["Language0"].SkillMod << "%" << "\t\t" << "  " << SkillTable["Knowledge2"].SubSkillName << "\t" << SkillTable["Knowledge2"].SkillMod << "%" << "\t\t" << SkillTable["Jump"].SkillName << " (" << SkillTable["Jump"].SkillBase << ")" << "\t" << SkillTable["Jump"].SkillMod << "%" << "\t\t" << std::endl;

  //Language(subskill1)    Literacy    Pilot(subskill0)
  std::cout << "  " << SkillTable["Language1"].SubSkillName << "\t\t" << SkillTable["Language1"].SkillMod << "%" << "\t\t" << SkillTable["Literacy"].SkillName << " (" << SkillTable["Language0"].SkillBase << ")" << "  " << SkillTable["Language0"].SkillMod << "%" << "\t\t\t\t" << SkillTable["Pilot0"].SkillName << " (" << SkillTable["Pilot0"].SkillBase << ")" << "\t" << SkillTable["Pilot0"].SkillMod << "%" << "\t\t" << std::endl;

  //Language(subskill2)    Medicine    Pilot(subskill1)
  std::cout << "  " << SkillTable["Language2"].SubSkillName << "\t\t" << SkillTable["Language2"].SkillMod << "%" << "\t\t" << "\t\t\t" << SkillTable["Medicine"].SkillName << " (" << SkillTable["Medicine"].SkillBase << ")" << "\t" << SkillTable["Medicine"].SkillMod << "%" << "\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Language(subskill3)    Psychotherapy    Pilot(subskill2)
  std::cout << "  " << SkillTable["Language3"].SubSkillName << "\t\t" << SkillTable["Language3"].SkillMod << "%" << "\t\t" << SkillTable["Psychotherapy"].SkillName << " (" << SkillTable["Psychotherapy"].SkillBase << ")" << "\t" << SkillTable["Psychotherapy"].SkillMod << "%" << "\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Preform    Science(subskill0)    Projection
  std::cout << SkillTable["Preform"].SkillName << " (" << SkillTable["Preform"].SkillBase << ")" << "\t" << SkillTable["Preform"].SkillMod << "%" << "\t\t\t\t\t" << SkillTable["Science0"].SkillName << " (" << SkillTable["Science0"].SkillBase << ")" << "\t" << SkillTable["Science0"].SkillMod << "%" << "\t\t" << SkillTable["Projection"].SkillName << " (" << SkillTable["Projection"].SkillBase << ")" << "\t" << SkillTable["Projection"].SkillMod << "%" << "\t\t" << std::endl;

  //Persuade    Science(subskill1)    Ride(subskill0)
  std::cout << SkillTable["Persuade"].SkillName << " (" << SkillTable["Persuade"].SkillBase << ")" << "\t" << SkillTable["Persuade"].SkillMod << "%" << "\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << SkillTable["Ride0"].SkillName << " (" << SkillTable["Ride0"].SkillBase << ")" << "\t" << SkillTable["Ride0"].SkillMod << "%" << "\t\t" << std::endl;

  //Status    Science(subskill2)    Ride(subskill1)
  std::cout << SkillTable["Status"].SkillName << " (" << SkillTable["Status"].SkillBase << ")" << "\t" << SkillTable["Status"].SkillMod << "%" << "\t\t\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Teach    Science(subskill3)    Stealth
  std::cout << SkillTable["Teach"].SkillName << " (" << SkillTable["Teach"].SkillBase << ")" << "\t\t" << SkillTable["Teach"].SkillMod << "%" << "\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << SkillTable["Stealth"].SkillName << " (" << SkillTable["Stealth"].SkillBase << ")" << "\t" << SkillTable["Stealth"].SkillMod << "%" << "\t\t" << std::endl;

  //Strategy    Swim
  std::cout << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t\t" << SkillTable["Strategy"].SkillName << " (" << SkillTable["Strategy"].SkillBase << ")" << "\t" << SkillTable["Strategy"].SkillMod << "%" << "\t\t" << SkillTable["Swim"].SkillName << " (" << SkillTable["Swim"].SkillBase << ")" << "\t" << SkillTable["Swim"].SkillMod << "%" << "\t\t" << std::endl;

  //MANIPULATION    Technical Skill(subskill0)    Throw
  std::cout << "MANIPULATION (" << Manipulation_skillcategory << ")" << "\t\t\t" << SkillTable["Technical Skill0"].SkillName << " (" << SkillTable["Technical Skill0"].SkillBase << ")" << "\t" << SkillTable["Technical Skill0"].SkillMod << "%" << "\t\t" << SkillTable["Throw"].SkillName << " (" << SkillTable["Throw"].SkillBase << ")" << "\t" << SkillTable["Throw"].SkillMod << "%" << "\t\t" << std::endl;

  //Art(subskill0)    Technical Skill(subskill1)
  std::cout << SkillTable["Art0"].SkillName << " (" << SkillTable["Art0"].SkillBase << ")" << " " << SkillTable["Art0"].SubSkillName << "\t" << SkillTable["Art0"].SkillMod << "%" << "\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << std::endl;

  //Art(subskill1)    COMBAT
  std::cout << "  " << SkillTable["Art1"].SubSkillName << "\t" << SkillTable["Art1"].SkillMod << "%" << "\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << "COMBAT (" << Combat_skillcategory << ")" << std::endl;

  //Craft(subskill0)    Dodge
  std::cout << SkillTable["Craft0"].SkillName << " (" << SkillTable["Craft0"].SkillBase << ")" << "\t" << SkillTable["Craft0"].SkillMod << "%" << "\t\t\t\t" << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t" << SkillTable["Dodge"].SkillName << " (" << SkillTable["Dodge"].SkillBase << ")" << "\t" << SkillTable["Dodge"].SkillMod << "%" << "\t\t" << std::endl;

  //Craft(subskill1)    PERCEPTION    Martial Arts
  std::cout << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t\t" << "PERCEPTION (" << Perception_skillcategory << ")" << "\t" << "\t\t" << SkillTable["Martial Arts"].SkillName << " (" << SkillTable["Martial Arts"].SkillBase << ")" << "\t" << SkillTable["Martial Arts"].SkillMod << "%" << "\t\t" << std::endl;

  //Demolition    Insight
  std::cout << SkillTable["Demolition"].SkillName << " (" << SkillTable["Demolition"].SkillBase << ")" << "\t" << SkillTable["Demolition"].SkillMod << "%" << "\t\t\t" << SkillTable["Insight"].SkillName << " (" << SkillTable["Insight"].SkillBase << ")" << "\t" << SkillTable["Insight"].SkillMod << "%" << "\t\t" << "See Weapons below for more Combat skills" << std::endl;

  //Fine Manipulation    Listen
  std::cout << SkillTable["Fine Manipulation"].SkillName << " (" << SkillTable["Fine Manipulation"].SkillBase << ")" << "\t" << SkillTable["Fine Manipulation"].SkillMod << "%" << "\t\t\t" << SkillTable["Listen"].SkillName << " (" << SkillTable["Listen"].SkillBase << ")" << "\t" << SkillTable["Listen"].SkillMod << "%" << std::endl;

  //Heavy Machine(subskill0)    Navigate    Combat Skill(ARMS0)
  std::cout << SkillTable["Heavy Machine0"].SkillName << " (" << SkillTable["Heavy Machine0"].SkillBase << ")" << "\t" << SkillTable["Heavy Machine0"].SkillMod << "%" << "\t\t\t" << SkillTable["Navigate"].SkillName << " (" << SkillTable["Navigate"].SkillBase << ")" << "\t" << SkillTable["Navigate"].SkillMod << "%" << "\t\t" << SkillTable["ARMS0"].SkillName << " (" << SkillTable["ARMS0"].SkillBase << ")" << "\t" << SkillTable["ARMS0"].SkillMod << "%" << "\t\t" << std::endl;

  //Heavy Machine(subskill1)    Research    Combat Skill(ARMS1)
  std::cout << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t\t" << SkillTable["Research"].SkillName << " (" << SkillTable["Research"].SkillBase << ")" << "\t" << SkillTable["Research"].SkillMod << "%" << "\t\t" << SkillTable["ARMS1"].SkillName << " (" << SkillTable["ARMS1"].SkillBase << ")" << "\t" << SkillTable["ARMS1"].SkillMod << "%" << "\t\t" << std::endl;

  //Repair(subskill0)    Sense    Combat Skill(ARMS2)
  std::cout << SkillTable["Repair0"].SkillName << " (" << SkillTable["Repair0"].SkillBase << ")" << "\t" << SkillTable["Repair0"].SkillMod << "%" << "\t\t\t\t" << SkillTable["Sense"].SkillName << " (" << SkillTable["Sense"].SkillBase << ")" << "\t" << SkillTable["Sense"].SkillMod << "%" << "\t\t" << SkillTable["ARMS2"].SkillName << " (" << SkillTable["ARMS2"].SkillBase << ")" << "\t" << SkillTable["ARMS2"].SkillMod << "%" << "\t\t" << std::endl;

  //Repair(subskill1)    Spot    Combat Skill(ARMS3)
  std::cout << SkillTable["BLANK"].SkillName << " (" << SkillTable["BLANK"].SkillBase << ")" << "\t" << SkillTable["BLANK"].SkillMod << "%" << "\t\t\t" << SkillTable["Spot"].SkillName << " (" << SkillTable["Spot"].SkillBase << ")" << "\t" << SkillTable["Spot"].SkillMod << "%" << "\t\t" << SkillTable["ARMS3"].SkillName << " (" << SkillTable["ARMS3"].SkillBase << ")" << "\t" << SkillTable["ARMS3"].SkillMod << "%" << "\t\t" << std::endl;

  //Slight of Hand    Track    EXPERENCE BONUS
  std::cout << SkillTable["Slight of Hand"].SkillName << " (" << SkillTable["Slight of Hand"].SkillBase << ")" << "\t" << SkillTable["Slight of Hand"].SkillMod << "%" << "\t\t\t" << SkillTable["Track"].SkillName << " (" << SkillTable["Track"].SkillBase << ")" << "\t" << SkillTable["Track"].SkillMod << "%" << "\t\t"; if(EXPERIENCE_BONUS == true){std::cout << "EXPERENCE BONUS " << ExperenceBonus << "%"<< std::endl;} else{std::cout << "" << std::endl;}
  //END OF SKILLS

  
  std::cout << "\n\nSeed: " << WOW.currentSeed;
}

//Prints a txt file character sheet
void BRP_human_base::printChar(RandomSetUp& WOW)
{
  std::string BRPFilePath = "Characters/BRP/";
  
  std::string BRPCharFileName = BRPFilePath + CN + "_by_" + PN + ".txt";
  
  std::ofstream BRPText(BRPCharFileName,std::ofstream::out);

  BRPText << "===========================================================" << std::endl;
  BRPText << "\t\t\tPERSONAL" << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "Name: " << CN << "\t\t" << "Player: " << PN << std::endl;
  BRPText << "Culture: " << "Human" << "\t\t" << "Gender: " << Gender << std::endl;
  BRPText << "Handedness: " << Handedness << "\t" << "Height: " << Height << "\t" << "Weight: " << Weight << std::endl;
  BRPText << "Profession: " << Profession << "\t\t" << "Wealth: " << Wealth << std::endl;
  BRPText << "Gods/Religion: " << Religion << std::endl;
  BRPText << "\n" << UnitedFeatures <<std::endl;
  BRPText << "MOV: " << 10 << "\t\t" << "Age: " << Age << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "\t\t\tCHARACTERISTICS" << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "STR " << std::setw(2) << std::setfill('0') << STR << "\t" << "Effort roll " << CharacteristicRoll(STR) << "%\t\t\t" << "INT " << std::setw(2) << std::setfill('0') << INT << "\t" << "Idea roll " << CharacteristicRoll(INT) << "%" << std::endl; 
  BRPText << "CON " << std::setw(2) << std::setfill('0') << CON << "\t" << "Stamina roll " << CharacteristicRoll(CON) << "%\t\t" << "CHA " << std::setw(2) << std::setfill('0') << CHA << "\t" << "Charm roll " << CharacteristicRoll(CHA) << "%" << std::endl;
  BRPText << "DEX " << std::setw(2) << std::setfill('0') << DEX << "\t" << "Agility roll " << CharacteristicRoll(DEX) << "%\t\t" << "POW " << std::setw(2) << std::setfill('0') << POW << "\t" << "Luck roll " << CharacteristicRoll(POW) << "%" << std::endl;  
  if (EDUCATION_STAT == true) 
  {BRPText << "EDU " << std::setw(2) << std::setfill('0') << EDU << "\t" << "Knowledge roll " << CharacteristicRoll(EDU) << "%\t";} 
  BRPText << "SIZ " << std::setw(2) << std::setfill('0') << SIZ << "\t" << "Damage Bonus of " << DamBonus << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "\t\t\tHIT POINTS" << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "HP: " << HP << " with Major Would occuring at " << MW << " HP" << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "\t\t\tSKILLS" << std::endl;
  BRPText << "===========================================================" << std::endl;
  BRPText << "Professional Skill Points Pool: "  << ProSkillPointsPool() << std::endl;
  BRPText << "Personal Skill Points Pool: "  << PerSkillPonitsPool() << std::endl;
  
  BRPText << SkillTable["Appraise"].SkillName << " (" << SkillTable["Appraise"].SkillBase << "%)" << "\t\t\t" << SkillTable["Appraise"].SkillMod << "%" << std::endl;
  
  BRPText << "COMMUNICATION (" << Communication_skillcategory << "%)" << "\t\t\t" << "MENTAL (" << Mental_skillcategory << "%)" << "\t\t\t" << "PHYSICAL (" << Physical_skillcategory << "%)" << "\t\t\t" << std::endl;
  BRPText << "MANIPULATION (" << Manipulation_skillcategory << "%)" << "\t\t\t" << "PERCEPTION (" << Perception_skillcategory << "%)" << "\t\t\t" << "COMBAT (" << Combat_skillcategory << "%)"  << "\t\t\t" << std::endl;
  
  BRPText << "\n\nSeed: " << WOW.currentSeed;
  
  BRPText.close();
}