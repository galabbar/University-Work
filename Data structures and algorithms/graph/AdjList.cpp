#include <iostream>
#include <stdio.h>
#include <queue>
#include <list>
using namespace std;

bool search(list<int> List, int data){

    if (List.empty())
        return false;

    list<int>::iterator it;
    for (it = List.begin(); it != List.end(); it++)
        if (*it == data)
            return true;

    return false;
}

void Remove(list<int>& List, int data){

    if (List.empty())
        return;

    list<int>::iterator it;
    for (it = List.begin(); it != List.end(); it++)
        if (*it == data){

            List.erase(it);
            return;
        }
}

class Graph{

public:

    Graph(int num){

        this->Size = num;
        AdjList = new list<int> [Size];

        visited = new bool [Size];
        for (int i = 0; i < Size; i++)
            visited[i] = false;
    }

    void InsertEdge(int V1, int V2){

        if (V1 >= Size || V2 >= Size){

            cout << "Cannot go beyond the capacity!\n";
            return;
        }

        if (search(AdjList[V1],V2) && search(AdjList[V2],V1)){

            cout << "The two verteces are already connected!\n";
            return;
        }

        AdjList[V1].push_back(V2);
        AdjList[V2].push_back(V1);

        printf("(%d) --> (%d)\n", V1, V2);
    }

    void RemoveEdge(int V1, int V2){

        if (V1 >= Size || V2 >= Size){

            cout << "Cannot go beyond the capacity!\n";
            return;
        }

        if (!search(AdjList[V1],V2) && !search(AdjList[V2],V1)){

            cout << "The two verteces were never connected!\n";
            return;
        }

        Remove(AdjList[V1], V2);
        Remove(AdjList[V2], V1);

        printf("(%d) -/-> (%d)\n", V1, V2);
    }

    void printGraph(){

        for (int i = 0; i < Size; i++){

            printf("(%d) --> ", i);

            list<int>::iterator it;
            for(it = AdjList[i].begin(); it != AdjList[i].end(); it++)
                cout << *it << " ; ";

            cout << endl;
        }
    }

    void DFS(int start){

        visited[start] = true;

        cout << start << " ";

        list<int>::iterator it = AdjList[start].begin();
        for (it; it != AdjList[start].end(); it++)
            if (visited[*it] == false)
                DFS(*it);
    }

    void BFS(int start){

        bool isVisited[Size];
        for (int i = 0; i < Size; i++)
            isVisited[i] = false;

        queue<int> Q;
        Q.push(start);
        isVisited[start] = true;

        while (!Q.empty()){

            list<int>::iterator it = AdjList[Q.front()].begin();
            for (; it != AdjList[Q.front()].end(); it++)
                if (isVisited[*it] == false){

                    isVisited[*it] = true;
                    Q.push(*it);
                }

            cout << Q.front() << " ";
            Q.pop();
        }
    }

private:

    list<int>* AdjList;
    bool *visited;
    int Size;


};

int main(){

    Graph g(6);

    g.InsertEdge(0,4);
    g.InsertEdge(0,1);
    g.InsertEdge(1,3);
    g.InsertEdge(1,2);
    g.InsertEdge(2,4);
    g.InsertEdge(2,3);
    g.InsertEdge(4,5);

    cout << "Printing graph edges:\n";
    g.printGraph();

    cout << "Printing dfs: ";
    g.BFS(5);

    return 0;
}
