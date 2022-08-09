#include <fstream>
#include <vector>

#include "ActorsClass.h"
#include "Constants.h"

vector<NAME_TYPE> &ActorsClass::operator[](NAME_TYPE i)
{
  return Array[i];
}
