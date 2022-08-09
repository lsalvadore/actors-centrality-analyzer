#include <iostream>
#include <vector>

#include "ActorsClass.h"
#include "Constants.h"
#include "Prototypes.h"
#include "TestsData.h"
#include "TitlesClass.h"

using namespace std;

void PrintActorsNumber(ActorsClass &ActorsObject, NAME_TYPE Actor)
{
  cout << ActorsObject[Actor].size() << endl;
}

int main()
{
  ActorsClass ActorsObject("../" ACTORS, "../" TITLES, "../" TITLES_ACTORS);
  cout << "Aldo Fabrizi: ";
  PrintActorsNumber(ActorsObject, ALDOFABRIZI);
  cout << "Benito Mussolini: ";
  PrintActorsNumber(ActorsObject, BENITOMUSSOLINI);
  cout << "Chuck Norris: ";
  PrintActorsNumber(ActorsObject, CHUCKNORRIS);
  cout << "Leonard Nimoy: ";
  PrintActorsNumber(ActorsObject, LEONARDNIMOY);
  cout << "Peter Falk: ";
  PrintActorsNumber(ActorsObject, PETERFALK);
  cout << "Ray Meagher: ";
  PrintActorsNumber(ActorsObject, RAYMEAGHER);
  cout << "Sean Connery: ";
  PrintActorsNumber(ActorsObject, SEANCONNERY);
  cout << "Tony Shalhoub: ";
  PrintActorsNumber(ActorsObject, TONYSHALHOUB);
  cout << "Toto: ";
  PrintActorsNumber(ActorsObject, TOTO);
  return 0;
}
