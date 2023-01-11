<?php

include "mydb.php";

$query = "SELECT * FROM `appointment`";
$Result = mysqli_query($db, $query);

?>

<!DOCTYPE html>
<html>

<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>home</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <?php
    include "styles.php";
    ?>
</head>

<body>
    <?php
    include "header.php";
    ?>

    <h1>appointments</h1>
    <ul>

        <?php

        while ($Row = mysqli_fetch_assoc($Result)) {

            $id = $Row["aptnum"];

            echo '<li><a href="details.php?id=$id">Appointemnt $id</a></li>';

        }

        ?>
    </ul>
</body>

</html>