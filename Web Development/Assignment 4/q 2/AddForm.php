<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: AddForm.php

$PageTitle = "Add a Book";

include("PageFrame.php");

?>

<html>

<body>
    <!-- Form to add a new book -->
    <form method="post" action="AddBook.php">
        <h1>Add a new Book</h1>
        <table>
            <tr>
                <td>Title</td>
                <td><input type="text" name="title"></td>
            </tr>
            <tr>
                <td>Publisher</td>
                <td><input type="text" name="publisher"></td>
            </tr>
            <tr>
                <td><input type="submit" name="submit" value="submit"></td>
            </tr>
        </table>
    </form>
</body>

</html><?php