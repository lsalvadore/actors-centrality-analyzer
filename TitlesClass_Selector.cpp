#include <fstream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "TitlesClass.h"

vector<NAME_TYPE> &TitlesClass::operator[](TITLE_TYPE i)
{
  return Array[i];
}
