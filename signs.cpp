#include "signs.hpp"

std::vector<std::tuple<int, int, int, int, std::string>> signs;

void initializeSigns() {
    signs = {
        {140, 175, 160, 190, "The sign reads: This is Carl Seaholm's Data Structures Class final project. He is hopefully using tuple hash-maps in tandem with the coordinates within this photo to accurately depict where you are on this map"},
        {70, 215, 85, 245, "The sign reads: I hear the air conditioning man is afraid of C++"},
        {260, 255, 270, 280, "The sign reads: Hopefully professor reads this and gives me an A!"},
        {195, 0, 220, 0, "If only Carl had more time to do other parts of the map..."}   
    };
}