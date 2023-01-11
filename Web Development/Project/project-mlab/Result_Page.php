<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Customer_Data.html
Project Phase: 2
-->


<?php

include "php/dbInfo.php";

if (isset($_POST["submit"]) && $_POST["submit"] === "submit") {
    ini_set("display_errors", 1);
    error_reporting(E_ALL);
    echo "beginning <br />";


    $name = cleanData($_POST["name"]);
    $email = cleanData($_POST["email"]);
    $cid = cleanData($_POST["cid"]);
    $PN = cleanData($_POST["phone_number"]);
    $date = cleanData($_POST["date"]);

    $OrderID = uniqid();

    $query1 = "SELECT * FROM Customer WHERE cid=$cid LIMIT 1";
    $Rows = mysqli_num_rows(mysqli_query($db, $query1));

    if ($Rows >= 1) {
        echo "inside up 1";

        $query2 = "SELECT cusid FROM Customer WHERE cid=$cid";

        $Cusid = mysqli_fetch_assoc(mysqli_query($db, $query2));
        $Cusid = $Cusid["cusid"];

        $Length = (int) $_SESSION["Cart-List-Length"];
        echo "inside up 2";
        for ($i = 1; $i < $Length; $i++) {

            echo "inside up loop $i";

            $med_id = $_SESSION["item-" . $i]["med-id"];
            $qty = $_SESSION["item-" . $i]["med-qty"];

            $query3 = "INSERT INTO order(`cusid`, `med_id`, `qty`, `date`, `invoice_id`) VALUES('$Cusid', '$med_id', '$qty', '$date', '$OrderID')";
            mysqli_query($db, $query3);

            unset($_SESSION["item-" . $i]);
        }

    } else {

        echo "inside down 1";

        $query4 = "INSERT INTO Customer (`cusid`, `cusname`, `email`, `phone`, `cid`) VALUES(NULL, '$name', '$email', '$PN', '$cid')";
        mysqli_query($db, $query4);

        $query5 = "SELECT Cusid FROM Customer WHERE cid=$cid";
        $Cusid = mysqli_query($db, $query5);

        $Length = (int) $_SESSION["Cart-List-Length"];
        echo "inside down 2";

        for ($i = 1; $i < $Length; $i++) {

            echo "inside down loop $i";

            $med_id = $_SESSION["item-" . $i]["med-id"];
            $qty = $_SESSION["item-" . $i]["med-qty"];

            $query6 = "INSERT INTO order(`cusid`, `med_id`, `qty`, `date`, `invoice_id`) VALUES('$Cusid', '$med_id', '$qty', '$date', '$OrderID')";
            mysqli_query($db, $query6);

            unset($_SESSION["item-" . $i]);
        }
    }

    unset($_SESSION["Cart-List-Length"]);
}

function cleanData($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = trim($data);
    $data = htmlspecialchars($data);
    $data = strip_tags($data);
    return $data;
}

?>

<!DOCTYPE html>
<!-- 
    Template Page
 -->
<html lang="en">

<head>
    <!-- Meta tages -->
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <!-- view port -->
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <!-- website information -->
    <meta name="description" content="A website that helps Lab Manager to manage it" />
    <meta name="keywords" content="Lab, Chem, Pharmacy" />
    <meta name="author" content="Hassan Khalaf, Rania Kharnoub, Ghazi AlAbar" />

    <!-- CSS -->
    <link href="./css/bootstrap.css" rel="stylesheet" crossorigin="anonymous" />
    <link rel="stylesheet" href="./css/style.css" />

    <link rel="shortcut icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <link rel="icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <title>Mlab &rarr; Invoice</title>
</head>

<body id="template" class="bg-white">
    <div class="container-fluid bg-white py-3 mt-5">
        <div class="mt-4"></div>
        <div class="row">
            <div class="col-md-6 mx-auto">
                <div class="card card-body">
                    <h3 class="text-center mb-4">Succesful Transaction</h3>
                    <hr />

                    <?php

                    echo "Order ID: " . $OrderID . "<br />";
                    //$newURL = "./Pharmacy_Invoice.php?id=$OrderID"
                    ?>

                    <a href="./Pharmacist_MainPage.php" class="d-block mb-3"><button class="btn btn-primary">Main
                            Page</button></a>
                    <!-- <a href="" class="d-block mb-3"><button class="btn btn-primary">View
                            Reciept</button></a> -->

                    <form method="post" action="./Pharmacy_Invoice.php">
                        <input type="hidden" name="id" value="<?php $OrderID ?>">
                        <input type="submit" name="submit" value="View Reciept" class="btn btn-primary d-block mb-3">
                    </form>

                </div>
            </div>
        </div>
    </div>

    <!-- geneal Java Script -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <!-- local  -->
    <script src="./js/template.js"></script>
</body>

</html>