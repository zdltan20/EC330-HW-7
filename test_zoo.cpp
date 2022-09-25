#include <iostream>
#include "escape_zoo.h"

int main() {
    grid zoo = {
        {1,1,1,1},
        {0,0,0,0},
        {1,0,0,1},
        {1,1,0,1}
    };
    motion_plan plan = escape_route(zoo, {2, 2}, North); // the plan should be go_straight, go_left, go_straight

    if (plan.empty())
        std::cout << "No escape!" << std::endl;
    else
        for (Action a : plan)
            switch (a) {
                case go_straight: std::cout << "go_straight" << std::endl; break;
                case go_left:     std::cout << "go_left"     << std::endl;
            }

    return 0;
}
