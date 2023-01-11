<?php

//Merge function for merge sort. Sorts a section of the array
function Merge($Start, $Middle, $End, &$Arr)
{
    /* Initialises two arrays to sort the original array */
    $SubArr1 = array();
    $SubArr2 = array();

    /* Two distinct sizes for SubArr1 and SubArr2 */
    $SubArrSize1 = $Middle - $Start + 1;
    $SubArrSize2 = $End - $Middle;

    //Fills in the SubArr1 with the unsorted scetion of the array
    for ($i = 0; $i < $SubArrSize1; $i++) {

        $SubArr1[$i] = $Arr[$Start + $i];
    }

    //Fills in the SubArr2 with the unsorted scetion of the array
    for ($i = 0; $i < $SubArrSize2; $i++) {

        $SubArr2[$i] = $Arr[$Middle + $i + 1];
    }

    /* Indexes for the sub arrays and the original one */
    $i = 0;
    $j = 0;
    $k = $Start;

    //Sorts the section of the array 
    while ($i < $SubArrSize1 && $j < $SubArrSize2) {

        //If $SubArr1[$i] alphabetically succeeds $SubArr2[$j], then $SubArr1[$i] should be put in the original array first
        if (strcmp($SubArr1[$i], $SubArr2[$j]) < 0) {

            $Arr[$k] = $SubArr1[$i];
            $i++;

        }

        //If not, then $SubArr2[$j] should be put in the original array first
        else {

            $Arr[$k] = $SubArr2[$j];
            $j++;
        }

        $k++;
    }

    //If the first sub array has not reached its last index, then the elements are just put in the original array 
    while ($i < $SubArrSize1) {

        $Arr[$k] = $SubArr1[$i];

        $i++;
        $k++;
    }

    //If the second sub array has not reached its last index, then the elements are just put in the original array 
    while ($j < $SubArrSize2) {

        $Arr[$k] = $SubArr2[$j];

        $j++;
        $k++;
    }
}

//Sorts an array using merge sort
function MergeSort(&$arr, $Start, $End)
{

    if ($Start >= $End) {

        return;
    }

    $Mid = (int) (($Start + $End) / 2);

    MergeSort($arr, $Start, $Mid);
    MergeSort($arr, $Mid + 1, $End);

    Merge($Start, $Mid, $End, $arr);
}

//Dsiplays an array
function Display_List($List)
{

    //Array size
    $Size = sizeof($List);

    //prints each array element
    for ($i = 0; $i < $Size; $i++) {

        print $List[i] . " ";
    }

    print "\n\n";
}


//Main program driver. Tests the above function
function main()
{

    //List of unsorted names
    $List = array("John", "Abigale", "Arthur", "Dutch", "Javier", "Sadie", "Hosea");

    print "The current (unsorted) List:\n";
    Display_List($List);

    MergeSort($List, 0, sizeof($List)); //sorts the array using merge sort

    print "The list after sorting:\n";
    Display_List($List);
}

//Calling main
main();

?>