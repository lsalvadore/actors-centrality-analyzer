#include <iostream>

#include "ActorsClass.h"
#include "Prototypes.h"
#include "TitlesClass.h"

using namespace std;

int main(int argc, char **argv)
{
  unsigned Choice;
  NAME_TYPE ActorId, ActorIdBis;
  cout << "Please choose an option:\n"
          "--------------------------------------------------------------\n"
          "0 - Single node - All centralities\n"
          "1 - Single node - Degree centrality\n"
          "2 - Single node - Closeness centrality\n"
          "3 - Single node - Lin centrality\n"
          "4 - Single node - Harmonic centrality\n"
          "5 - Single node - Betweeness centrality (approximation by sampling)\n"
          "--------------------------------------------------------------\n"
          "9 - Distance between two actors\n"
          "--------------------------------------------------------------\n"
          "10 - Get maximums - All centralities\n"
          "11 - Get maximums - Degree centrality\n"
          "12 - Get maximums - Closeness centrality (approximation by hybrid estimator, forced into largest connected component)\n"
          "13 - Get maximums - Lin centrality (approximation by hybrid estimator, forced into largest connected component)\n"
          "14 - Get maximums - Harmonic centrality (approximation by hybrid estimator, forced into largest connected component)\n"
          "15 - Get maximums - Betweeness centrality (approximation by sampling)\n"
          "--------------------------------------------------------------\n"
          "20 - Number of actors\n"
          "--------------------------------------------------------------\n"
          "Choice: ";
  cin >> Choice;
  if( Choice != 0 &&
      Choice != 1 &&
      Choice != 2 &&
      Choice != 3 &&
      Choice != 4 &&
      Choice != 5 &&
      Choice != 9 &&
      Choice != 10 &&
      Choice != 11 &&
      Choice != 12 &&
      Choice != 13 &&
      Choice != 14 &&
      Choice != 15 &&
      Choice != 20 )
  {
      cerr << "Invalid choice. Terminating." << endl;
      return 1;
  }
  if(Choice < 10)
  {
    cout << "Insert actor id (the number after nm): ";
    cin >> ActorId;
  }
  if(Choice == 9)
  {
      cout << "Insert other actor id (the number after nm): ";
      cin >> ActorIdBis;
  }
  cout << "Building actors graph..." << flush;
  ActorsClass ActorsObject(ACTORS, TITLES, TITLES_ACTORS);
  cout << "done." << endl << flush;
  switch(Choice)
  {
    case 0:
      cout << "Degree: " << ActorsObject.Degree(ActorId) << endl;
      cout << "Closeness: " << ActorsObject.Closeness(ActorId) << endl;
      cout << "Lin: " << ActorsObject.Lin(ActorId) << endl;
      cout << "Harmonic: " << ActorsObject.Harmonic(ActorId) << endl;
      cout  << "Betweeness: "
            << ActorsObject.ApproximatedBetweenessBySampling(ActorId) << endl;
      break;
    case 1:
      cout << "Degree: " << ActorsObject.Degree(ActorId) << endl;
      break;
    case 2:
      cout << "Closeness: " << ActorsObject.Closeness(ActorId) << endl;
      break;
    case 3:
      cout << "Lin: " << ActorsObject.Lin(ActorId) << endl;
      break;
    case 4:
      cout << "Harmonic: " << ActorsObject.Harmonic(ActorId) << endl;
      break;
    case 5:
      cout  << "Betweeness: "
            << ActorsObject.ApproximatedBetweenessBySampling(ActorId) << endl;
      break;
    case 9:
      cout << ActorsObject.Distance(ActorId,ActorIdBis) << endl;
      break;
    case 10:
      Degree(ActorsObject);
      Closeness(ActorsObject);
      Lin(ActorsObject);
      Harmonic(ActorsObject);
      Betweeness(ActorsObject);
      break;
    case 11:
      Degree(ActorsObject);
      break;
    case 12:
      Closeness(ActorsObject);
      break;
    case 13:
      Lin(ActorsObject);
      break;
    case 14:
      Harmonic(ActorsObject);
      break;
    case 15:
      Betweeness(ActorsObject);
      break;
    case 20:
      cout << ActorsObject.RealActors.size() << endl;
      break;
    default:
      cerr << "Hey, how did you get there?!" << endl;
  }
  return 0;
}
