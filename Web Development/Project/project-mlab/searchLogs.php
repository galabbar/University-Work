<?php
    session_start();
    $loginId=$_SESSION['loginId'];
  	include ("dbInfo.php");


$search = $_POST['search'];
	//sql statement to select what to search for

	$sql = "SELECT l.logId as logId, u.username as username, u.type as type, l.action as action , l.actionDate as actionDate FROM `Logs` l left outer join `Users` u on l.userId = u.userId  WHERE
				username LIKE '%$search%' OR
				action LIKE '%$search%' OR
				actionDate LIKE '%$search%' OR
                type LIKE '%$search%'
				
			order by actionDate DESC";


$pageTitle = "Search in Logs";

	$result = mysqli_query($db, $sql); // or die(mysql_error());

	// find out how many matches

	$number = mysqli_num_rows($result);
	
	print<<<HERE
		<br><br><br><br>
		<h3 align = "center">$number result(s) found searching for "$search" in logs<h3>
		<table class="sort-by table-sm table table-striped table-hover"  id = "logsTable" align ="center" style="width:70%">
				<thead>
					<tr>
						<th id = "rightside">username</th>
						<th id = "rightside">type</th>
						<th id = "rightside">action</th>
						<th id = "rightside">actionDate</th>

					</tr>
				</thead>
HERE;
	//loop through results and get variables 

	while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC)){
		$username = $row["username"];
        $type = $row["type"];
		$action = $row["action"];
		$actionDate = $row["actionDate"];
		

		print<<<HERE

				<tr> 
			
					<td id = "rightside"><strong>$username</strong></td>
					<td id = "rightside">$type</td>
					<td id = "rightside">$action</td>
                    <td id = "rightside">$actionDate</td>
					
				</tr>

HERE;
	} //End of While
print<<<HERE
<a href="adminLogs.php" style="font-size:16px">back to Logs page</a> <br>
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
