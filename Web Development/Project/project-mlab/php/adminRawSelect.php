<?php
// connect to db;
include "../hassanDB.php";

// insert to quarey
$res = [];
if ($result = mysqli_query($db, "SELECT * from raw;")) {
    echo ("[");
    while ($row = mysqli_fetch_assoc($result)) {
        $res = [];
        $res["id"] = $row["id"];
        $res["name"] = $row["name"];
        $res["img"] = $row["img"];
        $res["available"] = $row["available"];
        $res["used"] = $row["used"];
        echo json_encode($res) . ",";

    }
    echo ("{}]");
} else //if error
{
    echo -1;
    echo ("Error description: " . mysqli_error($db));
}

?>