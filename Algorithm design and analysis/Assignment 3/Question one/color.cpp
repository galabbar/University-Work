//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//Takes a string and stores every word in a vector
//Let n be the number of spaces in str and m be the size of the vector
//Time Complexity: O(n) since there are variable number of spaces in the string
//Space Complexity: O(m) since the string contains a variable number of words
vector<string> Tokenizer(string str){

    vector <string> tokens; //vector to store the words of the string
    stringstream Stream(str); //Makes a string into a stream so it can be read like a file
    string Res; //String to store the word from str

    //Goes through the string and stores every word in the "tokens" vector
    while(getline(Stream, Res, ' '))
        tokens.push_back(Res);

    return tokens;
}

//Graph Class
class Graph{
public:

    //Graph Constructor
    Graph(int num): Num_of_Nodes(num)
    {
        //Allocates memory for isColoured
        isColoured = new int [num];

        //Allocates memory for an array of arrays
        Mat = new int* [num];

        //Goes through Mat and allocates memory for an array for each index
        for (int i = 0; i < num; i++){

            Mat[i] = new int [num];

            for (int j = 0; j < num; j++){

                Mat[i][j] = 0;
            }
        }
    }

    //Fills the adjacency matrix using the contents of the given file
    //Let n be the height and width of the adjacency matrix, and m be the size of the vector
    //Time Complexity: O(n^2) Since it is filling up a matrix
    //Space Complexity: O(m) since the string contains a variable number of words
    void FillMat(fstream& File){

        vector<string> vec; //Vector to store the tokens
        string str; //string to read the file line

        //Fills up the matrix by reading the file line by line
        for (int i = 0; i < Num_of_Nodes; i++){

            //Reads a line in the file then stores the matrix rows in a vector
            getline(File, str);
            vec = Tokenizer(str);

            //stores the matrix row in the adjacency matrix
            for (int j = 0; j < Num_of_Nodes; j++)
                Mat[i][j] = stoi(vec[j]);
        }
    }

    //Finds the minimum amount of colours that that every node could have without any two adjacent nodes having the same colour
    //Let n be the width of the adjacency matrix
    //Time Complexity: O(n^3) Since Check_Free_Colour is used within a loop
    //Space Complexity: O(1) since only a constant amount of variables were declared
    int MinimumColours(){

        //Initialises the isColoured array to all 0's
        for (int i = 0; i < Num_of_Nodes; i++)
            isColoured[i] = 0;

        int Number_of_Colours = 1; //Stores the current number f colours
        int Max_Colour = 1; //Stores the greatest colour used
        int Colour; //variable that stores a colour

        //Goes through all nodes and assigns an appropriate colour to what isn't coloured
        for (int i = 0; i < Num_of_Nodes; i++){

                //Checks for an appropriate colour for the current node then assigns the colour to isColoured
                Colour = Check_Free_Colour(i);
                isColoured[i] = Colour;

                //Checks if a new colour has been reached
                if (Colour > Max_Colour){

                    Max_Colour = Colour;
                    Number_of_Colours++;
                }
        }

        //Returns the minimum amount of colours needed
        return Number_of_Colours;
    }

private:

    int** Mat;
    int Num_of_Nodes;
    int* isColoured;

    /*  Helper Functions  */
    //Checks if a node is connected to a certain colour
    //Let n be the width of the adjacency matrix
    //Time Complexity: O(n) since it goes through a matrix row
    //Space Complexity: O(1) since only a constant amount of variables were declared
    bool isConnectedToColour(int Node, int Colour){

        //Looks for a node that's connected to "Node" with colour "Colour"
        for(int i = 0; i < Num_of_Nodes; i++)
            if (Mat[Node][i] != 0 && isColoured[i] == Colour)
                return true;

        return false;
    }

    //Checks if a colour is appropriate for this node by looking from the first colour and beyond
    //Time Complexity: O(n^2) Since the loop could go up to n iterations or more
    //Space Complexity: O(1) since only a constant amount of variables were declared
    int Check_Free_Colour(int Node){

        int Colour = 1; //Starting colour

        //iterates to see if the current colour is connected or not. It will return the colour once it is a non-connected colour
        while (true){

            if (!isConnectedToColour(Node, Colour))
                return Colour;

            Colour++;
        }
    }
};

//Main Function
//Let T be the number of trials, n be the width of the adjacency matrix, and m be the size the vector
//Time Complexity: O(T*n^3) Since MinimumColours is called T amount of times
//Space Complexity: O(m) since the string contains a variable number of words
int main(){

    fstream File("test1.in"); //reads the input from the file
    vector<string> vec; //vectore to store the string tokens
    string str; //Line read from the file
    int Trials; //Number of trials

    //Reads the number of trials from the file
    getline(File, str);
    Trials = stoi(str);

    //Tests MinimumColours T times
    for (int i = 0; i < Trials; i++){

        //Reads the inputs from the file
        getline(File, str);
        vec = Tokenizer(str);

        //Executes MinimumColours after filling up the matrix
        Graph G(stoi(vec[0]));
        G.FillMat(File);
        cout << G.MinimumColours() << endl;
    }

    return 0;
}
//End of main
