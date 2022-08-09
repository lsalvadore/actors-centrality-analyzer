#ifndef TITLESCLASS
#define TITLESCLASS

#include <vector>

#include "Constants.h"

using namespace std;

class TitlesClass
{
  vector<NAME_TYPE> *Array;

  TitlesClass(const TitlesClass &Original) = delete;
  TitlesClass &operator=(const TitlesClass &Original) = delete;

  public:

  vector<NAME_TYPE> RealMovies;

  TitlesClass(const char* Filename_Titles, const char* Filename_Titles_Actors);
  ~TitlesClass();
  vector<NAME_TYPE> &operator[](TITLE_TYPE i);
};

#endif
