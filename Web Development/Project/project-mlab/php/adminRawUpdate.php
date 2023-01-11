<?php
// connect to db;
include "../hassanDB.php";

// get the information
$id = isset($_GET['id']) ? $_GET['id'] : '';
$update = isset($_GET['update']) ? $_GET['update'] : '';

// check if anything is null
if (empty($id) || empty($update)) {
    echo 0;
    return;
}

// test the input
$update = test_input($update);
$id = test_input($id);

// update to quarey
if ($result = mysqli_query($db, "UPDATE `raw` SET `available` = '$update' WHERE `raw`.`id` = '$id';"))
    echo 1;
else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>