#include <gtest/gtest.h>

#include <iostream>
#include <fstream>

#include "day04_functions.h"
#include "bingo_board.h"
 
TEST(Day4Part1Test, GivenTestDataFinalScoreIs4512) 
{ 
    const std::string filename{"../test-boards.txt"}; 
    std::cout << "Opening file " << filename << std::endl;
    std::ifstream myfile(filename);
    int finalScore {};
    std::vector<BingoBoard> boards;
    if ( ! createBoards(myfile, boards) )
    {
        std::cout << "ERROR: Failed to create boards!" << std::endl;
    }
    else
    {
        finalScore = playBingo(boards);
        std::cout << "The final score = " << finalScore << std::endl;
    }

    ASSERT_EQ(finalScore, 4512);
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
