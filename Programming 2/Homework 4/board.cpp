//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//IDE: QT
//CS142
//board.cpp

#include "board.h"
#include <iostream>
#include <vector>
using namespace std;

Board::Board()  //default constructor
{
    //empty
}

Board::Board(int snakeNum,int ladderNum)  //parimeterised constructor
    :ladders(10,vector<int>(10)), snakes(10,vector<int>(10))
{
    int snakeStart, snakeEnd, ladderStart, ladderEnd;
    current_location = 0;
    for (size_t i=0;i<snakes.size();i++) //assigns every element on both vectors to zero
    {
        for (size_t j=0; j<snakes[i].size();j++)
        {
            snakes[i][j]=0;
            ladders[i][j]=0;
        }
    }
    cout << "Enter the number of Ladders: ";
    cout << "Enter two positions (start and end) such that start is less than end, and\nboth don't go over 99 or under 2:\n"<<endl;
    for ( int i = 0; i < ladderNum; i++ ) //makes the user input the start and the end locations for the ladders
    {
        cout << "Enter start and end: ";
        cin >> ladderStart >> ladderEnd;
        while ( ladderStart == 1 || ladderStart == 100)
        {
            cout << "Ladder cannot be placed on first or last location\n\nEnter start: ";
            cin >> ladderStart;
        }
        cout << endl;
        //assigns start and end with the same value for easy searching
        ladders[(ladderStart-1)/10][(ladderStart-1)%10] = i + 1;
        ladders[(ladderEnd-1)/10][(ladderEnd-1)%10] = i + 1;
    }
    cout << "Enter the number of Snakes: ";
    cout << "Enter two positions (start and end) such that end is less than start, and\nboth don't go over 99 or under 2:\n"<<endl;
    for ( int i = 0; i < snakeNum; i++ )//makes the user input the start and the end locations for the snakes
    {
        cout << "Enter start and end: ";
        cin >> snakeStart >> snakeEnd;
        cout << endl;
        //assigns start and end with the same value for easy searching
        snakes[(snakeStart-1)/10][(snakeStart-1)%10] = i + 1;
        snakes[(snakeEnd-1)/10][(snakeEnd-1)%10] = i + 1;
    }
}
//Operator Overloading: makes it possible to add an integer to a Board object.
void Board::operator += (int N)
{
    this->current_location += N;
}
