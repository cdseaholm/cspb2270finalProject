#include "people.hpp"

std::vector<std::tuple<int, int, int, int, std::string>> people;

void initializePeople() {
    people = {
        {160, 65, 175, 95, "Old lady by Carl's home says: Have you seen that Carl? Boy can he sure code... I hope he comes by here soon."},
        {90, 215, 105, 245, "Air Conditioning Man says: The great thing about Air Conditioners is they don't make me learn C++!"},
        {200, 230, 230, 240, "Gary Admirer says: What is so great about Carl? I remember the old days when Gary was the best..."},
        {205, 285, 225, 310, "Old man in the way says: I think that kid up there defaced that sign above the gardner... shame."},
        {260, 300, 280, 320, "Gardner says: I'm just a gardner... I wish I went back to school like Carl."}  
    };
}