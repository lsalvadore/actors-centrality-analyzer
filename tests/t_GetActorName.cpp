#include <iostream>

#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"

using namespace std;

int main()
{
  cout << GetActorName("../" ACTORS, ALDOFABRIZI) << endl;
  cout << GetActorName("../" ACTORS, SEANCONNERY) << endl;
  cout << GetActorName("../" ACTORS, TOTO) << endl;
  return 0;
}
