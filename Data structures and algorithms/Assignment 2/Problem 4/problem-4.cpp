//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//problem-4.cpp

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

     /*List print function*/
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
/********************************************/

//Merge two sorted linked lists in sorted order
//Let n and m be the sizes of list1 and list2
//Time Complexity: O(m+n) because because both loop is being iterated n+m times
list<int> Merge(list<int> list1, list<int> list2){

    //Checks if list1 is empty. It will return list2 if list1 is empty
    if (list1.empty())
        return list2;

    //Checks if list2 is empty. It will return list1 if list2 is empty
    if (list2.empty())
        return list1;

    list<int> list3; //A new list to contain all the nodes in sorted order

    //Goes through both list1 and list2 until they're both empty and appends the nodes in list 3 in sorted order
    while (!list1.empty() || !list2.empty()){

        //Checks if list1 and list2 are not empty
        if (!list1.empty()){
            if (!list2.empty()){

                //Checks if the list1's front is less than or equal to list2's front
                //If that's the case, then list1's front will be appended in list3
                //Then list1's front is popped
                if (list1.front() <= list2.front()){

                    list3.push_back(list1.front());
                    list1.pop_front();
                }
            }
            //The case where list1 is not empty and list2 is empty, which means the rest of list1 is greater than whatever in list3
            //If that's the case, then list1's front will be appended in list3
            //Then list1's front is popped
            else{
                list3.push_back(list1.front());
                list1.pop_front();
            }
        }

        //Checks if list2 and list1 are not empty
        if (!list2.empty()){
            if (!list1.empty()){

                //Checks if the list2's front is greater than list1's front
                //If that's the case, then list2's front will be appended in list3
                //Then list2's front is popped
                if (list1.front() > list2.front()){

                    list3.push_back(list2.front());
                    list2.pop_front();
                }
            }

            //The case where list2 is not empty and list1 is empty, which means the rest of list2 is greater than whatever in list3
            //If that's the case, then list2's front will be appended in list3
            //Then list2's front is popped
            else{
                list3.push_back(list2.front());
                list2.pop_front();
            }
        }
    }

    return list3; //list3 is returned
}

//Beginning of program
int main(){

    //Three lists were declared
    list<int> L1,L2,L3;

    L1.push_back(1);
    L1.push_back(3);
    L1.push_back(5);

    L2.push_back(2);
    L2.push_back(4);
    L2.push_back(6);

    //L1: 1    3    5
    //L2: 2    4    6
    showlist(L1);
    showlist(L2);

    L3 = Merge(L1,L2);

    //L3: 1    2    3   4   5   6
    showlist(L3);

    return 0;
}
//End of program
