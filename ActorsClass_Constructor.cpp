#include "ActorsClass.h"
#include "Prototypes.h"
#include "TitlesClass.h"

ActorsClass::ActorsClass
(const char *Filename_Actors, const char *Filename_Titles,
const char *Filename_Titles_Actors)
{
  TitlesClass TitlesObject(Filename_Titles, Filename_Titles_Actors);
  NumberOfNames = GetMaxName(Filename_Actors);
  Array = new vector<NAME_TYPE>[NumberOfNames];
  for(const TITLE_TYPE &i: TitlesObject.RealMovies)
  {
    for(NAME_TYPE j = 0; j < TitlesObject[i].size(); j++)
    {
      for(NAME_TYPE k = j; k < TitlesObject[i].size(); k++)
      {
        Link(TitlesObject[i][j],TitlesObject[i][k]);
      }
    }
  }
  for(NAME_TYPE h = 1; h < NumberOfNames; h++)
  {
    if(Array[h].size()) RealActors.push_back(h);
  }
}
