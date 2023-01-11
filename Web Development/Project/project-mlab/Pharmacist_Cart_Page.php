<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacist_Cart_Page.html
Project Phase: 3 
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

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

  <script type="text/javascript" src="./js/Pharmacists_Cart_Page.js"></script>

  <title>Mlab &rarr; Cart</title>
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
    <ul class="nav nav-pills nav-flush flex-column mb-auto text-center mt-2">
      <!-- item 1 -->
      <li class="nav-item">
        <a href="./Pharmacist_MainPage.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Main Page">
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
        <a href="./Pharmacist_Cart_Page.php" class="nav-link active py-3" data-bs-toggle="tooltip"
          data-bs-placement="right" title="Cart">
          <img src="./imgs/cart.png" alt="Shopping Cart" width="40px" />
        </a>
      </li>
    </ul>
    <!-- 
      <-- profile picture --1>
      <div class="dropdown border-top">
        <a
          href="#"
          class="d-flex align-items-center justify-content-center p-3 link-dark text-decoration-none"
          id="dropDownProfile"
          data-bs-toggle="dropdown"
          aria-expanded="false"
          data-toggle="dropdown"
        >
          <-- profile image --1>
          <img
            src="./imgs/profile.png"
            alt="mdo"
            width="24"
            height="24"
            class="rounded-circle"
          />
        </a>

        <-- pages list of profile (drop down) --1>
        <ul
          class="dropdown-menu text-small shadow"
          aria-labelledby="dropDownProfile"
        >
          <li><a class="dropdown-item" href="#">Sign out</a></li>
        </ul>
      </div> -->
  </nav>
  <!-- end of nav -->
  <!-- start of page conent -->

  <section class="page-content" id="content">
    <!-- header -->
    <header class="navbar bg-info p-0 text-white">
      <div class="container-fluid px-4 py-3">
        <span class="navbar-brand mb-0 h1">Pharmacist</span>
        <!-- <small>Where you can make your Medicine</small> -->
      </div>
    </header>

    <!-- The real content of page -->
    <section class="pageBody">
      <div class="container">
        <!-- header -->
        <div class="d-flex justify-content-between align-items-center mb-4">
          <h4 class="mb-0">Shopping Cart</h4>
          <button class="btn btn-primary" onclick="isCartEmpty()">Check Out</button>
        </div>

        <?php

        // ini_set("display_errors", 1);
        // error_reporting(E_ALL);
        include "php/DisplayCart.php";

        // echo "Length = " . $_SESSION["Cart-List-Length"] . "<br />";
        
        // for ($i = 1; $i <= (int)$_SESSION["Cart-List-Length"]; $i++){
        
        //     print_r($_SESSION["item-".$i]);
        // }
        

        ?>

    </section>

    <footer class="bg-info py-3 text-white text-center">
      All Copyright&copy; reserved for MLab 2022
    </footer>
  </section>
  <!-- geneal Java Script -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
    crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <!-- local  -->
  <script src="./js/template.js"></script>
</body>

</html>