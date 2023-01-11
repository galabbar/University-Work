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

// insert to quarey
$res = [];
$comb = [];
$value = [];
if ($result = mysqli_query($db, "SELECT * from med WHERE id='$id';")) {
    echo ("[");
    while ($row = mysqli_fetch_assoc($result)) {
        $medID = $row["id"];
        $result2 = mysqli_query($db, "SELECT * from comb WHERE med='$medID'");
        while ($row2 = mysqli_fetch_assoc($result2)) {
            $rawID = $row2["raw"];
            $result3 = mysqli_query($db, "SELECT * from raw WHERE id='$rawID';");
            while ($row3 = mysqli_fetch_assoc($result3)) {
                array_push($comb, $row3["name"]);
                $value[$row3["name"]] = $row2["weight"];
            }
        }

        $res = [];
        $res["id"] = $row["id"];
        $res["name"] = $row["name"];
        $res["desc"] = $row["desc"];
        $res["img"] = $row["img"];
        $res["qty"] = $row["qty"];
        $res["count"] = count($comb);
        $res["comb"] = $comb;
        $res["weight"] = $value;
        echo json_encode($res) . ",";
        $comb = [];
        $value = [];
    }
    echo ("{}]");
} else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>