//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-3.cpp

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class Graph{

public:

    //Constructor
    Graph(int num): Size(num) /*num is assigned to size*/
    {

        //The adjacency matrix is initialised to be all zeros
        AdjMat = new int* [Size];

        for (int i = 0; i < Size; i++){

            AdjMat[i] = new int [Size];
            for (int j = 0; j < Size; j++)
                AdjMat[i][j] = 0;
        }
    }

    //inserts an edge in the graph
    //Time Complexity: O(1) since there are a constant amount of instructions
    void insertEdge(int V1, int V2, int W){

        //The case where the vertices entered are greater than or equal to the Size
        if (V1 >= Size || V2 >= Size){

            cout << "Cannot exceed capacity!\n";
            return;
        }

        //The case where the edge already exists
        if ( AdjMat[V1][V2] != 0 && AdjMat[V2][V1] != 0){

            cout << "This edge already exists!\n";
            return;
        }

        //Assigns an edge to the both vertices
        AdjMat[V1][V2] = W;
        AdjMat[V2][V1] = W;
    }

    //Prints the vertix and all its connected vertices
    //Time Complexity: O(n^2) since there is a nested loop
    void printGraph(){

        //Goes through the matrix and prints all the vertices connected by the vertix i
        for (int i = 0; i < Size; i++){

            cout << "(" << i << ") --> ";

            for (int j = 0; j < Size; j++)

                if (AdjMat[i][j] != 0){

                    cout << j << " ; ";
                }

            cout << endl;
        }
    }

    //Removes an edges from the graph
    //Time Complexity: O(1) Since there is a constant number of instructions
    void removeEdge(int V1, int V2){

        //The case where the vertices entered are greater than or equal to the Size
        if (V1 >= Size || V2 >= Size){

            cout << "Cannot exceed capacity!\n";
            return;
        }

        //The case where the edge already does not exist
        if ( AdjMat[V1][V2] == 0 && AdjMat[V2][V1] == 0){

            cout << "This edge already doesn't exists!\n";
            return;
        }

        //Removes the edge by assigning zero to the vertices
        AdjMat[V1][V2] = 0;
        AdjMat[V2][V1] = 0;
    }

    //Finds the smallest edge while marking it as visited . If there is none, then it returns -1
    //Time Complexity: O(n) since the row length is variable
    int findSmallestEdge(bool arr[], int Row){

        //Min is to find the minimum and chosen_index is to find the index with the minimum value
        int Min = 999, Chosen_Index = -1;

        //Goes through the matrix row to find the minimum unmarked value
        for (int i = 0; i < Size; i++)

            if (AdjMat[Row][i] != 0 && !arr[i] && AdjMat[Row][i] < Min){

                Min = AdjMat[Row][i];
                Chosen_Index = i;
            }

        //Returns the minimum value.
        return Chosen_Index;
    }

    //Finds the shortest path from start to all nodes
    //Time Complexity: O(n^2) since the loop will iterate n times and findSmallestEdge will be called multiple times
    void ShortestPaths(int start){

        /* Parent array is to keep track of the parents
           Dist array is to keep track of the minimum distance
           Visited array is to keep track of which vertices have been visited
           Queue is to push the unvisited and pop the visited vertices and also to keep the loop going
        */

        int Parent[Size];
        int Dist[Size];
        bool Visited[Size];
        queue<int> Q;

        //Initialising all the arrays
        for (int i = 0; i < Size; i++){

            Parent[i] = -1;
            Dist[i] = 9999;
            Visited[i] = false;
        }

        //pushing the start vertex into the queue and the length of the path from the start to itself
        Dist[start] = 0;
        Q.push(start);

        //Goes through all the vertices and finds the shortest path to each
        while (!Q.empty()){

            //Boolean array to keep track of all the visited vertices on the current row
            bool subVisited[Size] = {false};

            //gets the minimum unmarked value index
            int MinValIndex = 0;


            //Finds the edges in ascending order and picks the shortest path while updating the distance array.
            //It stops when MinValIndex is -1
            do{

                //Finds the smallest unmarked edge in the current row
                MinValIndex = findSmallestEdge(subVisited, Q.front());

                //If not all edges are unmarked, then continue
                if (MinValIndex != -1){

                    //current row index is marked as true
                    subVisited[MinValIndex] = true;

                    //If the minimum edge from the current row is less than or equal to its distance from the starting vertex plus itself
                    //then the new distance to the minimum vertex is updated to be the distance from the starting vertex plus
                    //the minimum edge from the current row
                    //Its parent will be updated to be the current row and it will be pushed into the queue
                    if (AdjMat[Q.front()][MinValIndex] + Dist[Q.front()] <= Dist[MinValIndex]){

                        Dist[MinValIndex] = AdjMat[Q.front()][MinValIndex] + Dist[Q.front()];
                        Parent[MinValIndex] = Q.front();
                        Q.push(MinValIndex);
                    }
                }

            }while (MinValIndex != -1);

            //Marks the current row as visited and pops it from the queue
            Visited[Q.front()] = true;
            Q.pop();
        }

        //prints the path from a vertex to the starting vertex
        for (int i = Size - 1; i >= 0; i--){

            int stopping_Cond = i;

            cout << "The shortest path from " << i << " to " << start << " is: " << i;
            while (true){

                if (Parent[stopping_Cond] == -1)
                    break;

                else{

                    cout << " --> " << Parent[stopping_Cond];
                    stopping_Cond = Parent[stopping_Cond];
                }
            }

            cout << endl;
        }

    }

private:

    int** AdjMat;
    int Size;
};

//Beginning of main
int main(){

    Graph g(8);

    g.insertEdge(0,1,3);
    g.insertEdge(1,2,7);
    g.insertEdge(1,3,2);
    g.insertEdge(2,4,1);
    g.insertEdge(2,7,6);
    g.insertEdge(2,3,2);
    g.insertEdge(3,5,4);
    g.insertEdge(3,6,3);

    g.printGraph();

    cout << "\n\nShortest path: \n\n";

    g.ShortestPaths(0);

    return 0;
}
//End of main
