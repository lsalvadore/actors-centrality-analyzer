#include <iostream>

#include "Constants.h"
#include "Prototypes.h"

using namespace std;

int main()
{
  cout << IsActorOrActress("actor") << endl;
  cout << IsActorOrActress("actress") << endl;
  cout << IsActorOrActress("director") << endl;
  cout << IsActorOrActress("writer,actor") << endl;
  cout << IsActorOrActress("self") << endl;
  return 0;
}
