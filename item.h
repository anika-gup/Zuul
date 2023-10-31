#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <map>
#include <vector>
//ITEM.h
using namespace std;

class item{
 public:
  item(char* Name);
  char* getName();

 protected:
  char* name = new char[30];


};

#endif
