#include <fstream>
#include <string>

#include "Constants.h"
#include "Prototypes.h"

using namespace std;

string GetActorName(const char *Filename, NAME_TYPE Id)
{
  string  ActorName,
          Word;
  ifstream File(Filename);
  File.ignore(MAX_LINE_LENGTH,'\n');
  while(File >> Word)
  {
    if(GetName(Word) == Id)
    {
      char c;
      File.get();
      do
      {
        c = File.get();
        if(c != '\t') ActorName.push_back(c);
      }
      while(c != '\t');
      return ActorName;
    }
    File.ignore(MAX_LINE_LENGTH,'\n');
  }
  return ActorName;
}
