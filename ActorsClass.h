#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <vector>

#include "Constants.h"
#include "TitlesClass.h"

class ActorsClass
{
  NAME_TYPE NumberOfNames;
  vector<NAME_TYPE> *Array;
  void Add(NAME_TYPE Destination, NAME_TYPE Source);

  ActorsClass(const ActorsClass &Original) = delete;
  ActorsClass &operator=(const ActorsClass &Original) = delete;

  public:

  vector<NAME_TYPE> RealActors;

  ActorsClass
    (const char *Filename_Actors, const char *Filename_Titles,
    const char *Filename_Titles_Actors);
  ~ActorsClass();
  vector<NAME_TYPE> &operator[](NAME_TYPE i);

  BETWEENESS_TYPE Betweeness(NAME_TYPE x);
  void ApproximatedBetweenessBySampling(BETWEENESS_TYPE *&BetweenessArray);
  BETWEENESS_TYPE ApproximatedBetweenessBySampling(NAME_TYPE x);

  CLOSENESS_TYPE Closeness(NAME_TYPE x);
  void ApproximatedClosenessByHybridEstimator(CLOSENESS_TYPE *&ClosenessArray);

  HARMONIC_TYPE Harmonic(NAME_TYPE x);
  void ApproximatedHarmonicByHybridEstimator(HARMONIC_TYPE *&HarmonicArray);

  LIN_TYPE Lin(NAME_TYPE x);
  void ApproximatedLinByHybridEstimator(LIN_TYPE *&LinArray);

  unsigned  Degree(NAME_TYPE x);
  DISTANCE_TYPE Distance(NAME_TYPE x, NAME_TYPE y);
  void Link(NAME_TYPE x, NAME_TYPE y);
  bool Test(NAME_TYPE x, NAME_TYPE y);
  NAME_TYPE Size();
};

#endif
