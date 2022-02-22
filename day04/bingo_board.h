// A bingo board is a 2D array of 5x5 squares

#ifndef BINGO_BOARD_H
#define BINGO_BOARD_H

#include <cstddef>
#include <vector>

class BingoBoard
{
public:
    static constexpr size_t numRows=5;
    static constexpr size_t numCols=5;

    //BingoBoard() = default;
    BingoBoard(const std::vector<int>&);

    BingoBoard(BingoBoard&&) = default;                 // move ctr
    BingoBoard& operator=(BingoBoard&&) = default;      // move assignment
    
    BingoBoard(const BingoBoard&) = default;            // copy ctr
    BingoBoard& operator=(const BingoBoard&) = default; // copy assignment

    ~BingoBoard() = default;

    void markNumber(int num);
    void print() const;
    int sumUnmarkedNumbers() const;

    bool bingo() const; // True if a row or column is complete, i.e. bingo!

private:

    struct Number
    {
        int number;
        bool marked;
    };

    Number board[numRows][numCols];

    bool rowIsComplete() const;
    bool columnIsComplete() const;
};

#endif // BINGO_BOARD_H

