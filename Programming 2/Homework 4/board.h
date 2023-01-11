//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//IDE: QT
//CS142
//board.h

#ifndef BOARD_H
#define BOARD_H

#include <vector>
using namespace std;

class Board
{
public:
    Board();
    Board(int,int);
    friend void quickestWayUp(Board&);
    void operator += (int);
    void printsnake();
    void printladder();
private:
    vector<vector<int>> ladders;
    vector<vector<int>> snakes;
    int current_location;
};

#endif // BOARD_H
