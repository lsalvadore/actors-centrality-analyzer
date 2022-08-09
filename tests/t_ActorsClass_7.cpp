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
  cout << ActorsObject.Lin(ALBERTDIEUDONNE) << endl;
  cout << ActorsObject.Lin(ALDOFABRIZI) << endl;
  cout << ActorsObject.Lin(FERNANDEL) << endl;
  cout << ActorsObject.Lin(JEANGABIN) << endl;
  cout << ActorsObject.Lin(JEANTOULOUT) << endl;
  cout << ActorsObject.Lin(NIKOLAYCHERKASOV) << endl;
  cout << ActorsObject.Lin(RAYMEAGHER) << endl;
  cout << ActorsObject.Lin(SUSUMUFUJITA) << endl;
  cout << ActorsObject.Lin(TONYSHALHOUB) << endl;
  cout << ActorsObject.Lin(TOTO) << endl;
  return 0;
}
