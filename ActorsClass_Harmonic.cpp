#include <vector>
#include <queue>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

HARMONIC_TYPE ActorsClass::Harmonic(NAME_TYPE x)
{
  queue<NAME_TYPE> Queue;
  NAME_TYPE Node;
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames];
  HARMONIC_TYPE Harmonic = 0;
  for(const NAME_TYPE &i: RealActors) ActorsDistances[i] = -1;
  Queue.push(x);
  ActorsDistances[x] = 0;
  while(!Queue.empty())
  {
    Node = Queue.front();
    Queue.pop();
    for(const NAME_TYPE &i: Array[Node])
    {
      if(ActorsDistances[i] < 0)
      {
        ActorsDistances[i] = ActorsDistances[Node] + 1;
        Harmonic = Harmonic + 1/HARMONIC_TYPE(ActorsDistances[i]);
        Queue.push(i);
      }
    }
  }
  delete[] ActorsDistances;
  if(!Harmonic) return 0;
  return Harmonic;
}
