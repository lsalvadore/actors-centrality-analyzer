#include <string>

#include "Constants.h"

using namespace std;

bool IsMovie(string Word)
{
  return  Word.length() == 5 &&
          Word[0] == 'm' &&
          Word[1] == 'o' &&
          Word[2] == 'v' &&
          Word[3] == 'i' &&
          Word[4] == 'e';
}
