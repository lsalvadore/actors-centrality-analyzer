#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void ActorsClass::ApproximatedBetweenessBySampling
(BETWEENESS_TYPE *&BetweenessArray)
{
  //Do not delete BetweenessArray: we want to give it to the caller function!
  BetweenessArray = new BETWEENESS_TYPE[NumberOfNames];
  BETWEENESS_TYPE *Delta = new BETWEENESS_TYPE[NumberOfNames];
  NAME_TYPE Node;
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames];
  queue<NAME_TYPE> Queue;
  stack<NAME_TYPE> Stack;
  unsigned *Sigma = new unsigned[NumberOfNames];
  vector<NAME_TYPE> *Predecessors;
  vector<NAME_TYPE> Sample;
  srand(time(NULL));
  for(int i = 0; i < SAMPLES_SIZE_BETWEENESS; i++)
  {
      NAME_TYPE k = rand() % RealActors.size();
      Sample.push_back(RealActors[k]);
  }
  for(const NAME_TYPE &v: RealActors) BetweenessArray[v] = 0;
  for(const NAME_TYPE &s: Sample)
  {
    for(const NAME_TYPE &v: RealActors)
    {
      Delta[v] = 0;
      Sigma[v] = 0;
      ActorsDistances[v] = -1;
    }
    Sigma[s] = 1;
    Predecessors = new vector<NAME_TYPE>[NumberOfNames];
    Queue.push(s);
    ActorsDistances[s] = 0;
    while(!Queue.empty())
    {
      Node = Queue.front();
      Queue.pop();
      Stack.push(Node);
      for(const NAME_TYPE &i: Array[Node])
      {
        if(ActorsDistances[i] < 0)
        {
          ActorsDistances[i] = ActorsDistances[Node] + 1;
          Queue.push(i);
        }
        if(ActorsDistances[i] == ActorsDistances[Node] + 1)
        {
          Sigma[i] = Sigma[i] + Sigma[Node];
          Predecessors[i].push_back(Node);
        }
      }
    }
    while(!Stack.empty())
    {
      Node = Stack.top();
      Stack.pop();
      for(const NAME_TYPE &i: Predecessors[Node])
        Delta[i] = Delta[i] +
          BETWEENESS_TYPE(Sigma[i])/BETWEENESS_TYPE(Sigma[Node]) *
          (1 + Delta[Node]);
      if(Node != s) BetweenessArray[Node] = BetweenessArray[Node] + Delta[Node];
    }
    delete[] Predecessors;
  }
  delete[] ActorsDistances;
  delete[] Delta;
  delete[] Sigma;
}
