//problem 0

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

class Graph{

public:

    Graph(int num){

        this->Size = num;

        AdjMat = new int* [Size];
        visited = new bool [Size];

        for (int i = 0; i < Size; i++){

            AdjMat[i] = new int[Size];

            for (int j = 0; j < Size; j++)
                AdjMat[i][j] = 0;
        }

        for (int i = 0; i < Size; i++)
            visited[i] = false;
    }

    void insertEdge(int Vertex1, int Vertex2){

        if (Vertex1 > Size || Vertex2 > Size){

            cout << "You cannot go above the capacity!\n";
            return;
        }

        if (AdjMat[Vertex1][Vertex2] == 1 && AdjMat[Vertex2][Vertex1] == 1){

            cout << Vertex1 << " and " << Vertex2 << " are already connected!\n";
            return;
        }

        AdjMat[Vertex1][Vertex2] = 1;
        AdjMat[Vertex2][Vertex1] = 1;

        printf("(%d) --> (%d)\n", Vertex1, Vertex2);
    }

    void removeEdge(int Vertex1, int Vertex2){

        if (Vertex1 > Size || Vertex2 > Size){

            cout << "No such vertex exists!\n";
            return;
        }

        if (AdjMat[Vertex1][Vertex2] == 0 && AdjMat[Vertex2][Vertex1] == 0){

            cout << Vertex1 << " and " << Vertex2 << " were never connected!\n";
            return;
        }

        AdjMat[Vertex1][Vertex2] = 0;
        AdjMat[Vertex2][Vertex1] = 0;

        printf("(%d) -/-> (%d)\n", Vertex1, Vertex2);
    }

    void printGraph(){

        for (int i = 0; i < Size; i++){

            cout << "(" << i << ") --> ";
            for (int j = 0; j < Size; j++)
                if (AdjMat[i][j] == 1){

                    cout << j << " ; ";
                }

            cout << endl;
        }
    }

    void DFS(int start){

        visited[start] = true;
        cout << start << " ";

        for (int i = 0; i < Size; i++)
            if (AdjMat[start][i] == 1 && visited[i] == false)
                DFS(i);

    }

    void BFS(int start){

        bool isVisited[Size];
        for (int i = 0; i < Size; i++)
            isVisited[i] = false;

        queue<int> Q;
        Q.push(start);
        isVisited[start] = true;

        while (!Q.empty()){

            for (int i = 0; i < Size; i++)
                if (AdjMat[Q.front()][i] == 1 && isVisited[i] == false){

                    Q.push(i);
                    isVisited[i] = true;
                }

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

    Graph g(5);

    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(2,1);
    g.insertEdge(3,1);
    g.insertEdge(3,2);
    g.insertEdge(3,4);
    g.insertEdge(2,4);

    cout << "Printing graph:\n";
    g.printGraph();

    cout << "printing dfs: ";
    g.DFS(3); cout << "\n\n";

    cout << "printing bfs: ";
    g.BFS(3);

    return 0;

}
