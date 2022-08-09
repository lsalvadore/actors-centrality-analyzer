#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "TitlesClass.h"

using namespace std;

int main()
{
  TitlesClass TitlesObject("../" TITLES, "../" TITLES_ACTORS);
  cout << TitlesObject.RealMovies.size();
  return 0;
}
