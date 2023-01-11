//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-1.cpp

/*Let n be the size of the matrix row or column*/

#include <iostream>
#include <list>
using namespace std;
//Size of the matrix
#define S 7

//Solves a given maze. Returns "NO SOLUTION" if there isn't any
//Time Complexity: O(n^2) Because the worst case scenario is a matrix with all 1's
void MazeSolver(int Matrix[][S], int Size){

    //Matrix that keeps track of which squares have been visited
    bool isVisited[Size][Size] = {false};

    //Lists that portray stacks. One stores the row index, and the other stores the column index
    //Lists are used for their iterative and popping from the back features
    list<int> StackRow, StackCol;
    int i = 0, j = 0; //i and j keep track of where the maze pointer is positioned
    int cost = 0; //Keeps track of the number of steps taken

    //StackRow and StackCol have 0 pushed as the starting place
    StackRow.push_back(i);
    StackCol.push_back(j);

    //(0,0) is marked as visited
    isVisited[i][j] = true;


    //The maze pointer begins to move. It's main goal is to find a path to the end
    //If there is no path to the end or the number of steps take less than 2*Size + 3
    //Then the function returns "NO SOLUTION" and exits
    while (true){

        //Checks if the two stacks are empty. If they are, then there is no solution.
        if (StackCol.empty() && StackRow.empty()){

            cout << "NO SOUTION!\n";
            return;
        }

        //Checks if the last element entered in both stacks are at the end
        if (StackRow.back() == Size - 1 && StackCol.back() == Size - 1){

            //If the number of steps is greater than 2*Size + 3, then the function has successfully found a way.
            if (cost >= (2 * Size) + 4 || cost <= (2 * Size) + 10)
                break;

            //If the cost is less than 2*Size + 3, then the function returns "NO SOLUTION" and exits
            else{

                cout << "NO SOUTION!\n";
                return;
            }
        }

        //Checks if the right of the current position is not zero
        //and if moving one unit to the right does not exit the maze boundry
        //and if the position to the right not marked as visited
        //If so, then the maze pointer moves one unit to the right
        if (Matrix[i][j + 1] != 0 && j + 1 < Size && !isVisited[i][j + 1]){

            j++; //j is incremented by 1
            isVisited[i][j] = true; //Current position is marked as visited

            //The row index and and the column index have been pushed into their respective stacks
            StackRow.push_back(i);
            StackCol.push_back(j);
            cost++; //The number of steps is incremented
        }

        //Checks if the left of the current position is not zero
        //and if moving one unit to the left does not exit the maze boundry
        //and if the position to the left not marked as visited
        //If so, then the maze pointer moves one unit to the left
        else if (Matrix[i][j - 1] != 0 && j - 1 >= 0 && !isVisited[i][j - 1]){

            j--; //j is decremented by 1
            isVisited[i][j] = true; //Current position is marked as visited

            //The row index and and the column index have been pushed into their respective stacks
            StackRow.push_back(i);
            StackCol.push_back(j);
            cost++;//The number of steps is incremented
        }

        //Checks if the position above the maze pointer is not zero
        //and if moving one unit up does not exit the maze boundry
        //and if the position above the current position not marked as visited
        //If so, then the maze pointer moves one unit up
        else if (Matrix[i - 1][j] != 0 && i - 1 >= 0 && !isVisited[i - 1][j]){

            i--; //i is decremented by 1
            isVisited[i][j] = true; //Current position is marked as visited

            //The row index and and the column index have been pushed into their respective stacks
            StackRow.push_back(i);
            StackCol.push_back(j);
            cost++;//The number of steps is incremented
        }

        //down
        //Checks if the position under the maze pointer is not zero
        //and if moving one unit down does not exit the maze boundry
        //and if the position under the current position not marked as visited
        //If so, then the maze pointer moves one unit up
        else if (Matrix[i + 1][j] != 0 && i + 1 < Size && !isVisited[i + 1][j]){

            i++; //i is incremented by 1
            isVisited[i][j] = true; //Current position is marked as visited

            //The row index and and the column index have been pushed into their respective stacks
            StackRow.push_back(i);
            StackCol.push_back(j);
            cost++;//The number of steps is incremented
        }

        //If the maze pointer reached a dead end, then it back-tracks one position at a time
        else{

            //Both stacks are popped
            StackCol.pop_back();
            StackRow.pop_back();

            //i and j are assigned to the current top, which is the previous position
            i = StackRow.back();
            j = StackCol.back();

            cost--; //The number of steps is decremented by 1
        }
    }

    //iterators for StackRow and StackCol
    list<int>::iterator itRow = StackRow.begin();
    list<int>::iterator itCol = StackCol.begin();

    //Prints the starting position then increments the iterators
    printf("(%d,%d)", *itRow, *itCol); itRow++; itCol++;

    //Goes through the rest of both lists and prints the positions
    while (itRow != StackRow.end() && itCol != StackCol.end()){

        printf(" -> (%d,%d)", *itRow, *itCol);

        //Both iterators are incremented
        itRow++;
        itCol++;
    }

    cout << "\n\nThe number of steps: " << cost << endl;
}

//Prints the matrix
//Time Complexity: O(n^2) since there is a nested loop
void PrintMatrix(int arr[][S], int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}

//Beginning of program
int main(){

    int Matrix[S][S] = {{1,1,1,1,0,1,0},
                        {0,0,0,1,1,1,1},
                        {1,1,1,0,0,0,1},
                        {1,0,1,1,1,1,1},
                        {1,0,0,0,0,0,0},
                        {1,0,0,1,1,1,0},
                        {1,1,1,1,0,1,1}
                       };

    PrintMatrix(Matrix, S);

    MazeSolver(Matrix, S);

    return 0;
}
//End of Program
