#include<string.h>
#include<iostream>
#include "room.h"
#include "item.h"
#include <map>
#include <vector>
// MAIN
using namespace std;
// Zuul: To win, pick up chocolate from chocolate room
// Map link: https://drive.google.com/file/d/1c-NBgaFH5OR6_HMzoQMqZPaSOQ24x4oc/view?usp=sharing
// By Anika Gupta, 10/31/23
int main() {
  cout << "Printing. " << endl;

  //Creating descriptions for rooms
  
  char* SR_Description = new char[35];
  strcpy(SR_Description, "in the Storage Room");
  char* Courtyard_Description = new char[35];
  strcpy(Courtyard_Description, "in the Courtyard.");
  char* EL_Description = new char[35];
  strcpy(EL_Description, "in the Engineering Lab.");
  char* Aquarium_Description = new char[35];
  strcpy(Aquarium_Description, "in the Aquarium");
  char* chemLab_Description =  new char[35];
  strcpy(chemLab_Description, "in the Chemistry Lab.");
  char* PL_Description = new char[35];
  strcpy(PL_Description, "in the Physics Lab.");
  char* cafe_Description = new char[35];
  strcpy(cafe_Description, "in the Cafeteria.");
  char* TL_Description = new char[35];
  strcpy(TL_Description, "in the Teacher's Lounge.");
  char* BR_Description = new char[35];
  strcpy(BR_Description, "in the Bathroom.");
  char* HR_Description = new char[35];
  strcpy(HR_Description, "in the History Room.");
  char* office_Description = new char[35];
  strcpy(office_Description, "in the Office." );
  char* CS_Description = new char[60];
  strcpy(CS_Description, "in the chocolate supply room..the best room!!");
  char* AB_Description = new char[35];
  strcpy(AB_Description, "in the Art Building.");
  char* JR_Description = new char[35];
  strcpy(JR_Description, "in the Janitor's room.");

  //creating vector inventory
  vector<item*>* inventory = new vector<item*>();

  //creating rooms
  //outline: room* roomName = new room(description);
  room* StorageRoom = new room(SR_Description);
  room* Courtyard = new room(Courtyard_Description);
  room* EngineeringLab = new room(EL_Description);
  room* Aquarium = new room(Aquarium_Description);
  room* ChemistryLab = new room(chemLab_Description);
  room* PhysicsLab = new room(PL_Description);
  room* Cafeteria = new room(cafe_Description);
  room* TeacherLounge = new room(TL_Description);
  room* Bathroom = new room(BR_Description);
  room* HistoryRoom = new room(HR_Description);
  room* Office  = new room(office_Description);
  room* ChocolateSupply = new room(CS_Description);
  room* ArtBuilding = new room(AB_Description);
  room* JanitorRoom = new room(JR_Description);


  
  //creating variables for directions:

  // set exits for each room
  char* NORTH = new char[10] ;
  strcpy(NORTH, "NORTH");
  char* SOUTH = new char[10];
  strcpy(SOUTH, "SOUTH");
  char* EAST = new char[10];
  strcpy(EAST, "EAST");
  char* WEST = new char[10];
  strcpy(WEST, "WEST");
  //outline for adding exits is roomName->setExit(NORTH, neighbourName);
  //Setting SR exits:
  StorageRoom->setExit(EAST, Courtyard);
  //Setting Courtyard Exits
  Courtyard->setExit(WEST, StorageRoom);
  Courtyard->setExit(EAST, Cafeteria);
  //Setting Engineering Lab Exits
  EngineeringLab->setExit(EAST, Aquarium);
  //Setting Aquarium Exits
  Aquarium->setExit(WEST, EngineeringLab);
  Aquarium->setExit(EAST, ChemistryLab);
  //Setting Chemistry Lab Exits
  ChemistryLab->setExit(WEST, Aquarium);
  ChemistryLab->setExit(EAST, PhysicsLab);
  ChemistryLab->setExit(NORTH, Bathroom);
  //Setting Physics Lab Exits
  PhysicsLab->setExit(WEST, ChemistryLab);
  PhysicsLab->setExit(NORTH, HistoryRoom);
  //Setting Cafeteria Lab exits
  Cafeteria->setExit(WEST, Courtyard);
  Cafeteria->setExit(NORTH, TeacherLounge);
  Cafeteria->setExit(EAST, Office);
  //Setting Teacher's Lounge Exits:
  TeacherLounge->setExit(SOUTH, Cafeteria);
  TeacherLounge->setExit(EAST, ArtBuilding);
  //Setting Bathroom Exits
  Bathroom->setExit(NORTH, Office);
  Bathroom->setExit(SOUTH, ChemistryLab);
  //Setting History Room Exits
  HistoryRoom->setExit(SOUTH, PhysicsLab);
  HistoryRoom->setExit(NORTH, ChocolateSupply);
  // Setting Office Exits:
  Office->setExit(WEST, Cafeteria);
  Office->setExit(NORTH, ArtBuilding);
  Office->setExit(EAST, ChocolateSupply);
  Office->setExit(SOUTH, Bathroom);
  //Setting Chocolate Supply Exits
  ChocolateSupply->setExit(NORTH, JanitorRoom);
  ChocolateSupply->setExit(SOUTH, HistoryRoom);
  ChocolateSupply->setExit(WEST, Office);
  //Setting ArtBuilding Exits
  ArtBuilding->setExit(SOUTH, Office);
  ArtBuilding->setExit(WEST, TeacherLounge);
  ArtBuilding->setExit(EAST, JanitorRoom);
  //Setting Janitor Room Exits
  JanitorRoom->setExit(SOUTH, ChocolateSupply);
  JanitorRoom->setExit(WEST, ArtBuilding);

  

  // Setting names for Items
  char* computerN=new char[20];
  strcpy(computerN, "Computer");
  char* fishN = new char[20];
  strcpy(fishN, "Fish");
  char* milkN= new char[20];
  strcpy(milkN, "Milk");
  char* sandwichN = new char[20];
  strcpy(sandwichN, "Sandwich");
  char* paintbrushN = new char[20];
  strcpy(paintbrushN, "Paintbrush");
  char* chocolateN = new char[20];
  strcpy(chocolateN, "Chocolate");

  // Creating new items
  // item* Object = new item(objectN);
  item* Computer = new item(computerN);
  item* Fish = new item(fishN);
  item* Milk = new item(milkN);
  item* Sandwich = new item(sandwichN);
  item* Paintbrush = new item(paintbrushN);
  item* Chocolate = new item(chocolateN);

  // REMINDER : PUT ITEMS IN ROOMS !! ---------------------------

  Cafeteria->setItem(Milk);
  Cafeteria->setItem(Sandwich);
  ArtBuilding->setItem(Paintbrush);
  ChocolateSupply->setItem(Chocolate);
  Aquarium->setItem(Fish);
  EngineeringLab->setItem(Computer);

  //Welcome
  cout << "Welcome to Zuul! To win, pick up the Chocolate from the Chocolate Supply Room." << endl;
  cout << endl;

  int quit = 0;

  // Setting start room

  room* currentRoom = Cafeteria;
  while (quit==0) {



    currentRoom->printDescription();
    //currentRoom->printItems();
    //currentRoom->printExitString() ; 
    char input[50];
    
    cout << "Your choices are: GO  QUIT  INVENTORY  GET  DROP " << endl;
    
    cin >> input ;
    if (strcmp(input, "QUIT") == 0) {
      quit = 1;
    } // end of if input == quit
    else if (strcmp(input, "GO")==0) {
      char* direction = new char[10];
      cout << "What direction? " << endl;
      currentRoom->printExitString();
      cin >> direction ;
      room* nextRoom = currentRoom->getExit(direction);
      if (nextRoom==NULL) {
	cout << "There is no room!" << endl;
      }
      else {
	currentRoom = nextRoom;
      
      }
      // check if null
      
    } // end of if input==go
    else if (strcmp(input, "GET" )==0) {
      //add stuff for picking up objects
      cout << "you said get " << endl;
      currentRoom->printItems();
      if (currentRoom->hasItems()==1) {
	cout << "What would you like to pick up?" << endl;
	char itemToPick[20];
	cin >> itemToPick ;
	if (strcmp(itemToPick, "Chocolate") ==0) {
	  cout << "You picked up the chocolate--therefore, you won!" << endl;
	  cout << "Thanks for playing!" << endl;
	  quit = 1;
	}
	inventory->push_back(currentRoom->takeItem(itemToPick));
	
      }
    } // else if input == get

    else if (strcmp(input, "INVENTORY")==0) {
      // cout inventory
      cout << "Inventory:  " ;
      vector<item*>::iterator iter = inventory->begin();
      for (iter; iter<inventory->end(); iter++) {
	cout << (*iter) -> getName() << "   " ;
      }
      cout << endl;
      
    } //end if input=inventory

    else if (strcmp(input, "DROP" ) ==0) {
      cout << "What item would you like to drop? " << endl;
      char toDrop[25];
      cin>>toDrop;
      item* itemToDrop;
      vector<item*>::iterator iter = inventory->begin();
      for (iter; iter<inventory->end() ; iter++) {
	if (strcmp(toDrop, (*iter)->getName() ) ==0) {
	  cout << "Dropping " << (*iter)->getName();
	  itemToDrop = *iter;
	  inventory->erase(iter);
	  currentRoom->dropItem(itemToDrop);
	}
      }
      cout << endl;
    } // end if input  = drop

    


  } // end of while quit ==0
}
