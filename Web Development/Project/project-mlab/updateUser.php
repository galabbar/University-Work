<?php
//Rania Kharnoub 
//2201131226
//phase3



if (isset($_POST['submit']) && $_POST['submit'] == "Update") {

    
    session_start();
  
     $loginId=$_SESSION['loginId'];
    
    $userId = $_GET["userId"];

    
   

    updateUser($userId);
}



$pageTitle = "Update user";
 
 
function updateUser($userId) 
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
    
    $query = "SELECT * FROM `Users` WHERE userId='$userId' LIMIT 1";

    
      $result = mysqli_query($db,$query);
      $row = mysqli_fetch_assoc($result);
      $username = $row['username'];
      $type = $row['type'];
      $email = $row['email'];
      $password= $row['password'];
      
      




   print<<<HERE
            
            <form method="post" action="confirmUpdate.php?userId=$userId">
            <table class="sort-by table-sm table table-striped table-hover"  >
            <h2>Update the reqiured details: </h2>
                <tr> 
                     
                    <th>userId</th>
                    <th>username</th>
                    <th>Type</th>
                    <th>Email</th>
                    <th>password</th>                  
                </tr>
                <tr>
                    <td>$userId</td>
                    <td>$username</td>
                    <td>$type</td>
                    <td>$email</td>          
                </tr> 
                <tr>
                    <td></td>
                    <td><input type="text" name="updatedusername" value="$username"></input></td>
                    <td><input type="text" name="updatedtype" value="$type"></input></td>
                    <td><input type="text" name="updatedemail" value="$email"></input></td>    
                    <td><input type="password" name="updatedpassword" value="$password"></input></td>    
                                  
                </tr>
            </table>
            <input class="btn btn-primary"
              data-bs-toggle="modal"
              data-bs-target="#addModal" type="submit" name="submit" value="submit">
               
            </form>
        HERE;


       
 
        
     
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