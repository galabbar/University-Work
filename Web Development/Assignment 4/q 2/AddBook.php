<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: AddBook.php

//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "submit"){

    /* Data info */
    $Title = cleanData($_POST["title"]);
    $Publisher = cleanData($_POST["publisher"]);

    //Calls the function to add the book to database
    Add_Book($Title, $Publisher);
}

//cleans values from the user input
function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);

    return $data;
}

//Adds Book info to the database
function Add_Book($Title, $Publisher){

    $PageTitle = "Add a Book";

    //Page header
    print<<<HERE

    <html>
        <body>

    HERE;

    include("myDB.php");
    include("PageFrame.php");

    $query = "SELECT Title, Publisher FROM Books WHERE Title='$Title' AND Publisher='$Publisher'"; //Checks if the book exists as a row in the database
    $Rows = mysqli_num_rows(mysqli_query($myDB, $query));

    //Checks if there is any row with the same information. If there is then print a message
    if ($Rows > 0){

        print "<h1>The Book Already Exists..</h1>";
    }

    //otherwise, add the book to the database
    else{

        $ID = uniqid(); //generates unique id 

        $query = "INSERT INTO Books (`id`, `title`, `publisher`) VALUES ('$ID', '$Title', '$Publisher')"; //Insert the book in the database with a unique id
        mysqli_query($myDB, $query);

        //html section for book addition confirmation
        print<<<HERE

        <h1>New Book Has Been Added!</h1>
        <table class="brdr">
            <tr class="brdr">
            <th class="brdr">ID</th>
                <th class="brdr">Title</th>
                <th class="brdr">Publisher</th>
            </tr>
            <tr class="brdr">
                <td class="brdr">$ID</td>
                <td class="brdr">$Title</td>
                <td class="brdr">$Publisher</td>
            </tr>
        </table>
        HERE;
    }

    //page footer
    print<<<HERE

    </body>
        </html>

    HERE;

}

?>