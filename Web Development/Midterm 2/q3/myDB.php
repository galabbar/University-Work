<?php


/* my DB information */
$DB_NAME = "epiz_33048164_construction";
$USERNAME = "epiz_33048164";
$PASSWORD = "fD3cwdZr34";
$HOST = "sql305.epizy.com";

$myDB = mysqli_connect($HOST, $USERNAME, $PASSWORD, $DB_NAME); //Connect to the DB

//Checks if there is an error with connecting to the DB
if (mysqli_connect_errno()) {

    echo "Connection Failed: " . mysqli_connect_error();
    exit(1);
}

?>