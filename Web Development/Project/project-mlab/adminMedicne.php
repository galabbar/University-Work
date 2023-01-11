<!DOCTYPE html>
<!-- 
    adminMedicne.php
    Phase 3
    Hassan Khlaf - 2192131028
 -->
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
  <link rel="stylesheet"
    href="https://cdnjs.cloudflare.com/ajax/libs/selectize.js/0.14.0/css/selectize.bootstrap5.min.css" />
  <link href="./css/bootstrap.css" rel="stylesheet" crossorigin="anonymous" />
  <link rel="stylesheet" href="./css/style.css" />

  <link rel="shortcut icon" href="./imgs/favicon.ico" type="image/x-icon" />
  <link rel="icon" href="./imgs/favicon.ico" type="image/x-icon" />
  <title>Mlab &rarr; Medicine Combinations</title>
</head>
<!-- include connections to database -->
<? include "hassanDB.php" ?>
<!-- type of body and set the main styles -->

<body id="template" class="d-flex">
  <!-- side nav -->
  <nav class="d-flex flex-column flex-shrink-0 bg-secondary">
    <!-- logo -->
    <a class="d-block text-decoration-none text-center py-3">
      <img src="./imgs/capsules.png" alt="Simple Logo" width="32px" class="mx-auto" />
    </a>
    <!-- pages -->
    <ul class="nav nav-pills nav-flush flex-column mb-auto text-center">
      <!-- item 1 -->
      <li class="nav-item">
        <a href="adminMedicne.php" class="nav-link active py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Combinations">
          <img src="./imgs/combine.png" alt="combinations" width="32px" />
        </a>
      </li>
      <!-- item 2 -->
      <li class="nav-item">
        <a href="adminRawMaterial.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Raw Material">
          <img src="./imgs/raw-materials.png" alt="raw material" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="adminUsers.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right" title="Users">
          <img src="./imgs/man.png" alt="raw material" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="adminLogs.php" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right" title="Logs">
          <img src="./imgs/log.png" alt="combinations" width="32px" />
        </a>
      </li>
    </ul>
  </nav>
  <!-- end of nav -->
  <!-- start of page conent -->
  <section class="page-content" id="content">
    <!-- header -->
    <header class="navbar bg-secondary p-0 text-white">
      <div class="container-fluid px-4 py-3">
        <span class="navbar-brand mb-0 h1">M-Lab Admin</span>
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
          <button class="btn btn-primary" onclick="openModal()">
            New Combination
          </button>
        </div>
        <!-- row -->
        <div class="row" id="medicineList"></div>
      </div>
    </section>
    <footer class="bg-secondary py-3 text-white text-center">
      All Copyright&copy; reserved for MLab 2022
    </footer>
  </section>

  <!-- modals -->
  <!-- add modal -->
  <div class="modal fade" id="addModal" tabindex="-1" aria-labelledby="addModalL" aria-hidden="true">
    <div class="modal-dialog modal-dialog-centered modal-dialog-scrollable">
      <div class="modal-content">
        <!-- header -->
        <div class="modal-header">
          <h5 class="modal-title" id="addModalL">Add new Combination</h5>
          <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <!-- body -->
        <div class="modal-body">
          <form action="#">
            <label for="formNewName">Name of Medicine:</label>
            <input type="text" name="formNewName" id="formNewName" class="form-control" placeholder="enter name here"
              required maxlength="20" />
            <div class="form-text d-none text-danger help" id="formNewNameHelp">
              Can not be empty
            </div>
            <br />
            <label for="formNewDesc">Description of Medicine:</label>
            <input type="text" name="formNewDesc" id="formNewDesc" class="form-control"
              placeholder="enter description here" required maxlength="20" />
            <div class="form-text d-none text-danger help" id="formNewDescHelp">
              Can not be empty
            </div>
            <br />
            <label for="formNewPic">Picture of Medicine:</label>
            <input type="file" name="formNewPic" id="formNewPic" required />
            <div class="form-text d-none text-danger help" id="formNewPicHelp">
              you must choose a pic
            </div>
            <br />
            <div id="newFormCom"></div>
          </form>
        </div>
        <!-- footer -->
        <div class="modal-footer">
          <button type="button" class="btn btn-sm btn-outline-secondary" onclick="removeComp()">
            Remove last component
          </button>
          <button type="button" class="btn btn-sm btn-outline-primary" onclick="addComp()">
            Add a component
          </button>
          <button type="button" class="btn btn-sm btn-primary" onclick="addNew()">
            Save changes
          </button>
        </div>
      </div>
    </div>
  </div>
  <!-- geneal Java Script -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
    crossorigin="anonymous"></script>
  <script src="https://code.jquery.com/jquery-3.6.1.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/selectize.js/0.14.0/js/selectize.min.js"></script>
  <script></script>

  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <!-- local  -->
  <script src="./js/adminMedicne.js"></script>
</body>

</html>