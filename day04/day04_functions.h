#include <vector>
#include "bingo_board.h"

bool createBoards(std::ifstream& myfile, 
                  std::vector<BingoBoard>& boards);

int playBingo(std::vector<BingoBoard> &boards);

