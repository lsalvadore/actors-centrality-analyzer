#include "ActorsClass.h"

void ActorsClass::Link(NAME_TYPE x, NAME_TYPE y)
{
  Add(x,y);
  Add(y,x);
}
