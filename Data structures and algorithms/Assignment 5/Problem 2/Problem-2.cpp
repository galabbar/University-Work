//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Problem-2.cpp

/*Let n be the number of rows or columns in the matrix*/

#include <iostream>
#include <stdio.h>
using namespace std;

class Graph{

public:

    //Constructor
    Graph(int num): Size(num)/*num is assigned to size*/
    {

        //The adjacency matrix is initialised to be all zeros
        AdjMat = new int* [Size];

        for (int i = 0; i < Size; i++){

            AdjMat[i] = new int[Size];

            for (int j = 0; j < Size; j++)
                AdjMat[i][j] = 0;
        }
    }

    //inserts an edge in the graph
    //Time Complexity: O(1) since there are a constant amount of instructions
    void insertEdge(int Vertex1, int Vertex2){

        //The case where the vertices entered are greater than or equal to the Size
        if (Vertex1 >= Size || Vertex2 >= Size){

            cout << "You cannot go above the capacity!\n";
            return;
        }

        //The case where the edge already exists
        if (AdjMat[Vertex1][Vertex2] == 1 && AdjMat[Vertex2][Vertex1] == 1){

            cout << Vertex1 << " and " << Vertex2 << " are already connected!\n";
            return;
        }

        //Assigns an edge to the both vertices
        AdjMat[Vertex1][Vertex2] = 1;
        AdjMat[Vertex2][Vertex1] = 1;

        printf("(%d) --> (%d)\n", Vertex1, Vertex2);
    }

    //Removes an edges from the graph
    //Time Complexity: O(1) Since there is a constant number of instructions
    void removeEdge(int Vertex1, int Vertex2){

        //The case where the vertices entered are greater than or equal to the Size
        if (Vertex1 >= Size || Vertex2 >= Size){

            cout << "No such vertex exists!\n";
            return;
        }

        //The case where the edge already does not exist
        if (AdjMat[Vertex1][Vertex2] == 0 && AdjMat[Vertex2][Vertex1] == 0){

            cout << Vertex1 << " and " << Vertex2 << " were never connected!\n";
            return;
        }

        //Removes the edge by assigning zero to the vertices
        AdjMat[Vertex1][Vertex2] = 0;
        AdjMat[Vertex2][Vertex1] = 0;

        printf("(%d) -/-> (%d)\n", Vertex1, Vertex2);
    }

    //Prints the vertix and all its connected vertices
    //Time Complexity: O(n^2) since there is a nested loop
    void printGraph(){

        //Goes through the matrix and prints all the vertices connected by the vertix i
        for (int i = 0; i < Size; i++){

            cout << "(" << i << ") --> ";

            for (int j = 0; j < Size; j++)

                if (AdjMat[i][j] == 1){

                    cout << j << " ; ";
                }

            cout << endl;
        }
    }

    //Checks if the graph is complete. Returns true if it is complete. Otherwise, returns false
    //Time Complexity: O(n^2) since there is a nested loop
    bool isComplete(){

        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (AdjMat[i][j] == 0)
                    return false;

        return true;

    }

private:

    int **AdjMat;
    int Size;
};

//Beginning of program
int main(){

    Graph g(5);

    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(0,3);
    g.insertEdge(0,4);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(1,4);
    g.insertEdge(2,3);
    g.insertEdge(2,4);
    g.insertEdge(3,4);

    cout << "\nprinting graph: \n";
    g.printGraph();

    cout << "\n\nIs the graph complete? The answer is: ";
    if (g.isComplete())
        cout << "True!\n";
    else
        cout << "False!\n";

    return 0;
}
//End of program
