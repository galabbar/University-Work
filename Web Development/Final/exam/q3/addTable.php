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

if (isset($_POST["submit"]) && $_POST["submit"] == "submit"){

    $id = cleandata($_POST["id"]);
    $name = cleandata($_POST["name"]);
    $hosp = cleandata($_POST["hosp"]);
    $date = cleandata($_POST["date"]);

    $query = "SELECT * FROM `appointment` WHERE `aptnum`=$id";

    $Result = mysqli_query($db, $query);
    $num = mysqli_num_rows($Result);


    if ($num > 0){

        echo "<h1>The row already exists</h1>";
    }

    else{

        $query = "INSERT INTO `appointment`(`aptnum`, `docname`, `hospital`, `aptdate`) VALUES ('$id', '$name', '$hosp', '$date')";
        mysqli_query($db, $query);

        echo "<h1>Added new row to table!</h1>";

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
    }
}



?>
</body>

</html>