#include <fstream>

#include "Constants.h"
#include "Prototypes.h"

using namespace std;

NAME_TYPE GetMaxName(const char *Filename)
{
  NAME_TYPE  LastName,
             MaxName = 0;
  ifstream File(Filename);
  string Word;
  File.ignore(MAX_LINE_LENGTH,'\n');
  while(File >> Word)
  {
    LastName = GetName(Word);
    if(LastName > MaxName) MaxName = LastName;
    File.ignore(MAX_LINE_LENGTH,'\n');
  }
  return MaxName;
}
