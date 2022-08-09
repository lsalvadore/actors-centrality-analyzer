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
  for(const TITLE_TYPE &i: TitlesObject.RealMovies)
  {
    if(i == GUARDIEELADRI) cout << "found";
  }
  return 0;
}
