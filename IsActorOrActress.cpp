#include <string>

#include "Constants.h"

using namespace std;

bool IsActorOrActress(string Word)
{
  int i = 0;
  while(i < int(Word.length()) - 6)
  {
    if  (Word[i + 0] == 'a' &&
         Word[i + 1] == 'c' &&
         Word[i + 2] == 't' &&
         ((Word[i + 3] == 'o' &&
           Word[i + 4] == 'r') ||
          (Word[i + 3] == 'r' &&
           Word[i + 4] == 'e' &&
           Word[i + 5] == 's' &&
           Word[i + 6] == 's'))) return true;
    i++;
  }
  while(i < int(Word.length()) - 4)
  {
    if  (Word[i + 0] == 'a' &&
         Word[i + 1] == 'c' &&
         Word[i + 2] == 't' &&
         Word[i + 3] == 'o' &&
         Word[i + 4] == 'r') return true;
    i++;
  }
  return false;
}
