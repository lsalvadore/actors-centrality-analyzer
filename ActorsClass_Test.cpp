#include "ActorsClass.h"

bool ActorsClass::Test(NAME_TYPE x, NAME_TYPE y)
{
  for(int i = 0; i < Array[x].size(); i++)
  {
    if(Array[x][i] == y) return true;
  }
  return false;
}
