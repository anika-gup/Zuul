#include <iostream>
#include "room.h"
#include "item.h"
#include <string.h>
#include <iterator>
#include <map>
#include <vector>

// ROOM.CPP
using namespace std;

//create vector with items

room::room(char* Description) {
  strcpy(description, Description);
  //description=Description;
  map<char*, room*> exits;
}

void room::dropItem(item* myItem) {
  // item is dropped in room, so vector adds item to it.
  roomInventory->push_back(myItem);
}

item* room::takeItem(char* itemName) {
  // user takes item, so it goes into the vector in main class and gets removed from the vector in room using itemName
  item* itemToReturn;
  vector<item*>::iterator iter = roomInventory->begin();
  int deleted=0;
  for (iter; iter<roomInventory->end() ; iter++) {
    if (strcmp((*iter)->getName(), itemName) ==0) {
      //delete item
      deleted = 1;
      //cout << "Taking: " << (*iter)->getName() << endl;
      itemToReturn = *iter;
      roomInventory->erase(iter);
      return itemToReturn;
      //delete *iter ;
    }
  }
  if (deleted==0) {
    cout << "That item is not available here." << endl;
  }
  return NULL;
  //return myItem;
}

void room::setItem(item* myItem) {
  // for the beginning in main class, you add items to the rooms
  roomInventory->push_back(myItem);
}
int room::hasItems() {
  if (roomInventory->empty()) {
    return 0;
  }
  else {
    return 1;
  }
}
void room::printItems() {
  //cout << "printing items" << endl;
  if (roomInventory->empty()) {
    cout << "There's nothing in this room!" << endl;
  }
  else {
    cout << "Items: " ;
    vector<item*>::iterator iter = roomInventory->begin();
    for (iter; iter < roomInventory->end() ; iter ++) {
      //iter is set up, print out items in roominventory
      cout << (*iter)-> getName() << " "   ; 
    }
  }
  // print out items from vector
  cout << endl ; 
}

void room::setExit(char* Direction, room* Neighbour) {
  exits.insert(pair<char*, room*>(Direction, Neighbour));
}

void room::printExitString() {
  cout << "Exits: " ;
  map<char*, room*> :: iterator iter = exits.begin();
  for (iter; iter != exits.end() ;iter++) {
    cout << iter->first << "  " ;
  }
  cout << endl;
  // figure out iterating through map
}

void room::printDescription() {
  cout << "You are " << description << endl;
}

room* room::getExit(char* Direction) {
  //return (room)exits.get(Direction);
  map<char*, room*> :: iterator iter = exits.begin();
  for (iter; iter != exits.end() ; iter++) {
    if (strcmp(iter->first, Direction)==0) {
      return(iter->second);
    }
  }
  return NULL;
}
