#include <string>

#include "Constants.h"

using namespace std;

TITLE_TYPE GetTitle(string Word)
{
  TITLE_TYPE ReturnValue = 0;
  for(unsigned i = 2; i < Word.length(); i++)
    ReturnValue = ReturnValue * 10 + Word[i] - 0x30;
  return ReturnValue;
}
