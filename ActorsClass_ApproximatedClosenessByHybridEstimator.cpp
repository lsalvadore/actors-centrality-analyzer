#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>

#include "Constants.h"
#include "Prototypes.h"
#include "ActorsClass.h"

void ActorsClass::ApproximatedClosenessByHybridEstimator
(CLOSENESS_TYPE *&ClosenessArray)
{
unsigned InNodesVectors;
  //Do not delete ClosenessArray: we want to give it to the caller function!
  ClosenessArray = new CLOSENESS_TYPE[NumberOfNames];
  queue<NAME_TYPE> Queue;
  vector<NAME_TYPE> *ListsForActors = new vector<NAME_TYPE>[NumberOfNames],
                    *NodesVectors = new vector<NAME_TYPE>[NumberOfNames],
                    Samples;
  vector<CLOSENESS_TYPE>  Thresholds;
  NAME_TYPE Node,
            *Pivot = new NAME_TYPE[NumberOfNames],
            *LastVisitedSample = new NAME_TYPE[NumberOfNames];
  DISTANCE_TYPE *ActorsDistances = new DISTANCE_TYPE[NumberOfNames],
                *ActorsDistancesFromPivot = new DISTANCE_TYPE[NumberOfNames],
                *BIN = new DISTANCE_TYPE[NumberOfNames],
                *DistancesFromLastVisitedSample
                  = new DISTANCE_TYPE[NumberOfNames],
                *HCSum = new DISTANCE_TYPE[NumberOfNames],
                *HSum = new DISTANCE_TYPE[NumberOfNames],
                *LCSum = new DISTANCE_TYPE[NumberOfNames],
                TailSum;
  vector<DISTANCE_TYPE> *ListsForDistances
    = new vector<DISTANCE_TYPE>[NumberOfNames];
  unsigned  *ConnectedCardinalitySample = new unsigned[NumberOfNames],
            **ConnectedCardinality = new unsigned *[NumberOfNames],
            curt,
            *COUNT = new unsigned[NumberOfNames],
            *HNum = new unsigned[NumberOfNames],
            *LCNum = new unsigned[NumberOfNames],
            TailNum,
            ThresholdsLast;
  srand(time(NULL));
  for(int i = 0; i < SAMPLES_SIZE_CLOSENESS; i++)
  {
      NAME_TYPE k = rand() % RealActors.size();
      Samples.push_back(RealActors[k]);
  }
  for(const NAME_TYPE &i: RealActors)
  {
    ActorsDistancesFromPivot[i] = -1;
    ClosenessArray[i] = 0;
    LCSum[i] = 0;
    HCSum[i] = 0;
    LCNum[i] = 0;
    Pivot[i] = INVALID_NAME_ID;
    ConnectedCardinality[i] = NULL;
  }
  for(const NAME_TYPE &s: Samples)
  {
    Queue.push(s);
    Pivot[s] = s;
    ActorsDistancesFromPivot[s] = 0;
  }
  while(!Queue.empty())
  {
    Node = Queue.front();
    Queue.pop();
    for(const NAME_TYPE &i: Array[Node])
    {
      if(ActorsDistancesFromPivot[i] < 0)
      {
        ActorsDistancesFromPivot[i] = ActorsDistancesFromPivot[Node] + 1;
        Pivot[i] = Pivot[Node];
        Queue.push(i);
      }
    }
  }
  for(const NAME_TYPE &s: Samples)
  {
    curt = 0;
    Thresholds.push_back(0);
    ThresholdsLast = 0;
    for(const NAME_TYPE &i: RealActors) ActorsDistances[i] = -1;
    for(const NAME_TYPE &i: Samples) LastVisitedSample[i] = INVALID_NAME_ID;
    Queue.push(s);
    ActorsDistances[s] = 0;
    LastVisitedSample[s] = s;
    DistancesFromLastVisitedSample[s] = 0;
    ConnectedCardinality[s] = &(ConnectedCardinalitySample[s]);
    ConnectedCardinalitySample[s] = 0;
    while(!Queue.empty())
    {
      Node = Queue.front();
      Queue.pop();
      for(const NAME_TYPE &i: Array[Node])
      {
        if(ActorsDistances[i] < 0)
        {
          ActorsDistances[i] = ActorsDistances[Node] + 1;
          ClosenessArray[s] += ActorsDistances[i];
          ConnectedCardinalitySample[s]++;
          ConnectedCardinality[i] = &(ConnectedCardinalitySample[s]);
          if(i == Pivot[i])
          {
            LastVisitedSample[i] = s;
            DistancesFromLastVisitedSample[i] = ActorsDistances[i];
            for(int z = 0; z < ListsForActors[i].size(); z++)
            {
              if(CLOSENESS_TYPE(ActorsDistances[i]) >
                CLOSENESS_TYPE(ActorsDistancesFromPivot[ListsForActors[i][z]])/CLOSENESS_TYPE(EPSILON))
                HCSum[ListsForActors[i][z]] +=
                  1/CLOSENESS_TYPE(ListsForDistances[i][z]);
              else
              {
                LCSum[ListsForActors[i][z]] +=
                  1/CLOSENESS_TYPE(ListsForDistances[i][z]);
                LCNum[ListsForActors[i][z]]++;
              }
            }
            ListsForActors[i].resize(0);
            ListsForDistances[i].resize(0);
          }
          else
          {
            if(CLOSENESS_TYPE(ActorsDistances[i]) <=
              CLOSENESS_TYPE(ActorsDistancesFromPivot[i])*(1/CLOSENESS_TYPE(EPSILON) - 1) ||
              (s == LastVisitedSample[Pivot[i]] &&
              CLOSENESS_TYPE(DistancesFromLastVisitedSample[Pivot[i]]) <= 
              CLOSENESS_TYPE(ActorsDistancesFromPivot[i])/CLOSENESS_TYPE(EPSILON)))
            {
                LCSum[i] += ActorsDistances[i];
                LCNum[i]++;
            }
            else
            {
              ListsForActors[Pivot[i]].push_back(i);
              ListsForDistances[Pivot[i]].push_back(ActorsDistances[i]);
            }
            if(Pivot[i] == s)
            {
              if(Thresholds.back() != CLOSENESS_TYPE(ActorsDistances[i])/CLOSENESS_TYPE(EPSILON))
              {
                Thresholds.push_back(CLOSENESS_TYPE(ActorsDistances[i])/CLOSENESS_TYPE(EPSILON));
                ThresholdsLast++;
                BIN[ThresholdsLast] = 0;
                COUNT[ThresholdsLast] = 0;
              }
              NodesVectors[ThresholdsLast].push_back(i);
            }
            while(curt < ThresholdsLast &&
              ActorsDistances[i] > Thresholds[curt + 1]) curt++;
            if(ActorsDistances[i] > Thresholds[curt])
            {
              BIN[curt] += ActorsDistances[i];
              COUNT[curt]++;
            }
          }
          Queue.push(i);
        }
      }
    }
    TailSum = 0;
    TailNum = 0;
    for(;ThresholdsLast;ThresholdsLast--)
    {
      TailSum += BIN[ThresholdsLast];
      TailNum += COUNT[ThresholdsLast];
      for(const NAME_TYPE &i: NodesVectors[ThresholdsLast])
      {
        HSum[i] = TailSum;
        HNum[i] = TailNum;
      }
    }
  }
  delete[] BIN;
  delete[] COUNT;
  delete[] ActorsDistances;
  delete[] ActorsDistancesFromPivot;
  delete[] DistancesFromLastVisitedSample;
  delete[] LastVisitedSample;
  delete[] ListsForActors;
  delete[] ListsForDistances;
  delete[] NodesVectors;
  for(const NAME_TYPE &i: RealActors)
  {
    if(!(Pivot[i] == i || Pivot[i] == INVALID_NAME_ID) &&
        *(ConnectedCardinality[i]) > RealActors.size()/2)
    {
      ClosenessArray[i] = HSum[i] +
                          HCSum[i] +
      CLOSENESS_TYPE(
       (- HNum[i] + *(ConnectedCardinality[i]) - SAMPLES_SIZE_CLOSENESS + LCNum[i]) *
          LCSum[i] ) /
          CLOSENESS_TYPE(LCNum[i]);
    }
    else if(Pivot[i] != INVALID_NAME_ID &&
      *(ConnectedCardinality[i]) < RealActors.size()/2) ClosenessArray[i] = 0;
    if(ClosenessArray[i]) ClosenessArray[i] = 1/ClosenessArray[i];
  }
  delete[] ConnectedCardinality;
  delete[] ConnectedCardinalitySample;
  delete[] HCSum;
  delete[] HNum;
  delete[] HSum;
  delete[] LCNum;
  delete[] LCSum;
  delete[] Pivot;
}
