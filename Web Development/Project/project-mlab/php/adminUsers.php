<!--
  Rania Kharnoub
  2201131226
  Updated Phase 3
  admin User page. 
-->
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
    <title>Mlab &rarr; Users</title>
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
            href="adminMedicne.html"
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
            href="adminRawMaterial.html"
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
            href="adminUsers.html"
            class="nav-link active py-3"
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
            href="adminLogs.html"
            class="nav-link py-3"
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
            <input
              type="text"
              class="form-control"
              name="search"
              id="search"
              placeholder="Search Users"
            />
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
                <li><a class="dropdown-item">Name: Template</a></li>
                <li>
                  <a class="dropdown-item"
                    >Login at: <span title="Date - Time">Time</span></a
                  >
                </li>
                <li><hr class="dropdown-divider" /></li>

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
           <br>
          <div >
            <!--the title of the page -->
            <div class="d-flex justify-content-between align-items-center mb-4">
              <h4 class="mb-0">Users</h4>
            <button
              class="btn btn-primary"
              data-bs-toggle="modal"
              data-bs-target="#addModal"
              onclick="document.getElementById('newFormuser').innerHTML=''"
            >
              New User
            </button>
            
            </div>
            
              <br>
           
           <center><div class="row" id="usersChartDiv" ></div>
           </center> 
              
              <br>
              <div class="row" id="ListOfUsers" ></div>
            </div>


        <!--start the table-->
        
    </section>
      <br><br>
      <footer class="bg-secondary py-3 text-white text-center">
        All Copyright&copy; reserved for MLab 2022
      </footer>
    </section>

    <!-- modals -->
    <!-- add modal -->
    <!--for the button add user-->
    <!-- modals -->
    <!-- add modal -->
    <div
      class="modal fade"
      id="addModal"
      tabindex="-1"
      aria-labelledby="addModalL"
      aria-hidden="true"
    >
      <div class="modal-dialog modal-dialog-centered modal-dialog-scrollable">
        <div class="modal-content">
          <!-- header -->
          <div class="modal-header">
            <h5 class="modal-title" id="addModalL">Add new user </h5>
            <!--to close thw window-->
            <button
              type="button"
              class="btn-close"
              data-bs-dismiss="modal"
              aria-label="Close"
            ></button>
          </div>
          <!-- body -->
          <div class="modal-body">
            <form action="#">
              <label for="UserName">Name</label>
              <input
                type="text"
                name="UserName"
                id="UserName"
                class="form-control"
                placeholder="Enter name here"
                required
                maxlength="20"
              />
              <br />
              <label for="UserEmail">Email</label>
              <input
                type="text"
                name="UserEmail"
                id="UserEmail"
                class="form-control"
                placeholder="abc@MLab.com"
                required
                maxlength="20"
              />
              <br />
              <div class="mb-3">
              <label for="userType" class="form-label">Type  </label>
                  <select name="userType" id="userType" class="form-control" >
                       <option value="admin">Admin</option>
                       <option value="chemist">Chemist</option>
                       <option value="pharmacist">Pharmacist</option>
                       <!--only one option "list" -->
                   </select>
              </div>
              <label for="formpassword">Password</label>
              <input
                type="password"
                name="formNewName"
                id="formNewName"
                class="form-control"
                placeholder="*********"
                required
                maxlength="20"
              />
              <br />
              <label for="formCpassword">Confirm Password</label>
              <input
                type="password"
                name="formNewDesc"
                id="formNewDesc"
                class="form-control"
                placeholder="*********"
                required
                maxlength="20"
              />
              <div id="newFormuser"></div>
            </form>
          </div>
          
          
          <!-- footer -->
          <div class="modal-footer">
            <button
              class="btn btn-primary"
              data-bs-toggle="modal"
              data-bs-target="#addModal"
              onclick="Adduser(0);"
            >
              Create User
            </button>        

            
          </div>
        </div>
      </div>
    </div>


      
    <!-- geneal Java Script -->
    
    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
      crossorigin="anonymous"
    ></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    
    
    
    <!-- local  -->
    <script >
    

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
  
   
      
         
      $adminCountSQL = "SELECT count(userId) as adminCount from Users where type='admin'";
      $result = mysqli_query($db,$adminCountSQL);
      $row = mysqli_fetch_assoc($result);
      $adminCount = $row['adminCount'];


      $chemistCountSQL = "SELECT count(userId) as chemistCount from Users    where type='chemist'";
      $result = mysqli_query($db,$chemistCountSQL);
      $row = mysqli_fetch_assoc($result); 
      $chemistCount = $row['chemistCount'];


      $pharmacistCountSQL = "SELECT count(userId) as pharmacistCount from  Users   where type='pharmacist'";
      $result = mysqli_query($db,$pharmacistCountSQL);
      $row = mysqli_fetch_assoc($result);
      $pharmacistCount = $row['pharmacistCount'];

                    
                ?>    
                  </div>
              `;




////////////////////////////////////////////////////


  // load from data base the data and set them
  // these infromation are fixed for testing
 let countUsersCharts = 1;
  let nameUsers = "Users";


  let adminUser = "<?php echo $adminCount; ?>"
  let pharmacistUser = "<?php echo $pharmacistCount; ?>"
  let chemistUser = "<?php echo $chemistCount; ?>"






    let AllUsersChart = [];
let container = document.getElementById("usersChartDiv");
let container2 = document.getElementById("ListOfUsers");
let userImage = "./imgs/profile.png";
let countUsersPerType = 2;  // test fixed value



  

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
                    <div class="d-flex justify-content-between align-items-center mt-4" >
                      <button class="btn btn-sm btn-primary" onclick="AdminList(${id});">Admin</button>
                      <button class="btn btn-sm btn-primary" onclick="PharmacistList(${id});">Pharmacist</button>
                      <button class="btn btn-sm btn-primary" onclick="ChemistList(${id});">Chemist</button>
                    </div>
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
            label: "",
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
  




function start() {
  //nav tool tips enabling
  var tooltipTriggerList = [].slice.call(
    document.querySelectorAll('[data-bs-toggle="tooltip"]')
  );
  tooltipTriggerList.map(function (tooltipTriggerEl) {
    return new bootstrap.Tooltip(tooltipTriggerEl);
  });
 
  // load items to page
  for (var i = 1; i <= countUsersCharts; i++) {
    drawUsersChart (i, nameUsers, pharmacistUser,chemistUser,adminUser);
  }
}


let MySQLDiv2 = document.createElement("div");
    
    MySQLDiv2.classList = "col-md-3 mb-3";
    MySQLDiv2.innerHTML = `
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
  
   
      
      $adminSQL = "SELECT * from Users where type='admin'";
      $resultAdmin = mysqli_query($db,$adminSQL);
      $rowAdmin = mysqli_fetch_assoc($resultAdmin);
      //$adminCount = $rowAdmin['adminCount'];


      $chemistSQL = "SELECT * from Users    where type='chemist'";
      $resultChemist = mysqli_query($db,$chemistSQL);
      $rowChemist = mysqli_fetch_assoc($resultChemist);
      //$chemistCount = $rowChemist['chemistCount'];


      $pharmacistSQL = "SELECT * from  Users   where type='pharmacist'";
      $resultPharmacist = mysqli_query($db,$pharmacistSQL);
      $rowPharmacist = mysqli_fetch_assoc($resultPharmacist);
      //$pharmacistCount = $rowPharmacist['pharmacistCount'];

     
   


                    
                ?>    
                  </div>
              `;




////////////////////////////////////////////////////
// Admin
function AdminList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  
  let MySQLDiv2 = document.createElement("div");
    
    MySQLDiv2.classList = "col-md-3 mb-3";
    MySQLDiv2.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" style="width:100%" >
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
  
   
      
      $adminSQL = "SELECT * from Users where type='admin'";
      $resultAdmin = mysqli_query($db,$adminSQL);
      //$rowAdmin = mysqli_fetch_assoc($resultAdmin);
      //$adminCount = $rowAdmin['adminCount'];

                    
                ?>    
                  </div>
              `;
  
  
  
  
  var i = 1;
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
				
              <div  id="adminUserDiv${i}" class="row" >
				<table  id = "logsTable"class="sort-by table-sm table table-striped table-hover"   >
              
              <tr>
            
              <th>userId </th>
              <th >username </th>
			  <th >Type </th>
              <th >email </th>
              <th>Edit</th>
			  <th>Delete</th>

			  </tr>   
        
            <?php
                while($rowAdmin = mysqli_fetch_assoc($resultAdmin)){?>
                <tr>
                    <td><?php echo $rowAdmin['userId']; ?></td>
                    <td><?php echo $rowAdmin['username']; ?></td>
                    <td><?php echo $rowAdmin['type']; ?></td>
                    <td><?php echo $rowAdmin['email']; ?></td>
					<td><button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'admin');">Delete</button></td>
					<td><button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button></td>
                   
                <tr>
            <?}?>
        
  </table>

               
             </div>
            `;





  // add it to the page
  container2.append(newElement);
 



}









////////////////////////////////////////////////////
// Pharmacist	
function PharmacistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  
  let MySQLDiv2 = document.createElement("div");
    
    MySQLDiv2.classList = "col-md-3 mb-3";
    MySQLDiv2.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" style="width:100%" >
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
  
   
      
      $pharmacistSQL = "SELECT * from Users where type='pharmacist'";
      $resultPharmacist = mysqli_query($db,$pharmacistSQL);
      //$rowPharmacist = mysqli_fetch_assoc($resultPharmacist);
      //$pharmacistCount = $rowPharmacist['pharmacistCount'];

                    
                ?>    
                  </div>
              `;
  
  
  
  
  var i = 1;
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
				
              <div  id="PharmacistUserDiv${i}" class="row" >
				<table  id = "usersTable"class="sort-by table-sm table table-striped table-hover"   >
              
              <tr>
            
              <th>userId </th>
              <th >username </th>
			  <th >Type </th>
              <th >email </th>
              <th>Edit</th>
			  <th>Delete</th>

			  </tr>   
        
            <?php
                while($rowPharmacist = mysqli_fetch_assoc($resultPharmacist)){?>
                <tr>
                    <td><?php echo $rowPharmacist['userId']; ?></td>
                    <td><?php echo $rowPharmacist['username']; ?></td>
                    <td><?php echo $rowPharmacist['type']; ?></td>
                    <td><?php echo $rowPharmacist['email']; ?></td>
					<td><button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'pharmacist');">Delete</button></td>
					<td><button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button></td>
                   
                <tr>
            <?}?>
        
  </table>

               
             </div>
            `;





  // add it to the page
  container2.append(newElement);
 



}









// Chemist
function ChemistList(id) {
  document.getElementById("ListOfUsers").innerHTML = "";
  
  let MySQLDiv2 = document.createElement("div");
    
    MySQLDiv2.classList = "col-md-3 mb-3";
    MySQLDiv2.innerHTML = `
                <!-- Item -->
                  <div class="card bg-white p-3 shaddow overflow-hidden" style="width:100%" >
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
  
   
      
      $chemistSQL = "SELECT * from Users where type='chemist'";
      $resultChemist = mysqli_query($db,$chemistSQL);
      //$rowChemist = mysqli_fetch_assoc($resultChemist);
      //$chemistCount = $rowChemist['chemistCount'];

                    
                ?>    
                  </div>
              `;
  
  
  
  
  var i = 1;
  let newElement = document.createElement("div");
  newElement.id = "userDetails" + id;
  newElement.classList = "col-md-3 mb-3";
  newElement.innerHTML = `
				
              <div  id="chemistUserDiv${i}" class="row" >
				<table  id = "logsTable"class="sort-by table-sm table table-striped table-hover"   >
              
              <tr>
            
              <th>userId </th>
              <th >username </th>
			  <th >Type </th>
              <th >email </th>
              <th>Edit</th>
			  <th>Delete</th>

			  </tr>   
        
            <?php
                while($rowChemist = mysqli_fetch_assoc($resultChemist)){?>
                <tr>
                    <td><?php echo $rowChemist['userId']; ?></td>
                    <td><?php echo $rowChemist['username']; ?></td>
                    <td><?php echo $rowChemist['type']; ?></td>
                    <td><?php echo $rowChemist['email']; ?></td>
					<td><button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'chemist');">Delete</button></td>
					<td><button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button></td>
                   
                <tr>
            <?}?>
        
  </table>

               
             </div>
            `;





  // add it to the page
  container2.append(newElement);
 



}






function Edit(id) {

Swal.fire("", "You can modify by clicking on the user details directly", "");

}


function Delete(id,uType)

{
  
  //document.getElementById("ListOfUsers").innerHTML=""
  
  
  if (uType=="admin")
  {
    document.getElementById("adminUserDiv" + id).innerHTML=""
    adminUser--;
  }
  
  else if (uType=="chemist")
  {
     document.getElementById("chemistUserDiv" + id).innerHTML=""
    chemistUser--;
    
  }
  else
  {
        document.getElementById("PharmacistUserDiv" + id).innerHTML=""
    pharmacistUser--;
  }
  //$("#usersChartDiv").load(window.location.href + " #usersChartDiv" );
  AllUsersChart[0].data.datasets[0].data = [parseInt(adminUser), parseInt(pharmacistUser),parseInt(chemistUser)];
  AllUsersChart[0].update();
}


function Adduser(id)
{
  let NewUserName = document.getElementById("UserName").value;
  let NewUserEmail = document.getElementById("UserEmail").value;
  let NewUserType = document.getElementById("userType").value;
  if (NewUserType == "admin")
    {
       adminUser= adminUser+1;
       id=adminUser;
    }
    else if (NewUserType == "pharmacist")
    {
      pharmacistUser= pharmacistUser +1;
      id=pharmacistUser;
    }
    else
    {
      chemistUser= chemistUser+1;
      id=chemistUser;
    }
    
    
    let newElement = document.createElement("div");
    let i=id;
    newElement.classList = "col-md-3 mb-3";
    if (NewUserType == "admin")
    {
      newElement.innerHTML = `
      <!-- item -->
      <div  id="adminUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
        <!-- img -->
        <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
        <!-- details -->
             <p contenteditable="true" id="adminUserNameP${i}">${NewUserName}</p>
            <p contenteditable="true" id="adminP${i}">${NewUserType}</p>
            <!--mailto -> to make it email-->
            <p contenteditable="true" id="AdminMailP${i}"> <a href = "mailto:${NewUserName}">${NewUserEmail}</a></p>        
          <div class="d-flex justify-content-between align-items-center mt-4">
          <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'admin');">Delete</button>
          <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
          
        </div>
       
       
      </div>
                `;
    }
    else if (NewUserType == "pharmacist")
    {
      newElement.innerHTML = `
            <!-- item -->
              <div  id="PharmacistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="PharmacistUserNameP${i}">PharmacistUser</p>
                    <p contenteditable="true" id="pharmacistP${i}">Pharmacist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="PharmacistMailP${i}"> <a href = "mailto: PharmacistUser@MLab.com">PharmacistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'pharmacist');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;

      
    }
    else
    {
      newElement.innerHTML = `
            <!-- item -->
              <div  id="chemistUserDiv${i}" class="card bg-white p-0 shadow overflow-hidden" >
                <!-- img -->
                <img src="${userImage}" alt="userImage" style="width:50px; height:50px;" />
                <!-- details -->
                     <p contenteditable="true" id="chemistUserNameP${i}">chemistUser</p>
                    <p contenteditable="true" id="chemistP${i}">Chemist</p>
                    <!--mailto -> to make it email-->
                    <p contenteditable="true" id="ChemistMailP${i}"> <a href = "mailto: chemistUser@MLab.com">chemistUser@MLab.com</a></p>        
                  <div class="d-flex justify-content-between align-items-center mt-4">
                  <button class="btn btn-sm btn-outline-primary" onclick="Delete(${i},'chemist');">Delete</button>
                  <button class="btn btn-sm btn-primary" onclick="Edit(${i});">Edit</button>
                  
                </div>
               
               
              </div>
            `;
    }
    
  // add it to the page
  
  container2.append(newElement);
  AllUsersChart[0].data.datasets[0].data = [parseInt(adminUser), parseInt(pharmacistUser),parseInt(chemistUser)];
  AllUsersChart[0].update();
  
}


// on load page
window.addEventListener("load", start, false);

    
    </script>
  </body>
</html>