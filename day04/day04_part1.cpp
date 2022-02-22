#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "bingo_board.h"
#include "day04_functions.h"

int main (int argc, char *argv[])
{
    assert(argc == 2);

    std::cout << "Opening file " << argv[1] << std::endl;
    std::ifstream myfile(argv[1]);

    std::vector<BingoBoard> boards;
    if ( ! createBoards(myfile, boards) )
    {
        std::cout << "ERROR: Failed to create boards!" << std::endl;
        return 1;
    }

    // Check boards look ok
    /*
    for ( auto b : boards )
    {
        b.print();
        std::cout << std::endl;
    }
    */

    const int finalScore = playBingo(boards);
    std::cout << "The final score = " << finalScore << std::endl;
    
    // Check board markings look ok
    /*
    for ( auto b : boards )
    {
        b.print();
        std::cout << std::endl;
    }
    */

    return 0;
}

