#include <vector>
#include <queue>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

CLOSENESS_TYPE ActorsClass::Closeness(NAME_TYPE x)
{
  queue<NAME_TYPE> Queue;
  NAME_TYPE Node;
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames];
  CLOSENESS_TYPE  Sum = 0;
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
        Sum = Sum + ActorsDistances[i];
        Queue.push(i);
      }
    }
  }
  delete[] ActorsDistances;
  if(!Sum) return 0;
  return 1/CLOSENESS_TYPE(Sum);
}
