#include <iostream>
#include "river.h"

void printRes(std::vector<int> res) {
	std::cout << "[ ";
	for (auto i = res.begin(); i !=res.end(); ++i) 
    	std::cout << *i << " ";
    std::cout << "]\n";
}

int main() {
    river r1 = { // river network in part (a)
	//	 0 1 2 3 4 5 6 7 8 9 10
        {0,0,0,0,0,0,1,0,0,0,0}, // 0
        {0,0,0,1,0,0,0,0,0,0,0}, // 1
        {0,0,0,1,0,0,0,0,0,0,0}, // 2
        {0,0,0,0,0,1,0,0,0,0,0}, // 3
        {0,0,0,0,0,0,0,0,1,0,0}, // 4
        {0,0,0,0,0,0,1,0,0,0,0}, // 5
        {0,0,0,0,0,0,0,1,0,0,0}, // 6
        {0,0,0,0,0,0,0,0,1,1,0}, // 7
        {0,0,0,0,0,0,0,0,0,0,0}, // 8
        {0,0,0,0,0,0,0,0,0,0,1}, // 9
        {0,0,0,0,0,0,0,0,0,0,0}  // 10
    };

    river r2 = { // river network in part (b)
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,1,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0}
    };

    std::vector<int> res1 = start(r1, 7);
    std::vector<int> res2 = start(r1, 8);
	
	
    std::vector<int> res3 = meet(r2, 0, 1);
    std::vector<int> res4 = meet(r2, 0, 8);
    std::vector<int> res5 = meet(r2, 1, 3);
	

    printRes(res1); // should print [ 0 1 2 ]
	printRes(res2); // should print [ 0 1 2 4 ]
	
	
	printRes(res3); // should print [ 4 ]
	printRes(res4); // should print [ ]
	printRes(res5); // should print [ 3 ]
	

	return 0;
}
