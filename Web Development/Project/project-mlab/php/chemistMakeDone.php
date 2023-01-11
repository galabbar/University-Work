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

$result2 = mysqli_query($db, "SELECT * FROM make WHERE med='$id'");
$row2 = mysqli_fetch_assoc($result2);
$qty = $row2["qty"];

$result3 = mysqli_query($db, "SELECT * FROM med WHERE id='$id'");
$row3 = mysqli_fetch_assoc($result3);
$qtyOLD = $row3["qty"];

$new = (int) $qty + (int) $qtyOLD;

if ($result = mysqli_query($db, "DELETE FROM make WHERE med='$id'")) {
    $result4 = mysqli_query($db, "UPDATE `med` SET `qty` = '$new' WHERE `id` = '$id';");
    echo 1;
} else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}
?>