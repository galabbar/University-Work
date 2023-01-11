<?php

session_start();
require($_SERVER['DOCUMENT_ROOT'] . "/dbInfo.php");

$action = $_REQUEST["action"];

if ($action === "decr") {

    $name = $_REQUEST["name"];
    $qty = $_REQUEST["qty"];

    $query = "UPDATE med SET qty=$qty WHERE name=`$name`";
    mysqli_query($db, $query);

} else if ($action === "incr") {

    $name = $_REQUEST["name"];
    $qty = $_REQUEST["qty"];

    $query = "SELECT qty FROM med WHERE name=`$name`";
    $Res = mysqli_query($db, $query);

    $Res = mysqli_fetch_assoc($Res);
    $Res = $Res["qty"];

    if ((int) $Res < (int) $qty) {

        echo '0';
        return;
    } else {

        $Res = (int) $Res - 1;
        $qty = (int) $qty + 1;

        $query = "UPDATE med SET qty=$Res WHERE name=`$name`";
        mysqli_query($db, $query);

        echo '1';
        return;
    }
} else if ($action === "rmv") {

    $name = $_REQUEST["name"];
    $qty = $_REQUEST["qty"];

    $query = "SELECT qty FROM med WHERE name=`$name`";
    $Res = mysqli_query($db, $query);

    $Res = mysqli_fetch_assoc($Res);
    $Res = $Res["qty"];

    $Res = (int) $Res + (int) $qty;

    $query = "UPDATE med SET qty=$Res WHERE name=`$name`";
    mysqli_query($db, $query);

} else if ($action === "empty") {

    if (!isset($_SESSION["Cart-List-Length"])) {

        echo '0';
        return;
    } else {

        echo '1';
        return;
    }
}

?>