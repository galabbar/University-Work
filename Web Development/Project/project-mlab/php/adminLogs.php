<!--
  Rania Kharnoub
  2201131226
  Phase 1
  admin Logs page. 
-->




<?php
   	//DATABASE CONNECTION INFORMATION
		$host = "sql202.epizy.com";
		$user = "epiz_33003979";
		$password = "G5PEUtFzXuE";
		$dbname = "epiz_33003979_project";
		$db = mysqli_connect($host, $user, $password, $dbname);
		// Check connection
        if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
  }
  
   
      
      $sql = "SELECT l.logId as logId, u.username as username, u.type as type, l.action as action , l.actionDate as actionDate FROM `Logs` l inner join `Users` u on l.userId = u.userId";
      
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
  <meta name="description" content="A website that helps Lab Manager to manage it" />
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
      <img src="./imgs/capsules.png" alt="Simple Logo" width="32px" class="mx-auto" />
    </a>
    <!-- pages -->
    <ul class="nav nav-pills nav-flush flex-column mb-auto text-center">
      <!-- item 1 -->
      <li class="nav-item">
        <a href="adminMedicne.html" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Combinations">
          <img src="./imgs/combine.png" alt="combinations" width="32px" />
        </a>
      </li>
      <!-- item 2 -->
      <li class="nav-item">
        <a href="adminRawMaterial.html" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Raw Material">
          <img src="./imgs/raw-materials.png" alt="raw material" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="adminUsers.html" class="nav-link py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Users">
          <img src="./imgs/man.png" alt="raw material" width="32px" />
        </a>
      </li>
      <li class="nav-item">
        <a href="adminLogs.html" class="nav-link active py-3" data-bs-toggle="tooltip" data-bs-placement="right"
          title="Logs">
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
          <input type="text" class="form-control" name="search" id="search" placeholder="Search Logs" />
          <!-- profile picture -->
          <div class="dropdown">
            <a href="#" class="d-flex align-items-center justify-content-center p-3 link-dark text-decoration-none"
              id="dropDownProfile" data-bs-toggle="dropdown" aria-expanded="false" data-toggle="dropdown">
              <!-- profile image -->
              <img src="./imgs/profile.png" alt="mdo" width="24" height="24" class="rounded-circle" />
            </a>

            <!-- pages list of profile (drop down) -->
            <ul class="dropdown-menu text-small shadow dropdown-menu-end" aria-labelledby="dropDownProfile">
              <li><a class="dropdown-item">Name: Template</a></li>
              <li>
                <a class="dropdown-item">Login at: <span title="Date - Time">Time</span></a>
              </li>
              <li>
                <hr class="dropdown-divider" />
              </li>

              <li><a class="dropdown-item" href="#">Sign out</a></li>
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

          <center>
            <div class="row" id="usersChartDiv"></div>
          </center>

          <br>
          <div class="row" id="ListOfUsers"></div>


          <table id="logsTable" class="sort-by table-sm table table-striped table-hover">

            <tr>

              <th onclick="sortTable(1)">username <i class="arrow down"></i></th>
              <th onclick="sortTable(2)">Type <i class="arrow down"></i></th>
              <th onclick="sortTable(3)">Action <i class="arrow down"></i></th>
              <th onclick="sortTable(4)">Date <i class="arrow down"></i></th>

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
    </section>

    <footer class="bg-secondary py-3 text-white text-center">
      All Copyright&copy; reserved for MLab 2022
    </footer>
  </section>
  <!-- geneal Java Script -->

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
    crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>


  <!-- local  -->
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

//DATABASE CONNECTION INFORMATION
$host = "sql202.epizy.com";
$user = "epiz_33003979";
$password = "G5PEUtFzXuE";
$dbname = "epiz_33003979_project";
		$db = mysqli_connect($host, $user, $password, $dbname);
		// Check connection
        if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
  }
  
   
      
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
      function drawUsersChart(id, nameUsers, pharmacistUser, chemistUser, adminUser) {
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
                data: [parseInt(adminUser), parseInt(pharmacistUser), parseInt(chemistUser)],
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
        drawUsersChart(i, nameUsers, pharmacistUser, chemistUser, adminUser);
      }
    }

    function sortTable(n) {
      var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
      table = document.getElementById("logsTable");
      switching = true;
      //Set the sorting direction to ascending:
      dir = "asc";
      /*Make a loop that will continue until
      no switching has been done:*/
      while (switching) {
        //start by saying: no switching is done:
        switching = false;
        rows = table.rows;
        /*Loop through all table rows (except the
        first, which contains table headers):*/
        for (i = 1; i < (rows.length - 1); i++) {
          //start by saying there should be no switching:
          shouldSwitch = false;
          /*Get the two elements you want to compare,
          one from current row and one from the next:*/
          x = rows[i].getElementsByTagName("TD")[n];
          y = rows[i + 1].getElementsByTagName("TD")[n];
          /*check if the two rows should switch place,
          based on the direction, asc or desc:*/
          if (dir == "asc") {
            if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
              //if so, mark as a switch and break the loop:
              shouldSwitch = true;
              break;
            }
          } else if (dir == "desc") {
            if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
              //if so, mark as a switch and break the loop:
              shouldSwitch = true;
              break;
            }
          }
        }
        if (shouldSwitch) {
          /*If a switch has been marked, make the switch
          and mark that a switch has been done:*/
          rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
          switching = true;
          //Each time a switch is done, increase this count by 1:
          switchcount++;
        } else {
          /*If no switching has been done AND the direction is "asc",
          set the direction to "desc" and run the while loop again.*/
          if (switchcount == 0 && dir == "asc") {
            dir = "desc";
            switching = true;
          }
        }
      }
    }





    // on load page
    window.addEventListener("load", start, false);

  </script>
</body>

</html>