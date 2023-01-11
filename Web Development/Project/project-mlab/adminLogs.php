<!--
  Rania Kharnoub
  2201131226
  Phase 1
  admin Logs page. 
-->




<?php
    session_start();
    $loginId=$_SESSION['loginId'];
    $loginName=$_SESSION['loginName'];
    $loginTime=$_SESSION['loginTime'];
    if($loginName == NULL or $loginName == "" )
    {
        header("location: index.php");
    }  

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
  
   
      
      $sql = "SELECT l.logId as logId, u.username as username, u.type as type, l.action as action , l.actionDate as actionDate FROM `Logs` l left outer join `Users` u on l.userId = u.userId order by actionDate DESC";
      
      $result = mysqli_query($db,$sql);
   










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
    <title>Mlab &rarr; Logs</title>
  </head>
  <!-- type of body and set the main styles -->

  <body id="template" class="d-flex">
    <!-- side nav -->
    <nav class="d-flex flex-column flex-shrink-0 bg-secondary">
      <!-- logo -->
      <a class="d-block text-decoration-none text-center py-3">
        <img
          src="./imgs/capsules.png"
          alt="Simple Logo"
          width="32px"
          class="mx-auto"
        />
      </a>
      <!-- pages -->
      <ul class="nav nav-pills nav-flush flex-column mb-auto text-center">
        <!-- item 1 -->
        <li class="nav-item">
          <a
            href="adminMedicne.php"
            class="nav-link py-3"
            data-bs-toggle="tooltip"
            data-bs-placement="right"
            title="Combinations"
          >
            <img src="./imgs/combine.png" alt="combinations" width="32px" />
          </a>
        </li>
        <!-- item 2 -->
        <li class="nav-item">
          <a
            href="adminRawMaterial.php"
            class="nav-link py-3"
            data-bs-toggle="tooltip"
            data-bs-placement="right"
            title="Raw Material"
          >
            <img
              src="./imgs/raw-materials.png"
              alt="raw material"
              width="32px"
            />
          </a>
        </li>
        <li class="nav-item">
          <a
            href="adminUsers.php"
            class="nav-link py-3"
            data-bs-toggle="tooltip"
            data-bs-placement="right"
            title="Users"
          >
            <img
              src="./imgs/man.png"
              alt="raw material"
              width="32px"
            />
          </a>
        </li>
        <li class="nav-item">
          <a
            href="adminLogs.php"
            class="nav-link active py-3"
            data-bs-toggle="tooltip"
            data-bs-placement="right"
            title="Logs"
          >
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
           <form method="post" action="searchLogs.php">
			<table><tr><td><input
              type="text"
              class="form-control"
              name="search"
              id="search"
              placeholder="Search Logs"
            /></td><td>
            <input  class="btn btn-sm btn-primary" type="submit" name="submit" value="search" style="height:40px; font-size:20px;"></td></tr></table>
            	</form>
            <!-- profile picture -->
            <div class="dropdown">
              <a
                href="#"
                class="d-flex align-items-center justify-content-center p-3 link-dark text-decoration-none"
                id="dropDownProfile"
                data-bs-toggle="dropdown"
                aria-expanded="false"
                data-toggle="dropdown" 
              >
                <!-- profile image -->
                <img
                  src="./imgs/profile.png"
                  alt="mdo"
                  width="24"
                  height="24"
                  class="rounded-circle"
                />
              </a>

              <!-- pages list of profile (drop down) -->
              <ul
                class="dropdown-menu text-small shadow dropdown-menu-end"
                aria-labelledby="dropDownProfile"
              >
                <li><a class="dropdown-item">Name:<?echo $loginName;?> </a></li>
                <li>
                  <a class="dropdown-item">Login at: <span title="Date - Time"><?echo $loginTime;?></span></a>
                </li>
                <li><hr class="dropdown-divider" /></li>

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
          <div>
          <div class="d-flex justify-content-between align-items-center mb-4">
            
            <h4 class="mb-0">Logs</h4>
            <div class="d-flex justify-content-between align-items-center mb-4"></div>
            
            </div>
           
          <br>
           
          <center><div class="row" id="usersChartDiv" ></div>
          </center> 
             
             <br>
             <div class="row" id="ListOfUsers" ></div>


            <table  id = "logsTable"class="sort-by table-sm table table-striped table-hover"   >
              
              <tr>
            
              <th >username </th>
              <th >Type </th>
              <th >Action </th>
              <th >Date </th>

        </tr>   
        
            <?php
                while($row = mysqli_fetch_assoc($result)){?>
                <tr>
                
                    <td><?php echo $row['username']; ?></td>
                    <td><?php echo $row['type']; ?></td>
                    <td><?php echo $row['action']; ?></td>
                    <td><?php echo $row['actionDate']; ?></td>
                <tr>
            <?}?>
        
  </table>
  <!--
  <form method="post" action='#'>  
  <div class="mb-3">
          <label  class="form-label">Filter by username:</label>
		  <input type="text" name = "filterusername" class = "form-control" style="width:20%"/>
        <div class="text-end">
            <input id="filterbutton" class="btn btn-sm btn-primary" type="submit" name="submit" value="filter" style="text">
        </div>
      
        </div>

  </form>
  -->
  
      </section>

      <footer class="bg-secondary py-3 text-white text-center">
        All Copyright&copy; reserved for MLab 2022
      </footer>
    </section>
    <!-- geneal Java Script -->
    
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"
    ></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  
<!-- PHASE3  -->   



    <!-- PHASE3  -->
 
 <script>
 
 
let AllUsersChart = [];
let container = document.getElementById("usersChartDiv");
let container2 = document.getElementById("ListOfUsers");
let userImage = "./imgs/profile.png";




function start() {
  //nav tool tips enabling
  var tooltipTriggerList = [].slice.call(
    document.querySelectorAll('[data-bs-toggle="tooltip"]')
  );
  tooltipTriggerList.map(function (tooltipTriggerEl) {
    return new bootstrap.Tooltip(tooltipTriggerEl);
  });


/////////////////////////////////////////////////////


let MySQLDiv = document.createElement("div");
    
    MySQLDiv.classList = "col-md-3 mb-3";
    MySQLDiv.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" >
                    <?

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
  
   
      
      $adminCountSQL = "SELECT count(l.userId) as adminCount from Logs l inner join Users u on l.userId = u.userId   where u.type='admin'";
      $result = mysqli_query($db,$adminCountSQL);
      $row = mysqli_fetch_assoc($result);
      $adminCount = $row['adminCount'];


      $chemistCountSQL = "SELECT count(l.userId) as chemistCount from Logs l inner join Users u on l.userId = u.userId   where u.type='chemist'";
      $result = mysqli_query($db,$chemistCountSQL);
      $row = mysqli_fetch_assoc($result);
      $chemistCount = $row['chemistCount'];


      $pharmacistCountSQL = "SELECT count(l.userId) as pharmacistCount from Logs l inner join Users u on l.userId = u.userId   where u.type='pharmacist'";
      $result = mysqli_query($db,$pharmacistCountSQL);
      $row = mysqli_fetch_assoc($result);
      $pharmacistCount = $row['pharmacistCount'];

     
     echo $adminCount;
     echo $chemistCount;
     echo $pharmacistCount;
 


                    
                ?>    
                  </div>
              `;




////////////////////////////////////////////////////


  // load from data base the data and set them
  // these infromation are fixed for testing
  let countUsersCharts = 1;
  let nameUsers = "User Logs";
  /*let adminUser= 3;
  let pharmacistUser = 2;
  let chemistUser= 2;*/

  let adminUser = "<?php echo $adminCount; ?>"
  let pharmacistUser = "<?php echo $pharmacistCount; ?>"
  let chemistUser = "<?php echo $chemistCount; ?>"
  
  // Load users Chart:
  function drawUsersChart (id, nameUsers, pharmacistUser,chemistUser,adminUser) {
    // define the new element 
    let newElement = document.createElement("div");
    newElement.id = "usersChartElement" + id;
    newElement.classList = "col-md-3 mb-3";
    newElement.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" >
                    <canvas id="usersCanvas${id}"></canvas>
                    
                  </div>
              `;
  
    // add it to the page
    container.append(newElement);
  
    // config the chart of it
    const config = {
      type: "doughnut",
      data: {
        labels: ["Admin", "pharmacist", "Chemist"],
        datasets: [
          {
            label: "Dataset 1",
            data: [parseInt(adminUser), parseInt(pharmacistUser),parseInt(chemistUser)],
            backgroundColor: ["grey", "#f2545b", "#19323c"],
          },
        ],
      },
      options: {
        plugins: {
          legend: {
            position: "top",
          },
          title: {
            display: true,
            text: nameUsers,
          },
        },
      },
    };
    // load the chart
    AllUsersChart.push(
      new Chart(document.getElementById("usersCanvas" + id), config)
    );
  }

  // Call
  

  
  
  // load items to page
  for (var i = 1; i <= countUsersCharts; i++) {
    drawUsersChart (i, nameUsers, pharmacistUser,chemistUser,adminUser);
  }
}







// on load page
window.addEventListener("load", start, false);
 
 </script>
      </body>
</html>
