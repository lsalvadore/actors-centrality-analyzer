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
  cout << ActorsObject.Degree(ALBERTDIEUDONNE) << endl;
  cout << ActorsObject.Degree(ALDOFABRIZI) << endl;
  cout << ActorsObject.Degree(FERNANDEL) << endl;
  cout << ActorsObject.Degree(JEANGABIN) << endl;
  cout << ActorsObject.Degree(JEANTOULOUT) << endl;
  cout << ActorsObject.Degree(NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Degree(RAYMEAGHER) << endl;
  cout << ActorsObject.Degree(SUSUMUFUJITA) << endl;
  cout << ActorsObject.Degree(TONYSHALHOUB) << endl;
  cout << ActorsObject.Degree(TOTO) << endl;
  return 0;
}
