<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: DeleteBook.php

//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "Confirm") {

    /* Data info */
    $Arr = explode("&", $_POST["book"]);
    $Title = cleanData($Arr[0]);
    $Publisher = cleanData($Arr[1]);

    //Deletes a book from the database
    Delete_Book($Title, $Publisher);
}

//Cleans the values from the user input
function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);

    return $data;
}

//Deletes a book from the database using the given data
function Delete_Book($Title, $Publisher)
{

    $PageTitle = "Book Deleted!";

    print<<<HERE

    <html>
        <body>

    HERE;

    include("myDB.php");
    include("PageFrame.php");

    $query = "SELECT id FROM Books WHERE Title='$Title' AND Publisher='$Publisher'"; //query to get an associative list of the books
    $Book = mysqli_fetch_assoc(mysqli_query($myDB, $query));

    $ID = $Book["id"];

    $query = "DELETE FROM Books WHERE id='$ID'"; //query to delete the row from the database's table
    mysqli_query($myDB, $query);

    //html section for book deletion confirmation
    print<<<HERE

    <h1>The book has been succesfully Deleted</h1>
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

    </body>
    </html>

    HERE;
}

?>