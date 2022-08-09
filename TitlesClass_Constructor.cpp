#include <fstream>
#include <string>

#include "Prototypes.h"
#include "TitlesClass.h"

TitlesClass::TitlesClass
(const char* Filename_Titles, const char* Filename_Titles_Actors)
{
  NAME_TYPE LastName;
  TITLE_TYPE  LastTitle,
              MaxTitle = 0;
  ifstream File(Filename_Titles);
  string Word;
  File.ignore(MAX_LINE_LENGTH,'\n');
  while(File >> Word)
  {
    LastTitle = GetTitle(Word);
    if(LastTitle > MaxTitle) MaxTitle = LastTitle;
    File >> Word;
    if(IsMovie(Word))
    {
#ifdef  FILTER_ADULT
      File.ignore();
      File.ignore(MAX_LINE_LENGTH,'\t');
      File.ignore(MAX_LINE_LENGTH,'\t');
      if(File.get() == '0') RealMovies.push_back(LastTitle);
#else
      RealMovies.push_back(LastTitle);
#endif
    }
    File.ignore(MAX_LINE_LENGTH,'\n');
  }
  File.close();
  Array = new vector<NAME_TYPE>[MaxTitle];
  File.open(Filename_Titles_Actors);
  File.ignore(MAX_LINE_LENGTH,'\n');
  while(File >> Word)
  {
    LastTitle = GetTitle(Word);
    File >> Word;
    File >> Word;
    LastName = GetName(Word);
    File >> Word;
    if(IsActorOrActress(Word)) Array[LastTitle].push_back(LastName);
    File.ignore(MAX_LINE_LENGTH,'\n');
  }
}
