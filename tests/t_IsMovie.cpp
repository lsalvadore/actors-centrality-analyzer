#include <iostream>

#include "Constants.h"
#include "Prototypes.h"

using namespace std;

int main()
{
  cout << IsMovie("hello world!") << endl;
  cout << IsMovie("movie") << endl;
  cout << IsMovie("short");
  return 0;
}
