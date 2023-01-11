<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: DeleteForm.php

$PageTitle = "Delete a Book";

include("PageFrame.php");

?>

<html>

<head>
    <script>
        //Prints on the document text and a button for confirm that the user wants to delete the book
        function DisplayForm() {

            var option = document.getElementById("book").value;
            var Form = document.getElementById("deleteForm");

            console.log(option);

            if (option === "none") {

                return;
            }

            Form.innerHTML =
                `
                <h1>Are You Sure You want to Delete This Book?</h1>

                <a href="index_1.php">
                    <button type="button">Cancel</button>
                </a>
                <input type="hidden" value="${option}" name="book">
                <input type="submit" name="submit" value="Confirm">
            `;
        }
    </script>
</head>

<body>
    <?php

    print "<h1>Delete a Book</h1>";

    include("myDB.php");

    $query = "SELECT * FROM Books"; //query to get an associative list of the books
    $Result = mysqli_query($myDB, $query);

    //Initialising a drop down list
    $dropDown =
        '
            <p>
            <select id="book">
                <option value="none">----</option>
        ';

    //Puts all the books as options in the drop down list
    while ($Row = mysqli_fetch_assoc($Result)) {

        $Title = $Row["Title"];
        $Publisher = $Row["Publisher"];

        //Sets value for the dropdown list option
        $Val = "$Title" . "&" . "$Publisher";

        $dropDown .= "<option value='$Val'>$Title - $Publisher</option>";
    }

    $dropDown .= "</select>";
    $btn = '<button type="button" onclick="DisplayForm()">Select</button></p>';

    print $dropDown . $btn;
    ?>
    
    <form id="deleteForm" method="post" action="DeleteBook.php"></form>
</body>

</html>