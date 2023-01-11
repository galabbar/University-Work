//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-0.cpp

/*Let V be the number of vertices and E be the number of Edges*/

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class Graph{

public:

    //Contructor
    Graph(int num){

        //num is assigned to size
        this->Size = num;

        //Adjacency matrix is assigned to be all 0's
        AdjMat = new int* [Size];

        //Boolean Visited array for depth first search is initialised to be all false
        visited = new bool [Size];

        for (int i = 0; i < Size; i++){

            AdjMat[i] = new int[Size];

            for (int j = 0; j < Size; j++)
                AdjMat[i][j] = 0;
        }

        for (int i = 0; i < Size; i++)
            visited[i] = false;
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
        if (Vertex1 > Size || Vertex2 > Size){

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

    //Prints the graph as a depth first search tree
    //Time Complexity: O(V + E) Since it goes through all the vertices and edges
    void DFS(int start){

        //The starting vertex is marked as visited and is printed
        visited[start] = true;
        cout << start << " ";

        //Goes through the rest of the vertices
        for (int i = 0; i < Size; i++)

            //If the current vertex is not 0 and is not marked as visited,
            //then the current vertex is treated as the starting vertex and the function is called recursively
            if (AdjMat[start][i] == 1 && visited[i] == false)
                DFS(i);

    }

    //Prints the graph as a breadth first search tree
    //Time Complexity: O(V + E) Since it goes through all the vertices and edges
    void BFS(int start){

        //Boolean visited array to keep track on which vertices have been visited.
        //It is initialised to false
        bool isVisited[Size];
        for (int i = 0; i < Size; i++)
            isVisited[i] = false;

        //Queue to keep the loop going and to print the vertices as a BFS traversal
        queue<int> Q;

        //The starting vertex is pushed and is marked as visited
        Q.push(start);
        isVisited[start] = true;

        //Goes through the rest of the graph and prints it as a breadth first search tree
        while (!Q.empty()){

            //Goes through the graph and checks if the queue front's neighbors are not zero and have not been visited
            for (int i = 0; i < Size; i++)

                //The case where the queue front's neighbors are not zero and have not been visited
                if (AdjMat[Q.front()][i] == 1 && isVisited[i] == false){

                    //The current vertex is pushed into the queue and is marked as visited
                    Q.push(i);
                    isVisited[i] = true;
                }

            //The queue front is printed then popped
            cout << Q.front() << " ";
            Q.pop();
        }
    }

private:

    int **AdjMat;
    bool *visited;
    int Size;
};



int main(){

    Graph g(6);

    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(0,3);
    g.insertEdge(1,5);
    g.insertEdge(2,3);
    g.insertEdge(2,4);

    cout << "Printing graph:\n";
    g.printGraph();

    cout << "printing dfs: ";
    g.DFS(0); cout << "\n\n";

    cout << "printing bfs: ";
    g.BFS(0);

    return 0;

}
