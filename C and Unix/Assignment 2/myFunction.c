#include <stdio.h>

//returns the minimal number of modifications
//to turn str1 into str2
int NumofModifications(char* str1, char* str2){

    //Checks whether the str1 has reached the end or str2 has reached the end
    //or both
    if (*str1 == '\0' || *str2 == '\0')
    {
        //The case where str1 reaches the end, but str2 did not
        if (*str1 == '\0' && *str2 != '\0')
        {
            printf("added %s\n",str2); //Prints the modification message (what is left from str2 is the modification)
            printf("The minimal number of changes is: ");
            return 1; //increments 1 to the number of changes
        }

        if (*str1 != '\0' && *str2 == '\0')
        {
            printf("removed %s\n",str1); ////Prints the modification message (what is left from str1 should be removed. That is the modification)
            printf("The minimal number of changes is: ");
            return 1; //increments 1 to the number of changes
        }

        printf("The minimal number of changes is: ");
        return 0; //Both str1 and str2 have reached their end, so it adds nothing
    }

    //The case where the character from str1 is equal to the character from str2
    if (*str1 == *str2){

        //Both str1 and str2 are incremented and returned recursivly
        str1 = str1 + 1;
        str2 = str2 + 1;

       return NumofModifications(str1,str2);
    }

    //The case where the character from str1 does not equal the character from str2
    else{

        //The case where the incremented index of str1 equals the incremented index of str2
        //It should be considered that the character from str1 is replaced by the character from str2
        if (*(str1 + 1) == *(str2 + 1)){

            printf("Replaced %c with %c\n", *str1,*str2);

            //Both str1 and str2 are incremented and returned recursivly
            str1 = str1 + 1;
            str2 = str2 + 1;

            return 1 + NumofModifications(str1,str2);
        }

        //The case where the character from str1 is equal to the incremented index of str2
        //It should be considered that the incremented index character from str2 is inserted to str1
        if (*str1 == *(str2 + 1)){

            printf("inserted %c\n", *str2);

            //Only str2 is incremented, then returned recursivly
            str2 = str2 + 1;

            return 1 + NumofModifications(str1,str2);
        }

        //The case where the incremented index of str1 is equal to the character from str2
        //It should be considered that the incremented index character from str1 is being removed from str2
        if (*(str1 + 1) == *str2){

            printf("removed %c\n", *str1);

            //Only str1 is incremented, then returned recursivly
            str1 = str1 + 1;

            return 1 + NumofModifications(str1,str2);
        }

        //The case where the character from str1 does not equal the incremented index character from str2
        //This is used to replace a character with a substring, or a substring with a substring
        //or simply insert a substring from str2 to str1
        if (*str1 != *(str2 + 1))
        {
            //insertedStr is used to store the substring that will be inserted or replaced
            //deletedStr is used to store the substring from str1 that will be removed
            char insertedStr[20] = {0}, deletedStr[20] = {0};

            //i is the index for insertedStr and j is the index for deletedStr
            int i = 0, j = 0;

            //insertStr is equal to the character of str2 that does not equal the character from str1
            //This is to show what is replaced or inserted
            insertedStr[i] = *str2;
            str2 = str2 + 1; //str2's index incremented

            char* temp = str2; //a temporary pointer to character to store str2's current character

            while (1) //1 is true, which means this loop is infinite until it breaks
            {
                //the case where str2 reaches it's end
                if (*str2 == '\0')
                {
                    //The current character in str1 is being stored in deletedStr
                    deletedStr[j] = *str1;

                    str2 = temp; //str2 is equal to temp again
                    str1 = str1 + 1; // str1's index is incremented
                    j++; //deletedStr's index is incremented
                }

                //The case where the current character from str1 is equal to the current character from str2
                if (*str1 == *str2)
                {
                    i++; //insertedStr's index is incremented
                    //This stores all the characters after temp that are not equal to the characters in str1
                    //before the two equal characters meet
                    while (temp != str2)
                    {
                        insertedStr[i] = *temp;
                        temp = temp + 1;
                        i++;
                    }


                    //if there is no substring in str1 that will be removed
                    //this means that a substring from str2 will be inserted in str1
                    if (*deletedStr == '\0')
                        printf("inserted %s\n", insertedStr);//new

                    //the case where there are substring that will be removed and replaced
                    else
                        printf("replaced  %s with %s\n", deletedStr, insertedStr);

                    return 1 + NumofModifications(str1,str2); //increment the number of modifications and return recursivly
                }

                //The case where the current character from str1 does not equal the incremented index character from str2
                if (*str1 != *(str2 + 1))
                    str2 = str2 + 1; //only str2 is incremented

                //The case where the current character from str1 does equal the incremented index character from str2
                else //only str2 is incremented, and the loop is broken
                {
                    str2 = str2 + 1;
                    break;
                }
            }

            i++; //insertStr's index is incremented
            //this loop stores the substring (from temp to when the loop was broken) inside of insertedStr
            while (temp != str2)
            {
                insertedStr[i] = *temp;
                temp = temp + 1;
                i++;
            }

            //if there is no substring in str1 that will be removed
            //this means that a substring from str2 will be inserted in str1
            if (*deletedStr == '\0')
                printf("inserted %s\n", insertedStr);//new

            //the case where there are substring that will be removed and replaced
            else
                printf("replaced  %s with %s\n", deletedStr, insertedStr);

            return 1 + NumofModifications(str1,str2); //increment the number of modifications and return recursivly
        }
    }
}
