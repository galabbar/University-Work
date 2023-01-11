//Ghazi Najeeb Al-Abbar
//2181148914
//Homework 7
//IDE: QT
//CS142
//letter.h

#include <iostream>
using namespace std;

#ifndef LETTER_H
#define LETTER_H


class Letter
{
public:
    Letter(); //Empty constructor
    void printToScale(string); //Prints the letters in *
    bool toCapital(string&); /*Turns the letters into capital and returns true.
                               Returns false if there is a character that isn't a letter*/
private:
    //2D character array with every letter in the alphabet written in *
    const char* alphabet[26][7] = {

        //A
        {" ********",
         " *      *",
         " *      *",
         " *      *",
         " ********",
         " *      *",
         " *      *"},

        //B
        {" ******* ",
         " *      *",
         " *     * ",
         " ******  ",
         " *     * ",
         " *      *",
         " ******* "},

        //C
        {" ********",
         " *       ",
         " *       ",
         " *       ",
         " *       ",
         " *       ",
         " ********"},

        //D
        {" ***     ",
         " *   *   ",
         " *     * ",
         " *      *",
         " *     * ",
         " *   *   ",
         " ***     "},

        //E
        {" ******** ",
         " *        ",
         " *        ",
         " ******** ",
         " *        ",
         " *        ",
         " ******** "},

        //F
        {" ******** ",
         " *        ",
         " *        ",
         " *        ",
         " ******** ",
         " *        ",
         " *        "},

        //G
        {" ******** ",
         " *        ",
         " *        ",
         " *        ",
         " *   **** ",
         " *      * ",
         " ******** "},

        //H
        {" *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " ******** ",
         " *      * ",
         " *      * "},

        //I
        {" ******** ",
         "    **    ",
         "    **    ",
         "    **    ",
         "    **    ",
         "    **    ",
         " ******** "},

        //J
        {" ******** ",
         "      *   ",
         "      *   ",
         "      *   ",
         "  *   *   ",
         "  *   *   ",
         "  *****   "},

        //K
        {" *     *  ",
         " *   *    ",
         " * *      ",
         " ** *     ",
         " *    *   ",
         " *      * ",
         " *        "},

        //L
        {" *        ",
         " *        ",
         " *        ",
         " *        ",
         " *        ",
         " *        ",
         " ******** "},

        //M
        {" **    ** ",
         " * *  * * ",
         " *   *  * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * "},

        //N
        {" **      * ",
         " * *     * ",
         " *  *    * ",
         " *   *   * ",
         " *    *  * ",
         " *     * * ",
         " *       * "},

        //O
        {" ******** ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " ******** "},

        //P
        {" ******** ",
         " *      * ",
         " *      * ",
         " ******** ",
         " *        ",
         " *        ",
         " *        "},

        //Q
        {" ********    ",
         " *      *    ",
         " *      *    ",
         " *      *    ",
         " *      *    ",
         " *    ****   ",
         " ******** ***"},

        //R
        {" ******** ",
         " *      * ",
         " *     *  ",
         " ******   ",
         " *      * ",
         " *      * ",
         " *      * "},

        //S
        {" ******** ",
         " *        ",
         " *        ",
         " ******** ",
         "        * ",
         "        * ",
         " ******** "},

        //T
        {" ******** ",
         "    **    ",
         "    **    ",
         "    **    ",
         "    **    ",
         "    **    ",
         "    **    "},

        //U
        {" *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " ******** "},

        //V
        {" *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " **    ** ",
         "    **    "},

        //W
        {" *      * ",
         " *      * ",
         " *      * ",
         " *      * ",
         " *   *  * ",
         " * *  * * ",
         " **    ** "},

        //X
        {" *     *  ",
         "  *   *   ",
         "   * *    ",
         "    *     ",
         "   *  *   ",
         "  *    *  ",
         " *      * "},

        //Y
        {" *      * ",
         " **    ** ",
         "  **   ** ",
         "    * *   ",
         "     *    ",
         "     *    ",
         "     *    "},

        //Z
        {" ******** ",
         "       *  ",
         "      *   ",
         "     *    ",
         "    *     ",
         "   *      ",
         " ******** "}
    }; //End of character array.
};

#endif // LETTER_H