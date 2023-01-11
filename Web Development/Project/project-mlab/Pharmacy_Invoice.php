<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacy_Invoice.html
Project Phase: 1 
-->


<?php

include "dbInfo.php";


if (isset($_POST["submit"]) && ($_POST["submit"] === "View Reciept" || $_POST["submit"] === "invoice")) {
  $id = $_POST["id"];

  $query = "SELECT cusid, date FROM Order WHERE invoice_id=$id LIMIT 1";
  $Row = mysqli_fetch_assoc(mysqli_query($db, $query));

  $cusid = $Row["cusid"];
  $date = $Row["date"];

  $query = "SELECT cusname, phone FROM Customer WHERE cusid=$cusid";
  $Row = mysqli_fetch_assoc(mysqli_query($db, $query));

  $PN = $Row["phone"];
  $name = $Row["cusname"];
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

<body id="template" class="p-5 bg-white">
  <!-- card -->
  <div class="card w-100 h-100 bg-white">
    <!-- content -->
    <div class="card-body">
      <div class="container mb-5 mt-3">
        <!-- top -->
        <div class="row d-flex align-items-center">
          <div class="col-2 text-end">
            <a class="btn btn-secondary">Print</a>
          </div>
        </div>

        <hr />

        <!-- details -->
        <div class="container">
          <div class="row">
            <div class="col-12">
              <div class="text-center">
                <img src="./imgs/capsules.png" width="64px" alt="logo" />
                <h3>MLab</h3>
              </div>
            </div>
            <div class="col-8">
              <ul class="list-unstyled">
                <li class="text-muted">To:
                  <?php  $name ?>
                </li>
                <li class="text-muted">Phone:
                  <?php  $PN ?>
                </li>
              </ul>
            </div>

            <div class="col-4">
              <p class="text-muted">Invoice</p>
              <ul class="list-unstyled">
                <li class="text-muted">ID:
                  <?php  $id ?>
                </li>
                <li class="text-muted">Date:
                  <?php $date  ?>
                </li>
              </ul>
            </div>
          </div>

          <!-- table  -->
          <div class="row mt-4">
            <table class="table table-striped table-borderless table-hover">
              <thead class="bg-info text-white">
                <tr>
                  <th scope="col">#</th>
                  <th scope="col">Medication</th>
                  <th scope="col">Qty</th>
                  <th scope="col">unit Price (kwd)</th>
                </tr>
              </thead>
              <tbody>
                <?php

                ini_set("display_errors", 1);
                error_reporting(E_ALL);

                $i = 1;
                $Total = 0;

                $query = "SELECT * FROM Order WHERE invoice_id=$id";
                $Result = mysqli_query($db, $query);

                while($Row = mysqli_fetch_assoc($Result)){

                  $medID = $Row["med_id"];
                  $qty = (int) $Row["qty"];

                  $query = "SELECT name, price FROM med WHERE id=$medID";

                  $med = mysqli_fetch_assoc(mysqli_query($db, $query));

                  $MedName = $med["name"];
                  $price = (int) $med["price"];

                  $Total += $price * $qty;

                  print<<<HERE

                  <tr>
                    <th scope="row">$i</th>
                    <td>$MedName</td>
                    <td>$qty</td>
                    <td>$price</td>
                  </tr>

                  HERE;
                }
                
                ?>
                <!-- empty -->
                <div class="col-9 text-end">
                  <p class="text-black">
                    <?php echo "<strong>Net Total: </strong>" . $Total  ?>
                  </p>
                </div>
          </div>
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