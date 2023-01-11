<?php

$dbname = "epiz_32996845_final";
$username = "epiz_32996845";
$host = "sql301.epizy.com";
$pass = "hAbYKRLyle";

$db = mysqli_connect($host, $username, $pass, $dbname);

if (mysqli_connect_errno() != 0) {

    echo "database connection error";
    exit(1);
}

?>