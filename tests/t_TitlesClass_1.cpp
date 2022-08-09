#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"
#include "TitlesClass.h"

using namespace std;

void CheckActor(NAME_TYPE i)
{
  switch(i)
  {
    case ALDOFABRIZI:
      cout << "Aldo Fabrizi" << endl;
      break;
    case SEANCONNERY:
      cout << "Sean Connery" << endl;
      break;
    case TOTO:
      cout << "Toto'" << endl;
      break;
  }
}

int main()
{
  TitlesClass TitlesObject("../" TITLES, "../" TITLES_ACTORS);
  vector<NAME_TYPE> GuardieELadri = TitlesObject[GUARDIEELADRI];
  vector<NAME_TYPE> HuntForRedOctober = TitlesObject[HUNTFORREDOCTOBER];
  for(int i = 0; i < GuardieELadri.size(); i++)
  {
    CheckActor(GuardieELadri[i]);
  }
  cout << "-----" << endl;
  for(int i = 0; i < HuntForRedOctober.size(); i++)
  {
    CheckActor(HuntForRedOctober[i]);
  }
  return 0;
}
