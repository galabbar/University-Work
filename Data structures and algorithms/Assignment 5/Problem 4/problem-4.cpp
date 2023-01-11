//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Problem-4

/*Let n be the size of the adjacency list, and m be the size of the linked lists*/

#include <iostream>
#include <stdio.h>
#include <list>
#include <queue>
using namespace std;

//Searches for an element in a given linked list. Returns true if it is found, otherwise returns false
//Time Complexity: O(m) since the size of the linked list is variable
bool search(list<int> List, int data){

    //If the linked list is empty, it returns false
    if (List.empty())
        return false;

    //Iterator that goes through the list
    list<int>::iterator it;

    //Goes through the list and checks if the element exists. Returns true if it does
    for (it = List.begin(); it != List.end(); it++)
        if (*it == data)
            return true;

    //If the loop stops, then the element does not exist. In that case, returns false
    return false;
}

//Removes an element from a given list
//Time Complexity: O(m) since the size of the linked list is variable
void Remove(list<int>& List, int data){

    //If the list is empty, then the function does nothing and exists.
    if (List.empty())
        return;

    //Iterator that goes through the list
    list<int>::iterator it;

    //Goes through the list and checks if the element exists. If it does, then it removes it and leaves the function
    for (it = List.begin(); it != List.end(); it++)
        if (*it == data){

            List.erase(it);
            return;
        }
}

class Graph{

public:

    //Constructor
    Graph(int num){

        //num is assigned to Size
        this->Size = num;

        //Adjacency list is defined
        AdjList = new list<int> [Size];

        //Weight matrix initialised to 0's
        Weight = new int* [Size];
        for (int i = 0; i < Size; i++){

            Weight[i] = new int [Size];

            for (int j = 0; j < Size; j++)
                Weight[i][j] = 0;
        }
    }

    //Inserts an edge to the graph
    //Time Complexity: O(1) since there is a constant number of instructions
    void InsertEdge(int V1, int V2, int W){

        //The case where the vertices entered are greater than or equal to the Size
        if (V1 >= Size || V2 >= Size){

            cout << "Cannot go beyond the capacity!\n";
            return;
        }

        //The case where the edge already exists
        if (search(AdjList[V1],V2) && search(AdjList[V2],V1)){

            cout << "The two verteces are already connected!\n";
            return;
        }

        //Both vertices are pushed
        AdjList[V1].push_back(V2);
        AdjList[V2].push_back(V1);

        //Both edges are assigned their weights
        Weight[V1][V2] = W; Weight[V2][V1] = W;

        printf("(%d) --> (%d)\n", V1, V2);
    }

    //Removes an edge from the graph
    //Time Complexity: O(1) Since there is a constant amount of instructions
    void RemoveEdge(int V1, int V2){

        //The case where the vertices entered are greater than or equal to the Size
        if (V1 >= Size || V2 >= Size){

            cout << "Cannot go beyond the capacity!\n";
            return;
        }
        //The case where the edge already does not exist
        if (!search(AdjList[V1],V2) && !search(AdjList[V2],V1)){

            cout << "The two verteces were never connected!\n";
            return;
        }

        //Removes the edge
        Remove(AdjList[V1], V2);
        Remove(AdjList[V2], V1);

        //The edge's weight is assigned to zero
        Weight[V1][V2] = 0; Weight[V2][V1] = 0;

        printf("(%d) -/-> (%d)\n", V1, V2);
    }

    //Prints the vertix and all its connected vertices
    //Time Complexity: O(n*m) since it's going through the array while going through the linked lists
    void printGraph(){

        for (int i = 0; i < Size; i++){

            printf("(%d) --> ", i);

            list<int>::iterator it;
            for(it = AdjList[i].begin(); it != AdjList[i].end(); it++)
                cout << *it << " ; ";

            cout << endl;
        }
    }
    //Finds the minimum spanning tree and prints its cost
    //Time Complexity: O(n^2) since it goes through the list of elements while going through all their list of connected verticies
                            //and goes through the matrix while printing the graph
    void MinimumSpanningTree(int start){

        //Adjacency list for the resultant tree (only used for printing)
        list<int> List[Size];

        //Boolean array to keep track of vertices that have been visited. It is initialised to be all zeros
        bool isVisited[Size];
        for (int i = 0; i < Size; i++)
            isVisited[i] = false;

        //A list to keep track of all the vertices with the lightest weights
        list<int> Verticies;

        //Queue to make the loop continue and to print all the vertices
        queue<int> Q;

        /*Min is to find out which vertex has the minimum weight
          Chosen_Vertix is used to store the vertex with the lowest weight
          Current_Row is the row where Chosen_Vertix lies
          Cost is the cost of the minimum spanning tree
        */
        int Min, Chosen_Vertix, Cost = 0, Current_Row;

        //The starting vertex is pushed into the queue and the list. It is also marked as visited
        Verticies.push_back(start);
        Q.push(start);
        isVisited[start] = true;

        //Goes through the graph to find and determine the minimum spanning tree and its cost
        while (!Q.empty()){

            //Min and Chose_Verix are both initialised at the start of each loop
            Min = 999;
            Chosen_Vertix = -1;


            /*
                The iterator it goes through all the elements and their neighbors to find
                which edge has the lowest weight.
                It also has to be from a vertex that has been unvisited
            */
            list<int>::iterator it = Verticies.begin();
            for (; it != Verticies.end(); it++){
                list<int>::iterator it2 = AdjList[*it].begin();
                for (; it2 != AdjList[*it].end(); it2++){

                    //The case where the lowest weight is found
                    if (Weight[*it][*it2] != 0 && Weight[*it][*it2] <= Min && !isVisited[*it2]){

                        //Min is changed to not affect the if statement
                        Min = Weight[*it][*it2];

                        //it and it2 are assigned to Current_Row and Chosen_Verix
                        Chosen_Vertix = *it2;
                        Current_Row = *it;
                    }
                }
            }

            //If Chosen_Verix is changed (meaning a new lowest weight was found) then mark Chosen_Vertix as visited
            //Push it into both the queue and the vericies list
            //and add the weight of the current edge to the cost
            if (Chosen_Vertix != -1){

                isVisited[Chosen_Vertix] = true;
                Q.push(Chosen_Vertix);
                Verticies.push_back(Chosen_Vertix);
                Cost += Weight[Current_Row][Chosen_Vertix];

                //Setting the current row and column to 1
                List[Current_Row].push_back(Chosen_Vertix);
                List[Chosen_Vertix].push_back(Current_Row);
            }

            //The queue is popped
            Q.pop();
        }


        //Prints the minimum spanning tree
        for (int i = 0; i < Size; i++){

            list<int>::iterator it = List[i].begin();

            printf("(%d) --> ", i);
            for (; it != List[i].end(); it++)
                cout << *it << " ; ";

            cout << endl;
        }

        //Prints the cost
        cout << "\nThe cost is : " << Cost << endl;

    }

private:

    list<int>* AdjList;
    int **Weight;
    int Size;


};

int main(){

    Graph g(7);

    g.InsertEdge(0,1,3);
    g.InsertEdge(0,2,4);
    g.InsertEdge(0,6,7);
    g.InsertEdge(1,5,2);
    g.InsertEdge(2,3,5);
    g.InsertEdge(2,4,6);
    g.InsertEdge(2,5,1);
    g.InsertEdge(4,5,4);

    cout << "\nPrinting graph: " << endl;

    g.printGraph();

    cout << "\nMinimum spanning tree: " << endl;
    g.MinimumSpanningTree(0);
}
