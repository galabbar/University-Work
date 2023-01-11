<?php
// connect to db;
include "../hassanDB.php";

// get the information
$name = isset($_GET['name']) ? $_GET['name'] : '';
$qty = isset($_GET['qty']) ? $_GET['qty'] : '';
$img = isset($_GET['pic']) ? $_GET['pic'] : '';

// check if anything is null
if (empty($name) || empty($qty) || empty($img)) {
    echo 0;
    return;
}

// test the input
$name = test_input($name);
$qty = test_input($qty);
$img = test_input($img);

// insert to quarey
if ($result = mysqli_query($db, "INSERT INTO raw (id, name, img, available, used) VALUES (NULL, '$name', '$img', '$qty', '0');"))
    echo 1;
else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>