<!-- 
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
File Name: Pharmacist_MainPage.html
Project Phase: 2 
-->

<?php
session_start();
$loginId = $_SESSION['loginId'];
$loginName = $_SESSION['loginName'];
$loginTime = $_SESSION['loginTime'];
if ($loginName == NULL or $loginName == "") {
  header("location: index.php");
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


  <script type="text/javascript" src="./js/Pharmacist_Main_Page.js"></script>

  <title>Mlab &rarr; Main</title>
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
              <li><a class="dropdown-item">Name:
                  <?echo $loginName;?>
                </a></li>
              <li>
                <a class="dropdown-item">Login at: <span title="Date - Time">
                    <?echo $loginTime;?>
                  </span></a>
              </li>
              <li>
                <hr class="dropdown-divider" />
              </li>

              <li><a class="dropdown-item" href="signout.php">Sign out</a></li>
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
          require("./php/Display_Medicine.php");
          //unset($_SESSION["item-1"]);
          //session_write_close();
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