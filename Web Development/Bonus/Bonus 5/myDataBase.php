<?php

$DB_NAME = "epiz_33019398_FixIt";
$USERNAME = "epiz_33019398";
$PASSWORD = "IfsEyrpWwmyO";
$HOST = "sql309.epizy.com";

$myDB = mysqli_connect($HOST, $USERNAME, $PASSWORD, $DB_NAME);

if (mysqli_connect_errno()) {

    echo "Connection Failed: " . mysqli_connect_error();
    exit(1);
}

?>