<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: UpdateBook.php

//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "submit"){

    /* Data info */
    $Title = cleanData($_POST["title"]);
    $PrevTitle = cleanData($_POST["prev-title"]);
    $Publisher = cleanData($_POST["publisher"]);
    $PrevPublisher = cleanData($_POST["prev-publisher"]);

    //Updates the books info
    Update_Book($Title, $Publisher, $PrevTitle, $PrevPublisher);
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

//Updates the books using the given info
function Update_Book($Title, $Publisher, $PrevTitle, $PrevPublisher){

    $PageTitle = "Book Updated!";

    print<<<HERE

    <html>
    <body>

    HERE;

    include("myDB.php");
    include("PageFrame.php");

    $query = "SELECT id FROM Books WHERE title='$PrevTitle' AND publisher='$PrevPublisher'"; //query to get the book's unique id
    $Book = mysqli_fetch_assoc(mysqli_query($myDB, $query));

    $ID = $Book["id"];

    $query = "UPDATE Books SET title='$Title', publisher='$Publisher' WHERE id='$ID'"; //query to update the book's information
    mysqli_query($myDB, $query);

    //html section for updated book info success 
    print<<<HERE

    <h1>The book has been succesfully updated</h1>
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