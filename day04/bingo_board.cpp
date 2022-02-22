#include <iostream>
#include "bingo_board.h"

    
BingoBoard::BingoBoard(const std::vector<int>& numbers)
{
    for (int i = 0; i < numbers.size() ; ++i)
    {
        board[i/numCols][i%numCols].number = numbers[i];
        board[i/numCols][i%numCols].marked = false;
    }
}

void BingoBoard::print() const
{
    for (int row = 0; row < numRows; ++row)
    {
        std::cout << std::endl;
        for (int col = 0; col < numCols; ++col)
        {
            std::cout << board[row][col].number;
            if (board[row][col].marked == true)
            {
                std::cout << "*";
            }
            std::cout << " ";
        }
    }
}

void BingoBoard::markNumber(int n)
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            if (board[row][col].number == n)
            {
                board[row][col].marked = true;
                // Not returning here in case number appears twice on board
            }
        }
    }
    return;
}

bool BingoBoard::bingo() const
{
    return ( rowIsComplete() || columnIsComplete() );
}


bool BingoBoard::rowIsComplete() const
{
    bool isComplete = false;
    for (int row = 0; row < numRows; ++row)
    {
        int count {};
        for (int col = 0; col < numCols; ++col)
        {
            if (board[row][col].marked == true)
            {
                ++count;
            }
        }
        
        if (count == numCols)
        {
            std::cout << "A row is complete" << std::endl;
            isComplete = true;
            break;
        }        
    }

    return isComplete;
}

bool BingoBoard::columnIsComplete() const
{
    bool isComplete = false;
    
    for (int col = 0; col < numCols; ++col)
    {
        int count {};
        for (int row = 0; row < numRows; ++row)
        {
            if (board[row][col].marked == true)
            {
                ++count;
            }
        }
        
        if (count == numRows)
        {
            std::cout << "A column is complete" << std::endl;
            isComplete = true;
            break;
        }        
    }

    return isComplete;
}

int BingoBoard::sumUnmarkedNumbers() const
{
    int sum {};
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            if (board[row][col].marked == false)
            {
                sum += board[row][col].number;
            }
        }
    }

    return sum;
}
