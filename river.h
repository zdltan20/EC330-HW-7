#ifndef _RIVER
#define _RIVER

#include <vector>
#include <utility>
#include <cstddef>

typedef std::vector<std::vector<bool>> river;

std::vector<int> start(river const&, int); 
std::vector<int> meet(river const&, int, int);

#endif