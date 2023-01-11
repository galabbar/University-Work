//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 7
//IDE: QT
//CS142
//main.cpp

#include <iostream>
#include <fstream>
#include <letter.h>
using namespace std;

int main() //Beginning of program
{
    //variable decleration
    int choice,num, i = 1;
    Letter l;
    string File_Name, Input;


    //The user enters the file name
    cout << "Enter the name of the text file: ";
    cin >> File_Name;

    ifstream File(File_Name);

    //Checks to see if the file is open and/or exists

    //The case where the file is open
    if ( File.is_open() ){

        //The program reads fro the file and inputs the string inside "Input"
        while (File >> Input ){
            cout << "Please type \'1\' if you want the text to be a single line or \'2\' if you want it 7 lines: ";
            cin >> choice;

            //If the user types one, the string will be printed as a normal string
            if (choice == 1)
                cout << "\n" << Input << "\n\n";

            //if the user types 2 (or anything else), The program will print the string written in '*'
            else{
                cout << "\n";
                l.printToScale(Input);
                cout << "\n\n";
            }
        }
        //The program closses the file
        File.close();
    }

    //The case where the file is not open, so the user is prompted to create a new one
    else{

        //New input-output file instantiated
        fstream ioFile;
        ioFile.open(File_Name, ios::out);

        cout << "The file does not exist or is not open!\n";
        cout << "A new one will be created.\n";
        cout << "Enter the number of names you would like ( Please type at least 3 names): ";
        cin >> num;

        //The user enters the names in the file
        while (i <= num){
            cin >> Input;
            ioFile << Input << "\n";
            i++;
        }

        ioFile.close();
        ioFile.open(File_Name, ios::in);

        //The program reads fro the file and inputs the string inside "Input"
        while (ioFile >> Input ){
            cout << "Please type \'1\' if you want the text to be a single line or \'2\' if you want it 7 lines: ";
            cin >> choice;

            //If the user types one, the string will be printed as a normal string
            if (choice == 1)
                cout << "\n" << Input << "\n\n";

            //if the user types 2 (or anything else), The program will print the string written in '*'
            else{
                cout << "\n";
                l.printToScale(Input);
                cout << "\n\n";
            }
        }

        //The files are closed
        ioFile.close();
        File.close();
    }

    return 0;

} //End of program
