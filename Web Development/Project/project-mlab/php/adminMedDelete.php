<?php
// connect to db;
include "../hassanDB.php";

// get the information
$id = isset($_GET['id']) ? $_GET['id'] : '';

// check if anything is null
if (empty($id)) {
    echo 0;
    return;
}

// test the input
$id = test_input($id);

// update to quarey
if ($result = mysqli_query($db, "DELETE FROM `med` WHERE `id` = '$id'")) {
    mysqli_query($db, "DELETE FROM `comb` WHERE `med` = '$id'");
    echo 1;
} else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>