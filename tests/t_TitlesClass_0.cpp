#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"
#include "TitlesClass.h"

using namespace std;

int main()
{
  TitlesClass TitlesObject("../" TITLES, "../" TITLES_ACTORS);
  vector<NAME_TYPE> GuardieELadri = TitlesObject[GUARDIEELADRI];
  cout << GuardieELadri.size();
  return 0;
}
