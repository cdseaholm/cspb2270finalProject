#include "obstacles.hpp"

std::vector<std::tuple<int, int, int, int>> obstacles;

void initializeObstacles() {
    obstacles = {
        //border
        {20, 20, 20, 315}, // starting top left border moves down left y 
        {20, 315, 80, 315},  // moves bottom x right to adjacent opening towards fence
        {80, 315, 80, 325}, // moves down treeline towards fence
        {80, 325, 105, 325}, // moves right along first fence to lake
        {105, 280, 105, 325}, // left side lake up
        {105, 280, 170, 280}, // top lake right
        {170, 280, 170, 325}, // right side lake down
        {170, 325, 290, 325}, // fence line to tree
        {290, 315, 290, 325}, //slgithy movement up to adjacent tree line
        {290, 315, 360, 315}, //right towards right trees
        {360, 25, 360, 315}, //moves up along y right
        {225, 25, 360, 25}, //moves left towards opening along top tree
        {225, 0, 225, 25}, //moves up into gap
        {190, 0, 190, 20}, //skipping gap then moving down tree line
        {20, 20, 190, 20}, //moving left towards start

        //inmap fences
        {70, 175, 70, 190},
        {70, 175, 160, 175},
        {160, 175, 160, 190},
        {70, 190, 160, 190},
        {205, 260, 205, 275},
        {205, 260, 310, 260},
        {310, 260, 310, 275},
        {205, 275, 310, 275},


        //buildings
        {70, 50, 70, 100}, //top left building, left side
        {50, 100, 70, 100}, //top mailbox
        {50, 100, 50, 120}, // left side mailbox
        {50, 120, 155, 120}, //top left, bottom
        {70, 50, 160, 50},
        {160, 50, 160, 70},
        {160, 70, 170, 70},
        {170, 70, 175, 90},
        {155, 90, 175, 90},
        {155, 90, 155, 120},
        {220, 50, 220, 100}, // top right building, right side
        {200, 100, 220, 100}, // right mailbox
        {200, 100, 200, 125}, // left side mailbox
        {200, 120, 305, 120}, // top right, bottom
        {220, 50, 310, 50},
        {305, 90, 305, 120},
        {205, 150, 325, 150},
        {325, 150, 325, 225},
        {205, 150, 205, 235},
        {205, 235, 225, 235},
        {225, 225, 225, 235},
        {225, 225, 325, 225},


        //people
        {70, 220, 70, 240}, //air conditioning man
        {70, 240, 105, 240},
        {70, 220, 105, 220},
        {105, 220, 105, 240},
        {260, 305, 275, 305}, //gardner
        {275, 305, 275, 320},
        {260, 305, 260, 320},
        {205, 290, 205, 305}, //old man in the way
        {205, 290, 225, 290},
        {225, 290, 225, 305},
        {205, 305, 225, 305}
    };
}