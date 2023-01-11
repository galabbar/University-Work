//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//IDE: QT
//CS142
//main.cpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <board.h>
using namespace std;

int Rolls = 0;

//Calculates the quickest way up by counting the least amount of rolls needed to win.
void quickestWayUp(Board& Pawn) //Function start
{
    int count = 0;

    //Counts how many snakes are there on the board
    for ( size_t i = 0; i < Pawn.snakes.size(); i++ )
    {
        for ( size_t j = 0; j < Pawn.snakes[i].size(); j++ )
        {
            if ( Pawn.snakes[i][j] != 0)
                count++;
        }
    }

    //Checks if number of snakes is over 15, and if it is, the function stops.
    if ( count/2 > 15 )
    {
        Rolls = -1;
        return;
    }
    int Dice_throw;
    srand(time(NULL)); //Random Number Generator
    while (true) //Counts the rolls and updates the current location
    {
        Rolls++;
        Dice_throw = rand() % 6 + 1; //Simulates dice throw
        if (Pawn.current_location + Dice_throw == 99) //Game ends
            break;
        else if (Pawn.current_location + Dice_throw > 99) /*if the current locationis higher 99, program must
                                                            re-throw the dice */
            continue;
        else //Game is played normally
        {
            Pawn += Dice_throw;

            //Checks if Pawn landed on a ladder's base
            if (Pawn.ladders[Pawn.current_location/10][Pawn.current_location%10] != 0)
            {
                bool areSame = false;

                //Checks for all elements on board if the pawn landed on a ladder's base.
                for ( int i = 0; i < Pawn.ladders.size(); i++ )
                {
                    for ( int j = 0; j < Pawn.ladders[i].size(); j++ )
                    {
                        //Makes sure if the pawn is on ladder's base and not ladder's end
                        if (Pawn.ladders[i][j] == Pawn.ladders[Pawn.current_location/10][Pawn.current_location%10])
                        {
                            //Makes sure pawn doesn't jump to its current location
                            if ( i*10 + j == Pawn.current_location) {continue;}
                            //Makes the Pawn not go down the ladder
                            if ( i*10 + j < Pawn.current_location )
                            {
                                areSame = true;
                                break;
                            }
                            //Pawn landed on a ladder's base, so it changes locations from base to end.
                            Pawn.current_location = i*10 + j;
                            areSame = true;
                            break;
                        }
                    }
                    if (areSame == true)
                       break;
                }
            }
            //Checks if Pawn landed on a snake's mouth
            if (Pawn.snakes[Pawn.current_location/10][Pawn.current_location%10] != 0)
            {
                bool areSame = false;

                //Checks for all elements on board if the pawn landed on a snake's mouth.
                for ( int i = 0; i < Pawn.snakes.size(); i++ )
                {
                    for ( int j = 0; j < Pawn.snakes[i].size(); j++ )
                    {
                        //Makes sure if the pawn is on snake's mouth and not snake's tail
                        if (Pawn.snakes[i][j] == Pawn.snakes[Pawn.current_location/10][Pawn.current_location%10])
                        {
                            //Makes sure pawn doesn't jump to its current location
                            if ( i*10 + j == Pawn.current_location) {continue;}
                            //Makes the Pawn not go up along the snake
                            if ( i*10 + j > Pawn.current_location)
                            {
                                areSame = true;
                                break;
                            }
                            //Pawn landed on snake's mouth, so the pawn changes locations from the snake's mouth to tail
                            Pawn.current_location = i*10 + j;
                            areSame = true;
                            break;
                        }
                }
                    if (areSame == true)
                        break;
            }
        }
     }
   }
} //Function end

int main() //Beginning of program
{
    int trials, LadderNum, SnakeNum;
    cout << "Enter the number of Trials: ";
    cin >> trials;
    Board *Board_Arr = new Board [trials]; //Array of Board objects
    int *Rolls_Arr = new int [trials]; //Array of integers
    for (int i = 0; i < trials; i++ )
    {
        cout << "Enter the number of Ladders and Snakes: ";
        cin >> LadderNum >> SnakeNum;
        Board_Arr[i] = Board(SnakeNum,LadderNum);
        quickestWayUp(Board_Arr[i]);
        Rolls_Arr[i] = Rolls;
        Rolls = 0;
        cout<<"=========== Game Finished! ===========\n"<<endl;
    }
    for ( int i = 0; i < trials; i++ )
        cout<<" For game #"<<i+1<<", the number of rolls needed to win is "<<Rolls_Arr[i]<<endl<<endl;
    //Board_Arr and Rolls_Arr were deleted to reserve memory
    delete [] Board_Arr;
    delete [] Rolls_Arr;
    return 0;
} //End of Program.

