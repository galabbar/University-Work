<?php

//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//Assignment 4
//Filename: PageFrame.php

?>

<!DOCTYPE html>
<html>

<head>
    <meta charset='utf-8'>
    <title>
        <?php print $PageTitle ?>
    </title>
    <?php
    include("Styles.php");
    ?>
</head>
<!-- Page header for all pages -->

<body style="margin-bottom: 50px">
    <nav>
        <ul>
            <li><a href="index_1.php">Home</a></li>
            <li><a href="addmanager.php">Add manager</a></li>
            <li><a href="addproject.php">add project</a></li>
            <li><a href="question_c.php">question c</a></li>
            <li><a href="question_d.php">question d</a></li>
        </ul>
    </nav>
</body>

</html>