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
  cout << ActorsObject.Harmonic(ALBERTDIEUDONNE) << endl;
  cout << ActorsObject.Harmonic(ALDOFABRIZI) << endl;
  cout << ActorsObject.Harmonic(FERNANDEL) << endl;
  cout << ActorsObject.Harmonic(JEANGABIN) << endl;
  cout << ActorsObject.Harmonic(JEANTOULOUT) << endl;
  cout << ActorsObject.Harmonic(NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Harmonic(RAYMEAGHER) << endl;
  cout << ActorsObject.Harmonic(SUSUMUFUJITA) << endl;
  cout << ActorsObject.Harmonic(TONYSHALHOUB) << endl;
  cout << ActorsObject.Harmonic(TOTO) << endl;
  return 0;
}
