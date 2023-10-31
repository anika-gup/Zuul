#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "item.h"
#include <map>

//ROOM.H

using namespace std;

class room {
 public:
  room(char* Description);
  void dropItem(item* myItem);
  item* takeItem(char* itemName);
  void setItem(item* myItem);
  void printItems();
  void setExit(char* Direction, room* Neighbour);
  void printExitString();
  void printDescription();
  room* getExit(char* Direction);
  int hasItems();
private:
  char* description = new char[30];
  map<char*, room*> exits;
  char Name[35] = "This is my name" ;
  item* testItem = new item(Name);
  vector<item*>* roomInventory = new vector<item*>();
} ;

#endif




