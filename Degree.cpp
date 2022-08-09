#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void Degree(ActorsClass &ActorsObject)
{
  unsigned Degree,
           MaxDegree = 0;
  vector<NAME_TYPE> Actors;
  for(const NAME_TYPE &i: ActorsObject.RealActors)
  {
    Degree = ActorsObject.Degree(i);
    if(Degree > MaxDegree)
    {
      Actors.resize(0);
      Actors.push_back(i);
      MaxDegree = Degree;
    }
    else if(Degree == MaxDegree) Actors.push_back(i);
  }
  cout << "Degree:" << endl;
  for(const NAME_TYPE &i: Actors)
  {
    cout  << "Actor id: " << i
          << "\tActor name: " << GetActorName(ACTORS, i)
          << "\tDegree centrality: " << MaxDegree << endl;
  }
}
