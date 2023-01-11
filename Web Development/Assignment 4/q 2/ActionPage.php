<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: ActionPage.php

//Page header
print<<<HERE

<html>
<body>

HERE;

//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "Delete"){

    //Page title
    $PageTitle = "Delete Book";
    include("PageFrame.php");

    /* Data info */
    $ID = cleanData($_POST["id"]);
    $Title = cleanData($_POST["title"]);
    $Publisher = cleanData($_POST["publisher"]);

    //title and publisher formated for DeleteBook.php 
    $Val = $Title . "&" . $Publisher;

    //html section for book deletion
    print<<<HERE

    <h1>Are you sure you want to delete this book?</h1>
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
    <form method="post" action="DeleteBook.php">
        <a href="index_1.php">
            <button type="button">Cancel</button>
        </a>
        <input type="hidden" name="book" value="$Val">
        <input type="submit" name="submit" value="Confirm">
    </form>

    HERE;
}

//Checks if the submit button was entered in the right page and the right place
if (isset($_POST['submit']) && $_POST['submit'] == "Edit"){

    //Page title
    $PageTitle = "Edit Book";
    include("PageFrame.php");

    /* Data info */
    $PrevTitle = cleanData($_POST["title"]);
    $PrevPublisher = cleanData($_POST["publisher"]);

    //html section for editing book data
    print<<<HERE

    <h1>Edit The Book's Information</h1>
    <form method="post" action="UpdateBook.php">
        <p>
            <input type="text" name="title" value="$PrevTitle">
            <input type="hidden" name="prev-title" value="$PrevTitle">
            <input type="text" name="publisher" value="$PrevPublisher">
            <input type="hidden" name="prev-publisher" value="$PrevPublisher">
        </p>
        <input type="submit" name="submit" value="submit">
    </form>

    HERE;


}

print<<<HERE

</body>
</html>

HERE;

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

?>