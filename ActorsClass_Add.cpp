#include "ActorsClass.h"

void ActorsClass::Add(NAME_TYPE Destination, NAME_TYPE Source)
{
  Array[Destination].push_back(Source);
}
