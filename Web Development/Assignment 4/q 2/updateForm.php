<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: updateForm.php

$PageTitle = "Update a Book";

include("PageFrame.php");

?>

<html>

<head>
    <script>
        //Displays form to update the book's info
        function DisplayForm() {

            var option = document.getElementById("book").value.split("&");
            var Form = document.getElementById("updateForm");

            if (option[0] === "none") {

                return;
            }

            Form.innerHTML =
                `
                <h1>Update the Book:</h1>
                <p>
                    <label>Book Title<br /></label>
                    <input type="hidden" value="${option[0]}" name="prev-title">
                    <input type="text" value="${option[0]}" name="title">
                </p>
                <p>
                    <label>Book Publisher<br /></label>
                    <input type="hidden" value="${option[1]}" name="prev-publisher">
                    <input type="text" value="${option[1]}" name="publisher">
                </p>
                <input type="submit" name="submit" value="submit">
            `;
        }
    </script>
</head>

<body>
    <?php

    include("myDB.php");

    $query = "SELECT * FROM Books"; //query to get an associative list of the books
    $Result = mysqli_query($myDB, $query);

    //dropdown menu initialisation
    $dropDown =
        '
            <p><select id="book">
                <option none="none">----</option>
        ';

    //adds every book as an option in the dropdown menu 
    while ($Row = mysqli_fetch_assoc($Result)) {

        $Title = $Row["Title"];
        $Publisher = $Row["Publisher"];

        $Val = $Title . "&" . $Publisher;

        $dropDown .= "<option value='$Val'>$Title - $Publisher</option>";
    }

    $dropDown .= "</select>";
    $btn = '<button type="button" onclick="DisplayForm()">Select</button></p>';

    print $dropDown . $btn;
    ?>

    <form id="updateForm" method="post" action="UpdateBook.php"></form>
</body>

</html>