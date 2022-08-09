#ifndef CONSTANTS
#define CONSTANTS

#include <limits>

#define ACTORS            "name.basics.tsv"
#define TITLES            "title.basics.tsv"
#define TITLES_ACTORS     "title.principals.tsv"

#define BETWEENESS_TYPE   double
#define CLOSENESS_TYPE    double
#define DISTANCE_TYPE     int
#define HARMONIC_TYPE     double
#define LIN_TYPE          double
#define NAME_TYPE         unsigned
#define TITLE_TYPE        unsigned

#define MAX_LINE_LENGTH   4096

#define EPSILON                   std::numeric_limits<double>::min()
#define SAMPLES_SIZE_CLOSENESS    100
#define SAMPLES_SIZE_HARMONIC     100
#define SAMPLES_SIZE_LIN          100
#define SAMPLES_SIZE_BETWEENESS   50

#define FILTER_ADULT

#define INVALID_NAME_ID         0

#endif
