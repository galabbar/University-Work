<?php

//Returns the product of the given two matrices 
function MatProd($Mat1, $Mat2)
{
    /* Dimensions of the matricies */
    $Cols1 = sizeof($Mat1[0]);
    $Rows1 = sizeof($Mat1);
    $Cols2 = sizeof($Mat2[0]);
    $Rows2 = sizeof($Mat2);

    //Returns -1 if the two matricies are not compatible for multiplications
    if ($Cols1 != $Rows2) {

        return -1; //Not compatible sizes
    }

    $ResMat = array(); //Resultant matrix will be stored here

    //Initialises the resultant matrix
    for ($i = 0; $i < $Rows1; $i++) {

        array_push($ResMat, array());
    }

    //Multiplies the two matricies
    for ($i = 0; $i < $Rows1; $i++) {

        $Res = 0; //to store the result odf the matrix cell after multiplication 
        $CurrRow = 0; //represents the coloumn of the matrix on the right

        //Multiplies the row of the matrix on the left with the coloumns of the matrix on the right 
        while ($CurrRow < $Cols2) {

            //Calculates the result in the matrix cell
            for ($j = 0; $j < $Rows2; $j++) {

                $Res += $Mat1[$i][$j] * $Mat2[$j][$CurrRow];
            }

            $ResMat[$i][$CurrRow] = $Res; //stores it in the matrix cell

            //Res returns to zero and the coloumn is incremented
            $Res = 0;
            $CurrRow++;
        }
    }

    return $ResMat; //returns the resultant matrix
}

//Displays the matrix
function display_Matrix($Mat)
{

    /* Matrix Dimensions */
    $Row = sizeof($Mat);
    $Col = sizeof($Mat[0]);

    //Goes through every cell in the matrix and prints them
    for ($i = 0; $i < $Row; $i++) {
        for ($j = 0; $j < $Col; $j++) {

            print $Mat[$i][$j] . " ";
        }

        print "\n";
    }

    print "\n\n";
}

//Main program driver. Tests the above function
function main()
{

    //Matrix 1
    $Mat1 = array(
        array(4, 2),
        array(3, 6)
    );

    //Matrix 2
    $Mat2 = array(
        array(-1, 9),
        array(2, 7)
    );

    //Gets the result of matrix product (could be an error or an actual result)
    $Prod = MatProd($Mat1, $Mat2);

    //Displays the first matrix
    print "Matrix 1:\n";
    display_Matrix($Mat1);

    //Displays the second matrix
    print "Matrix 2:\n";
    display_Matrix($Mat2);

    print "The product of Matrix 1 and Matrix 2:\n";

    //Checks if there is an error wit multiplying the matrix
    if ($Prod == -1) {

        print "The two matricies are incompatible for multiplication..\n";

        //Displays the resultant matrix
    } else {

        display_Matrix($Prod);
    }

}

//Calls Main
main();

?>