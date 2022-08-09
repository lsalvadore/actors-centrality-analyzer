#include <string>

#include "Constants.h"

using namespace std;

NAME_TYPE IsName(string Word)
{
  TITLE_TYPE ReturnValue = 0;
  if(Word.length() < 2 || Word[0] != 'n' || Word[1] != 'm') return 0;
  for(unsigned i = 2; i < Word.length(); i++)
  {
    if(Word[i] < 0x30 || Word[i] > 0x39) return 0;
    ReturnValue = ReturnValue * 10 + Word[i] - 0x30;
  }
  return ReturnValue;
}
