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
  cout << ActorsObject.Distance(TOTO,FERNANDEL) << endl;
  cout << ActorsObject.Distance(ALDOFABRIZI,FERNANDEL) << endl;
  cout << ActorsObject.Distance(ALDOFABRIZI,TONYSHALHOUB) << endl;
  cout << ActorsObject.Distance(JEANGABIN,NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Distance(SUSUMUFUJITA,NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Distance(TOTO,NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Distance(ALBERTDIEUDONNE,NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Distance(ALBERTDIEUDONNE,JEANTOULOUT) << endl;
  cout << ActorsObject.Distance(ALBERTDIEUDONNE,RAYMEAGHER) << endl;
  cout << ActorsObject.Distance(TOTO,BENITOMUSSOLINI) << endl;
  return 0;
}
