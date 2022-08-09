#include <iostream>
#include <vector>

#include "ActorsClass.h"
#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"
#include "TitlesClass.h"

using namespace std;

int main()
{
  ActorsClass ActorsObject("../" ACTORS, "../" TITLES, "../" TITLES_ACTORS);
  cout << ActorsObject.Test(TOTO,ALDOFABRIZI) << endl;
  cout << ActorsObject.Test(TOTO,SEANCONNERY);
  return 0;
}
