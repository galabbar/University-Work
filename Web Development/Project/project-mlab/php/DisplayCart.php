<?php

PRINT <<<HERE

<table class="table table-striped table-hover">
    <tr class="bg-info text-white">
        <th>#</th>
        <th>Name</th>
        <th>Unit Price</th>
        <th>Quantity</th>
        <th>Total (KD)</th>
        <th colspan="3">Action</th>
    </tr>

HERE;

if (isset($_SESSION["Cart-List-Length"])){

    $CartLength = (int) $_SESSION["Cart-List-Length"];

    $NetTotal = 0;

    for ($i = 1; $i <= $CartLength; $i++){

        $name = $_SESSION["item-" . $i]["med-name"];
        $unitPrice = $_SESSION["item-" . $i]["unit-price"];
        $qty = $_SESSION["item-" . $i]["med-qty"];

        $Total = (float) $unitPrice * (int) $qty;
        $NetTotal += $Total;

        PRINT <<<HERE

        <tr class="bg-info text-white" id="Cart-Item-$i">
            <td>$i</td>
            <td>$name</td>
            <td>$unitPrice</td>
            <td><span id="qty-$i">$qty</span></td>
            <td>$Total</td>
            <td><button id="decr-$i" class="btn btn-primary" onclick="Decrement(this, '$name', $qty)">-</button></td>
            <td><button id="incr-$i" class="btn btn-primary" onclick="Increment(this, '$name', $qty)">+</button></td>
            <td><button id="rmv-$i" class="btn btn-primary" onclick="Remove(this, '$name')">Remove</button></td>
        </tr>

        HERE;
    }

    if (isset($_SESSION["Cart-List-Length"])){

        PRINT<<<HERE

        <tr class="bg-info text-white">
            <td><strong>Net Total:</strong></td>
            <td></td><td></td><td></td>
            <td>$NetTotal</td>
        </tr>

        HERE;
    }
}

print("</table>");

?>