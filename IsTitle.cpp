#include <string>

#include "Constants.h"

using namespace std;

TITLE_TYPE IsTitle(string Word)
{
  TITLE_TYPE ReturnValue = 0;
  if(Word.length() < 2 || Word[0] != 't' || Word[1] != 't') return 0;
  for(unsigned i = 2; i < Word.length(); i++)
  {
    if(Word[i] < 0x30 || Word[i] > 0x39) return 0;
    ReturnValue = ReturnValue * 10 + Word[i] - 0x30;
  }
  return ReturnValue;
}
