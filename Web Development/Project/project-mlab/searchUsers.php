<?php
    session_start();
    $loginId=$_SESSION['loginId'];
  	include ("dbInfo.php");


$search = $_POST['search'];
	//sql statement to select what to search for

	$sql = "SELECT userId, username,type,email from  `Users`   WHERE
				username LIKE '%$search%' OR
				userId LIKE '%$search%' OR
				email LIKE '%$search%' OR
                type LIKE '%$search%'
				";


$pageTitle = "Search in users";

	$result = mysqli_query($db, $sql); // or die(mysql_error());

	// find out how many matches

	$number = mysqli_num_rows($result);
	
	
	print<<<HERE
		<br><br><br><br>
		<h3 align = "center">$number result(s) found searching for "$search" in Users<h3>
		<table class="sort-by table-sm table table-striped table-hover"  id = "logsTable" align ="center" style="width:70%">
				<thead>
					<tr>
                        <th></th>
						<th id = "rightside">userId</th>
						<th id = "rightside">username</th>
						<th id = "rightside">email</th>
						<th id = "rightside">type</th>

					</tr>
				</thead>
HERE;
	//loop through results and get variables 

	while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC)){
		$username = $row["username"];
        $type = $row["type"];
		$email = $row["email"];
		$userId = $row["userId"];
		

		print<<<HERE

				<tr> 
					<td id = "rightside">
                    
						<form method="post" action='updateUser.php?userId=$userId'>  
                    <input class="btn btn-sm btn-primary" type="submit" name="submit" value="Update">
                    </form>
                        
						<form method="post" action='deleteUser.php?userId=$userId'>    
                    <input class="btn btn-sm btn-outline-primary" type="submit" name="submit" value="Delete">
                </form>   
					</td>
					<td id = "rightside"><strong>$userId</strong></td>
					<td id = "rightside">$username</td>
					<td id = "rightside">$email</td>
                    <td id = "rightside">$type</td>
					
				</tr>

HERE;
	} //End of While
print<<<HERE
<a href="adminUsers.php" style="font-size:16px">back to Users page</a> <br> <br>
HERE;
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
