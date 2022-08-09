#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void Betweeness(ActorsClass &ActorsObject)
{
  BETWEENESS_TYPE  Betweeness,
                  MaxBetweeness = 0;
  vector<NAME_TYPE> Actors;
  BETWEENESS_TYPE *BetweenessArray;
  ActorsObject.ApproximatedBetweenessBySampling(BetweenessArray);
  for(const NAME_TYPE &i: ActorsObject.RealActors)
  {
    Betweeness = BetweenessArray[i];
    if(Betweeness > MaxBetweeness)
    {
      Actors.resize(0);
      Actors.push_back(i);
      MaxBetweeness = Betweeness;
    }
    else if(Betweeness == MaxBetweeness) Actors.push_back(i);
  }
  delete[] BetweenessArray;
  cout << "Betweeness:" << endl;
  for(const NAME_TYPE &i: Actors)
  {
    cout  << "Actor id: " << i
          << "\tActor name: " << GetActorName(ACTORS, i)
          << "\tBetweeness centrality: " << MaxBetweeness << endl;
  }
}
