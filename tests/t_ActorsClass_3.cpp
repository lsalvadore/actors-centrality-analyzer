#include <iostream>

#include "ActorsClass.h"
#include "Constants.h"
#include "TitlesClass.h"

using namespace std;

int main()
{
  ActorsClass ActorsObject("../" ACTORS, "../" TITLES, "../" TITLES_ACTORS);
  cout << ActorsObject.Size();
  return 0;
}
