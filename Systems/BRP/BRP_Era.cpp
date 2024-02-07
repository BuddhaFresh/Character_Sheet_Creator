#include "BRP_Era.h"
#include <iostream>

BRP_human_AncientEra::BRP_human_AncientEra(int a, int b, int c, int d, int e, int x, int y, int z) : BRP_human_base(a,b,c,d,e,x,y,z){}

void BRP_human_AncientEra::Skills(int stat_dex, int stat_int, int stat_pow){
  //special base values for skills
  int DodgeBase = stat_dex*2; //Dodge
  int FlyBase = ceil(stat_dex/2); //Fly
  if (WINGED_CHARACTER == true) 
    {FlyBase = stat_dex*4;}
  int GamingBase = stat_int+stat_pow; //Gaming
  int Language0Base = stat_int*5; //Own Language
  if (EDUCATION_STAT == true && EDU*5 > stat_int*5)
    {Language0Base = EDU*5;}
  int ProjectionBase = stat_dex*2; //Projection
  int PsychotherapyBase = 0; //Psychotherapy
  if (SANITY == true)
    {PsychotherapyBase = 1;}
  int LiteracyBase = 0; //Literacy, need an if statement for modern setting
  //int DriveBase = 1; or 20, depends on setting and what is driven in that era

  //map of all skills with; name, subtype, base%, a value to be modifyed, and skill category
  //This still seems too unweildly, especially with subtypes and Bases set by weapons
  //Should Each type also have skill category assigned too it as well?
  //COMBAT are slots for all combat and weapon skills. 
  SkillTable["COMBAT0"] = { "", "", 0, 0, 0};
  SkillTable["COMBAT1"] = { "", "", 0, 0, 0};
  SkillTable["COMBAT2"] = { "", "", 0, 0, 0};
  SkillTable["COMBAT3"] = { "", "", 0, 0, 0};
  SkillTable["COMBAT4"] = { "", "", 0, 0, 0};
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
  SkillTable["Heavy Weapon0"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon1"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Heavy Weapon2"] = { "Heavy Weapon", "", 0, 0, Combat_skillcategory};
  SkillTable["Hide"] = { "Hide", "", 10, 0, Physical_skillcategory};
  SkillTable["Insight"] = { "Insight", "", 5, 0, Perception_skillcategory};
  SkillTable["Jump"] = { "Jump", "", 25, 0, Physical_skillcategory};
  SkillTable["Knowledge0"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge1"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Knowledge2"] = { "Knowledge", "", 0, 0, Mental_skillcategory};
  SkillTable["Language0"] = { "Language", "", Language0Base, 0, Communication_skillcategory};
  SkillTable["Language1"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language2"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Language3"] = { "Language", "", 0, 0, Communication_skillcategory};
  SkillTable["Listen"] = { "Listen", "", 25, 0, Perception_skillcategory};
  SkillTable["Literacy"] = { "Literacy", "", LiteracyBase, 0, Mental_skillcategory};
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
  SkillTable["Preform0"] = { "Preform", "", 5, 0, Communication_skillcategory};
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
  SkillTable["Sleight of Hand"] = { "Sleight of Hand", "", 5, 0, Manipulation_skillcategory};
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

  //A vector of all Skill names.
  SkillList = {"Appraise", "Art", "Artillery", "Bargain", "Brawl", "Climb", "Command", "Craft", "Demolition", "Disguise", "Dodge", "Drive", "Energy Weapon", "Etiquette", "Fast Talk", "Fine Manipulation", "Firearm", "First Aid", "Fly", "Gaming", "Grapple", "Heavy Machine", "Heavy Weapon", "Hide", "Insight", "Jump", "Knowledge", "Language", "Listen", "Literacy", "Martial Arts", "Medicine", "Melee Weapon", "Missile Weapon", "Navigate", "Parry", "Perform", "Persuade", "Pilot", "Projection", "Psychotherapy", "Repair", "Research", "Ride", "Science", "Sense", "Shield", "Sleight of Hand", "Spot", "Status", "Stealth", "Strategy", "Swim", "Teach", "Technical Skill", "Throw", "Track"};

  //Skil Sub Categories
  //Art
  Art = {"Calligraphy", "Composing", "Conceptual Art", "Digital Art", "Drawing", "Painting", "Photography", "Poetry", "Sculpture", "Sketching", "Songwriting", "Writing"};

  //Craft
  Craft = {"Blacksmithing", "Carpentry", "Ceramics", "Cooking", "Leatherworking", "Locksmithing", "Metallurgy", "Stonemasonry"};

  //Drive
  Drive = {"Automobile", "Bicycle", "Carriage", "Cart", "Chariot", "Dogsled", "Motorcycle", "Truck", "Sleight"};

  //Heavy Machines
  Heavy_Machine = {"Armored Vehicles", "Boilers", "Bulldozers", "Cranes", "Drilling Machine", "Engines", "Forklift", "Street Sweeper", "Tracker", "Turbines"};

  //Knowledges
  Knowledge = {"Academic Lore", "Accounting", "Anthropology", "Archaeology", "Art History", "Blasphemous Lore", "Business", "Espionage", "Folklore", "Group (subspecialty)", "History", "Law", "Linguistics", "Literature", "Occult", "Philosophy", "Politics", "Region (subspecialty)", "Religion (subspecialty)", "Streetwise"}; 

  //Knowledge (Group)
  Group = {"Afghans", "Algerians", "Americans", "Angolans", "Argentines", "Australians", "Azerbaijanis", "Bangladeshis", "Belgians", "Bolivians", "Brazilians", "British", "Burkinabè", "Cambodians", "Cameroonians", "Canadians", "Chinese", "Chileans", "Colombians", "Cubans", "Czechs", "DR Congolese", "Dominicans", "Egyptians", "El Salvadorians", "Emiratis", "Ethiopians", "Europeans", "Filipinos", "French", "Germans", "Ghanaians", "Guatemalans", "Guineans", "Haitians", "Hondurans", "Indians", "Indonesians", "Iranians", "Iraqis", "Irish", "Italians", "Japanese", "Jamaicans", "Jordanians", "Kazakhstani", "Kenyans", "Kuwaitis", "Kyrgyzstanis", "Laotians", "Latvians", "Lebanese", "Libyans", "Malaysians", "Malians", "Mexicans", "Moroccans", "Mozambicans", "Myanma", "Nepalese", "Netherlands", "New Zealanders", "Nicaraguans", "Nigeriens", "Nigerians", "North Koreans", "Pakistanis", "Palestinians", "Panamanians", "Paraguayans", "Peruvians", "Poles", "Portuguese", "Russians", "Saudi Arabians", "Scots", "Singaporeans", "Sudanese", "Saudis", "South Africans", "South Koreans", "Spanish", "Swiss", "Tajikistanis", "Tanzanians", "Thai", "Turkmenistanis", "Turkish", "Tunisia", "Ukrainians", "Uruguayans", "Uzbekistanis", "Venezuelans", "Vietnamese", "Yemenis"};
  //Knowledge (Region)
  Region = {"Local", "Nation", "Country", "Desert", "Plains", "Fields", "Jungles", "Forests", "Swamps", "Mountians", "The City", "The Village", "The Town"};
  //Knowledge (Religion)
  Religion = {"Christianity", "Islam", "Hinduism", "Buddhism", "Judaism", "Sikhism", "Bahá'í Faith", "Jainism", "Shinto", "Taoism", "Zoroastrianism", "Confucianism", "Rastafari", "Cao Dai", "Tenrikyo", "Falun Gong", "Druze", "Bön", "Shamanism", "Wicca", "Hellenism", "Raelism", "Unitarian Universalism", "New Age"};

  //Languages
  Language = {"Ug-Ugh", "Ogga-Booga", "Bam-Bam", "Yaba-Daba", "Zug-Zug", "Chi-Chi"};

  //Languages, Computer Code
  LanguageComputerCode = {"Assembly", "BASIC", "C", "C#", "C++", "COBOL", "Delphi", "Fortran", "Java", "JavaScript", "Lua", "Python", "Ruby", "Scratch", "SQL"};

  //Preform
  Preform = {"Act", "Conduct Orchestra", "Dance", "Juggle", "Orate", "Play", "Instrument (subspeciality)", "Recite", "Ritual", "Sing"};

  //Preform (Instrument)
  Instrument = {"Accordion", "Bagpipes", "Banjo", "Bassoon", "Cello", "Clarinet", "Cowbell", "Didgeridoo", "Drums", "Flute", "French Horn", "Guitar", "Harp", "Mandolin", "Oboe", "Piano", "Saxophone", "Sitar", "Steel Drum", "Trombone", "Trumpet", "Ukulele", "Viola", "Violin", "Xylophone"};

  //Pilot
  Pilot = {"Airplane", "Airship", "Balloon", "Boat", "Helicopter", "Hovercraft", "Jet Aircraft", "Jetpack", "Starship", "Submarine"};

  //Repair
  Repair = {"Electrical", "Electronic", "Engineering", "Hydroelectric", "Mechanical", "Structural", "Quantum"};

  //Ride
  Ride = {"Alpaca", "Camel", "Donkey", "Dromedary", "Elephant", "Horse", "Llama", "Mule", "Ox", "Pony", "Reindeer", "Water Buffalo", "Water Ox", "Yak", "Zebra"};

  //Science
  Science = {"Alchemy", "Astronomy", "Behavioral Science", "Biology", "Botany", "Chemistry", "Cryptography", "Genetics", "Geology", "Mathematics", "Meteorology", "Natural History", "Pharmacology", "Physics", "Planetology", "Psychology", "Quantum Mechanics", "Xenobiology", "Zoology"};

  //Technical
  Technical_Skill = {"Clockwork", "Computers", "Cybernetics", "Electronics", "Robotics", "Sensors", "Siege Engines", "Traps"};


  //Map of None-Combat Skills to Subskill vectors and Subskill subspecialities to their respective vectors
  SubSkillTable["Art0"] = {Art};
  SubSkillTable["Art1"] = {Art};
  SubSkillTable["Craft0"] = {Craft};
  SubSkillTable["Craft1"] = {Craft};
  SubSkillTable["Drive0"] = {Drive};
  SubSkillTable["Drive1"] = {Drive};
  SubSkillTable["Drive2"] = {Drive};
  SubSkillTable["Drive3"] = {Drive};
  SubSkillTable["Heavy Machine0"] = {Heavy_Machine};
  SubSkillTable["Knowledge0"] = {Knowledge};
  SubSkillTable["Knowledge1"] = {Knowledge};
  SubSkillTable["Knowledge2"] = {Knowledge};
  SubSkillTable["Language0"] = {Language};
  SubSkillTable["Language1"] = {Language};
  SubSkillTable["Language2"] = {Language};
  SubSkillTable["Language3"] = {Language};
  SubSkillTable["Preform0"] = {Preform};
  SubSkillTable["Pilot0"] = {Pilot};
  SubSkillTable["Pilot1"] = {Pilot};
  SubSkillTable["Pilot2"] = {Pilot};
  SubSkillTable["Repair0"] = {Repair};
  SubSkillTable["Repair1"] = {Repair};
  SubSkillTable["Ride0"] = {Ride};
  SubSkillTable["Ride1"] = {Ride};
  SubSkillTable["Ride2"] = {Ride};
  SubSkillTable["Science0"] = {Science};
  SubSkillTable["Science1"] = {Science};
  SubSkillTable["Science2"] = {Science};
  SubSkillTable["Science3"] = {Science};
  SubSkillTable["Technical Skill0"] = {Technical_Skill};
  SubSkillTable["Technical Skill1"] = {Technical_Skill};
  SubSkillTable["Technical Skill2"] = {Technical_Skill};
  SubSkillTable["Group"] = {Group};
  SubSkillTable["Region"] = {Region};
  SubSkillTable["Religion"] = {Religion};
  SubSkillTable["Instrument"] = {Instrument};
}

