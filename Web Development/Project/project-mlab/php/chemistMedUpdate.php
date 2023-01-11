<?php
// connect to db;
include "../hassanDB.php";

// get the information
$id = isset($_GET['id']) ? $_GET['id'] : '';
$qty = isset($_GET['qty']) ? $_GET['qty'] : '';

// check if anything is null
if (empty($id) || empty($qty)) {
    echo 0;
    return;
}

// test the input
$id = test_input($id);
$qty = test_input($qty);

// insert to quarey
if ($result = mysqli_query($db, "UPDATE `make` SET `qty` = '$qty' WHERE `make`.`med` = '$id';"))
    echo 1;
else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>