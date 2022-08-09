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
  cout << ActorsObject.Closeness(ALBERTDIEUDONNE) << endl;
  cout << ActorsObject.Closeness(ALDOFABRIZI) << endl;
  cout << ActorsObject.Closeness(FERNANDEL) << endl;
  cout << ActorsObject.Closeness(JEANGABIN) << endl;
  cout << ActorsObject.Closeness(JEANTOULOUT) << endl;
  cout << ActorsObject.Closeness(NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Closeness(RAYMEAGHER) << endl;
  cout << ActorsObject.Closeness(SUSUMUFUJITA) << endl;
  cout << ActorsObject.Closeness(TONYSHALHOUB) << endl;
  cout << ActorsObject.Closeness(TOTO) << endl;
  return 0;
}
