<?php
//Rania Kharnoub 
//2201131226
//phase3


 

    
if (isset($_POST['submit']) && $_POST['submit'] == "submit") {
    
       session_start();
  
     $loginId=$_SESSION['loginId'];
    
    $username = $_POST["username"];
    $email = $_POST["email"];
    $type = $_POST["type"];
    $password = $_POST["password"];
    $confirmpassword = $_POST["confirmpassword"];
   

 
    if($password != $confirmpassword)
    {
        echo "wrong password!"; 
        
    }
    else
    {
        AddUser($username, $email, $type, $password,$loginId);
    }
}
$pageTitle = "Add user";


function AddUser($username, $email, $type, $password,$loginId)
{
include ("dbInfo.php");
    //DATABASE CONNECTION INFORMATION
		/*$host = "sql202.epizy.com";
		$user = "epiz_33003991"; 
		$dbpassword = "lCyumAPIPC";
		$dbname = "epiz_33003991_mlabdb";
		$db = mysqli_connect($host, $user, $dbpassword, $dbname);
		// Check connection
        if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
  }
    */
    $query = "SELECT * FROM `Users` WHERE username='$username' LIMIT 1"; 

    $Rows = mysqli_num_rows(mysqli_query($db, $query));

   

    if ($Rows > 0) {
        
        print "<h1>This user already exists in the database!</h1>";
    } else {

      $query = "INSERT INTO `Users` (userId, username, imageURL, type, email,password) VALUES (NULL, '$username',NULL, '$type', '$email', '$password')";
        
        mysqli_query($db, $query); 
        
        
        $query2 = "INSERT INTO `Logs` (logId,userId, action, actionDate) VALUES (NULL, '$loginId', 'add user ($username) with type $type to system ', now())";
        
        mysqli_query($db, $query2); 
       
        print<<<HERE
            
            <table class="sort-by table-sm table table-striped table-hover"  >
            <h2>New user added: </h2>
                <tr>
                    
                    <th>UserName</th>
                    <th>Type</th>
                    <th>Email</th>                  
                </tr> 
                <tr> 
                    <td>$username</td>
                    <td>$type</td>
                    <td>$email</td>                  
                </tr>
            </table>
            <a href="adminUsers.php">back to users page</a>
        HERE;
    }
}
?>






<html lang="en">
  <head>
    
    <!-- Meta tages -->
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <!-- view port -->
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <!-- website information -->
    <meta
      name="description"
      content="A website that helps Lab Manager to manage it"
    />
    <meta name="keywords" content="Lab, Chem, Pharmacy" />
    <meta name="author" content="Hassan Khalaf, Rania Kharnoub, Ghazi AlAbar" />

    <!-- CSS -->
    <link href="./css/bootstrap.css" rel="stylesheet" crossorigin="anonymous" />
    <link rel="stylesheet" href="./css/style.css" />

    <link rel="shortcut icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <link rel="icon" href="./imgs/favicon.ico" type="image/x-icon" />
    <title>Mlab &rarr; Users</title>
  </head>
  <!-- type of body and set the main styles -->

</html>