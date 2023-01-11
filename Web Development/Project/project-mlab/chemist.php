<!DOCTYPE html>
<!-- 
    chemist.php
    Phase 3
    Hassan Khlaf - 2192131028 -->
<html lang="en">
<?php

session_start();
$loginId = $_SESSION['loginId'];
$loginName = $_SESSION['loginName'];
$loginTime = $_SESSION['loginTime'];
if ($loginName == NULL or $loginName == "") {
  header("location: index.php");
}

?>

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
  <title>Mlab &rarr; Chemist</title>
</head>
<!-- include connections to database -->
<? include "hassanDB.php" ?>
<!-- type of body and set the main styles -->

<body id="template" class="d-flex">
  <!-- side nav -->
  <nav class="d-flex flex-column flex-shrink-0 bg-danger">
    <!-- logo -->
    <a class="d-block text-decoration-none text-center py-3">
      <img src="./imgs/capsules.png" alt="Simple Logo" width="32px" class="mx-auto" />
    </a>
    <!-- pages -->
    <ul class="nav nav-pills nav-flush flex-column mb-auto text-center">
      <li class="nav-item">
        <a href="chemist.php" class="nav-link active py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Combinations">
          <img src="./imgs/combine.png" alt="combinations" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="chemistMaterial.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Raw Material">
          <img src="./imgs/raw-materials.png" alt="raw material" width="32px" />
        </a>
      </li>
    </ul>
  </nav>
  <!-- end of nav -->
  <!-- start of page conent -->
  <section class="page-content" id="content">
    <!-- header -->
    <header class="navbar bg-danger p-0 text-white">
      <div class="container-fluid px-4 py-3">
        <span class="navbar-brand mb-0 h1">M-Lab Chemist</span>
        <div class="d-flex align-items-center">
          <!-- search bar -->
          <input type="text" class="form-control" name="search" id="search" onkeyup="filter()"
            placeholder="Search Medicine" />
          <!-- profile picture -->
          <div class="dropdown">
            <a href="#" class="d-flex align-items-center justify-content-center p-3 link-dark text-decoration-none"
              id="dropDownProfile" data-bs-toggle="dropdown" aria-expanded="false" data-toggle="dropdown">
              <!-- profile image -->
              <img src="./imgs/profile.png" alt="mdo" width="24" height="24" class="rounded-circle" />
            </a>

            <!-- pages list of profile (drop down) -->
            <ul class="dropdown-menu text-small shadow dropdown-menu-end" aria-labelledby="dropDownProfile">
              <li><a class="dropdown-item">Name: <?php echo $loginName ?></a></li>
              <li>
                <a class="dropdown-item">Login at: <span title="Date - Time"><?php echo $loginTime ?></span></a>
              </li>
              <li>
                <hr class="dropdown-divider" />
              </li>

              <li><a class="dropdown-item" href="./signout.php">Sign out</a></li>
            </ul>
          </div>
        </div>
      </div>
    </header>

    <section class="pageBody">
      <!-- container -->
      <div class="container py-4">
        <!-- header -->
        <div class="d-flex justify-content-between align-items-center mb-4">
          <h4 class="mb-0">Combinations</h4>
        </div>
        <!-- rw -->
        <div class="row" id="medicineList"></div>
      </div>
    </section>
    <footer class="bg-danger py-3 text-white text-center">
      All Copyright&copy; reserved for MLab 2022
    </footer>
  </section>

  <!-- geneal Java Script -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
    crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <!-- local  -->

  <script src="./js/chemist.js"></script>
</body>

</html>