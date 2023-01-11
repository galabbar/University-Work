<?php

include "dbInfo.php";

$query = "SELECT * FROM med";
$Result = mysqli_query($db, $query);
$i = 1;

while ($Row = mysqli_fetch_assoc($Result)) {

    $medID = $Row["id"];
    $name = $Row["name"];
    $img = $Row["img"];
    $qty = $Row["qty"];
    $price = $Row["price"];
    $Desc = $Row["desc"];

    if ($qty === "0") {

        continue;
    }

    $query = "SELECT raw FROM comb WHERE med=$medID";
    $ingredients = mysqli_query($db, $query);
    $ingr_List = "";

    while ($item = mysqli_fetch_assoc($ingredients)) {

        $mat_id = $item["raw"];

        $query2 = "SELECT name FROM raw WHERE id=$mat_id";
        $matNames = mysqli_query($db, $query2);
        $matName = mysqli_fetch_assoc($matNames);

        $ingr_name = $matName["name"];

        $ingr_List .= "$ingr_name, ";
    }

    print <<<HERE

<div id="Medicine_Item-$i" class="col-md-3 mb-3">
<!-- item -->
<div class="card bg-white p-0 shadow overflow-hidden">
<!-- img -->
<img src="../imgs/$img" width="366" height="300" alt="Medicne i" />
<!-- details -->
<div class="p-3">
<h5>$name</h5>
<p>
Availibilty: <span id="avail-$i">$qty</span> in stock<br />
Price: $price kwd<br />
ingredients: $ingr_List
</p>
<p class="text-muted">
$Desc
</p>
<div class="d-flex justify-content-between mt-2 float-end">
<button class="btn btn-primary" type="button" id="btn-$i" onclick="AddtoCart(this, '$name', $price, $qty, $medID)">Add to Cart</button>
<input type="text" style="width: 50px" placeholder="QTY" id="qty-$i" >
</div>
</div>
</div>
</div>

HERE;

    $i++;

}

?>