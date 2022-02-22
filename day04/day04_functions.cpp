#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "bingo_board.h"
#include "day04_functions.h"

bool createBoards(std::ifstream& myfile, 
                  std::vector<BingoBoard>& boards)
{
    const int board_size = BingoBoard::numRows * BingoBoard::numCols;
    std::cout << "board_size: " << board_size << std::endl;

    int n {};
    std::vector<int> all_the_numbers;
    while (myfile >> n)
    {
        all_the_numbers.push_back(n);
    }

    std::cout << "all_the_numbers.size(): " << all_the_numbers.size() 
        << std::endl;

    // Check vector size is a multiple of board_size
    if ( (all_the_numbers.size() % board_size) != 0)
    {
        std::cout << "ERROR: all_the_numbers is not a multiple of " 
            << board_size << std::endl;
        return false;
    }

    const int num_boards = all_the_numbers.size() / board_size;
    std::cout << "num_boards: " << num_boards << std::endl;

    // Read in numbers for each board, e.g. a 5x5 board, i.e. 25 numbers

    auto iter = std::begin(all_the_numbers);
    for (int b = 0; b < num_boards; ++b)
    {
        std::vector<int> board_numbers;
        for (int i = 0; i < board_size; ++i)
        {
            board_numbers.push_back(*iter);
            ++iter;
        }

        BingoBoard board(board_numbers);
        boards.push_back(board);
        //std::cout << "Created a board" << std::endl;
    }

    std::cout << "Created " << boards.size() << " boards" << std::endl;

    return true;
}

int playBingo(std::vector<BingoBoard> &boards)
{
    int finalScore {};

    // Read in line of numbers, comma delimited
    std::string draw_numbers;
    std::cin >> draw_numbers;

    std::istringstream iss(draw_numbers);
    int i {};
    int n {};
    while (iss >> n)
    {
        if (iss.peek() == ',')
        {
            iss.ignore();
        }

        //std::cout << "n=" << n << std::endl;

        for (auto& b : boards)
        {
            b.markNumber(n);
        
            if ( b.bingo() )
            {
                std::cout << "Bingo for a board" << std::endl;

                const int sum = b.sumUnmarkedNumbers();
                std::cout << "sum: " << sum << std::endl;
                finalScore = n * sum;
                std::cout << "finalScore = " << finalScore << std::endl;
                return finalScore;
            }
        }
    }

    return finalScore;
}

