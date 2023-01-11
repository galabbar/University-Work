<?php

//Checks if a password is in a certain pattern or not
function CheckPassword($Password)
{
    //Password regex. Checks if the password starts with a capital letter, has at least one numerical digit, and is at least 9 characters in length.
    $Pattern = "/^[A-Z](?=.*[0-9]{1,})[a-zA-Z0-9!@#$%^&*<>?~\\\"';:.,\-+=_()[\]{}]{8,}$/";

    return preg_match($Pattern, $Password); //returns true if the password matches the regex pattern.
}

//Main program driver. Tests the above function
function main()
{

    $Correct_Pass = "Aa*^2hp+6"; //correct password
    $Incorrect_Pass = "hello"; //incorrect password

    /* Checks both passwords and gives an appropriate message */
    if (CheckPassword($Correct_Pass)) {

        print "You have entered \"$Correct_Pass\". the password is good!\n\n";
    }

    if (!CheckPassword($Incorrect_Pass)) {

        print "You have eneterd \"$Incorrect_Pass\". The password is not good. Your password must contain a capital letter in the beginning, at least one number"
            . ", and must have a length higher than 8 characters.\n\n";
    }
}

//Calls main
main();