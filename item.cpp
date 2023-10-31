#include <iostream>
#include "item.h"
#include <string.h>
#include <map>
#include <vector>
// ITEM.CPP
using namespace std;

item::item(char* Name) {
  //name = Name;
  strcpy(name, Name);
  //cout << "name: " << name << endl;
}

char* item::getName() {
  return name;
}

