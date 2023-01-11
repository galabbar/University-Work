<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacist_MainPage.html
Project Phase: 2 
-->

<?php
session_start();
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


  <script type="text/javascript" src="./js/Pharmacist_Main_Page.js"></script>

  <title>Mlab &rarr; Search Results</title>
</head>
<!-- type of body and set the main styles -->

<body id="template" class="d-flex">
  <!-- side nav -->
  <nav class="d-flex flex-column flex-shrink-0 bg-info">
    <!-- logo -->
    <a class="d-block text-decoration-none text-center py-3">
      <img src="./imgs/capsules.png" alt="Simple Logo" width="32px" class="mx-auto" />
    </a>
    <!-- pages -->
    <ul class="nav nav-pills nav-flush flex-column mb-auto text-center">
      <!-- item 1 -->
      <li class="nav-item">
        <a href="./Pharmacist_MainPage.php" class="nav-link active py-3" data-bs-toggle="tooltip"
          data-bs-placement="right" title="Main Page">
          <img src="./imgs/medicine.png" alt="combinations" width="32px" />
        </a>
      </li>
      <!-- item 2 -->
      <li class="nav-item">
        <a href="./Pharmacist_Invoice_Page.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Invoices">
          <img src="./imgs/invoice.png" alt="raw material" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="./Pharmacist_Cart_Page.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Cart">
          <img src="./imgs/cart.png" alt="Shopping Cart" width="40px" />
        </a>
      </li>
    </ul>
  </nav>
  <!-- end of nav -->
  <!-- start of page conent -->
  <section class="page-content" id="content">
    <!-- header -->
    <header class="navbar bg-info p-0 text-white">
      <div class="container-fluid px-4 py-3">
        <span class="navbar-brand mb-0 h1">M-Lab Pharmacist</span>
        <div class="d-flex align-items-center">
          <!-- search bar -->
          <form method="post" action="Search_Results.php">
            <span>
              <input type="text" class="form-control" name="search" id="search" placeholder="Search for Medicine" />
              <input class="btn btn-primary" type="submit" name="submit" value="Go">
            </span>
          </form>
          <!-- profile picture -->
          <div class="dropdown">
            <a href="#" class="d-flex align-items-center justify-content-center p-3 link-dark text-decoration-none"
              id="dropDownProfile" data-bs-toggle="dropdown" aria-expanded="false" data-toggle="dropdown">
              <!-- profile image -->
              <img src="./imgs/profile.png" alt="mdo" width="24" height="24" class="rounded-circle" />
            </a>

            <!-- pages list of profile (drop down) -->
            <ul class="dropdown-menu text-small shadow dropdown-menu-end" aria-labelledby="dropDownProfile">
              <li><a class="dropdown-item">Name: Template</a></li>
              <li>
                <a class="dropdown-item">Login at: <span title="Date - Time">Time</span></a>
              </li>
              <li>
                <hr class="dropdown-divider" />
              </li>

              <li><a class="dropdown-item" href="#">Sign out</a></li>
            </ul>
          </div>
        </div>
      </div>
    </header>

    <!-- The real content of page -->
    <section class="pageBody">
      <div class="container">
        <!-- header -->
        <div class="d-flex justify-content-between align-items-center mb-4">
          <h4 class="mb-0">Medicine List</h4>
          <!-- <button
              class="btn btn-primary"
              data-toggle="modal"
              data-target="#checkout"
            >
              Check out
            </button> -->
        </div>
        <!-- list of available medicine -->
        <div id="Medicine_List" class="row">

          <?php

        ini_set("display_errors", 1);
        error_reporting(E_ALL);

        include "php/dbInfo.php";

        function cleanData($data)
        {
            $data = trim($data);
            $data = stripslashes($data);
            $data = trim($data);
            $data = htmlspecialchars($data);
            $data = strip_tags($data);
            return $data;
        }
        
        if (isset($_POST["submit"]) && $_POST["submit"] === "Go"){

            $filter = cleanData($_POST["search"]);

            $query = "SELECT * FROM med WHERE name LIKE '%" . $filter . "%'";
            //$query = "SELECT * FROM med";
            $Result = mysqli_query($db, $query);

            $i = 1;

            // echo "i=$i" . " filter=" . $filter. "    result=$Result";

            // $Row = mysqli_fetch_assoc($Result);

            // $medID = $Row["med_id"];    
            // $name = $Row["med_name"];
            // $img = $Row["img"];
            // $qty = $Row["qty"];
            // $price = $Row["price"];
            // $Desc = $Row["desc"];

            //echo $name;

            while (True){

                $Row = mysqli_fetch_assoc($Result);

                if ($Row == False){

                    break;
                }
                // $medID = $Row["med_id"];    
                // $name = $Row["med_name"];
                // $img = $Row["img"];
                // $qty = $Row["qty"];
                // $price = $Row["price"];
                // $Desc = $Row["desc"];

                // if ($qty === "0"){

                //     continue;
                // }

            //     $query = "SELECT material_id FROM comb WHERE med_id=$medID";
            //     $ingredients = mysqli_query($db, $query);
            //     $ingr_List = "";

            //     while ($item = mysqli_fetch_assoc($ingredients)){

            //         $mat_id = $item["material_id"];

            //         $query = "SELECT name FROM raw WHERE id=$mat_id";
            //         $ingr_name = mysqli_query($db, $query);
            //         $ingr_name = mysqli_fetch_assoc($ingr_name);
            //         $ingr_name = $ingr_name["name"];

            //         $ingr_List .= "$ingr_name, ";
            //     }

            //     PRINT<<<HERE

            //     <div id="Medicine_Item-$i" class="col-md-3 mb-3">
            //     <!-- item -->
            //     <div class="card bg-white p-0 shadow overflow-hidden">
            //     <!-- img -->
            //     <img src="../imgs/$img" width="366" height="300" alt="Medicne i" />
            //     <!-- details -->
            //     <div class="p-3">
            //     <h5>$name</h5>
            //     <p>
            //     Availibilty: <span id="avail-$i">$qty</span> in stock<br />
            //     Price: $price kwd<br />
            //     ingredients: $ingr_List
            //     </p>
            //     <p class="text-muted">
            //     $Desc
            //     </p>
            //     <div class="d-flex justify-content-between mt-2 float-end">
            //     <button class="btn btn-primary" type="button" id="btn-$i" onclick="AddtoCart(this, '$name', $price, $qty, $medID)">Add to Cart</button>
            //     <input type="text" style="width: 50px" placeholder="QTY" id="qty-$i" >
            //     </div>
            //     </div>
            //     </div>
            //     </div>

            //     HERE;

            //     $i++;
            // }
        }

        ?>

        </div>
      </div>
    </section>

    <footer class="bg-info py-3 text-white text-center">
      All Copyright&copy; reserved for MLab 2022
    </footer>
    <!-- geneal Java Script -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <!-- local  -->
    <script src="./js/template.js"></script>
</body>

</html>