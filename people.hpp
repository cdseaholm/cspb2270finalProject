#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <vector>
#include <tuple>
#include <string>

extern std::vector<std::tuple<int, int, int, int, std::string>> people;

void initializePeople();

#endif