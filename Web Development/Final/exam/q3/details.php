<!DOCTYPE html>
<html>

<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>row added</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <?php
    include "styles.php";
    ?>
</head>

<body>
    <?php
    include "header.php";
    ?>

    <?php

    include "mydb.php";


    $id = $_REQUEST["id"];

    $query = "SELECT * FROM `appointment` WHERE `aptnum`=$id";

    $Result = mysqli_query($db, $query);
    $Result = mysqli_fetch_assoc($Result);

    $name = $Result["docname"];
    $hosp = $Result["hospital"];
    $date = $Result["aptdate"];

    echo <<<HERE

<table>
<tr>
<th>apointment number</th>
<th>doctor name</th>
<th>hospital</th>
<th>apointment date</th>
</tr>
<tr>
<td>$id</td>
<td>$name</td>
<td>$hosp</td>
<td>$date</td>
</tr>
</table>

HERE;



    ?>
</body>

</html>