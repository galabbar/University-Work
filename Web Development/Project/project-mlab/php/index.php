<!DOCTYPE html>
<!-- 
    rania
 -->


<?php
//DATABASE CONNECTION INFORMATION
$host = "sql202.epizy.com";
$user = "epiz_33003979";
$password = "G5PEUtFzXuE";
$dbname = "epiz_33003979_project";
$db = mysqli_connect($host, $user, $password, $dbname);
// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}
// echo "Connected successfully";
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  // username and password sent from form 

  $username = mysqli_real_escape_string($db, $_POST['username']);
  $password = mysqli_real_escape_string($db, $_POST['password']);


  $sql = "SELECT * FROM `Users` WHERE username = '$username'"; // and password = '$password'";
  //$sql2 = "SELECT type FROM `Users` WHERE username = '$username'";// and password = '$password'";

  $result = mysqli_query($db, $sql);
  $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
  //$active = $row['active'];
  $type = $row['type'];
  $count = mysqli_num_rows($result);

  // If result matched $username and $password, table row must be 1 row

  if ($count == 1) {
    // 	printf("Result set has %d rows.\n",$type);

    //session_register("username");
    $_SESSION['login_user'] = $username;
    if ($type == "admin") // Admin
    {

      header("location: adminUsers.html");
    } else if ($type == "chemist") // chemist
    {

      header("location: adminRawMaterial.html");
    } else if ($type == "pharmacist") {


      header("location: adminMedicne.html");

    } else {
      $error = "wrong '$type' selected";
    }


    // header("location: adminUsers.html");
  } else {
    $error = "Your Login Name or Password is invalid";
    //$error="$count";
  }
}
?>


<html>

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
  <title>Mlab &rarr; Login</title>
</head>
<!-- type of body and set the main styles -->

<body id="login" class="d-flex justify-content-center align-items-center container-fluid">
  <!-- form section of login -->
  <section class="bg-white p-4 rounded">
    <!-- logo and title -->
    <div class="text-center">
      <h3>M-Lab</h3>
      <img src="./imgs/capsules.png" alt="Logo" width="100px" />
    </div>
    <hr />
    <!-- title -->

    <h5 class="text-center mb-3">Login</h5>
    <!-- form -->
    <form action="" method="post" class="login-form">
      <div class="mb-3">
        <label class="form-label">UserName</label>
        <input type="text" name="username" class="form-control" />


      </div>
      <!-- password input -->
      <div class="mb-3">
        <label class="form-label">Password</label>
        <input type="password" class="form-control" id="password" name="passowrd" aria-describedby="passwordHelp" />

        <div id="passwordHelp" class="form-text">Keep it secret</div>
      </div>
      <!-- remeber checkbox -->
      <div class="mb-3 form-check">
        <input type="checkbox" class="form-check-input" id="loginSave" />
        <label class="form-check-label" for="loginSave">Save accout</label>
      </div>
      <!-- login button -->
      <div class="text-end">
        <button type="submit" class="btn btn-primary" onclick="login()">
          Login
        </button>
      </div>
    </form>
    <div><?php echo "$error"; ?></div>





  </section>

































  <!-- geneal Java Script -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
    crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <!-- local  -->
  <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.1.1/crypto-js.min.js"></script>
  <script src="./js/login.js"></script>
</body>

</html>