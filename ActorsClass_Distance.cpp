#include <queue>

#include "ActorsClass.h"
#include "Constants.h"

DISTANCE_TYPE ActorsClass::Distance(NAME_TYPE x, NAME_TYPE y)
{
  queue<NAME_TYPE> Queue;
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames];
  NAME_TYPE Node;
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
        if(i == y) return ActorsDistances[i];
        Queue.push(i);
      }
    }
  }
  return -1;
}
