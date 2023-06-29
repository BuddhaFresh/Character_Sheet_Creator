

int menu(){
int mainmenuinput = NULL;
bool exit = false;

while (exit == false) {
  
}
  std::cout << "Welcome to Character Sheet Creator\nMain Menu\n";
  std::cout << "O. New Sheet\n";
  std::cout << "1. Load Sheet\n";
  std::cout << "2. Options\n";
  std::cout << "3. Exit\n\n";

  std::cout << "Please Enter Your Command\n";
  std::cin >> mainmenuinput;
  //need to finish main menu logic
  if (mainmenuinput == 0) {
    std::cout << "New Sheet not availible\n\n";
  } 
  if (mainmenuinput == 1) {
    std::cout << "Load Sheet not availible\n\n";
  }
  if (mainmenuinput == 2) {
    optionsMenu();
  }
  else if (mainmenuinput == 3) {
    exit = true;
    return 0;
  }
  
}