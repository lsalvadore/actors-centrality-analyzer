#include <string>
#include <vector>

#include "ActorsClass.h"
#include "Constants.h"

using namespace std;

void Betweeness(ActorsClass &ActorsObject);
void Closeness(ActorsClass &ActorsObject);
void Degree(ActorsClass &ActorsObject);
int Distribute(vector<NAME_TYPE> &Vector,int Left,int Pivot, int Right);
string GetActorName(const char *Filename, NAME_TYPE Id);
NAME_TYPE GetMaxName(const char *Filename);
NAME_TYPE GetName(string Word);
TITLE_TYPE GetTitle(string Word);
void Harmonic(ActorsClass &ActorsObject);
bool IsActorOrActress(string Word);
bool IsMovie(string Word);
void Lin(ActorsClass &ActorsObject);
void SwapNAME_TYPE(NAME_TYPE *A, NAME_TYPE *B);
