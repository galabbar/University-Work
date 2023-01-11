<?php

session_start();
//echo "hello ghazi";

include "dbInfo.php";

$name = $_REQUEST["med-name"];
$unitPrice = $_REQUEST["unit-price"];
$qty = $_REQUEST["med-qty"];
$id = $_REQUEST["med-id"];

$query = "SELECT qty FROM med WHERE id=$id";
$AvailableQty = mysqli_query($db, $query);

$AvailableQty = mysqli_fetch_assoc($AvailableQty);
$AvailableQty = $AvailableQty["qty"];

$AvailableQty = (int) $AvailableQty - (int) $qty;

if ($AvailableQty >= 0) {

    $query = "UPDATE med SET qty=$AvailableQty WHERE id=$id";
    mysqli_query($db, $query);

    if (isset($_SESSION["Cart-List-Length"]) && isset($_SESSION["item-1"])) {

        $Length = (int) $_SESSION["Cart-List-Length"];
        $found = False;

        for ($i = 1; $i <= $Length; $i++) {

            if ($name === $_SESSION["item-" . $i]["med-name"]) {

                $qty = (int) $qty + (int) $_SESSION["item-" . $i]["med-qty"];
                $_SESSION["item-" . $i]["med-qty"] = (string) $qty;

                $found = True;
                break;

            }
        }

        if (!$found) {

            $Length++;

            $newCartItem = array(
                "med-id" => $id,
                "med-name" => $name,
                "unit-price" => $unitPrice,
                "med-qty" => $qty
            );

            $_SESSION["item-" . $Length] = $newCartItem;
            $_SESSION["Cart-List-Length"] = (string) $Length;
        }
    } else {

        $_SESSION["Cart-List-Length"] = "1";

        $newCartItem = array(
            "med-id" => $id,
            "med-name" => $name,
            "unit-price" => $unitPrice,
            "med-qty" => $qty
        );

        $_SESSION["item-1"] = $newCartItem;
    }
}

?>