<?php
// connect to db;
include "../hassanDB.php";

// get the information
$name = isset($_GET['name']) ? $_GET['name'] : '';
$desc = isset($_GET['desc']) ? $_GET['desc'] : '';
$img = isset($_GET['pic']) ? $_GET['pic'] : '';
$comp = isset($_GET['comp']) ? $_GET['comp'] : '';
$compk = isset($_GET['compk']) ? $_GET['compk'] : '';

// check if anything is null
if (empty($name) || empty($desc) || empty($img) || empty($comp) || empty($compk)) {
    echo 0;
    return;
}

// test the input
$name = test_input($name);
$desc = test_input($desc);
$img = test_input($img);
// $comp = test_input($comp);
$comp = (array) json_decode($comp);
$compk = (array) json_decode($compk);
$compk = explode(',', $compk["k"]);

// insert to quarey
if ($result = mysqli_query($db, "INSERT INTO `med` (`id`, `name`, `desc`, `img`, `qty`) VALUES (NULL, '$name', '$desc', '$img', '0');"))
    echo 1;
else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}
$last_id = mysqli_insert_id($db);

for ($i = 0; $i < count($comp); $i++) {
    $c = $compk[$i];
    $c2 = $comp["$c"];
    if ($result = mysqli_query($db, "INSERT INTO comb (id, med, raw, weight) VALUES (NULL, '$last_id', '$c', '$c2');"))
        echo 1;
    else //if error
    {
        echo -2;
        echo ("Error description: " . mysqli_error($db));
    }
}

?>