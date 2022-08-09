#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void Lin(ActorsClass &ActorsObject)
{
  LIN_TYPE  Lin,
                  MaxLin = 0;
  vector<NAME_TYPE> Actors;
  LIN_TYPE *LinArray;
  ActorsObject.ApproximatedLinByHybridEstimator(LinArray);
  for(const NAME_TYPE &i: ActorsObject.RealActors)
  {
    Lin = LinArray[i];
    if(Lin > MaxLin)
    {
      Actors.resize(0);
      Actors.push_back(i);
      MaxLin = Lin;
    }
    else if(Lin == MaxLin) Actors.push_back(i);
  }
  delete[] LinArray;
  cout << "Lin:" << endl;
  for(const NAME_TYPE &i: Actors)
  {
    cout  << "Actor id: " << i
          << "\tActor name: " << GetActorName(ACTORS, i)
          << "\tLin centrality: " << MaxLin << endl;
  }
}
