#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void Closeness(ActorsClass &ActorsObject)
{
  CLOSENESS_TYPE  Closeness,
                  MaxCloseness = 0;
  vector<NAME_TYPE> Actors;
  CLOSENESS_TYPE *ClosenessArray;
  ActorsObject.ApproximatedClosenessByHybridEstimator(ClosenessArray);
  for(const NAME_TYPE &i: ActorsObject.RealActors)
  {
    Closeness = ClosenessArray[i];
    if(Closeness > MaxCloseness)
    {
      Actors.resize(0);
      Actors.push_back(i);
      MaxCloseness = Closeness;
    }
    else if(Closeness == MaxCloseness) Actors.push_back(i);
  }
  delete[] ClosenessArray;
  cout << "Closeness:" << endl;
  for(const NAME_TYPE &i: Actors)
  {
    cout  << "Actor id: " << i
          << "\tActor name: " << GetActorName(ACTORS, i)
          << "\tCloseness centrality: " << MaxCloseness << endl;
  }
}
