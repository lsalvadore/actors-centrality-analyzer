#include <vector>
#include <queue>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

LIN_TYPE ActorsClass::Lin(NAME_TYPE x)
{
  queue<NAME_TYPE> Queue;
  NAME_TYPE Node;
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames];
  unsigned ConnectedCardinality = 0;
  LIN_TYPE  Sum = 0;
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
        ConnectedCardinality++;
        Queue.push(i);
      }
    }
  }
  delete[] ActorsDistances;
  if(!Sum) return 0;
  return (ConnectedCardinality * ConnectedCardinality)/LIN_TYPE(Sum);
}
