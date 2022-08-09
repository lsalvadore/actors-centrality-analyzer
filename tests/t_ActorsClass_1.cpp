#include <iostream>
#include <vector>

#include "ActorsClass.h"
#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"
#include "TitlesClass.h"

using namespace std;

void PrintActors(ActorsClass &ActorsObject, NAME_TYPE Actor)
{
  for(NAME_TYPE i = 0; i < ActorsObject[Actor].size(); i++)
  {
    cout << (ActorsObject[Actor])[i] << endl;
  }
}

int main()
{
  ActorsClass ActorsObject("../" ACTORS, "../" TITLES, "../" TITLES_ACTORS);
  PrintActors(ActorsObject, ALDOFABRIZI);
  cout << "-------" << endl;
  PrintActors(ActorsObject, TONYSHALHOUB);
  return 0;
}
