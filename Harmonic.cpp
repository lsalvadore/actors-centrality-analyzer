#include <cmath>
#include <iostream>
#include <vector>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void Harmonic(ActorsClass &ActorsObject)
{
  HARMONIC_TYPE  Harmonic,
                  MaxHarmonic = 0;
  vector<NAME_TYPE> Actors;
  HARMONIC_TYPE *HarmonicArray;
  ActorsObject.ApproximatedHarmonicByHybridEstimator(HarmonicArray);
  for(const NAME_TYPE &i: ActorsObject.RealActors)
  {
    Harmonic = HarmonicArray[i];
    if(Harmonic > MaxHarmonic)
    {
      Actors.resize(0);
      Actors.push_back(i);
      MaxHarmonic = Harmonic;
    }
    else if(Harmonic == MaxHarmonic) Actors.push_back(i);
  }
  delete[] HarmonicArray;
  cout << "Harmonic:" << endl;
  for(const NAME_TYPE &i: Actors)
  {
    cout  << "Actor id: " << i
          << "\tActor name: " << GetActorName(ACTORS, i)
          << "\tHarmonic centrality: " << MaxHarmonic << endl;
  }
}
